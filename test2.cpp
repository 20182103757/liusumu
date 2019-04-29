// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include "iostream"
using namespace std;
class CMyLiuSuMu
{
private:
	int year;
	int month;
	int day;
	int check();
public:
	CMyLiuSuMu();
	CMyLiuSuMu(int y, int m, int d);
	int setLiuSuMu(int y, int m, int d);
	void displayLiuSuMu();
	void addOneDay();
	int getYear();
	int getMonth();
	int getDay();
};
CMyLiuSuMu::CMyLiuSuMu()
{
	year = 2019;
	month = 1;
	day = 1;
}
CMyLiuSuMu::CMyLiuSuMu(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "�����˴������ڣ���������1" << endl;
	}
}
int CMyLiuSuMu::setLiuSuMu(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
	if (check() == 1 || check() == -1)
	{
		month = 1;
		day = 1;
		cout << "�����˴������ڣ���������1" << endl;
		return -1;
	}
	return 0;
}
void CMyLiuSuMu::displayLiuSuMu()
{
	cout << year << "��" << month << "��" << day << "��" << endl;
}
int CMyLiuSuMu::check()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31
	
	};
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	if (month > 12 || month < 1)
		return -1;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day || day < 1)
			return 1;
	}
	else
	{
		if (flatYearDays[month - 1] < day || day < 1)
			return 1;
	}
	return 0;
}
int CMyLiuSuMu::getYear()
{
	return year;
}
int CMyLiuSuMu::getMonth()
{
	return month;
}
int CMyLiuSuMu::getDay()
{
	return day;
}
void CMyLiuSuMu::addOneDay()
{
	int flatYearDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int leapYearDays[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	day++;
	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
	{
		if (leapYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	else
	{
		if (flatYearDays[month - 1] < day)
		{
			day = 1;
			month++;
		}
	}
	if (month > 12)
	{
		month = 1;
		year++;
	}
}
int main()
{
	CMyLiuSuMu od;
	int i;
	int count = 1;
	od.setLiuSuMu(1999, 3, 21);
	od.displayLiuSuMu();
	while (!((od.getYear() == 2019) && (od.getMonth() == 4) && (od.getDay()) == 11))
	{
		od.addOneDay();
		count++;
	}
	cout << count << endl;
	return 0;
}