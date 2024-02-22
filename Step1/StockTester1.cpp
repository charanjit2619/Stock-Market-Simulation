#include "Stock.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){
	
	// locally allocated stock object (on the stack)
	// no parameters provided
	Stock stock1;
	cout << "stock 1: name: " << stock1.getStockName() 
		  << " , ticker: " << stock1.getTickerSymbol()
		  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stock1.getPricePerShare()
		  << " , quantity: " << stock1.getNumShares()
		  << endl << endl;

	// parameters provided
	Stock stock2("Abbott Laboratories", "ABB", 33.63, 200);
	cout << "stock 2: name: " << stock2.getStockName() 
		  << " , ticker: " << stock2.getTickerSymbol()
		  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stock2.getPricePerShare()
		  << " , quantity: " << stock2.getNumShares()
		  << endl << endl;

	// set methods called to change data attributes
	stock2.setStockName("ABBVie");
	stock2.setTickerSymbol("ABBV");
	stock2.setPricePerShare(152.05);
	stock2.setNumShares(1000);

	cout << "But now we've changed stock 2, as seen here:  " << endl;
	cout << "stock 2: name: " << stock2.getStockName() 
		  << " , ticker: " << stock2.getTickerSymbol()
	  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stock2.getPricePerShare()
		  << " , quantity: " << stock2.getNumShares()
		  << endl << endl;

	// dynamically allocated stock
	// no argument constructor causes default values to be set
	Stock * stockPtr3 = new Stock(); 
	cout << "*stockPtr3: name: " << stockPtr3->getStockName() 
		  << " , ticker: " << stockPtr3->getTickerSymbol()
		  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr3->getPricePerShare()
		  << " , quantity: " << stockPtr3->getNumShares()
		  << endl << endl;

	// dynamically allocated stock
	// passes all 4 arguments
	Stock * stockPtr4 = new Stock("Activision Blizzard", "ATVI",75.45, 1000 );
	cout << "*stockPtr4: name: " << stockPtr4->getStockName() 
		  << " , ticker: " << stockPtr4->getTickerSymbol()
		  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr4->getPricePerShare()
		  << " , quantity: " << stockPtr4->getNumShares()
		  << endl << endl;

	stockPtr4->setStockName("Amazon");
	stockPtr4->setTickerSymbol("AMZN");
	stockPtr4->setPricePerShare(97.61);
	stockPtr4->setNumShares(1000);

	cout << "But now we've changed stock 4, as seen here:  " << endl;
	cout << "stock 4: name: " << stockPtr4->getStockName() 
		  << " , ticker: " << stockPtr4->getTickerSymbol()
		  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr4->getPricePerShare()
		  << " , quantity: " << stockPtr4->getNumShares()
		  << endl << endl;

	Stock stock6(stock2);
	cout << "stock 6 is a copy of stock 2: name: " << stock6.getStockName() 
		  << " , ticker: " << stock6.getTickerSymbol()
		  << " , price: $" 
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stock6.getPricePerShare()
		  << " , quantity: " << stock6.getNumShares()
		  << endl << endl;

	cout << "Now we change the price of stock 6." << endl;
	stock6.setPricePerShare(126.44);
	cout << "stock 6: " 
		  << stock6.getStockName() << "," << stock6.getTickerSymbol() << ","
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stock6.getPricePerShare() << "," << stock6.getNumShares() << endl;
	cout << "and see that stock 2 is unchanged -- 6 is a separate copy " << endl;
	cout << "stock 2: " 
		  << stock2.getStockName() << "," << stock2.getTickerSymbol() << ","
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stock2.getPricePerShare() << "," << stock2.getNumShares() << endl;

	cout << "This is also true with dynamically allocated Stock objects." 
		  << endl;
	Stock *stockPtr5 = new Stock(*stockPtr4);
	cout << "*stockPtr5 is a copy of *stockPtr4 " << endl;
	cout << "*stockPtr5: " << stockPtr5->getStockName() << ", " 
		  << stockPtr5->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr5->getPricePerShare() << " , " 
		  << stockPtr5->getNumShares() << endl << endl;

	cout << "*stockPtr4: " << stockPtr4->getStockName() << ", " 
		  << stockPtr4->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr4->getPricePerShare() << " , " 
		  << stockPtr4->getNumShares() << endl << endl;

	cout << "And if we make a change to *stock5Ptr, *stock4Ptr is unaffected." 
		  << endl;
	stockPtr5->setPricePerShare(101.44);
	cout << "*stockPtr5: " << stockPtr5->getStockName() << ", " 
		  << stockPtr5->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr5->getPricePerShare() << " , " 
		  << stockPtr5->getNumShares() << endl << endl;

	cout << "*stockPtr4: " << stockPtr4->getStockName() << ", " 
		  << stockPtr4->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr4->getPricePerShare() << " , " 
		  << stockPtr4->getNumShares() << endl << endl;

	cout << "But notice that if two pointer point to the same thing," << endl; 
	cout << "then changes through one pointer affect the object, " << endl;
	cout << "which is also referred to by the second pointer" << endl << endl;
	Stock *stockPtr7 = new Stock("Allstate Corp", "ALL", 135.41, 1000);
	Stock *stockPtr8 = stockPtr7;
	cout << "Before: *stockPtr7: " << stockPtr7->getStockName() << ", " 
		  << stockPtr7->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr7->getPricePerShare() << " , " 
		  << stockPtr7->getNumShares() << endl;
	cout << "Before: *stockPtr8: " << stockPtr8->getStockName() << ", " 
		  << stockPtr8->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr8->getPricePerShare() << " , " 
		  << stockPtr8->getNumShares() << endl << endl;

	stockPtr7->setPricePerShare(188.88);

	cout << "After: *stockPtr7: " << stockPtr7->getStockName() << ", " 
		  << stockPtr7->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr7->getPricePerShare() << " , " 
		  << stockPtr7->getNumShares() << endl;
	cout << "After: *stockPtr8: " << stockPtr8->getStockName() << ", " 
		  << stockPtr8->getTickerSymbol() << " , "
 		  << fixed << setprecision(2) << setw(5) << right 
		  << stockPtr8->getPricePerShare() << " , " 
		  << stockPtr8->getNumShares() << endl << endl;

	return 0;

}
