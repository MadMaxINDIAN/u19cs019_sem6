// Create two classes DM and DB which store the value of distances. 
// DM stores distances in metres and centimeters and DB in feet and inches. 
// Write a program that can read values for the class objects and,
//  add one object of DM with another object of DB. 
// Use a function to carry out the addition operation. 
// The object that stores the results may be a DM object or DB object, 
// depending on the units in which the results are required. 
// The display should be in the format of feet and inches or metres and centimeters depending on the object on display.

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