#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}	

void Employee::showInfo() {
	cout << "¾�u�s��:  " << this->m_id
		<< " \t¾�u�m�W:  " << this->m_Name
		<< " \t�^��:  " << this->getDeptName()
		<< " \t�^��¾�d: �����g�z��N������" << endl;
}

string Employee::getDeptName() {
	return string("���u");
}