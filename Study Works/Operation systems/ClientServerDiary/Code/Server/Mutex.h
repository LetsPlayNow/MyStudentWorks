#pragma once
#include "windows.h"
class Mutex
{
public:
	Mutex(LPCWSTR mutex_name);
	Mutex();
	virtual ~Mutex();

	virtual void lock();
	virtual void unlock();

	//���������� ������ ��� ����������� ������������
	virtual void enter();
	virtual void leave();

protected:
	HANDLE mutex;
};

