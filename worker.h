#pragma once
#include <iostream>
#include <string>
using namespace std;

//¾�u��H����
class Worker {
public:

	//��ܭӤH�H��
	virtual void showInfo() = 0;
	//����^��W��
	virtual string getDeptName() = 0;

	int m_id; //¾�u�s��
	string m_Name;//¾�u�m�W
	int m_DeptId;//¾�u�Ҧb�����W�ٽs��
};