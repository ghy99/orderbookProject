#include "OrderBook.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Bid::Bid(float price, float qty) : price(price), qty(qty) {
	// Constructor for a Bid. 
}

void Bid::setPrice(float price) {
	// Setter method for price in a bid. 
	Bid::price = price;
}

void Bid::setQty(float qty) {
	// Setter method for quantity in a bid. 
	Bid::qty = qty;
}

float Bid::getPrice() {
	// Getter method for price in a bid.
	return Bid::price;
}

float Bid::getQty() {
	// Getter method for quantity in a bid.
	return Bid::qty;
}

void Bid::printBid() {
	// Print the price and quantity for a bid. 
	cout << fixed << setprecision(5) << price << "---->" << qty << endl;
}

Ask::Ask(float price, float qty) : price(price), qty(qty) {
	// Constructor for an Ask. 
}

void Ask::setPrice(float price) {
	// Setter method for price in an Ask. 
	Ask::price = price;
}

void Ask::setQty(float qty) {
	// Setter method for quantity in an Ask. 
	Ask::qty = qty;
}

float Ask::getPrice() {
	// Getter method for price in an Ask. 
	return Ask::price;
}

float Ask::getQty() {
	// Getter method for quantity in an Ask. 
	return Ask::qty;
}

void Ask::printAsk() {
	// Print the price and quantity for an Ask. 
	cout << fixed << setprecision(5) << price << "---->" << qty << endl;
}

OrderBook::OrderBook() {
	// Constructor for an OrderBook. 
}

void OrderBook::setOrderBook(json result)
{
	// Parse the result and store it in the attributes. 
	string updateId = to_string(result["lastUpdateId"]);
	OrderBook::lastUpdateId = updateId;
	

	vector<Bid> extract_bids;
	for (int i = 0; i < result["bids"].size(); i++) {
		string price_str = result["bids"][i][0];
		float price = std::stof(price_str);
		string qty_str = result["bids"][i][1];
		float qty = std::stof(qty_str);
		Bid each_bid(price, qty);
		extract_bids.push_back(each_bid);
	}
	OrderBook::bids = extract_bids;
	cout << endl;
	
	vector<Ask> extract_asks;
	for (int i = 0; i < result["asks"].size(); i++) {
		string price_str = result["asks"][i][0];
		float price = std::stof(price_str);
		string qty_str = result["asks"][i][1];
		float qty = std::stof(qty_str);
		Ask each_ask(price, qty);
		extract_asks.push_back(each_ask);
	}
	OrderBook::asks = extract_asks;
}

void OrderBook::setLastUpdateId(string lastUpdateId) {
	// Setter method for the Last Update ID.
	OrderBook::lastUpdateId = lastUpdateId;
}

void OrderBook::setBids(vector<Bid> bids) {
	// Setter method for the top 5 bids. 
	OrderBook::bids = bids;
}

void OrderBook::setAsks(std::vector<Ask> asks) {
	// Setter method for the top 5 asks. 
	OrderBook::asks = asks;
}

string OrderBook::getLastUpdateId() {
	// Getter method for the Last Update ID. 
	return OrderBook::lastUpdateId;
}

vector<Bid> OrderBook::getBids() {
	// Getter method for the top 5 bids. 
	return OrderBook::bids;
}

vector<Ask> OrderBook::getAsks() {
	// Getter method for the top 5 asks. 
	return OrderBook::asks;
}

void OrderBook::printBids() {
	// Display each bid in the order book.
	cout << "BIDS:" << endl;
	cout << "Price:\t\tQuantity:" << endl;
	for (int i = 0; i < bids.size(); i++) {
		bids[i].printBid();
	}
	cout << endl;
}

void OrderBook::printAsks() {
	// Display each ask in the order book.
	cout << "ASKS:" << endl;
	cout << "Price:\t\tQuantity:" << endl;
	for (int i = 0; i < asks.size(); i++) {
		asks[i].printAsk();
	}
	cout << endl;
}

void OrderBook::printOrderBook() {
	// Display the bids and asks in the order book.
	cout << "Last update ID: " << OrderBook::getLastUpdateId() << endl;;
	OrderBook::printBids();
	OrderBook::printAsks();
}
