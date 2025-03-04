#include <iostream>

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

    // Withdraw Function

    // Show Balance Function
};

// Validate Input Function

int main() {
    


    return 0;
}
