#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

//���u��
class Employee :public Worker {
public:
	
	//�c�y���
	Employee(int id, string name, int dId);

	//��ܭӤH�H��
	virtual void showInfo();

	//���¾�u�^��W��
	virtual string getDeptName();

};

