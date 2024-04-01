#include "manager.h"

Manager::Manager(int id, string name, int dId) {
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Manager::showInfo() {
	cout << "職工編號:  " << this->m_id
		<< " \t職工姓名:  " << this->m_Name
		<< " \t崗位:  " << this->getDeptName()
		<< " \t崗位職責: 完成老闆交代的任務，並下發給員工" << endl;
}

string Manager::getDeptName() {
	return string("經理");
}