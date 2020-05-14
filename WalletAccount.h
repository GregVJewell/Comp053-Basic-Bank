#pragma once
#include<iostream>
#include<string>

#include "BankAccount.h"
#include "SavingsAccount.h"

using namespace std;

class WalletAccount : public BankAccount {
public:
	WalletAccount();
	~WalletAccount();
	WalletAccount(double bal, double rate, int ID);

	double getMaxWalletCapacity();
	void deposit(double addition);
	void setBalance(double bal);
	void printInfo();
private:
	double maxWalletCapacity = 100;
	int walInt;
	WalletAccount* walPtr = nullptr;
};

WalletAccount::WalletAccount() {
	balance = 0.00;
	interestRate = 0.00;
}
WalletAccount::~WalletAccount() {

}
WalletAccount::WalletAccount(double bal, double rate, int ID) : BankAccount(bal, rate, ID) {
	
}

double WalletAccount::getMaxWalletCapacity() {
	return maxWalletCapacity;
}
void WalletAccount::deposit(double addition) {
	if ((addition + balance) > getMaxWalletCapacity()) {
		cout << "Adding $" << addition << " would go over the max capacity!" << endl << endl;
	}
	else if ((addition + balance) <= getMaxWalletCapacity()) {
		balance = balance + addition;
	}
}
void WalletAccount::setBalance(double bal) {
	if (bal > getMaxWalletCapacity()) {
		cout << "Balance can not be larger than the maximum capacity of: $" << getMaxWalletCapacity() << endl;
	}
	else if (bal <= getMaxWalletCapacity()) {
		balance = bal;
	}
}
void WalletAccount::printInfo() {
	cout << "Wallet Account Information: " << endl;
	BankAccount::printInfo();
	cout << "The max amount is: " << getMaxWalletCapacity() << endl << endl;
}