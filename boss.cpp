#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "¾�u�s��:  " << this->m_id
		<< " \t¾�u�m�W:  " << this->m_Name
		<< " \t�^��:  " << this->getDeptName()
		<< " \t�^��¾�d: �޲z���q�Ҧ��ư�" << endl;
}

string Boss::getDeptName() {
	return string("����");
}