#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Hotel
{
public:
    int bedrooms;
    int bathrooms;
    int price;
    Hotel(int bedrooms, int bathrooms)
    {
        this->bedrooms = bedrooms;
        this->bathrooms = bathrooms;
        this->price = 50 * bedrooms + 100 * bathrooms;
    }
};

class HotelApartment : public Hotel
{
public:
    HotelApartment(int bedrooms, int bathrooms) : Hotel(bedrooms, bathrooms)
    {
        this->price += 100;
    }
};

class HotelRoom : public Hotel
{
public:
    HotelRoom(int bedrooms, int bathrooms) : Hotel(bedrooms, bathrooms)
    {
    }
};

int main()
{
    int bedrooms, bathrooms;
    cout << "Enter number of bedrooms: ";
    cin >> bedrooms;
    cout << "Enter number of bathrooms: ";
    cin >> bathrooms;
    HotelRoom room(bedrooms, bathrooms);
    HotelApartment apartment(bedrooms, bathrooms);
    cout << "Room price: " << room.price << endl;
    cout << "Apartment price: " << apartment.price << endl;
    return 0;
}