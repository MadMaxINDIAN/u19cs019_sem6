// Write a C program to test whether a given identifier is valid or not.
// A valid identifier must begin with a letter or an underscore and can
// contain only letters, digits, and underscores.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main () {
    string s;
    cin >> s;
    if (s[0] == '_' || isalpha(s[0])) {
        for (int i = 1; i < s.length(); i++) {
            if (!(isalpha(s[i]) || isdigit(s[i]) || s[i] == '_')) {
                cout << "Invalid identifier" << endl;
                return 0;
            }
        }
        cout << "Valid identifier" << endl;
    } else {
        cout << "Invalid identifier" << endl;
    }
    return 0;
}