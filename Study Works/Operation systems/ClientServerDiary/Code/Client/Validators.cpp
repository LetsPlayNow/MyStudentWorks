//���������� ������ "ExampleValidator"
#include "Validators.h"

ExampleValidator::ExampleValidator(QObject *parent)
	: QValidator(parent)
{}

ExampleValidator::~ExampleValidator()
{}

//��������� ��� ������ ������
QValidator::State ExampleValidator::validate(QString & input, int &) const
{
	bool acceptable = 1;
	bool intermediate = input.isEmpty();
	//�� ����� 100 ��������, ������� �� ����, ������� �������, �������� � ������ ���������� , . !
	//������ �������� ���������� � QTDesigner
	//��� ��������� �������� ��
	for (int i = 0; i<= input.size() - 1; i++)
	{
		acceptable = acceptable && (input[i].isLetter() || input[i] == ' ' || input[i] == ',' || input[i] == '.' || input[i] == '!');
	}

	//���� ������
	if (acceptable || intermediate)
	{return QValidator::Intermediate;}

	else 
	{return QValidator::Invalid;}
}