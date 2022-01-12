// Assume that a bank maintains two kinds of accounts for customers, 
// one called a savings account and the other as a current account. 
// The savings account provides simple interest and withdrawal facilities but no cheque book facility. 
// The current account provides a check book facility but no interest. 
// Current account holders should also maintain a minimum balance and if the balance falls below this level, 
// a service charge is imposed.
// 
// Create a class account that stores customer name, account number and type of account. From this derive the classes cur_acct and sav_acct to make them more specific to their requirements. Include necessary member functions in order to achieve the following tasks:
//      Accept deposits from a customer and update the balance.
//      Display the balance.
//      Compute and deposit interest.
//      Permit withdrawal and update the balance.
//      Check for the minimum balance, impose penalty, necessary and update the balance.
//      Do not use any constructors. Use member functions to initialize the class members.

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

enum account_type {
    CURRENT=1,
    SAVINGS
};

// Class Account
class Account {
    public:
        string name;
        long long int acc_no;
        account_type type;
        double balance;
        double min_bal;
        double penalty;
        double interest_rate;
        
        void deposit(double amount) {
            balance += amount;
            cout << "Deposited " << amount << " to " << name << "'s account.\n";
        }

        void withdraw(double amount) {
            if (balance - amount < min_bal) {
                balance -= amount + penalty;
                cout << "Withdrew " << amount << " from " << name << "'s account. " << penalty << " penalty imposed.\n";
            } else {
                balance -= amount;
                cout << "Withdrew " << amount << " from " << name << "'s account.\n";
            }
        }

        void display() {
            for (int i = 0; i < 25; i++) cout << "-";
            cout << "\nName: " << name << endl;
            cout << "Account Number: " << acc_no << endl;
            cout << "Account Type: " << type << endl;
            cout << "Balance: " << balance << endl;
            for (int i = 0; i < 25; i++) cout << "-";
            cout << "\n";
        }

        void penalty_calc() {
            if (balance < min_bal) {
                balance -= penalty;
                cout << "Penalty imposed.\n";
            } else {
                cout << "No penalty imposed.\n";
            }
        }

        void compute_interest() {
            cout << "Interest added: " << balance*interest_rate << endl;
            balance += balance * interest_rate;
            cout << "Current balance: " << balance << endl;
        }
};

// Class Current Account
class CurrentAccount : public Account {
    public:
        CurrentAccount(string name) {
            this->name = name;
            this->type = CURRENT;
            this->balance = 0;
            this->min_bal = 5000;
            this->penalty = 150;
            this->interest_rate = 0;
            long long int acc_no = 0;
            for (int i = 0; i < 12; i++) {
                acc_no *= 10;
                acc_no += rand() % 10;
            }
            this->acc_no = acc_no;
        }

        void compute_interest() {
            cout << "Interest is not applicable to current accounts.\n";
        }
};

// Class Savings Account
class SavingsAccount : public Account {
    public:
        SavingsAccount(string name) {
            this->name = name;
            this->type = SAVINGS;
            this->balance = 0;
            this->min_bal = 0;
            this->penalty = 0;
            this->interest_rate = 0.05;
            long long int acc_no = 0;
            for (int i = 0; i < 12; i++) {
                acc_no *= 10;
                acc_no += rand() % 10;
            }
            this->acc_no = acc_no;
        }

        void penalty_calc() {
            cout << "Penalty is not applicable to savings accounts.\n";
        }

};

// Help (print instructions)
void help() {
    cout << "Enter the following commands:\n";
    cout << "1. deposit\n";
    cout << "2. withdraw\n";
    cout << "3. display\n";
    cout << "4. compute_interest\n";
    cout << "5. penalty_calc\n";
    cout << "0. exit\n";
}

int main () {
    // HELP
    cout << "For help, type 'help'\n";
    string fname, lname;
    cout << "Enter full name: ";
    cin >> fname >> lname;
    cout << "Account type: (type 1 for current, 2 for savings): ";
    int type;
    cin >> type;
    CurrentAccount *cacc;
    SavingsAccount *sacc;
    if (type == 1) {
        cacc = new CurrentAccount(fname + " " + lname);
    } else {
        sacc = new SavingsAccount(fname + " " + lname);
    }
    int balanace;
    cout << "Enter initial balance: ";
    cin >> balanace;
    if (type == 1) {
        cacc->deposit(balanace);
        cacc->display();
    } else {
        sacc->deposit(balanace);
        sacc->display();
    }
    while (true) {
        string input;
        cout << "Enter command: ";
        cin >> input;
        if (input == "help") {
            help();
        } else if (input == "1") {
            double amount;
            cout << "Enter amount: ";
            cin >> amount;
            if (type == 1) {
                cacc->deposit(amount);
                cacc->display();
            } else {
                sacc->deposit(amount);
                sacc->display();
            }
        } else if (input == "2") {
            double amount;
            cout << "Enter amount: ";
            cin >> amount;
            if (type == 1) {
                cacc->withdraw(amount);
                cacc->display();
            } else {
                sacc->withdraw(amount);
                sacc->display();
            }
        } else if (input == "3") {
            if (type == 1) {
                cacc->display();
            } else {
                sacc->display();
            }
        } else if (input == "4") {
            if (type == 1) {
                cacc->compute_interest();
                cacc->display();
            } else {
                sacc->compute_interest();
                sacc->display();
            }
        } else if (input == "5") {
            if (type == 1) {
                cacc->penalty_calc();
                cacc->display();
            } else {
                sacc->penalty_calc();
                sacc->display();
            }
        } else if (input == "0") {
            break;
        } else {
            cout << "Invalid command.\n";
        }
    }
    return 0;
}