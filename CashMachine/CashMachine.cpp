#include "CashMachine.h"
#include <iostream>
#include <string>
using namespace std;

CashMachine::CashMachine(string str, int m, int min_m, int max_m) : res(str), sum(m), min(min_m), max(max_m), id(0) {}

void CashMachine::Print() const
{
    cout << "CashMachine"<<endl;
    cout << "ID: " << id << endl;
    cout << "Money in CashMachine: " << sum << endl;
    cout << "Minimum banknote: " << min << endl;
    cout << "Maximum banknote: " << max << endl;
    cout << endl << endl;
}

string CashMachine::Str(int r) const
{
    return to_string(r);
}

void CashMachine::GetMoney(int mon) 
{
    bool validNominal = false;
    for (int i = 0; i < 6; i++) 
    {
        if (mon == nominals[i])
        {
            validNominal = true;
            break;
        }
    }

    if (validNominal) 
    {
        if (sum + mon <= max)
        {
            sum += mon;
            cout << "Added " << mon << " UAH!" << endl;
            cout << "Balance: " << sum << " UAH!" << endl;
        }
        else 
        {
            cout << "Max amount of money in CashMachine!"<<endl;
        }
    }
    else 
    {
        cout << "We do not have such banknote!"<<endl;
    }
}
int CashMachine::GiveMoney(int amount)
{
    if (amount >= min && amount <= max && amount <= sum)
    {
        bool validNominal = false;
        for (int i = 0; i < 6; i++) 
        {
            if (amount == nominals[i]) 
            {
                validNominal = true;
                break;
            }
        }
        if (validNominal) 
        {
            if (amount % 100 == 0)
            {
                sum -= amount;
                cout << "Withdrawing.... " << amount << " UAH!" << endl;
                cout << "Balance: " << sum << " UAH!" << endl;
                return amount;
            }
            else 
            {
                cout << "Minimum withdraw 100!" << endl;
                return -1;
            }
        }
        else 
        {
            cout << "Invalid banknote! " << amount << " UAH from CashMachine!" << endl;
            return -1;
        }
    }
    else 
    {
        cout << "Unable to withdraw " << amount << " UAH from ATM!" << endl;
        return -1;
    }
}

void CashMachine::SetID(int id)
{
    this->id = id;
}