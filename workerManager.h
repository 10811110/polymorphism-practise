#pragma once //防止頭文件重複包含
#include <iostream> //包含輸入輸出流頭文件
using namespace std; //使用標準命名空間
#include <fstream>
#define FILENAME "empfile.txt"

#include "worker.h"

class WorkerManager 
{
public:

	//構造函數
	WorkerManager();

	//展示菜單
	void Show_Menu();

	//退出系統
	void ExitSystem();

	//紀錄職工人數
	int m_EmpNum;

	//職工數組指針
	Worker ** m_EmpArray;

	//添加職工
	void Add_Emp();

	//保存文件
	void save();

	//判斷文件是否為空
	bool m_FileIsEmpty;

	//統計文件中人數
	int get_EmpNum();

	//初始化員工
	void init_Emp();

	//顯示職工
	void Show_Emp();

	//刪除職工
	void Del_Emp();

	//判斷職工是否存在 如果存在返回職工所在數組的位置 不存在返回-1
	int IsExist(int id);

	//修改職工
	void Mod_Emp();

	//查找職工
	void Find_Emp();
	
	//按照編號排序
	void Sort_Emp();

	//清空文件
	void Clean_File();

	//析構函數
	~WorkerManager();
};