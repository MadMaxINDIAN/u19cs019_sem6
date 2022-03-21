#include <iostream>
using namespace std;
class Top
{
private:
    int x;

public:
    Top(int x = 0) { this->x = x; }
    void change(Top *t) { this = t; }
    void print() { cout << "x = " << x << endl; }
};
int main()
{
    Top obj(5);
    Top *ptr = new Top(10);
    obj.change(ptr);
    obj.print();
    return 0;
}