#include <iostream>
#include <string>
#include "CashMachine.h"
using namespace std;

int main() {
    CashMachine machine("cAsH", 100000, 100, 1000);
    machine.SetID(7711);
    machine.Print();

    cout << machine.Str(machine.GiveMoney(200)) << endl;
    cout << endl;
    machine.GetMoney(500);
    cout << machine.Str(machine.GiveMoney(500)) << endl;
    machine.SetID(1377);
    machine.Print();
}