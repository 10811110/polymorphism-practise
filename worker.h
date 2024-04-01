#pragma once
#include <iostream>
#include <string>
using namespace std;

//職工抽象基類
class Worker {
public:

	//顯示個人信息
	virtual void showInfo() = 0;
	//獲取崗位名稱
	virtual string getDeptName() = 0;

	int m_id; //職工編號
	string m_Name;//職工姓名
	int m_DeptId;//職工所在部門名稱編號
};