#pragma once
#include "DataBase.h"
//���������
class mediator
{
public:
	mediator(SOCKET s_client, DataBase & server_DB);
	~mediator();

	bool count();

	bool append();
	bool remove();
	bool update();

	bool record();
	bool records();
public: //����� ������ �� private:
	SOCKET socket;
	DataBase & DB;
};

