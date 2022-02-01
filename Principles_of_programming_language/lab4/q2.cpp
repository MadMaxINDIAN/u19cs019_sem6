#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int compute(int a, int b) {
    try {
        return a / b;
    } catch (bad_alloc &e) {
        cout << "Not enough memory" << endl;
    } catch (exception &e) {
        cout << "Exception: " << e.what() << endl;
    } catch (...) {
        cout << "Other Exceptions" << endl;
    }
}

int main () {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << "Result: " << compute(a, b) << endl;
    return 0;
}