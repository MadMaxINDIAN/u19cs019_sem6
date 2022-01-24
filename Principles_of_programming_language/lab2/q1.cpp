#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// CLASS DM
class DM {
// class variables
    private:
        float meters;
        float centimeters;

    public:
        // constructor
        DM(float f, float i) {
            meters = f;
            centimeters = i;
        }
        // getters
        float getMeters() {
            return meters;
        }
        float getCentimeters() {
            return centimeters;
        }
        // setters
        void setMeters(float f) {
            meters = f;
        }
        void setCentimeters(float i) {
            centimeters = i;
        }
        // other functions
        void display() {
            cout << meters << " Meters " << centimeters << " Centimeters" << endl;
        }

        // add function for diff classes
        void add(DM dm) {
            float f = dm.getMeters();
            float i = dm.getCentimeters();
            float m = meters + f;
            float c = centimeters + i;
            if (c >= 100) {
                m++;
                c -= 100;
            }
            meters = m;
            centimeters = c;
            display();
        }
};

// CLASS DB
class DB {
// class variables
    private:
        float feet;
        float inches;

    public:
        // constructor
        DB(float f, float i) {
            feet = f;
            inches = i;
        }
        // getters
        float getFeet() {
            return feet;
        }
        float getInches() {
            return inches;
        }
        // setters
        void setFeet(float f) {
            feet = f;
        }
        void setInches(float i) {
            inches = i;
        }
        // other functions
        void display() {
            cout << feet << " feet " << inches << " inches" << endl;
        }

        void add(DB db) {
            float f = db.getFeet();
            float i = db.getInches();
            float m = feet + f;
            float c = inches + i;
            if (c >= 12) {
                m++;
                c -= 12;
            }
            feet = m;
            inches = c;
            display();
        }
};

// add function for diff classes
void add(DM dm, DB db) {
    float f = dm.getMeters();
    float i = dm.getCentimeters();
    float m = f + db.getFeet()*0.3048;
    float c = i + db.getInches()*2.54;
    if (c >= 12) {
        m++;
        c -= 12;
    }
    cout << m << " Meters " << c << " Centimeters" << endl;
}

int main() {
    // DM object
    DM dm1(1, 1);
    DM dm2(4, 5);
    DB db1(2, 2);

    // add dm1 and dm2
    dm1.add(dm2);
    // add dm1 and db1
    add(dm1, db1);
    db1.display();
    return 0;
}

// Admission no: U19CS019
// Author: Naman Khater