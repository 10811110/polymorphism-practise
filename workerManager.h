#pragma once //�����Y��󭫽ƥ]�t
#include <iostream> //�]�t��J��X�y�Y���
using namespace std; //�ϥμзǩR�W�Ŷ�
#include <fstream>
#define FILENAME "empfile.txt"

#include "worker.h"

class WorkerManager 
{
public:

	//�c�y���
	WorkerManager();

	//�i�ܵ��
	void Show_Menu();

	//�h�X�t��
	void ExitSystem();

	//����¾�u�H��
	int m_EmpNum;

	//¾�u�Ʋի��w
	Worker ** m_EmpArray;

	//�K�[¾�u
	void Add_Emp();

	//�O�s���
	void save();

	//�P�_���O�_����
	bool m_FileIsEmpty;

	//�έp��󤤤H��
	int get_EmpNum();

	//��l�ƭ��u
	void init_Emp();

	//���¾�u
	void Show_Emp();

	//�R��¾�u
	void Del_Emp();

	//�P�_¾�u�O�_�s�b �p�G�s�b��^¾�u�Ҧb�Ʋժ���m ���s�b��^-1
	int IsExist(int id);

	//�ק�¾�u
	void Mod_Emp();

	//�d��¾�u
	void Find_Emp();
	
	//���ӽs���Ƨ�
	void Sort_Emp();

	//�M�Ť��
	void Clean_File();

	//�R�c���
	~WorkerManager();
};