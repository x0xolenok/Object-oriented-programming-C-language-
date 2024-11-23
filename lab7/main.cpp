#include <iostream>
#include <string>
#include <vector>

// Class to represent a bank account
class BankAccount {
private:
    int m_ID;                // Account ID
    std::string m_FullName;  // Account holder's full name
    float m_Balance;         // Current balance

    static int ID;           // Static variable for unique account ID
    static float PercentageRate;   // Static interest rate
    static float SummaryMoney;     // Total money in all accounts

public:
    // Constructors
    BankAccount(const std::string& otherFullName);
    BankAccount(const std::string& otherFullName, const float& otherMoney);

    // Getter methods
    int getID() const;
    std::string getFullName() const;

    // Account management methods
    void replenishTheBalance(const float& otherMoney);
    float withdrawMoney(const float& otherMoney);
    float checkBalance() const;
    void addPercentage();   // Calculate interest on the balance

    // Output account information
    void outputInfo() const;

    // Static methods for managing interest rate and total balance
    static void setPercentageRate(const float& otherPercentageRate);
    static float getPercentageRate();
    static float getSummaryMoney();
};

// Initialization of static variables
int BankAccount::ID = 1;
float BankAccount::PercentageRate = 0;
float BankAccount::SummaryMoney = 0;

// Constructor that creates an account with a name
BankAccount::BankAccount(const std::string& otherFullName) {
    this->m_ID = BankAccount::ID++; // Assign unique ID and increment static ID
    this->m_FullName = otherFullName;
    this->m_Balance = 0;  // Initial balance is 0
}

// Constructor that creates an account with a name and initial deposit
BankAccount::BankAccount(const std::string& otherFullName, const float& otherMoney) {
    this->m_ID = BankAccount::ID++; // Assign unique ID and increment static ID
    this->m_FullName = otherFullName;
    this->m_Balance = 0;  // Initial balance is 0
    if (otherMoney > 0) { // Check for valid deposit
        BankAccount::SummaryMoney += otherMoney; // Add deposit to total money
        this->m_Balance += otherMoney;
    }
}

// Getter for account ID
int BankAccount::getID() const {
    return this->m_ID;
}

// Getter for account holder's full name
std::string BankAccount::getFullName() const {
    return this->m_FullName;
}

// Method to replenish balance
void BankAccount::replenishTheBalance(const float& otherMoney) {
    if (otherMoney > 0) { // Check for valid amount
        this->m_Balance += otherMoney;
        BankAccount::SummaryMoney += otherMoney; // Update total money
    }
}

// Method to withdraw money from account
float BankAccount::withdrawMoney(const float& otherMoney) {
    float resultSum = 0;  // Temporary variable for amount to withdraw
    if (otherMoney > 0) { // Check for valid amount
        if (otherMoney >= this->m_Balance) {
            resultSum = this->m_Balance;
        } else {
            resultSum = otherMoney;
        }
        this->m_Balance -= resultSum; // Subtract from balance
        BankAccount::SummaryMoney -= resultSum; // Subtract from total money
    }
    return resultSum; // Return the withdrawn amount
}

// Method to check account balance
float BankAccount::checkBalance() const {
    return this->m_Balance;
}

// Method to add interest to the balance
void BankAccount::addPercentage() {
    float tempBalance = this->m_Balance; // Temporary variable to store current balance
    this->m_Balance += tempBalance * (BankAccount::PercentageRate / 100.0); // Add interest
    BankAccount::SummaryMoney += tempBalance * (BankAccount::PercentageRate / 100.0); // Add interest to total money
}

// Output account info
void BankAccount::outputInfo() const {
    std::cout << "ID:               " << this->m_ID << std::endl;
    std::cout << "Full name:        " << this->m_FullName << std::endl;
    std::cout << "Balance:          " << this->m_Balance << std::endl;
    std::cout << "Percentage rate:  " << BankAccount::PercentageRate << "%" << std::endl;
}

// Set interest rate
void BankAccount::setPercentageRate(const float& otherPercentageRate) {
    if (otherPercentageRate >= 0) { // Check for valid percentage
        BankAccount::PercentageRate = otherPercentageRate;
    }
}

// Get the current interest rate
float BankAccount::getPercentageRate() {
    return BankAccount::PercentageRate;
}

// Get total money in all accounts
float BankAccount::getSummaryMoney() {
    return BankAccount::SummaryMoney;
}

