#include "pch.h"
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <windows.h>
#include "HeaderMoney.h"
using namespace std;
/*Должны быть реализованы метод инициализации Init(), метод ввода данных с клавиатуры Read(),
метод вывода данных на экран Display(), преобразование в строку toString(),
необходимо выполнить перегрузку основных операций для методов класса.
Для демонстрации работы с объектами нового типа во всех заданиях требуется
написать главную функцию.

Реализовать класс Money с двумя полями: first и second. Поле first – целое
положительное число, номинал купюры; номинал может принимать значения 1, 2, 5, 10,
50, 100, 500. Поле second - целое положительное число, количество купюр данного
достоинства. Требуется реализовать операции получения и изменения полей, сложение,
вычитание и операции сравнения.*/

//нужны не массивы, а два числа целых. Создается объект, который содержит два поля номинал и количество купюр. Объект один, когда нужно сравнить их становится два
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

		cout << "Введите номинал 1, 2, 5, 10, 50, 100, 500 : ";
		cin >> first;
		if ((first != 1) && (first != 2) && (first != 5) && (first != 10) && (first != 50) && (first != 100) && (first != 500))
		{
			cout << "неправильный номинал" << endl;
			ok = false;
		}
		else ok = true;
	} while (ok == false);
	cout << "Введите количество купюр номинала " << first << " : ";
	cin >> second;
}
void Money::Display()
{
	cout << "Количество купюр номинала " << first << " : " << second << endl;
}
unsigned int Money::get_Nominal()
{
	cout << "Номинал " << first << endl;
	return first;
}
unsigned int Money::get_Count()
{
	cout << "Количество купюр: " << second << endl;
	return second;
}
void Money::Change()
{
	bool ok = true;
	cout << "текущий номинал : " << first << endl;
	do
	{

		cout << "Введите новый номинал (1, 2, 5, 10, 50, 100, 500) : ";
		cin >> first;
		if ((first != 1) && (first != 2) && (first != 5) && (first != 10) && (first != 50) && (first != 100) && (first != 500))
		{
			cout << "неправильный номинал" << endl;
			ok = false;
		}
		else ok = true;
	} while (ok == false);
	cout << "текущее количество купюр : " << second << endl;
	cout << "Введите новое количество купюр : ";
	cin >> second;
}
string Money::toString()
{
	string s;
	s = "Количество купюр номинала " + to_string(first) + " : " + to_string(second);
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
		cout << "уменьшаемое меньше вычитаемого! Значение обнулено." << endl;
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