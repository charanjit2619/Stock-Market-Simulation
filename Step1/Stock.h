#ifndef STOCK_H
#define STOCK_H
#include <string>
#include <iostream>

/*
 * The class Stock encapsulates a stock lot, including stock name, 
 * ticker symbol, price per share and number of shares purchased.
 * We assume that all stocks in the lot were purchased at the same time & price.
 * Provides methods used by Account, the Market, and Transactions and the 
 * main simulation program to support buying and selling of shares.
 * EK, Feb 2024
 */
using namespace std;


class Stock {

/*
 * This overloaded output stream operator:
 *	- displays the content of the Stock specified in the second parameter
 *	- to the output stream specified in the first parameter
 * - and returns a reference to the same output stream
 * The use of reference types (the &) prevents excess copying.
 * Making this a friend function permits the operator<< method
 * to directly access the private variables of the Stock class.
 */
friend ostream& operator<<(ostream& os, const Stock& st);

public:
	 // marked as explicit to avoid implicit conversion
	 // use default values of "NAME", "TKR", 0.00, 0
	 explicit Stock();

	 // We want the client to specify all parameters or none; no partial
	 // so don't use default notation
	 Stock(string sn, string ts, double pps, int nsh);

	/*
	 * A copy constructor takes a single argument: a object of the 
	 * same class.  The goal of the copy constructor is to 
	 * make an copy of the object passed in(labeled "other" below).
	 * The copied object (other) should not change, thus we use
	 * the const modifier.
	 * If we did not use the reference notation (&), then what
	 * would happen when this constructor is called would be:
	 * 1. a copy of the passed object is created
	 * 2. the constructor makes a new Stock object
	 * 3. the values in the object created in #1 are copied, element by 
	 *    element into the object created in #2.
	 * 4. When the constructor returns, the copy created in #1 is 
	 *    destroyed and the memory returned.
	 * With the use of the reference parameter (&) we avoid making
	 * the extra copy of step 1.
	 * Moral of story: use the & -- it is more efficient, and use
	 * const to ensure that the original is unchanged.
	 */
   /*
	 * Note further:  the use of "= default" indicates that we want
	 * the compiler to provide this method for us.  It will be okay
	 * because this object is "flat" -- it does not have/contain
	 * other object / no pointers.
	 */
	Stock(const Stock& other) = default;


	// the getKey() method will be used in our comparisons
	// allows us to modify what the key value is
	const string getKey() const;
	const string getStockName() const;
	const string getTickerSymbol() const;
	double getPricePerShare() const;
	int getNumShares() const;

	void setStockName(string s);
	void setTickerSymbol(string s);
	void setPricePerShare(double p);
	void setNumShares(int s);

	Stock & operator=(const Stock& other) = default;
	bool operator==(const Stock &other) const;


	// relational operators
	// these can all be member functions and will work no matter the order of operands:
	// stock1 < stock2 , and so on
	bool operator<(const Stock &other) const;
	bool operator>(const Stock &other) const;
	bool operator>=(const Stock &other) const;
	bool operator<=(const Stock &other) const;

	// this one only works as a member function if the stock is the left operand
	// stock1 == key_value
	bool operator==(const string key) const;

private:
	string stockName;
	string tickerSymbol;
	double pricePerShare;
	int numShares;
};


#endif
