// ����� ��������� ���������� �������� 
// ������������ �������� ������-������-�����
#pragma once
#include <cstdio>
#include "f_x.h"

// ������� ����������� ��������
// ����� �� ���� a � b ��������?
struct MinInterval{
	float a; // ������
	float b; // �����

public:
	MinInterval(float a_o = -1.0, float b_o = -1.0) : a(a_o), b(b_o){}

	void log()
	{
		printf("a: %f\nb: %f\n", a, b);		
		puts("=================================");
	}
};

// �������� ������-������-�����
// ����� ��������� ���������� ��������
// * param[in]     float | x_0: ��������� �����
// * param[in]		 float | h: ��� (> 0)
// * param[in/out] MinInterval | min_i: ��������, ���������� �������
// * param[out]    bool: ����� ������ �������
// ! ������� �� �������� ������������ �������� ����������
void findMinInterval(float x_0, float h, MinInterval & min_i);