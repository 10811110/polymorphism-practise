#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

//������
class Boss :public Worker {
public:

	//�c�y���
	Boss(int id, string name, int dId);

	//��ܭӤH�H��
	virtual void showInfo();

	//���¾�u�^��W��
	virtual string getDeptName();

};