// Menu for managing a specific bank account
void account_menu(BankAccount& account) {
    system("cls");
    int choise;
    while (true) {
        std::cout << "     Account info" << std::endl;
        account.outputInfo(); // Output account info
        std::cout << std::endl;
        std::cout << "1 - replenish the balance" << std::endl;
        std::cout << "2 - withdraw money" << std::endl;
        std::cout << "3 - add percentage" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cout << "Your choise: ";
        std::cin >> choise;

        if (choise == 0) {
            system("cls");
            return; // Exit the menu
        } else if (choise == 1) { // Replenish balance
            system("cls");
            float value;
            std::cout << "Enter sum: ";
            std::cin >> value;

            system("cls");
            if (value > 0) {
                account.replenishTheBalance(value); // Call replenish method
                std::cout << "The balance was replenished." << std::endl;
            } else {
                std::cout << "Uncorrect value." << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (choise == 2) { // Withdraw money
            system("cls");
            float value;
            std::cout << "Enter sum: ";
            std::cin >> value;

            system("cls");
            if (value > 0) {
                account.withdrawMoney(value); // Call withdraw method
                std::cout << "The money was withdrawn." << std::endl;
            } else {
                std::cout << "Uncorrect value." << std::endl;
            }
            system("pause");
            system("cls");
        }
        else if (choise == 3) { // Add percentage
            system("cls");
            account.addPercentage(); // Call method to add interest
            std::cout << "The percentage was added." << std::endl;
            system("pause");
            system("cls");
        }
        else { // Invalid choice
            system("cls");
            std::cout << "Uncorrect choise." << std::endl;
        }
    }
}

// Menu for bank settings (managing overall bank info)
void bank_settings_menu() {
    system("cls");
    int choise;
    while (true) {
        std::cout << "1 - Check summary balance" << std::endl;
        std::cout << "2 - Check percentage rate" << std::endl;
        std::cout << "3 - Set percentage rate" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cout << "Your choise: ";
        std::cin >> choise;

        if (choise == 0) {
            system("cls");
            return; // Exit the menu
        } else if (choise == 1) { // Check summary balance
            system("cls");
            std::cout << "Summary balance: " << BankAccount::getSummaryMoney() << std::endl;
            system("pause");
            system("cls");
        }
        else if (choise == 2) { // Check interest rate
            system("cls");
            std::cout << "Percentage rate: " << BankAccount::getPercentageRate() << "%" << std::endl;
            system("pause");
            system("cls");
        }
        else if (choise == 3) { // Set interest rate
            system("cls");
            float value;
            std::cout << "Enter new percentage rate: ";
            std::cin >> value;
            if (value >= 0) { // Check for valid interest rate
                BankAccount::setPercentageRate(value);
            }
            system("cls");
            std::cout << "Percentage rate was setted." << std::endl;
            system("pause");
            system("cls");
        }
        else { // Invalid choice
            system("cls");
            std::cout << "Uncorrect choise." << std::endl;
        }
    }
}

// Function to add a new account to the vector of accounts
void add_new_account(std::vector<BankAccount>& accounts) {
    system("cls");
    std::string name;
    std::cout << "Enter full name: ";
    std::cin >> name;

    BankAccount newAccount(name);
    accounts.push_back(newAccount); // Add the new account to the vector
    system("cls");
    std::cout << "Account was added." << std::endl;
    system("pause");
    system("cls");
}

int main() {
    std::vector<BankAccount> accounts;
    int choise;
    while (true) {
        system("cls");
        std::cout << "1 - Add new account" << std::endl;
        std::cout << "2 - Account menu" << std::endl;
        std::cout << "3 - Bank settings" << std::endl;
        std::cout << "0 - exit" << std::endl;
        std::cout << "Your choise: ";
        std::cin >> choise;

        if (choise == 0) {
            system("cls");
            return 0;
        }
        else if (choise == 1) { // Add new account
            add_new_account(accounts);
        }
        else if (choise == 2) { // Choose account and go to account menu
            system("cls");
            int accountID;
            std::cout << "Enter account ID: ";
            std::cin >> accountID;

            bool found = false;
            for (auto& account : accounts) {
                if (account.getID() == accountID) {
                    account_menu(account);
                    found = true;
                    break;
                }
            }
            if (!found) {
                system("cls");
                std::cout << "Account with that ID doesn't exist!" << std::endl;
                system("pause");
                system("cls");
            }
        }
        else if (choise == 3) { // Go to bank settings menu
            bank_settings_menu();
        }
        else {
            system("cls");
            std::cout << "Incorrect choice, try again." << std::endl;
            system("pause");
        }
    }
}
