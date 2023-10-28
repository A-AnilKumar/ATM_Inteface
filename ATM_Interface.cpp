#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Account {
private:
    string name;
    int accountNumber;
    double balance;

public:
    Account(string name, long accountNumber, double initialBalance)
        : name(name), accountNumber(accountNumber), balance(initialBalance) {}

    string getName() const {
        return name;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn $" << amount << " successfully." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
};

class ATM {
public:
    void displayMainMenu() const {
        cout << "========= ATM Main Menu ===========" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Exit" << endl;
        cout << "===================================" << endl;
        cout << "Enter your choice: ";
    }

    void displayAccountInfo(const Account& account) const {
        cout << "Account Holder: " << account.getName() << endl;
        cout << "Account Number: " << account.getAccountNumber() << endl;
        cout << fixed << setprecision(2);
        cout << "Current Balance: $" << account.getBalance() << endl;
    }

    void run(Account& account) {
        int choice;
        double amount;

        cout << "======= Welcome to the ATM ========" << endl;

        while (true) {
            displayMainMenu();
            cin >> choice;

            switch (choice) {
                case 1:
                    displayAccountInfo(account);
                    break;
                case 2:
                    cout << "Enter the deposit amount: $";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 3:
                    cout << "Enter the withdrawal amount: $";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 4:
                    cout << "Thank you for using the ATM ...!!" << endl;
                    return;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        }
    }
};

int main() {

    // replace YOUR NAME with your name and load intial account opening balance 
    // Accont Number let be default as 123456
    // Ex : John Doe , Account Number , 1000
    Account userAccount("YOUR NAME", 123456, 1000.0);
    ATM atm;
    atm.run(userAccount);

    return 0;
}
