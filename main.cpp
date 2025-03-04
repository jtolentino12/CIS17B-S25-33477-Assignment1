#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;
public:
    // Constructor
    BankAccount(string name, int accountNum, double initialBalance) : accountHolderName(name), accountNumber(accountNum), balance(initialBalance) {
        cout << "Account created successfully!" << endl;
    }

    // Deposit Function
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Deposit amount must be greater than zero." << endl;
        }
        balance += amount;
        cout << "Deposit successful! New Balance: $" << balance << endl;
    }
    // Withdraw Function
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid amount! Withdrawal amount must be greater than zero." << endl;
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
            return;
        }
        balance -= amount;
        cout << "Withdrawal successful! New Balance: $" << balance << endl;
    }
    // Display Balance Function
    double displayBalance() {
        return balance;
    }
};

// Validate Input Function
double getInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cout << "Invalid input! Please enter a numeric value.\n";
            cin.clear(); // Reset error state
            while (cin.get() != '\n'); // Manually clear the input buffer
        } else {
            return value;
        }
    }
}

int main() {
    
    // create bankaccount object
    BankAccount* account = nullptr;
    int choice;
    int accountNumber;
    string name;
    double amount;

    cout << "Welcome to Simple Bank System" << endl;
    // loop for prompt
    while(true) {
        cout << "1. Create Account" << endl
             << "2. Deposit Money" << endl
             << "3. Withdraw Money" << endl
             << "4. Check Balance" << endl
             << "5. Exit" << endl << endl
             << "Enter your choice: ";
        cin >> choice;
    
    if (cin.fail()) {
        cout << "Invalid input! Please enter a number between 1 and 5." << endl;
        cin.clear();
        while (cin.get() != '\n');
        continue;
    }

    switch (choice) {
        case 1: // create account
            if (account) {
                cout << "An account already exists" << endl;
            } else {
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, name);
                double initialDeposit = getInput("Enter initial deposit: ");
                account = new BankAccount(name, accountNumber, initialDeposit);
            }
            break;
        case 2: // deposit amount
            if (!account) {
                cout << "Please create an account first." << endl;
            } else {
                amount = getInput("Enter amount to deposit: ");
                account->deposit(amount);
            }
            break;
        case 3: // withdraw amount
            if (!account) {
                cout << "Please create an account first." << endl;
            } else {
                amount = getInput("Enter amount to withdraw: ");
                account->withdraw(amount);
            }
            break;
        case 4: // display balance
            if (!account) {
                cout << "Please create an account first." << endl;
            } else {
                cout << "Current balance: " << account->displayBalance() << endl << endl;
            }
            break;
        case 5: // exit program
            cout << "Thank you for using Simple Bank System!" << endl;
            return 0;
            break;
        default:
            cout << "Invalid choice! Please pick a number between 1 and 5." << endl;
            break;
    }

}

}
