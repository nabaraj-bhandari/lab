// Write a program for transaction processing that write and read object
// randomly to and from a random access file so that user can add, update,
// delete and display the account information (account-number, last-name, first-name, total-balance).
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;

struct Account
{
    int accNo;
    char first[20];
    char last[20];
    double balance;
};

class Bank
{
    fstream file;
    const char *fname = "accounts.dat";
    static const int MAX_ACCOUNTS = 100;

public:
    Bank()
    {
        // Open file in read-write mode; if doesn't exist, create with blank records
        file.open(fname, ios::in | ios::out | ios::binary);
        if (!file)
        {
            // Create file with blank accounts
            ofstream fout(fname, ios::binary);
            Account blank = {0, "", "", 0.0};
            for (int i = 0; i < MAX_ACCOUNTS; i++)
                fout.write(reinterpret_cast<char *>(&blank), sizeof(Account));
            fout.close();
            // Reopen for read-write
            file.open(fname, ios::in | ios::out | ios::binary);
        }
    }

    ~Bank()
    {
        file.close();
    }

    void add()
    {
        Account acc;
        cout << "Enter Account Number (1-" << MAX_ACCOUNTS << "): ";
        cin >> acc.accNo;

        if (acc.accNo < 1 || acc.accNo > MAX_ACCOUNTS)
        {
            cout << "Invalid account number.\n";
            return;
        }

        file.seekg((acc.accNo - 1) * sizeof(Account));
        Account existing;
        file.read(reinterpret_cast<char *>(&existing), sizeof(Account));

        if (existing.accNo != 0)
        {
            cout << "Account already exists!\n";
            return;
        }

        cout << "Enter First Name: ";
        cin >> acc.first;
        cout << "Enter Last Name: ";
        cin >> acc.last;
        cout << "Enter Balance: ";
        cin >> acc.balance;

        file.seekp((acc.accNo - 1) * sizeof(Account));
        file.write(reinterpret_cast<char *>(&acc), sizeof(Account));
        cout << "Account added successfully.\n";
    }

    void update()
    {
        int accNo;
        cout << "Enter Account Number to update: ";
        cin >> accNo;

        if (accNo < 1 || accNo > MAX_ACCOUNTS)
        {
            cout << "Invalid account number.\n";
            return;
        }

        file.seekg((accNo - 1) * sizeof(Account));
        Account acc;
        file.read(reinterpret_cast<char *>(&acc), sizeof(Account));

        if (acc.accNo == 0)
        {
            cout << "Account not found.\n";
            return;
        }

        cout << "Current details:\n";
        displayAccount(acc);

        cout << "Enter new First Name: ";
        cin >> acc.first;
        cout << "Enter new Last Name: ";
        cin >> acc.last;
        cout << "Enter new Balance: ";
        cin >> acc.balance;

        file.seekp((accNo - 1) * sizeof(Account));
        file.write(reinterpret_cast<char *>(&acc), sizeof(Account));
        cout << "Account updated successfully.\n";
    }

    void remove()
    {
        int accNo;
        cout << "Enter Account Number to delete: ";
        cin >> accNo;

        if (accNo < 1 || accNo > MAX_ACCOUNTS)
        {
            cout << "Invalid account number.\n";
            return;
        }

        file.seekg((accNo - 1) * sizeof(Account));
        Account acc;
        file.read(reinterpret_cast<char *>(&acc), sizeof(Account));

        if (acc.accNo == 0)
        {
            cout << "Account not found.\n";
            return;
        }

        Account blank = {0, "", "", 0.0};
        file.seekp((accNo - 1) * sizeof(Account));
        file.write(reinterpret_cast<char *>(&blank), sizeof(Account));
        cout << "Account deleted successfully.\n";
    }

    void display()
    {
        file.clear();
        file.seekg(0);
        cout << left << setw(10) << "AccNo"
             << setw(15) << "First Name"
             << setw(15) << "Last Name"
             << setw(12) << "Balance" << "\n";
        cout << "--------------------------------------------------\n";

        Account acc;
        for (int i = 0; i < MAX_ACCOUNTS; i++)
        {
            file.seekg(i * sizeof(Account));
            file.read(reinterpret_cast<char *>(&acc), sizeof(Account));
            if (acc.accNo != 0)
            {
                displayAccount(acc);
            }
        }
    }

private:
    void displayAccount(const Account &acc)
    {
        cout << left << setw(10) << acc.accNo
             << setw(15) << acc.first
             << setw(15) << acc.last
             << fixed << setprecision(2) << setw(12) << acc.balance << "\n";
    }
};

int main()
{
    Bank bank;
    int choice;

    do
    {
        cout << "\nTransaction Menu\n";
        cout << "1. Add Account\n";
        cout << "2. Update Account\n";
        cout << "3. Delete Account\n";
        cout << "4. Display Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.add();
            break;
        case 2:
            bank.update();
            break;
        case 3:
            bank.remove();
            break;
        case 4:
            bank.display();
            break;
        case 5:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
