#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "¾�u�s��:  " << this->m_id
		<< " \t¾�u�m�W:  " << this->m_Name
		<< " \t�^��:  " << this->getDeptName()
		<< " \t�^��¾�d: ���������N�����ȡA�äU�o�����u" << endl;
}

string Manager::getDeptName() {
	return string("�g�z");
}