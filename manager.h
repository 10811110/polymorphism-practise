#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

//�g�z��
class Manager :public Worker {
public:

	//�c�y���
	Manager(int id, string name, int dId);

	//��ܭӤH�H��
	virtual void showInfo();

	//���¾�u�^��W��
	virtual string getDeptName();

};