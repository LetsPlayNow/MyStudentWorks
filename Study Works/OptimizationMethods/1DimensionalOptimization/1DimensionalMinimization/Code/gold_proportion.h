#include "find_min_interval.h"
#include "f_x.h"

// ���������� �������� �� �������
// ����� �������� �������
// * param[in] eps (> 0): �������� �������� ������
// * param[in/out] min_i: ��������, ���������� �������
// * param[out] x*: ���������� �������� ������� f
// ! ������� �� �������� ������������ �������� ����������
float gold_proportion_method(MinInterval min_i, float eps);

// ~ 1.618
float find_tao();

void log(float x_1, float x_2);