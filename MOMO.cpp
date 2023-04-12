#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Account {
    private:
        string accountName;
        int pin;
        float balance;
        int wrongPinCount;

    public:
        // Default constructor
        Account(string name, int pin, float balance) {
            accountName = name;
            this->pin = pin;
            this->balance = balance;
            wrongPinCount = 0;
        }

        // Authenticate user
        bool authenticate(int enteredPin) {
            if (enteredPin == pin) {
                wrongPinCount = 0;
                return true;
            } else {
                wrongPinCount++;
                if (wrongPinCount >= 3) {
                    cout << "Maximum number of incorrect PIN attempts reached. Exiting program." << endl;
                    exit(EXIT_FAILURE);
                } else {
                    cout << "Incorrect PIN. Please try again." << endl;
                    return false;
                }
            }
        }

        // Reset PIN
        void resetPin(int newPin) {
            pin = newPin;
            cout << "PIN reset successful." << endl;
        }

        // Check balance
        void checkBalance() {
            cout << "Your current balance is " << balance << " dollars." << endl;
        }

        // Send money
        bool sendMoney(float amount, string recipient) {
            if (amount > balance) {
                cout << "Insufficient balance. Transaction cancelled." << endl;
                return false;
            } else {
                balance -= amount;
                cout << amount << " cedis sent to " << recipient << ". Your new balance is " << balance << " dollars." << endl;
                return true;
            }
        }
};

int main() {
    // Initialize account
    Account account("John Doe", 0000, 1000);

    // Main loop
    while (true) {
        // Prompt user for action
        int choice;
        cout << "What would you like to do?" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset PIN" << endl;
        cout << "3. Check balance" << endl;
        cout << "4. Send money" << endl;
        cout << "5. Exit" << endl;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Authenticate user
                int enteredPin;
                cout << "Enter your PIN: ";
                cin >> enteredPin;
                bool authenticated = account.authenticate(enteredPin);
                if (authenticated) {
                    cout << "Authentication successful." << endl;
                }
                break;
            }

            case 2: {
                // Reset PIN
                int newPin;
                cout << "Enter your new PIN: ";
                cin >> newPin;
                account.resetPin(newPin);
                break;
            }

            case 3: {
                // Check balance
                account.checkBalance();
                break;
            }

            case 4: {
                // Send money
                string recipient;
                float amount;
                cout << "Enter recipient name: ";
                cin >> recipient;
                cout << "Enter amount to send: ";
                cin >> amount;
                bool sent = account.sendMoney(amount, recipient);
                if (!sent) {
                    cout << "Transaction failed." << endl;
                }
                break;
            }

            case 5: {
                // Exit program
                cout << "Exiting program." << endl;
                exit(EXIT_SUCCESS);
                break;
            }
        }
    }
}