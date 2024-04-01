#include <iostream>
using namespace std;
#include "workerManager.h"

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main() {

	////測試代碼
	//Worker* worker = NULL;
	//worker = new Boss(1, "張三", 1);
	//worker->showInfo();

	//實例化管理對象
	WorkerManager wm;
	
	int choice = 0; // 用來儲存用戶的選項

	while (true) {
		
		
		//調用展示菜單成員函數
		wm.Show_Menu();

		cout << "請輸入您的選擇:  " << endl;
		cin >> choice; //接收用戶的選項
		switch (choice)
		{
		case 0://退出管理程序
			wm.ExitSystem();
			break;
		case 1://增加職工信息
			wm.Add_Emp();
			break;
		case 2://顯示職工信息
			wm.Show_Emp();
			break;
		case 3://刪除離職職工
			wm.Del_Emp();
			break;
		case 4://修改職工信息
			wm.Mod_Emp();
			break;
		case 5://查找職工信息
			wm.Find_Emp();
			break;
		case 6://按照編號排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文檔
			wm.Clean_File();
			break;
		default:
			system("cls");//清屏
			break;
		}
	}

	system("pause");
	
	return 0;
}