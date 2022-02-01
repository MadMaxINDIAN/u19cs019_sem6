#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Polar {
    public:
        double radius;
        double angle;
        Polar(double r, double a) {
            radius = r;
            angle = a;
        }
        Polar operator+(Polar p) {
            double x1 = radius*cos(angle);
            double y1 = radius*sin(angle);
            double x2 = p.radius*cos(p.angle);
            double y2 = p.radius*sin(p.angle);
            double x = x1 + x2;
            double y = y1 + y2;
            double a = atan(y/x);
            double r = sqrt(x*x + y*y);
            return Polar(r, a);
        }
};

int main () {
    cout << "Enter radius and angle: (angle in degrees)" << endl;
    double r, a;
    cin >> r >> a;
    Polar p1(r, a*M_PI/180);
    cout << "\nEnter radius and angle: (angle in degrees)" << endl;
    cin >> r >> a;
    Polar p2(r, a*M_PI/180);
    Polar p3 = p1 + p2;
    cout << "\nRadius: " << p3.radius << endl;
    cout << "Angle: " << p3.angle << endl;
    return 0;
}