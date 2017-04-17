//��� ���� � ��������� ������ Note
//���������� ������ ��������� � "Note.cpp"
#pragma once
#undef min
#include <QDateTime>
#include <QStringList.h> //��� ��������� �������� ���� QStringList
#include <qstring.h> //��� ��������� localAwareCompare
#include <qdatastream.h>
#include <Windows.h>

class Note
{
public:
	Note(const Note & other);
	Note(); //���������� ������ �����������, ������� ����� ����� ��������

	unsigned int id;
	QString name; //������������ �����������
	QDateTime dateAndTime; //���� � ����� �����������
	QTime timeLength; //������������� �����������
	QString place; //����� ���������� �����������
	int importantly; //�������� �����������

	/*_____�������������_____*/
	bool hasPeriodicity; //������� �� �������������?
	int periodicity; //������ ���������� (�������� ���� �� ���������)
	int numberOfRepeat; //���������� ����������


	bool to_file(HANDLE file);
	bool from_file(HANDLE file);

	bool send(SOCKET socket);
	bool recv(SOCKET socket);
	
	friend QDataStream & operator<<(QDataStream & out, const Note & data);
	friend QDataStream & operator>>(QDataStream & in, Note & data);

	void operator=(const Note &);
	bool operator>(const Note &) const;
	bool operator>=(const Note &) const;
	bool operator<(const Note &) const;
	bool operator<=(const Note &) const;
	bool operator!=(const Note &) const;
	bool operator==(const Note &) const;
};