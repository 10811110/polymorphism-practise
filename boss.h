#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

//老闆類
class Boss :public Worker {
public:

	//構造函數
	Boss(int id, string name, int dId);

	//顯示個人信息
	virtual void showInfo();

	//獲取職工崗位名稱
	virtual string getDeptName();

};

