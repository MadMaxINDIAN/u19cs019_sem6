#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    string title = "";
    string author = "";
    string publisher = "";
    int stock = 0;
    int price = 0;

    Book () {
        this->title = "";
        this->author = "";
        this->publisher = "";
        this->stock = 0;
        this->price = 0;
    }

    Book(string title, string author, string publisher, int stock, int price) {
        this->title = title;
        this->author = author;
        this->publisher = publisher;
        this->stock = stock;
        this->price = price;
    }

    string getName() {
        return title;
    }

    string getAuthor() {
        return author;
    }
    
    string getPublisher() {
        return publisher;
    }

    int getStock() {
        return stock;
    }
    
    int getPrice() {
        return price;
    }

    int setStock(int stock) {
        this->stock = stock;
        return stock;
    }

    int setPrice(int price) {
        this->price = price;
        return price;
    }

    void display() {
        cout << "\t===================" << endl;
        cout << "\tTitle: " << title << endl;
        cout << "\tAuthor: " << author << endl;
        cout << "\tPublisher: " << publisher << endl;
        cout << "\tStock: " << stock << endl;
        cout << "\tPrice: " << price << endl;
        cout << "\t===================" << endl;
    }
};

int main () {
    cout << "===================" << endl;
    cout << "U19CS019 Book Store" << endl;
    cout << "===================" << endl;

    // array of books
    Book books[100];
    int n = 0;
    int transactions = 0;
    int success_transactions = 0;
    
    while (true) {
        cout << "1. Add Book" << endl;
        cout << "2. Search Book" << endl;
        cout << "3. Update price of book" << endl;
        cout << "4. Stats" << endl;
        cout << "0. Quit." << endl;
 
        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Book Title: ";
            string book_title;
            cin >> book_title;
            
            string book_author;
            cout << "Enter Book Author: ";
            cin >> book_author;

            string book_publisher;
            cout << "Enter Book Publisher: ";
            cin >> book_publisher;

            int book_stock;
            cout << "Enter Book Stock: ";
            cin >> book_stock;

            int book_price;
            cout << "Enter Book Price: ";
            cin >> book_price;

            books[n] = Book(book_title, book_author, book_publisher, book_stock, book_price);
            n++;
        } else if (choice == 2) {
            cout << "Enter Book Title: ";
            string book_title;
            cin >> book_title;

            cout << "Enter Book Author: ";
            string book_author;
            cin >> book_author;

            int i = 0;
            while (i < n) {
                if (books[i].getName() == book_title && books[i].getAuthor() == book_author) {
                    books[i].display();
                    cout << "Do you want to buy this book? (y/n)" << endl;
                    char choice;
                    cin >> choice;
                    if (choice == 'y') {
                        int quantity;
                        cout << "Enter quantity: ";
                        cin >> quantity;
                        if (quantity > books[i].getStock()) {
                            transactions++;
                            cout << "Not enough stock" << endl;
                        } else {
                            books[i].setStock(books[i].getStock() - quantity);
                            transactions++;
                            success_transactions++;
                            cout << "Thank you for buying. Total cost of " << quantity << " books is " << books[i].getPrice()*quantity << endl;
                        }
                    } else {
                        cout << "Book not purchased!" << endl;
                    }
                    break;
                }
                i++;
                cout << endl;
            }
            if (i == n) {
                cout << "===================" << endl;
                cout << "Book not found\n";
                cout << "===================\n" << endl;
            }
        } else if (choice == 3) {
            cout << "Enter Book Title: ";
            string book_title;
            cin >> book_title;

            cout << "Enter Book Author: ";
            string book_author;
            cin >> book_author;

            int i = 0;
            while (i < n) {
                if (books[i].getName() == book_title && books[i].getAuthor() == book_author) {
                    books[i].display();
                    cout << "Enter new price: ";
                    int new_price;
                    cin >> new_price;
                    books[i].setPrice(new_price);
                    cout << "Price updated!" << endl;
                    books[i].display();
                    cout << endl;
                    break;
                }
                i++;
                cout << endl;
            }
            if (i == n) {
                cout << "===================" << endl;
                cout << "Book not found\n";
                cout << "===================\n" << endl;
            }
        } else if (choice == 0) {
            break;
        } else if (choice == 4) {
            cout << "===================" << endl;
            cout << "Stats" << endl;
            cout << "===================" << endl;
            cout << "Total transactions: " << transactions << endl;
            cout << "Successful transactions: " << success_transactions << endl;
            cout << "Unsuccessful transactions: " << transactions - success_transactions << endl;
            cout << "===================" << endl;
        } else {
            cout << "\nInvalid option selected\n\n";
        }
    }
    
    return 0;
}