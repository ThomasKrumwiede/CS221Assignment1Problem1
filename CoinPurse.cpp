//Thomas Krumwiede 
//CS 221
//Assignment 1 Problem 1

#include <iostream>
#include <set>
using namespace std;


//Struct to represent the coins 
struct coin{
	string coinType;
	double coinValue; 

	coin(string name, double value)
	{
		coinType = name;
		coinValue = value;
	}

	bool operator<(const coin& other) const {
		return coinValue < other.coinValue;
	}
};

//Class the represents a purse
class purse {
public:
	//Method to add a multiset of coins to the purse 
	void add(const std::multiset<coin>& newCoins) {
		coinMultiset.insert(newCoins.begin(), newCoins.end());
	}

	//Method to get the total ammount of money in a purse 
	double totalMoney() {
		double purseMoney = 0;

		multiset<coin>::iterator pos;
		for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
			purseMoney += pos->coinValue;
		}

		return purseMoney;
	}

	//Method to complete a payment 
	void pay(double paymentAmmount) {
		
		//Make sure the payment ammount in not more than the total
		if (paymentAmmount > totalMoney()) {
			cout << "Warning: Payment is greater than the money in the purse" << endl;
		}

		//Pay with quarters 
		while (paymentAmmount >= .25 && countQuarters() > 0) {
			multiset<coin>::iterator pos = coinMultiset.find(coin("Quarter", .25));
			if (pos != coinMultiset.end()) {
				coinMultiset.erase(pos);
				paymentAmmount -= .25;
				cout << "Quarter removed" << endl;
			}
		}
		
		//Pay with dimes 
		while (paymentAmmount >= .10 && countDimes() > 0) {
			multiset<coin>::iterator pos = coinMultiset.find(coin("Dimes", .10));
			if (pos != coinMultiset.end()) {
				coinMultiset.erase(pos);
				paymentAmmount -= .10;
				cout << "Dime removed" << endl;
			}
		}
		
		//Pay with nickles 
		while (paymentAmmount >= .05 && countNickels() > 0) {
			multiset<coin>::iterator pos = coinMultiset.find(coin("Nickel", .05));
			if (pos != coinMultiset.end()) {
				coinMultiset.erase(pos);
				paymentAmmount -= .05;
				cout << "Nickle removed" << endl;
			}
		}

		//Pay with pennies
		while (paymentAmmount > 0 && countPennies() > 0) {
			multiset<coin>::iterator pos = coinMultiset.find(coin("Penny", .01));
			if (pos != coinMultiset.end()) {
				coinMultiset.erase(pos);
				paymentAmmount -= .01;
				cout << "Penny removed" << endl;
			}
		}

		if (paymentAmmount == 0) cout << "You have payed with exact change" << endl;
		if (paymentAmmount != 0) cout << "No exact change" << endl;
	}

	//Method to count pennies
	int countPennies() {
		int pennyCount = 0;

		multiset<coin>::iterator pos;
		for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
			if (pos->coinType == "Penny") pennyCount += 1;
		}

		return pennyCount; 
	}

	//Method to count nickles
	int countNickels() {
		int nickelCount = 0;

		multiset<coin>::iterator pos;
		for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
			if (pos->coinType == "Nickel") 	nickelCount += 1;
		}

		return nickelCount;
	}

	//Method to count nickles
	int countDimes() {
		int dimeCount = 0;

		multiset<coin>::iterator pos;
		for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
			if (pos->coinType == "Dime") dimeCount += 1;
		}

		return dimeCount;
	}

	//Method to count nickles
	int countQuarters() {
		int quarterCount = 0;

		multiset<coin>::iterator pos;
		for (pos = coinMultiset.begin(); pos != coinMultiset.end(); pos++) {
			if (pos->coinType == "Quarter") quarterCount += 1;
		}

		return quarterCount;
	}
	
private:
	multiset<coin> coinMultiset;
};


int main() {
	//initalize values for coin 
	coin penny("Penny", .01);
	coin nickel("Nickel", .05);
	coin dime("Dime", .10);
	coin quarter("Quarter", .25); 

	//initalize the multiset to be added to purse 
	multiset<coin> coinList= { penny, nickel, dime, quarter, quarter, nickel, dime, penny, penny, penny };

	//initalize the purse 
	purse Purse1;
	Purse1.add(coinList); 

	//test the totalMoney memberfunction 
	cout << "The total ammount of change in the purse is: $" << Purse1.totalMoney() << endl;

	//test the countPennies method
	cout << "The total number of pennies in the purse is: " << Purse1.countPennies() << endl;

	//test the countNickles method
	cout << "The total number of nickels in the purse is: " << Purse1.countNickels() << endl;

	//test the countDimes method
	cout << "The total number of dimes in the purse is: " << Purse1.countDimes() << endl;

	//test the countQuarters method
	cout << "The total number of quarters in the purse is: " << Purse1.countQuarters() << endl;

	//Test the payment method
	double x = .57;
	Purse1.pay(x);
	cout << "Payment is $" << x <<" , the new total ammount in the purse is : " << Purse1.totalMoney() << endl;


	// test the totalMoney memberfunction
	cout << "The total ammount of change in the purse is: $" << Purse1.totalMoney() << endl;

	//test the countPennies method
	cout << "The total number of pennies in the purse is: " << Purse1.countPennies() << endl;

	//test the countNickles method
	cout << "The total number of nickels in the purse is: " << Purse1.countNickels() << endl;

	//test the countDimes method
	cout << "The total number of dimes in the purse is: " << Purse1.countDimes() << endl;

	//test the countQuarters method
	cout << "The total number of quarters in the purse is: " << Purse1.countQuarters() << endl;


	//Part 2:
	//initalize the the purses for the array 
	multiset<coin> coinList2 = { penny, nickel, dime, nickel, dime, penny, penny, penny };
	purse Purse2;
	Purse2.add(coinList2);

	multiset<coin> coinList3 = { penny, nickel, dime, quarter, nickel, dime, penny };
	purse Purse3;
	Purse3.add(coinList3);

	multiset<coin> coinList4 = { penny, dime, quarter, quarter,  dime};
	purse Purse4;
	Purse4.add(coinList4);

	multiset<coin> coinList5 = { penny, dime, quarter, quarter,  dime, quarter, quarter, nickel, penny };
	purse Purse5;
	Purse5.add(coinList5);

	multiset<coin> coinList6 = { penny, dime, dime, penny, penny, nickel};
	purse Purse6;
	Purse6.add(coinList6);

	//create the array the purses will be stored in 
	purse* purseArray[] = { &Purse1, &Purse2, &Purse3, &Purse4, &Purse5, &Purse6 };
	
	cout << '\n' << "Problem 1 Part B" << endl;

	for (int i = 0; i < 6; i++) {
		cout << "The total ammount of change in Purse" << i + 1 << " is : $" << purseArray[i]->totalMoney() << endl;
	}

	cout << "made it to the end with changes what about with more changes  " << endl;

	cout << "This is another attampt to make sure this works ";
}