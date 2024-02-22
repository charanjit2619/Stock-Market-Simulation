#include<iostream>
#include "Stock.h"
#include<iomanip>

using namespace std;

// Defining Constructors
Stock::Stock(string sn, string ts, double pps, int nsh):stockName(sn), tickerSymbol(ts), pricePerShare(pps), numShares(nsh){};
Stock::Stock():stockName("NAME"), tickerSymbol("TKR"), pricePerShare(0.00), numShares(0){};

//Friend Function
ostream& operator<<(ostream& os, const Stock& st){
    os << left << setw(5) << st.getTickerSymbol() <<":" << right << setw(5) << st.getNumShares() << " @ $" << setw(8) << fixed << setprecision(2) << st.getPricePerShare() << " (" <<st.getStockName() << ")";
    return os;
}

//getter methods
const string Stock::getKey() const{
    return tickerSymbol;
}

const string Stock::getStockName() const{
    return stockName;
}

const string Stock::getTickerSymbol() const{
    return tickerSymbol;
}
double Stock::getPricePerShare() const{
    return pricePerShare;
}

int Stock::getNumShares() const{
    return numShares;
}

//Setter methods
void Stock::setStockName(string s){
    stockName = s;
}

void Stock::setTickerSymbol(string s){
    tickerSymbol = s;
}

void Stock::setPricePerShare(double p){
    pricePerShare = p;
}

void Stock::setNumShares(int s){
    numShares = s;
}

//Operator overlaoding
bool Stock::operator==(const Stock &other) const{
    return  (getKey() == other.getKey());
}

bool Stock::operator<(const Stock &other) const{
    return  (getKey() < other.getKey());
}

bool Stock::operator>(const Stock &other) const{
    return  (getKey() > other.getKey());
}

bool Stock::operator>=(const Stock &other) const{
    return  (getKey() >= other.getKey());
}

bool Stock::operator<=(const Stock &other) const{
    return  (getKey() <= other.getKey());
}

bool Stock::operator==(const string key) const{
    return (getKey() == key);
}