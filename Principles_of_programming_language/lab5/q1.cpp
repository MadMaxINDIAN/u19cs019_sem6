// Write a program in C++ that calls both a dynamically bound method and a statically 
// bound method a large number of times, timing the calls to both of the two. 
// Compare the timing results and compute the difference of the time required by the two. 
// Explain the results.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class A {
    public:
    double static_method(double x) {
        return x * x;
    }
    virtual double dynamic_method(double x) {
        return x * x;
    }
};

class B: public A {
    public:
    double dynamic_method(double x) {
        return x * x;
    }
};

const int N = 100000;

int main () {
    A *a = new B();
    time_t start, end;
    start = clock();
    for (int i = 0; i < N; i++) {
        a->static_method(i);
    }
    end = clock();
    cout << "Static method: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    start = clock();
    for (int i = 0; i < N; i++) {
        a->dynamic_method(i);
    }
    end = clock();
    cout << "Dynamic method: " << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}