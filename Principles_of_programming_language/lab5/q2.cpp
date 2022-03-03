#include <iostream>

using namespace std;

class A
{
public:
    virtual void print()
    {
        cout << "\nA\n";
    }
};

class B : public A
{
public:
    void print()
    {
        cout << "\nB\n";
    }
};

class C : public B
{
public:
    void print()
    {
        cout << "\nC\n";
    }
};

int main()
{
    A a, *test;
    B b;
    C c;
    a.print(); // statically bound to A
    test = &a;
    test->print();
    test = &b;
    test->print(); // dynamically bound to B
    test = &c;
    test->print(); // dynamically bound to C
    return 0;
}
