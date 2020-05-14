#include<iostream>
#include<string>
#include<vector>

#include"BankAccount.h"
#include"SavingsAccount.h"
#include"WalletAccount.h"

using namespace std;

int main() {

	string choice;
	int number;
	unsigned int i;

	vector<SavingsAccount*> accounts;
	SavingsAccount *accountPtr;

	vector<WalletAccount*> wAccounts;
	WalletAccount *wAccountPtr;


	cout << "Savings Accounts Open: " << accounts.size() << endl;
	cout << "Wallet Accounts Open: " << wAccounts.size() << endl;

	cout << "Total Accounts Open: " << accounts.size() + wAccounts.size() << endl << endl;

	while (choice != "No") {
		cout << "\nWould you like to open a 2% savings account?" << endl;
		cin >> choice;

		if (choice == "Yes" || choice == "yes") {
			cout << "\nPlease enter the balance of the account: " << endl;
			cin >> number;

			if (number > 0) {
				accountPtr = new SavingsAccount(number, .02, 1, false);
				accounts.push_back(accountPtr);

				cout << "\nA complementary Wallet Account is included with your Banking Account" << endl;
				cout << "Would you like to add any funds to the Wallet Account?" << endl;
				cout << "It can hold up to $100" << endl;
				cin >> choice;
			}

			else if (number <= 0) {
				cout << "The balance must be greater that $1" << endl;
				cout << "Would you like to open a Wallet Account instead?" << endl;
				cout << "It can hold up to $100" << endl;
				cin >> choice;
			}

			if (choice == "Yes" || choice == "yes") {

				cout << "How much will you be adding to the Wallet?" << endl;
				cin >> number;

				if (number > 0 && number <= 100) {
					wAccountPtr = new WalletAccount(number, .02, wAccounts.size());
					wAccounts.push_back(wAccountPtr);
				}
				else if (number > 100 || number <= 0)
					cout << "The amount entered is not allowed" << endl;
			}
			else if (choice == "No" || choice == "no") {
				wAccountPtr = new WalletAccount(0, .02, wAccounts.size());
				wAccounts.push_back(wAccountPtr);
			}
		}
		else
			choice = "No";
	}

	cout << "There are currently " << accounts.size() << " saving accounts currently open\n\n";

	cout << "There are currently " << wAccounts.size() << " wallet accounts open\n\n";

	cout << "\n\n";

	for (i = 0; i < (accounts.size() + wAccounts.size()); ++i) {
		if (i < accounts.size()) {
			int l = accounts.at(i)->getBalance();
			if (i < wAccounts.size()) {
				int k = wAccounts.at(i)->getBalance();
				cout << "--------------------------------" << endl;
				cout << "Aggregated Funds: " << (l + k) << endl;
			}
			else
				cout << "Aggregated Funds: " << (l) << endl;
		}
	}

	cout << "Contents:" << endl << endl;

	for (i = 0; i < accounts.size(); ++i) {
		cout << "Account ID: " << i + 1000 << endl;
		accounts.at(i)->printInfo();
	}

	for (i = 0; i < wAccounts.size(); ++i) {
		cout << "Account ID: " << i + 1000 << endl;
		wAccounts.at(i)->printInfo();
	}

	choice = "reset";

	while (choice != "No") {
		cout << "Do any accounts need to be deleted?" << endl;
		cin >> choice;

		if (choice == "Yes" || choice == "yes") {

				cout << "Please select the Account ID that needs to be deleted" << endl;
				cin >> number;

				i = number - 1000;

				if ((i) < accounts.size()) {
					accounts.erase(accounts.begin() + (i), accounts.begin() + (i) + 1);
				}
				if ((i) < wAccounts.size()) {
					wAccounts.erase(wAccounts.begin() + (i), wAccounts.begin() + (i) + 1);
				}

				else
					cout << "Entered number was not in the range of any index" << endl;
		}
		else
			choice = "No";
	}

	cout << "\n\n";

	for (i = 0; i < accounts.size(); ++i) {
		cout << "Account ID: " << i + 1000 << endl;
		accounts.at(i)->printInfo();
	}

	for (i = 0; i < wAccounts.size(); ++i) {
		cout << "Account ID: " << i + 1000 << endl;
		wAccounts.at(i)->printInfo();
	}

	cout << "\n\n";

	choice = "Reset";

	while (choice != "No") {

		cout << "Are any further deposits required?" << endl;
		cin >> choice;

		if (choice == "Yes" || choice == "yes") {
			cout << "Are you adding to a Savings or Wallet Account?" << endl;
			cout << "Type: 'Savings' or 'Wallet'" << endl;
			cin >> choice;

			if (choice == "Savings") {
				cout << "What ID do you need to deposit in?" << endl;
				cin >> i;

				cout << "How much are you depositing: " << endl;
				cin >> number;

				accounts.at(i-1000)->deposit(number);

				cout << "Updated Information for the account is: " << endl;

				accounts.at(i-1000)->printInfo();
			}

			else if (choice == "Wallet") {
				cout << "What ID do you need to deposit in?" << endl;
				cin >> i;

				cout << "How much are you depositing: " << endl;
				cin >> number;

				if ((wAccounts.at(i-1000)->getBalance() + number) <= 100)
					wAccounts.at(i-1000)->deposit(number);

				else if ((wAccounts.at(i-1000)->getBalance() + number) > 100)
					cout << "The wallet account can not exceed $100, please try again." << endl;

				cout << "Updated Information for the account is: " << endl;

				wAccounts.at(i-1000)->printInfo();
			}

			else
				cout << "Please check your input, and try again" << endl;
		}
		else
			choice = "No";
	}

	for (i = 0; i < accounts.size(); ++i) {
		cout << "Account ID: " << i + 1000 << endl;
		accounts.at(i)->printInfo();
	}

	for (i = 0; i < wAccounts.size(); ++i) {
		cout << "Account ID: " << i + 1000 << endl;
		wAccounts.at(i)->printInfo();
	}

	for (i = 0; i < accounts.size(); ++i) {
		double largest = accounts.at(i)->getBalance();
		if (largest < accounts.at(i)->getBalance()) {
			largest = accounts.at(i)->getBalance();
		}
		if (i = accounts.size()) {
			cout << "The ID of the largest Account is: " << endl;
			cout << "The largest account holds: $" << largest << endl;
		}
	}

	cout << "Please enter the account number you are looking for: " << endl;
	cin >> number;

	if ((number-1000) >= accounts.size()) {
		cout << "There is no Savings Account associated with this ID" << endl;
	}
	else if ((number-1000) <= accounts.size())
		accounts.at(number-1000)->printInfo();

	if ((number-1000) >= wAccounts.size()) {
		cout << "There is no Wallet Account for this ID" << endl;
	}
	else if ((number-1000) <= wAccounts.size())
		wAccounts.at(number-1000)->printInfo();

	cout << "Savings Accounts Open: " << accounts.size() << endl;
	cout << "Wallet Accounts Open: " << wAccounts.size() << endl;

	cout << "\nTotal Accounts Open: " << accounts.size() + wAccounts.size() << endl;
	
	char exit;
	cin >> exit;
}