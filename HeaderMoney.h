#pragma once
#include <String>

class Money {
	unsigned int first;
	unsigned int second;
public:
	void Init();
	void Read();
	void Display();
	unsigned int get_Nominal();
	unsigned int get_Count();
	std::string toString();
	void Change();
	unsigned int operator+(const Money &B) const;
	int operator-(const Money &B) const;
	bool operator==(const Money &B) const;
	bool operator>(const Money &B) const;
	bool operator<(const Money &B) const;
};