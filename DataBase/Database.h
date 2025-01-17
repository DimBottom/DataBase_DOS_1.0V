#ifndef DATA_BASE_H
#define DATA_BASE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
#include <sstream>
using namespace std;

class Database
{
private:
	string baseName;//数据库名称
	vector <vector<vector<string > > > BASE;//数据库三维向量
	int size;//数据库当前有的表的数量
	vector<string > tablesName;//储存各表的名称，其索引与储存表的三维向量第一维的索引对应
	int mark;//当前打开的表，未打开则为-1
	string defaultPath;//默认路径，不存在则为空

public:
	Database();//构造一个数据库
	Database(string baseName);//构造一个数据库同时赋予名称
	string getName();//查看数据库名称
	void changeName(string newName);//修改数据库名称
	void loadDatabase(string loadPath);//加载数据库
	void loadTable(string loadPath);//加载表
	void saveDatabase();//保存数据库
	void saveDatabaseAs(string savePath);//数据库另存为
	void exportTable(string savePath, int mark);//导出表

	void createTable(string tableName, int rowSize, int columnSize);//创建一个表并赋予名称，并打开
	void openTable(string tableName);//打开一个表
	void closeTable();//关闭当前表
	void addRow();//增加记录
	void addColumn();//增加列
	void insertRow(int rowIndex);//插入记录
	void insertColumn(int columnIndex);//插入列
	void deleteTable(int mark);//删除表
	void deleteRow(int mark, int rowMark);//删除指定记录
	void deleteColumn(int mark, int columnMark);//删除指定列
	void changeData(string data, int mark, int rowNum, int columnNum);//修改指定表的指定数据
	string getTableName(int mark);//获取指定表的名称
	string getTableName();//获取当前表的名称
	int getMark(string tableName);//获取指定表的编号
	int getMark();//获取当前表的编号
	void printTable(int mark);//打印指定表
	void printRow(int marks, int rowIndex);
	void searchInBase(string data);//在数据库搜索数据
	void searchInTable(string data, vector<int> tableMarks);//在指定表中搜索

public:
	bool checkSameName(string tableName);//检验是否重名
	int getRowSize();//获取当前表的记录大小
	int getRowSize(int mark);//获取指定表的记录大小
	int getColumnSize();//获取当前表的字段大小
	int getColumnSize(int mark);//获取指定表的字段大小
	string getData(int mark, int rowIndex, int columnIndex);//获取指定表的数据
	vector<string > getTablesName();//获取获取当前表的名称
	string getDefaultPath();//获取默认保存路径
};

#endif