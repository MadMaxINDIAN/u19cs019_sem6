#include <bits/stdc++.h>
#include <limits>
#include <iostream>
using namespace std;
class Book
{
public:
    int id, stock;
    string author, title, publisher;
    double price;
    Book() {}
    Book(int id, string author, string title, string publisher, double price,
         int stock)
    {
        this->id = id;
        this->author = author;
        this->title = title;
        this->publisher = publisher;
        this->price = price;
        this->stock = stock;
    }
    void updatePrice(double price)
    {
        this->price = price;
        cout << "\nPrice updated successfully!" << endl;
    }
};
class Library
{
public:
    Book books[100];
    int idx;
    int successful, unsuccessful;
    Library()
    {
        idx = 0;
        successful = 0;
        unsuccessful = 0;
    }
    void addBook(int id, string author, string title, string publisher, double price, int stock)
    {
        if (idx == 99)
        {
            cout << "\nLibrary is full" << endl;
            return;
        }
        books[idx++] = Book(id, author, title, publisher, price, stock);
        cout << "\nBook added successfully!" << endl;
    }
    void showBooks()
    {
        cout << "\nBooks in library are: " << endl;
        for (int i = 0; i < idx; i++)
        {
            cout << "\nBook ID: " << books[i].id << endl;
            cout << "Author: " << books[i].author << endl;
            cout << "Title: " << books[i].title << endl;
            cout << "Publisher: " << books[i].publisher << endl;
            cout << "Price: " << books[i].price << endl;
            cout << "Stock: " << books[i].stock << endl;
        }
    }
    void issueBook(int id, int n)
    {
        for (int i = 0; i < idx; i++)
        {
            if (books[i].id == id)
            {
                if (books[i].stock < n)
                {
                    cout << "\nNot enough books in stock. Only " << books[i].stock << " left." << endl;
                    unsuccessful++;
                    return;
                }
                books[i].stock -= n;
                successful++;
                cout << "\nBook issued successfully!" << endl;
                return;
            }
        }
        unsuccessful++;
        cout << "\nBook not found" << endl;
    }
};
int main()
{
    Library library = Library();
    int choice;
    do
    {
        cout << "\n1- Add book" << endl;
        cout << "2- Issue book" << endl;
        cout << "3- Update price" << endl;
        cout << "4- Show statistics" << endl;
        cout << "5- Show books" << endl;
        cout << "0- Exit" << endl;
        cout << "-------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int id, stock;
            string author, title, publisher;
            double price;
            cout << "\nEnter book id: ";
            cin >> id;
            cout << "\nEnter author: ";
            fflush(stdin);
            getline(cin, author);
            getline(cin, author);
            cout << "\nEnter title: ";
            fflush(stdin);
            getline(cin, title);
            cout << "\nEnter publisher: ";
            fflush(stdin);
            getline(cin, publisher);
            cout << "\nEnter price: ";
            fflush(stdin);
            cin >> price;
            cout << "\nEnter stock: ";
            cin >> stock;
            library.addBook(id, author, title, publisher, price, stock);
            break;
        }
        case 2:
        {
            int n, id;
            cout << "\nEnter book id: ";
            cin >> id;
            cout << "\nEnter number of books: ";
            cin >> n;
            library.issueBook(id, n);
            break;
        }
        case 3:
        {
            double price;
            int id;
            cout << "\nEnter book id: ";
            cin >> id;
            cout << "Enter new price: ";
            cin >> price;
            bool found = false;
            for (int i = 0; i < library.idx; i++)
            {
                if (library.books[i].id == id)
                {
                    library.books[i].updatePrice(price);
                    library.successful++;
                    found = true;
                    break;
                }
            }
            if (!found)
            {
                library.unsuccessful++;
                cout << "\nBook not found" << endl;
            }
            break;
        }
        case 4:
        {
            cout << "\nSuccessful transactions: " << library.successful << endl;
            cout << "Unsuccessful transactions: " << library.unsuccessful << endl;
            break;
        }
        case 5:
        {
            library.showBooks();
            break;
        }
        case 0:
        {
            cout << "\nThank you!" << endl;
            break;
        }
        default:
            cout << "\nInvalid choice" << endl;
            break;
        }
    } while (choice != 0);
    return 0;
}