#pragma once
#include "windows.h"
#include "Mutex.h"
class Semaphore : public Mutex
{
public:
	Semaphore(LPCWSTR semaphore_name);
	~Semaphore();

	void enter(); //��������� ��������������� �������
	void leave(); //��������� ��������������� �������

	void lock();
	void unlock(); //������� ������
private:
	int count; //����� �������, ����������� ���� �������
};

