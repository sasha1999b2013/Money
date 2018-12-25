#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <windows.h>
#include "HeaderMoney.h"
using namespace std;
/*������ ���� ����������� ����� ������������� Init(), ����� ����� ������ � ���������� Read(),
����� ������ ������ �� ����� Display(), �������������� � ������ toString(),
���������� ��������� ���������� �������� �������� ��� ������� ������.
��� ������������ ������ � ��������� ������ ���� �� ���� �������� ���������
�������� ������� �������.

����������� ����� Money � ����� ������: first � second. ���� first � �����
������������� �����, ������� ������; ������� ����� ��������� �������� 1, 2, 5, 10,
50, 100, 500. ���� second - ����� ������������� �����, ���������� ����� �������
�����������. ��������� ����������� �������� ��������� � ��������� �����, ��������,
��������� � �������� ���������.*/

//����� �� �������, � ��� ����� �����. ��������� ������, ������� �������� ��� ���� ������� � ���������� �����. ������ ����, ����� ����� �������� �� ���������� ���
unsigned int first;
unsigned int second;
void Money::Init()
{
	first = 0;
	second = 0;
}

void Money::Read()
{
	bool ok = true;
	do
	{

		cout << "������� ������� 1, 2, 5, 10, 50, 100, 500 : ";
		cin >> first;
		if ((first != 1) && (first != 2) && (first != 5) && (first != 10) && (first != 50) && (first != 100) && (first != 500))
		{
			cout << "������������ �������" << endl;
			ok = false;
		}
		else ok = true;
	} while (ok == false);
	cout << "������� ���������� ����� �������� " << first << " : ";
	cin >> second;
}
void Money::Display()
{
	cout << "���������� ����� �������� " << first << " : " << second << endl;
}
unsigned int Money::get_Nominal()
{
	cout << "������� " << first << endl;
	return first;
}
unsigned int Money::get_Count()
{
	cout << "���������� �����: " << second << endl;
	return second;
}
void Money::Change()
{
	bool ok = true;
	cout << "������� ������� : " << first << endl;
	do
	{

		cout << "������� ����� ������� (1, 2, 5, 10, 50, 100, 500) : ";
		cin >> first;
		if ((first != 1) && (first != 2) && (first != 5) && (first != 10) && (first != 50) && (first != 100) && (first != 500))
		{
			cout << "������������ �������" << endl;
			ok = false;
		}
		else ok = true;
	} while (ok == false);
	cout << "������� ���������� ����� : " << second << endl;
	cout << "������� ����� ���������� ����� : ";
	cin >> second;
}
string Money::toString()
{
	string s;
	s = "���������� ����� �������� " + to_string(first) + " : " + to_string(second);
	return s;
}


unsigned int Money::operator+(const Money &B) const
{

	return first * second + B.first*B.second;
}
int Money::operator-(const Money &B) const
{
	int C = 0, D = 0;
	bool ok = true;
	C = C + first * second;
	D = D + B.second * B.first;
	if (D > C)
		ok = false;
	if (ok)
	{
		C = C - D;
	}
	else
	{
		cout << "����������� ������ �����������! �������� ��������." << endl;
		C = 0;
	}
	return C;
}
bool Money::operator==(const Money &B) const
{
	cout << endl;
	return first * second == B.first*B.second;
}
bool Money::operator>(const Money &B) const
{
	cout << endl;
	return first * second > B.first*B.second;
}

bool Money::operator<(const Money &B) const
{
	cout << endl;
	return first * second < B.first*B.second;
}