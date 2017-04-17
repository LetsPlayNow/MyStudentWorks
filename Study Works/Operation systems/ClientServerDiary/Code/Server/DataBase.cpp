#include "DataBase.h"

DataBase::DataBase()
{
	id = 0;
	lstrcpy(filename, L"Diary.db");
}

DataBase::~DataBase()
{
}


//���������� ���������� ������� � ���� ������
int DataBase::count() const
{
	return dataBase.size();
}


//��������� ������ � ���� ������
//���������� ���������� ������������� � ���������� ��� � ���� Id ��������� record
//[in]����������� ������
//[out]������ ������ � ����������
index_id DataBase::append(Note rec)
{
	rec.id = id;
	dataBase.insert(id, rec);
	index_id note_info = { getIndex(rec.id), rec.id };

	id++;
	return note_info;
}


//������� �� ���� ������ ������ � ������ ���������������
//[in] ������������� (id)
bool DataBase::remove(u_int id)
{
	return dataBase.remove(id) != 0;
}


//�������� ������ � ���� ������
//[in]���������� ������
//[out]����� ������� ������ � ������ ����������
int DataBase::update(Note record)
{
	int index = -1;

	if (dataBase.contains(record.id))
	{
		WaitForSingleObject(dataBase[record.id].mutex, INFINITE);
		dataBase[record.id] = record;
		index = getIndex(record.id);
		ReleaseMutex(dataBase[record.id].mutex);
	}

	return index;
}


//���������� ������ (������ ��� ������) �� ��������� ��������������
Note DataBase::record(u_int id)
{
	Note note;
	if (dataBase.contains(id))
	{
		WaitForSingleObject(dataBase[id].mutex, INFINITE);
		note = dataBase[id];
		ReleaseMutex(dataBase[id].mutex);
	}
		
	return note;
}

//���������� ������ �������, ������� ������ ������������ � �������� � ������ ����������
//[out]������ ������� ��� ����������� � QListWidget
QVector<Note> DataBase::records()
{
	//����������� QMAP
	//���������� ��� ������ Note �� QMap � QVector
	QVector<Note> notes;
	for (QMap <u_int, Note>::const_iterator i = dataBase.constBegin(); i != dataBase.constEnd(); i++)
		notes << i.value();

	//��������� ���������� QVector notes
	for(int i = 0; i < notes.size() - 1; i++)
		for(int j = 0; j < notes.size() - i - 1; j++)
			if(notes[j] > notes[j+1])
				{
					Note temp = notes[j];
					notes[j] = notes[j+1];
					notes[j+1] = temp;
				}

	return notes;
}

//��������� ������ � �������� ����
//[out] bool = false - ��������� ������ �� �������
//[out] bool = true - ������ ������� ���������
bool DataBase::write_to_file()
{
	HANDLE file = CreateFile(filename, GENERIC_WRITE, NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	bool success = file != INVALID_HANDLE_VALUE;
	if (!success)
		return false;

	DWORD writed;
	int size = count();
	success = WriteFile(file, (void *)&size, sizeof(int), &writed, NULL) && writed == sizeof(int) && success;

	QVector <Note> notes = records();
	for (int i = 0; i < size; i++)
		success = notes[i].to_file(file) && success;


	//� ����� ������� id
	success = WriteFile(file, (void *)&id, sizeof(short int), &writed, NULL) && writed == sizeof(short int) && success;

	success = CloseHandle(file) && success;
	return success;
}
	


//��������� ������ �� ��������� ����� (!���������� ������ ������������!)
//[out] bool = false - ��������� ������ �� �������
//[out] bool = true - ������ ������� ���������
bool DataBase::read_from_file()
{
	HANDLE file = CreateFile(filename, GENERIC_READ, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	bool success = file != INVALID_HANDLE_VALUE;
	if (!success)
		return false;

	DWORD readed;
	int size = count();
	Note temp;
	success = ReadFile(file, (void *)&size, sizeof(int), &readed, NULL) && sizeof(int) == readed && success;

	for (int i = 0; i < size; i++)
	{
		success = temp.from_file(file) && success;
		append(temp);
	}

	success = ReadFile(file, (void *)&id, sizeof(short int), &readed, NULL) && readed == sizeof(short int) && success;

	success = CloseHandle(file) && success;
	return success;
}

//���������� ��� ������
void DataBase::clear()
{
	dataBase.clear();
}

/*�����:
-1:        ���� � ���� ������ ��� ������ � ��������������� id
int index: ������ ������ � ���� ������
*/
int DataBase::getIndex(u_int id)
{
	if (!dataBase.contains(id))
		return -1;

	Note temp = dataBase[id];
	QMap <u_int, Note>::const_iterator i = dataBase.constBegin();
	int index = 0;
	while (i != dataBase.constEnd())
	{
		if (*i < temp)
			index++;
		i++;
	}

	return index;
}