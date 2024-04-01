#include "workerManager.h"
//using namespace std;

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

WorkerManager::WorkerManager() {

	// 1. 文件不存在

	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	if (!ifs.is_open()) {
		//cout << "文件不存在" << endl;
		//初始化屬性
		//初始化紀錄人數
		this->m_EmpNum = 0;
		//初始化數組指針
		this->m_EmpArray = NULL;
		//初始化文件是否為空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2. 文件存在 數據為空
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		//文件為空
		//cout << "文件為空! " << endl;
		//初始化紀錄人數
		this->m_EmpNum = 0;
		//初始化數組指針
		this->m_EmpArray = NULL;
		//初始化文件是否為空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在並且記錄數據
	int num = this->get_EmpNum();
	//cout << "職工人數為: " << num << endl;
	this->m_EmpNum = num;

	//開闢空間
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//將文件中的數據存放到數組中
	this->init_Emp();

	//測試代碼
	//for (int i = 0; i < this->m_EmpNum; i++) {
	//	cout << "職工編號: " << this->m_EmpArray[i]->m_id << " "
	//		<< "姓名: " << this->m_EmpArray[i]->m_Name << " "
	//		<< "部門編號: " << this->m_EmpArray[i]->m_DeptId << endl;
	//}

}

//展示菜單
void WorkerManager::Show_Menu() {
	cout << "****************************************" << endl;
	cout << "**********歡迎使用職工管理系統**********" << endl;
	cout << "**************0.退出管理程序************" << endl;
	cout << "**************1.增加職工信息************" << endl;
	cout << "**************2.顯示職工信息************" << endl;
	cout << "**************3.刪除離職職工************" << endl;
	cout << "**************4.修改職工信息************" << endl;
	cout << "**************5.查找職工信息************" << endl;
	cout << "**************6.按照編號排序************" << endl;
	cout << "**************7.清空所有文檔************" << endl;
	cout << "****************************************" << endl;
	cout << endl;
}

//退出系統
void WorkerManager::ExitSystem() {
	cout << "歡迎下次使用" << endl;
	system("pause");
	exit(0);
}

//添加職工
void WorkerManager::Add_Emp() {
	cout << "請輸入添加職工數量:  " << endl;

	int addNum = 0; //保存用戶的輸入數量
	cin >> addNum;

	if (addNum > 0) {
		//添加
		//計算添加新空間大小
		int newSize = this->m_EmpNum + addNum; // 新空間大小 = 原來紀錄人數 + 新增人數

		//開闢新空間
		Worker ** newSpace = new Worker* [newSize];
		
		//將原來空間下數據 拷貝到新空間下
		if (this->m_EmpArray != NULL) {
			for (int i = 0; i < this->m_EmpNum; i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		
		//批量添加新數據
		for (int i = 0; i < addNum; i++) {
			int id;
			string name;
			int dSelect;

			cout << "請輸入第 " << i + 1 << " 個新員工編號: " << endl;
			cin >> id;

			cout << "請輸入第 " << i + 1 << " 個新員工姓名: " << endl;
			cin >> name;

			cout << "請選擇該職工崗位: " << endl;
			cout << "1. 普通職員" << endl;
			cout << "2. 經理" << endl;
			cout << "3. 老闆" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			//將創建職工指針 保存到數組中
			newSpace[this->m_EmpNum + i] = worker;
		}

		//釋放原有空間
		delete[] this->m_EmpArray;

		//更改新空間的指向
		this->m_EmpArray = newSpace;

		//更新新的職工人數
		this->m_EmpNum = newSize;

		//更新職工不為空標誌
		this->m_FileIsEmpty = false;

		//成功添加後保存到文件中
		this->save();

		//提示添加成功
		cout << "成功添加" << addNum << "名新職工" << endl;
	}
	else {
		cout << "輸入數據有誤" << endl;
	}

	//案任意鍵後清屏回到上級目錄
	system("pause");
	system("cls");

}

//保存文件
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//用輸出的方式打開文件 --寫文件

	//將每個人數遽寫入到文件中
	for (int i = 0; i < this->m_EmpNum; i++) {
		ofs << this->m_EmpArray[i]->m_id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	//關閉文件
	ofs.close();
}

//統計文件中人數
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);//打開文件 讀

	int id;
	string name;
	int dId;
	
	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}

	return num;
}

//初始化員工
void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;

	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;

		if (dId == 1) { //普通職工
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) { //經理
			worker = new Manager(id, name, dId);
		}
		else if (dId == 3) { //老闆
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}

//顯示職工
void WorkerManager::Show_Emp() {
	//判斷文件是否為空
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或紀錄為空!" << endl;
	}
	else {
		for (int i = 0; i < this->m_EmpNum; i++) {
			//利用多態調用程序接口
			this->m_EmpArray[i]->showInfo();
		}
	}
	//案任意鍵後清屏回到上級目錄
	system("pause");
	system("cls");
}

