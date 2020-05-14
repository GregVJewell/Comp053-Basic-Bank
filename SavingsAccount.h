#pragma once
#include<iostream>
#include<string>

#include "BankAccount.h"

using namespace std;

class SavingsAccount : protected BankAccount {
public:
	SavingsAccount();
	~SavingsAccount();

	SavingsAccount(double bal, double rate, int ID, bool lock);
	void lockAccount();
	void removeLock();

	void setBalance(double bal);
	double getBalance();
	void setInterestRate(double rate);
	virtual void incurInterest();
	void deposit(double addition);
	void withdraw(double deduction);
	void printInfo();

private:
	bool lock = false;
	void accountLockMessage();
	int savInt;
	SavingsAccount* savePtr = nullptr;
};


SavingsAccount::SavingsAccount() : BankAccount() {
	
}
SavingsAccount::~SavingsAccount() {

}
SavingsAccount::SavingsAccount(double bal, double rate, int ID, bool locked) : BankAccount(bal, rate, ID) {
		lock = locked;
		++accountCount;
}

void SavingsAccount::lockAccount() {
	lock = true;
	cout << "\nAccount Locked" << endl << endl;
}
void SavingsAccount::removeLock() {
	lock = false;
	cout << "\nAccount Unlocked" << endl << endl;
}

void SavingsAccount::accountLockMessage() {
	if(lock == true) { cout << "---The account is locked---\n" << endl; }
	
	else if(lock == false) { cout << "---The account is unlocked---\n" << endl; }
}

void SavingsAccount::setBalance(double bal) {
	if (lock == true)
		accountLockMessage();
	else if(lock == false)
		balance = bal;
}
double SavingsAccount::getBalance() {
	return BankAccount::getBalance();
}
void SavingsAccount::setInterestRate(double rate) {
	if (lock == true)
		accountLockMessage();
	else if(lock == false)
		interestRate = rate;
}
void SavingsAccount::incurInterest() {
	if (lastInterestDate == "01/24/2019" || "02/24/2019" || "03/24/2019" || "04/24/2019") {
		if (lock == true)
			accountLockMessage();
		else if (lock == false) {
			balance = (interestRate * balance) + balance;
			cout << "Interest incurred!" << endl << endl;
		}
	}
	else
		cout << "Interest has already been incurred" << endl;
}

void SavingsAccount::deposit(double addition) {
	if(lock == true) 
		accountLockMessage();

	else if(lock == false) {
		balance = addition + balance;
		cout << "Balance after adding $" << addition << " is $" << balance << endl << endl;
	}

}

void SavingsAccount::withdraw(double deduction) {

	if (lock == true) { accountLockMessage(); }

	else if(lock == false) {
		if(deduction <= balance) {
			balance = balance - deduction;
			cout << "$" << deduction << " removed from account" << endl;
			cout << "Current balance is now: $" << balance << endl << endl;
		}

		else if(deduction > balance) {
			cout << "Insufficent funds! " << "Cannot remove $" << deduction << " from $" << balance << "!" << endl << endl;
		}
	}
}


void SavingsAccount::printInfo() {
	cout << "Savings Account Information: " << endl;
	BankAccount::printInfo();
	accountLockMessage();
}
