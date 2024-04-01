#include "workerManager.h"
//using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() {

	// 1. ��󤣦s�b

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		//cout << "��󤣦s�b" << endl;
		//��l���ݩ�
		//��l�Ƭ����H��
		this->m_EmpNum = 0;
		//��l�ƼƲի��w
		this->m_EmpArray = NULL;
		//��l�Ƥ��O�_����
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2. ���s�b �ƾڬ���
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//��󬰪�
		//cout << "��󬰪�! " << endl;
		//��l�Ƭ����H��
		this->m_EmpNum = 0;
		//��l�ƼƲի��w
		this->m_EmpArray = NULL;
		//��l�Ƥ��O�_����
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.���s�b�åB�O���ƾ�
	int num = this->get_EmpNum();
	//cout << "¾�u�H�Ƭ�: " << num << endl;
	this->m_EmpNum = num;

	//�}�P�Ŷ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//�N��󤤪��ƾڦs���Ʋդ�
	this->init_Emp();

	//���եN�X
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "¾�u�s��: " << this->m_EmpArray[i]->m_id << " "
	//		<< "�m�W: " << this->m_EmpArray[i]->m_Name << " "
	//		<< "�����s��: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

//�i�ܵ��
void WorkerManager::Show_Menu() {
	cout << "****************************************" << endl;
	cout << "**********�w��ϥ�¾�u�޲z�t��**********" << endl;
	cout << "**************0.�h�X�޲z�{��************" << endl;
	cout << "**************1.�W�[¾�u�H��************" << endl;
	cout << "**************2.���¾�u�H��************" << endl;
	cout << "**************3.�R����¾¾�u************" << endl;
	cout << "**************4.�ק�¾�u�H��************" << endl;
	cout << "**************5.�d��¾�u�H��************" << endl;
	cout << "**************6.���ӽs���Ƨ�************" << endl;
	cout << "**************7.�M�ũҦ�����************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//�h�X�t��
void WorkerManager::ExitSystem() {
	cout << "�w��U���ϥ�" << endl;
	system("pause");
	exit(0);
}

//�K�[¾�u
void WorkerManager::Add_Emp() {
	cout << "�п�J�K�[¾�u�ƶq:  " << endl;

	int addNum = 0; //�O�s�Τ᪺��J�ƶq
	cin >> addNum;

	if (addNum > 0) {
		//�K�[
		//�p��K�[�s�Ŷ��j�p
		int newSize = this->m_EmpNum + addNum; // �s�Ŷ��j�p = ��Ӭ����H�� + �s�W�H��

		//�}�P�s�Ŷ�
		Worker ** newSpace = new Worker* [newSize];
		
		//�N��ӪŶ��U�ƾ� ������s�Ŷ��U
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//��q�K�[�s�ƾ�
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;

			cout << "�п�J�� " << i + 1 << " �ӷs���u�s��: " << endl;
			cin >> id;

			cout << "�п�J�� " << i + 1 << " �ӷs���u�m�W: " << endl;
			cin >> name;

			cout << "�п�ܸ�¾�u�^��: " << endl;
			cout << "1. ���q¾��" << endl;
			cout << "2. �g�z" << endl;
			cout << "3. ����" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//�N�Ы�¾�u���w �O�s��Ʋդ�
			newSpace[this->m_EmpNum + i] = worker;
		}

		//����즳�Ŷ�
		delete[] this->m_EmpArray;

		//���s�Ŷ������V
		this->m_EmpArray = newSpace;

		//��s�s��¾�u�H��
		this->m_EmpNum = newSize;

		//��s¾�u�����żлx
		this->m_FileIsEmpty = false;

		//���\�K�[��O�s����
		this->save();

		//���ܲK�[���\
		cout << "���\�K�[" << addNum << "�W�s¾�u" << endl;
	}
	else {
		cout << "��J�ƾڦ��~" << endl;
	}

	//�ץ��N���M�̦^��W�ťؿ�
	system("pause");
	system("cls");

}

//�O�s���
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//�ο�X���覡���}��� --�g���

	//�N�C�ӤH���ؼg�J����
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//�������
	ofs.close();
}

//�έp��󤤤H��
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//���}��� Ū

	int id;
	string name;
	int dId;
	
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}

	return num;
}

//��l�ƭ��u
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;

		if (dId == 1) { //���q¾�u
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) { //�g�z
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) { //����
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//���¾�u
void WorkerManager::Show_Emp() {
	//�P�_���O�_����
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������!" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//�Q�Φh�A�եε{�Ǳ��f
			this->m_EmpArray[i]->showInfo();
		}
	}
	//�ץ��N���M�̦^��W�ťؿ�
	system("pause");
	system("cls");
}

