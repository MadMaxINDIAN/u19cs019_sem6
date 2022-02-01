#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define MIN_LENGTH 5
#define MAX_LENGTH 15

void validate(string s) {
    if (s.length() < MIN_LENGTH || s.length() > MAX_LENGTH) {
        throw invalid_argument("Invalid string length");
    }
}

int main () {
    string username;
    cout << "Enter your username: ";
    cin >> username;
    try {
        validate(username);
    } catch (invalid_argument &e) {
        cout << "Invalid username: " << e.what() << endl;
    }
    cout << "Username: " << username << endl;
    cout << endl;
    return 0;
}