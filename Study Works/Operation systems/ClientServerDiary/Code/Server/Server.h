#pragma once
#include "mediator.h"
#include "server_requests.h"
#include "Semaphore.h"
#include <qobject.h>
#include <map>

using std::map;
using std::vector;
using std::pair;

class Server : public QObject
{
	Q_OBJECT
public:
	static Server * to_use_signals;
	Server();
	~Server();

	//�������� ��������� �������
	static DWORD WINAPI service_client(LPVOID p);
	static DWORD WINAPI server_control(LPVOID p);
	static DWORD WINAPI shutdown(LPVOID p);
	static DWORD WINAPI autosave(LPVOID p);


	//������� ������������ �������
	static void count(mediator &, int &);
	static void append(mediator &, int &);
	static void remove(mediator &, int &);
	static void update(mediator &, int &);
	static void record(mediator &, int &);
	static void records(mediator &, int &);
	static void to_file();

	
	void operating_cycle();    //������ �������
private:
	short int port_service;
	short int port_update;
	static DataBase server_DB;

	//��������� ��������� 
	//============================================
	static int clients_count;    //����� ������������ ��������
	static int errors_limit;     //����� ����� ������ (�� ����������)
	static int operations_count; //����� ����������� �������� ��� ����� ������
	static int autosave_period;  //����� ����� ����� �������� ������ ������ �����������
	static map <SOCKET, SOCKET> clients; //������ ����� - ���� - ��� ������ ���� � ��������, ������ - �� ������ ��������������
	static vector <HANDLE> threads;
	//����������
	//=====================================
	static const int locks_count = 5;
	enum global_locks
	{
		AD,
		Count,
		Records_and_toFile,
		Record,
		Update
	};

	static Mutex global_locks[locks_count];

	//���������� ��������
	static void update_clients(SOCKET);
};