//�R��¾�u
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������!" << endl;
	}
	else {
		cout << "�п�J�Q�n�R��¾�u�s��: ";
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		
		if (index != -1) {
			//�ƾګe��
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//��s�ƲդH���Ӽ�
			//�ƾڦP�B��s����
			this->save();
		}
		else {
			cout << "�R������ ������¾�u" << endl;
		}

	}
	//�ץ��N���M�̦^��W�ťؿ�
	system("pause");
	system("cls");
}

//�P�_¾�u�O�_�s�b �p�G�s�b��^¾�u�Ҧb�Ʋժ���m ���s�b��^-1
int WorkerManager::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_id == id) {
			//���¾�u
			index = i;
			break;
		}
	}

	return index;
}

//�ק�¾�u
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������!" << endl;
	}
	else {
		cout << "�п�J�Q�n�ק�¾�u�s��: ";
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1) {
			
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�d��: " << id << "��¾�u, �п�J�s¾�u��: " << endl;
			cin >> newId;

			cout << "�п�J�s�m�W: " << endl;
			cin >> newName;

			cout << "�п�J�^��: " << endl;
			cout << "1. ���q¾��" << endl;
			cout << "2. �g�z" << endl;
			cout << "3. ����" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
			case 2:
				worker = new Manager(newId, newName, 2);
			case 3:
				worker = new Boss(newId, newName, 3);
			default:
				break;
			}

			//�N�Ы�¾�u���w �O�s��Ʋդ�
			this->m_EmpArray[ret] = worker;

			cout << "�ק令�\!" << endl;
			//�ƾڦP�B��s����
			this->save();
		}
		else {
			cout << "�ק異�� ������¾�u" << endl;
		}

	}
	//�ץ��N���M�̦^��W�ťؿ�
	system("pause");
	system("cls");
}

//�d��¾�u
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������!" << endl;
	}
	else {
		cout << "�п�J�d�䪺�覡: " << endl;
		cout << "1. ���s���d: " << endl;
		cout << "2. ���m�W�d: " << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "�п�J�Q�n�d��¾�u�s��: ";
			int id = 0;
			cin >> id;

			int ret = this->IsExist(id);

			if (ret != -1) {
				//���¾�u
				cout << "�d���¾�u �H���p�U" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "�d�䥢�� �d�L���H" << endl;
		}
		else if (select == 2) {
			cout << "�п�J�Q�n�d��¾�u�m�W: ";
			string name ;
			cin >> name;

			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					//���¾�u
					cout << "�d���¾�u �H���p�U" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}

			if (flag == false) {
				cout << "�d�䥢�� �d�L���H" << endl;
			}	
		}
		else {
			cout << "��J�ﶵ���~" << endl;
		}
	}
	//�ץ��N���M�̦^��W�ťؿ�
	system("pause");
	system("cls");
}

//���ӽs���Ƨ�
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "��󤣦s�b�ά�������!" << endl;
		//�ץ��N���M�̦^��W�ťؿ�
		system("pause");
		system("cls");
	}
	else {
		cout << "�п�ܱƧǪ��覡: " << endl;
		cout << "1. ��¾�u���i��ɧ�: " << endl;
		cout << "2. ��¾�u���i�歰��: " << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++) {
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) { //�ɧ�
					if (this->m_EmpArray[MinOrMax]->m_id > this->m_EmpArray[j]->m_id) {
						MinOrMax = j;
					}
				}
				else { //����
					if (this->m_EmpArray[MinOrMax]->m_id < this->m_EmpArray[j]->m_id) {
						MinOrMax = j;
					}
				}
			}
			//�P�_�@�}�l���̤j�̤p�O���O�̫᪺�̤j�̤p
			if (i != MinOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "�ƧǦ��\! ���G��: " << endl;
		this->save();
		this->Show_Emp();
	}

}

//�M�Ť��
void WorkerManager::Clean_File() {
	cout << "�T�w�M��? " << endl;
	cout << "1. �T�w " << endl;
	cout << "2. ��^ " << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//ios::trunc �p�G�s�b�R�����í��s�Ы�
		ofstream ofs(FILENAME, ios::trunc);

		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0l; i < m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//�R����ϼƲի��w
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "�M�Ŧ��\! " << endl;
	}

	//�ץ��N���M�̦^��W�ťؿ�
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0l; i < m_EmpNum; i++) {
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}

		//�R����ϼƲի��w
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}