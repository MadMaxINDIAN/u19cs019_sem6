#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Vector
{
    public:
        int size;
        float *arr;
        Vector(int size)
        {
            this->size = size;
            arr = new float[size];
        }
        void set(int index, float value)
        {
            arr[index] = value;
        }
        void display()
        {
            cout << "(";
            for(int i = 0; i < size; i++)
            {
                cout << arr[i];
                if(i != size - 1)
                    cout << ", ";
            }
            cout << ")";
        }
        void multiply(float value)
        {
            for(int i = 0; i < size; i++)
                arr[i] *= value;
        }
};

int main () {
    int size;
    cout << "Enter the size of the vector: ";
    cin >> size;
    Vector v(size);
    cout << "Enter the elements of the vector: ";
    for(int i = 0; i < size; i++)
    {
        cin >> v.arr[i];
    }
    v.display();
    cout << endl;
    float value;
    cout << "Enter the value to multiply the vector by: ";
    cin >> value;
    v.multiply(value);
    v.display();
    cout << endl;
    return 0;
}