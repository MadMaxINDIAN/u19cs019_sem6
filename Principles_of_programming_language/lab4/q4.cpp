#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main () {
    string name, number;
    // read file
    ifstream fin("telephone.txt");
    cout << setw(20) << left << "Name" << setw(10) << right << "Number" << endl;
    if (fin.is_open()) {
        while (fin >> name >> number) {
            cout << setw(20) << left << name << setw(10) << right << number << endl;
        }
    }
    return 0;
}