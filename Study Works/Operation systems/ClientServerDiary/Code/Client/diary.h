#pragma once
//��� ���� � ��������� ������ �������� ���� "Diary.h"
//���������� ������ ��������� � "Diary.cpp"
#include <QtWidgets/QMainWindow>
#include "ui_diary.h"
#include "Note.h"
#include "DataBase.h"


class Diary : public QMainWindow
{
	Q_OBJECT

public:
	Diary(QWidget *parent = 0);
	~Diary();
	
	void connecting();

public slots: 
	void addNote();
	void updateNote();
	void deleteCurrentNote();

	void fillData();
	void tcp_connect();
	void checkedButton(bool newValue);

	void showNoteWhichClikedInBrowser();

	void update_browser_list();

	void error_service(int error_code);

public:
	QString makeBrowserString(const Note &);
	void from_file();

private:
	void saveInTemp();
	bool canBeSaved(const Note & note); //����������, ����� �� ��������� ������ ������
	void showNote(unsigned int id);
	void clearTemp(); //������� ��������� ������ �� ��������� � ��� ���������
	void clearWidgets(); //������� ������� ����� �������� ��������� ������ �� ��������
	
	void prepare_view_forms();
	//���� ������
	DataBase DB;

	//������������� ���������� ��������
	HANDLE fill_browser_mutex;

	//������ ������
	Note temp;
	Ui::Diary ui;
};
