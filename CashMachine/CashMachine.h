#pragma once
#include <iostream>
#include <string>
using namespace std;

class CashMachine
{
	string res;
	int sum;
	int max;
	int min;
	int id;
	int nominals[4] = {100, 200, 500, 1000};
public:
	CashMachine() = default;
	CashMachine(string str, int m, int min_m, int max_m);
	string Str(int r) const;
	void GetMoney(int mon);
	void Print() const;
	void SetID(int newID);
	int GiveMoney(int amount);
};