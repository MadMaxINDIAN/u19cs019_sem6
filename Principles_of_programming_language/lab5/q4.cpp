#include <iostream>

using namespace std;

template <class T1, class T2>

class AddElements{
    T1 a;
    T2 b;
public:
    AddElements(T1 a1, T2 b1)
    {
        a = a1;
        b = b1;
    };
    void add()
    {
        cout << a << " + " << b << " = " << a + b << endl;
    }
};

template <> // class template specialization

class AddElements<string, string> {
    string a, b;
public:
    AddElements(string a1, string b1)
    {
        a = a1;
        b = b1;
    }
    void concatenate()
    {
        cout << a << " + " << b << " = " << a + b << endl;
    }
};

int main(){
    int ch;
    while (1)
    {
        cout << "\n1. Add int.";
        cout << "\n2. Add float.";
        cout << "\n3. Add strings.";
        cout << "\n4. Exit.";
        cout << "\nEnter choice: ";
        cin >> ch;
        if (ch == 1)
        {
            int a, b;
            cout << "\nEnter int values: ";
            cin >> a >> b;
            AddElements<int, int> p(a, b);
            p.add();
        }
        else if (ch == 2)
        {
            float a, b;
            cout << "\nEnter float values: ";
            cin >> a >> b;
            AddElements<float, float> q(a, b);
            q.add();
        }
        else if (ch == 3)
        {
            string c, d;
            cout << "\nEnter string values: ";
            cin >> c >> d;
            AddElements<string, string> s(c, d);
            s.concatenate();
        }
        else
            exit(0);
    }
    return 0;
}