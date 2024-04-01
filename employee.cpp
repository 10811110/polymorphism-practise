#include "employee.h"

Employee::Employee(int id, string name, int dId) {
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}	

void Employee::showInfo() {
	cout << "職工編號:  " << this->m_id
		<< " \t職工姓名:  " << this->m_Name
		<< " \t崗位:  " << this->getDeptName()
		<< " \t崗位職責: 完成經理交代的任務" << endl;
}

string Employee::getDeptName() {
	return string("員工");
}