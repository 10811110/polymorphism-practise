#include <iostream>
using namespace std;
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

	////���եN�X
	//Worker* worker = NULL;
	//worker = new Boss(1, "�i�T", 1);
	//worker->showInfo();

	//��Ҥƺ޲z��H
	WorkerManager wm;
	
	int choice = 0; // �Ψ��x�s�Τ᪺�ﶵ

	while (true) {
		
		
		//�եήi�ܵ�榨�����
		wm.Show_Menu();

		cout << "�п�J�z�����:  " << endl;
		cin >> choice; //�����Τ᪺�ﶵ
		switch (choice)
		{
		case 0://�h�X�޲z�{��
			wm.ExitSystem();
			break;
		case 1://�W�[¾�u�H��
			wm.Add_Emp();
			break;
		case 2://���¾�u�H��
			wm.Show_Emp();
			break;
		case 3://�R����¾¾�u
			wm.Del_Emp();
			break;
		case 4://�ק�¾�u�H��
			wm.Mod_Emp();
			break;
		case 5://�d��¾�u�H��
			wm.Find_Emp();
			break;
		case 6://���ӽs���Ƨ�
			wm.Sort_Emp();
			break;
		case 7://�M�ũҦ�����
			wm.Clean_File();
			break;
		default:
			system("cls");//�M��
			break;
		}
	}

	system("pause");
	
	return 0;
}