#pragma once
#define NOMINMAX
#include <Windows.h>
#include <QDateTime>
#include <qstring.h>
#include <qdatastream.h>
#include <qstringlist.h>


class Note
{
public:
	Note();
	Note(const Note & other);
	~Note();

	unsigned int id;
	QString name; //������������ �����������
	QDateTime dateAndTime; //���� � ����� �����������
	QTime timeLength; //������������� �����������
	QString place; //����� ���������� �����������
	int importantly; //�������� �����������

	bool hasPeriodicity; //������� �� �������������?
	int periodicity; //������ ���������� (�������� ���� �� ���������)
	int numberOfRepeat; //���������� ����������

	bool to_file(HANDLE file);
	bool from_file(HANDLE file);

	bool send(SOCKET socket);
	bool recv(SOCKET socket);

	HANDLE mutex;


	//���������
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