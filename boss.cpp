#include "boss.h"

Boss::Boss(int id, string name, int dId) {
	this->m_id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "職工編號:  " << this->m_id
		<< " \t職工姓名:  " << this->m_Name
		<< " \t崗位:  " << this->getDeptName()
		<< " \t崗位職責: 管理公司所有事務" << endl;
}

string Boss::getDeptName() {
	return string("老闆");
}