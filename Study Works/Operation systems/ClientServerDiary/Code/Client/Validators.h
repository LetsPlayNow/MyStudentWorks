//��� ���� � ��������� ������ ���������� "ExampleValidator"
//���������� ������ ��������� � "Validators.cpp"
#ifndef EXAMPLEVALIDATOR_H
#define EXAMPLEVALIDATOR_H

#include <QValidator>

class ExampleValidator : public QValidator
{
public:
	ExampleValidator(QObject *parent);
	~ExampleValidator();
	QValidator::State validate(QString & input, int &) const;
};

#endif // EXAMPLEVALIDATOR_H



