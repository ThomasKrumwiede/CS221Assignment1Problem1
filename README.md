1)	Implement a struct Coin and a class Purse containing as a data member an STL multiset of Coin instances. A coin has a name ("penny", "nickel", "dime", and "quarter") and a corresponding numeric value. 
a)	Implement the following Purse methods:
•	add(multiset<coin>)to add the coins from the argument to the purse,
•	totalMoney()to return the total value of the coins in the purse
•	pay(amount)to remove coins totaling the argument from the purse
•	countPennies(), countNickels(), countDimes() and countQuarters()to return the count of the corresponding coin in the purse.
b)	Use the built-in function qsort to sort an array of Purse pointers in two different ways (for example, by the total value of the quarters and by the total number of coins) .
c)	Overload the < operator and use the STL sort function to sort a collection of purses.
[20 Points]
