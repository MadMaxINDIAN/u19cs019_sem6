#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void update(int *a, int *b)
{
    *a = *a + *b;
    *b = abs(*a - *b);
}

int main () {
    int a = 10, b = 20;
    update(&a, &b);
    cout << "a = " << a << " b = " << b << endl;
    return 0;
}