//刪除職工
void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或紀錄為空!" << endl;
	}
	else {
		cout << "請輸入想要刪除職工編號: ";
		int id = 0;
		cin >> id;

		int index = this->IsExist(id);
		
		if (index != -1) {
			//數據前移
			for (int i = index; i < this->m_EmpNum - 1; i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;//更新數組人員個數
			//數據同步更新到文件中
			this->save();
		}
		else {
			cout << "刪除失敗 未找到該職工" << endl;
		}

	}
	//案任意鍵後清屏回到上級目錄
	system("pause");
	system("cls");
}

//判斷職工是否存在 如果存在返回職工所在數組的位置 不存在返回-1
int WorkerManager::IsExist(int id) {
	int index = -1;

	for (int i = 0; i < this->m_EmpNum; i++) {
		if (this->m_EmpArray[i]->m_id == id) {
			//找到職工
			index = i;
			break;
		}
	}

	return index;
}

//修改職工
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或紀錄為空!" << endl;
	}
	else {
		cout << "請輸入想要修改職工編號: ";
		int id = 0;
		cin >> id;

		int ret = this->IsExist(id);

		if (ret != -1) {
			
			delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到: " << id << "號職工, 請輸入新職工號: " << endl;
			cin >> newId;

			cout << "請輸入新姓名: " << endl;
			cin >> newName;

			cout << "請輸入崗位: " << endl;
			cout << "1. 普通職員" << endl;
			cout << "2. 經理" << endl;
			cout << "3. 老闆" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, 1);
			case 2:
				worker = new Manager(newId, newName, 2);
			case 3:
				worker = new Boss(newId, newName, 3);
			default:
				break;
			}

			//將創建職工指針 保存到數組中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功!" << endl;
			//數據同步更新到文件中
			this->save();
		}
		else {
			cout << "修改失敗 未找到該職工" << endl;
		}

	}
	//案任意鍵後清屏回到上級目錄
	system("pause");
	system("cls");
}

//查找職工
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或紀錄為空!" << endl;
	}
	else {
		cout << "請輸入查找的方式: " << endl;
		cout << "1. 按編號查: " << endl;
		cout << "2. 按姓名查: " << endl;

		int select = 0;
		cin >> select;

		if (select == 1) {
			cout << "請輸入想要查找職工編號: ";
			int id = 0;
			cin >> id;

			int ret = this->IsExist(id);

			if (ret != -1) {
				//找到職工
				cout << "查到該職工 信息如下" << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
				cout << "查找失敗 查無此人" << endl;
		}
		else if (select == 2) {
			cout << "請輸入想要查找職工姓名: ";
			string name ;
			cin >> name;

			bool flag = false;

			for (int i = 0; i < this->m_EmpNum; i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					//找到職工
					cout << "查到該職工 信息如下" << endl;
					this->m_EmpArray[i]->showInfo();

					flag = true;
				}
			}

			if (flag == false) {
				cout << "查找失敗 查無此人" << endl;
			}	
		}
		else {
			cout << "輸入選項有誤" << endl;
		}
	}
	//案任意鍵後清屏回到上級目錄
	system("pause");
	system("cls");
}

//按照編號排序
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "文件不存在或紀錄為空!" << endl;
		//案任意鍵後清屏回到上級目錄
		system("pause");
		system("cls");
	}
	else {
		cout << "請選擇排序的方式: " << endl;
		cout << "1. 按職工號進行升序: " << endl;
		cout << "2. 按職工號進行降序: " << endl;

		int select = 0;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++) {
			int MinOrMax = i;
			for (int j = i + 1; j < this->m_EmpNum; j++) {
				if (select == 1) { //升序
					if (this->m_EmpArray[MinOrMax]->m_id > this->m_EmpArray[j]->m_id) {
						MinOrMax = j;
					}
				}
				else { //降序
					if (this->m_EmpArray[MinOrMax]->m_id < this->m_EmpArray[j]->m_id) {
						MinOrMax = j;
					}
				}
			}
			//判斷一開始的最大最小是不是最後的最大最小
			if (i != MinOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
				this->m_EmpArray[MinOrMax] = temp;
			}
		}
		cout << "排序成功! 結果為: " << endl;
		this->save();
		this->Show_Emp();
	}

}

//清空文件
void WorkerManager::Clean_File() {
	cout << "確定清空? " << endl;
	cout << "1. 確定 " << endl;
	cout << "2. 返回 " << endl;

	int select = 0;
	cin >> select;

	if (select == 1) {
		//ios::trunc 如果存在刪除文件並重新創建
		ofstream ofs(FILENAME, ios::trunc);

		ofs.close();

		if (this->m_EmpArray != NULL) {
			for (int i = 0l; i < m_EmpNum; i++) {
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}

			//刪除堆區數組指針
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功! " << endl;
	}

	//案任意鍵後清屏回到上級目錄
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0l; i < m_EmpNum; i++) {
			delete this->m_EmpArray[i];
			this->m_EmpArray[i] = NULL;
		}

		//刪除堆區數組指針
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}