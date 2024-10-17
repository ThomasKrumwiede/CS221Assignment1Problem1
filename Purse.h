#pragma once
#include <iostream>
#include <set>
#include "coin.h"
using namespace std;

class purse {
public:
	//Method to add a multiset of coins to the purse 
	void add(const std::multiset<coin>& newCoins);


	//Method to get the total ammount of money in a purse 
	double totalMoney() const;

	//Method to complete a payment 
	void pay(double paymentAmmount);

	//Method to count pennies
	int countPennies() const;
	//Method to count nickles
	int countNickels() const;
	//Method to count nickles
	int countDimes() const;
	//Method to count nickles
	int countQuarters() const;

	//overload of < for comparison 
	bool operator<(const purse& other) const;

private:
	multiset<coin> coinMultiset;
};