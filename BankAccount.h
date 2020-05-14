#pragma once

#include<iostream>
#include<string>

using namespace std;

class BankAccount {
public:
	//Methods

	//Constructor & Deconstructor
	BankAccount();
	~BankAccount();
	BankAccount(double balance, double interestRate, int accountNumber);

	//Mutators 
	void setBalance(double balance);
	void deposit(double deposit);
	void withdraw(double withdrawl);
	void setInterestRate(double interesetRate);
	void addIntereset(double interest);
	void setLastInterestDate(string month, string day, string year);
	void assignID(int accountNumber);
	
	//Accessors
	double getBalance();
	double getInterestRate();
	string getLastInterestDate();
	int getAccountCount();
	int getAccountID();

	//Print Command
	void printInfo();

protected:
	//Members
	double balance = 0.00;
	double interestRate = .00;
	string lastInterestDate = "02 / 8 / 2019";
	static int accountNumber;
	static int accountCount; //Declare Static Member
};

BankAccount::BankAccount() {
	
}
BankAccount::~BankAccount() {
	balance = 0;
	interestRate = .0;

	--accountCount; //Decrement accountCount
}
BankAccount::BankAccount(double bal, double rate, int ID) {
	balance = bal;
	interestRate = rate;
	ID = getAccountID();
	accountNumber = ID;
}

int BankAccount::accountCount = 1;
int BankAccount::accountNumber = 1000;

void BankAccount::setBalance(double bal) {
	balance = bal;
}
double BankAccount::getBalance() {
	return balance;
}
void BankAccount::assignID(int ID) {
	accountNumber = ID;
}
int BankAccount::getAccountID() {
	return accountNumber;
}
void BankAccount::deposit(double addition) {
	balance = addition + balance;
	cout << "\nCurrent balance is: $" << balance << " after adding $" << addition << endl << endl;
}
void BankAccount::withdraw(double deduction) {
	if (deduction <= balance) {
		balance = balance - deduction;
		cout << "\n$" << deduction << " removed from account" << endl;
		cout << "Current balance is now: $" << balance << endl << endl;
	}

	else if (deduction > balance) {
		cout << "Insufficent funds! " << "Cannot remove $" << deduction << " from $" << balance << "!" << endl << endl;
	}
}
void BankAccount::setInterestRate(double rate) {
	interestRate = rate;
}
double BankAccount::getInterestRate() {
	return interestRate;

}
int BankAccount::getAccountCount() {
	return accountCount;
}
void BankAccount::addIntereset(double interest) {
	if (lastInterestDate == "02/24/2019" || "03/24/2019" || "04/24/2019")
		balance = (interest * balance) + balance;
	else
		cout << "Interest has already been incurred" << endl;
}
void BankAccount::setLastInterestDate(string month, string day, string year) {
	cout << "Please enter the date of last incurred interest: " << endl;
	cout << "Month (XX): " << endl;
	cin >> month;
	cout << "Day (XX): " << endl;
	cin >> day;
	cout << "Year (XXXX): " << endl;
	cin >> year;

	lastInterestDate = month + '/' + day + '/' + year;
}
string BankAccount::getLastInterestDate() {
	return lastInterestDate;
}

void BankAccount::printInfo() {
	cout << "---------Account Information---------" << endl;
	//cout << "The account ID is: " << getAccountCount() << endl;
	cout << "The current account balance is: $" << balance << endl;
	cout << "The interest rate is: " << (interestRate*100) << "%" << endl;
	cout << "The last incurred interest date was: " << getLastInterestDate() << endl;
}