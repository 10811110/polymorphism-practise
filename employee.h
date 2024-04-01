#pragma once
#include <iostream>
#include <string>
using namespace std;
#include "worker.h"

//員工類
class Employee :public Worker {
public:
	
	//構造函數
	Employee(int id, string name, int dId);

	//顯示個人信息
	virtual void showInfo();

	//獲取職工崗位名稱
	virtual string getDeptName();

};

