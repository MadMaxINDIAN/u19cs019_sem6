#include <bits/stdc++.h>
using namespace std;
class Staff
{
public:
    int code;
    string name;
    void set_basic_info(int code, string name)
    {
        this->code = code;
        this->name = name;
    }
};
class Education : public Staff
{
public:
    string qualification;
    void set_qualification(string qualification)
    {
        this->qualification = qualification;
    }
};
class Teacher : public Education
{
public:
    string subject;
    string publication;
    void set_details(string subject, string publication)
    {
        this->subject = subject;
        this->publication = publication;
    }
    void display()
    {
        cout << "\tCode: " << code << endl;
        cout << "\tName: " << name << endl;
        cout << "\tQualification: " << qualification << endl;
        cout << "\tSubject: " << subject << endl;
        cout << "\tPublication: " << publication << endl;
    }
};
class Officer : public Education
{
public:
    string grade;
    void set_details(string grade)
    {
        this->grade = grade;
    }
    void display()
    {
        cout << "\tCode: " << code << endl;
        cout << "\tName: " << name << endl;
        cout << "\tQualification: " << qualification << endl;
        cout << "\tGrade: " << grade << endl;
    }
};
class Typist : public Staff
{
public:
    float speed;
    void set_speed(float speed)
    {
        this->speed = speed;
    }
};
class Regular : public Typist
{
public:
    void display()
    {
        cout << "\tCode: " << code << endl;
        cout << "\tName: " << name << endl;
        cout << "\tSpeed: " << speed << endl;
    }
};
class Casual : public Typist
{
public:
    float daily_wage;
    void set_daily_wage(float wage)
    {
        this->daily_wage = wage;
    }
    void display()
    {
        cout << "\n\tName: " << this->name << ",\n\tCode: " << this->code << ",\n\tSpeed: " << this->speed << ",\n\tDaily wage: Rs. " << this->daily_wage << endl;
    }
};

int main()
{
    Teacher t;
    t.set_basic_info(1, "Naman");
    t.set_qualification("M.Tech");
    t.set_details("CSE", "IEEE");
    cout << "\nTeacher";
    t.display();
    Officer o;
    o.set_basic_info(2, "Karan");
    o.set_qualification("M.A");
    o.set_details("A");
    cout << "\nOfficer";
    o.display();
    Regular r;
    r.set_basic_info(3, "Rohan");
    r.set_speed(30);
    cout << "\nRegular Typist";
    r.display();
    Casual c;
    c.set_basic_info(4, "Rishabh");
    c.set_speed(40);
    c.set_daily_wage(200);
    cout << "\nCasual Typist";
    c.display();
    return 0;
}