#include "OrderBook.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

Bid::Bid(float price, float qty) : price(price), qty(qty) {}

void Bid::setPrice(float price) {
	Bid::price = price;
}

void Bid::setQty(float qty) {
	Bid::qty = qty;
}

float Bid::getPrice() {
	return Bid::price;
}

float Bid::getQty() {
	return Bid::qty;
}

void Bid::printBid() {
	cout << fixed << setprecision(5) << price << "---->" << qty << endl;
}

Ask::Ask(float price, float qty) : price(price), qty(qty) {}

void Ask::setPrice(float price) {
	Ask::price = price;
}

void Ask::setQty(float qty) {
	Ask::qty = qty;
}

float Ask::getPrice() {
	return Ask::price;
}

float Ask::getQty() {
	return Ask::qty;
}

void Ask::printAsk() {
	cout << fixed << setprecision(5) << price << "---->" << qty << endl;
}

OrderBook::OrderBook() {}

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
	// Set the Last Update ID
	OrderBook::lastUpdateId = lastUpdateId;
}

void OrderBook::setBids(vector<Bid> bids) {
	// Store the bids in list of lists[int].
	OrderBook::bids = bids;
}

void OrderBook::setAsks(std::vector<Ask> asks) {
	// Store the asks in list of lists[int].
	OrderBook::asks = asks;
}

string OrderBook::getLastUpdateId() {
	// Return last update ID
	return OrderBook::lastUpdateId;
}

vector<Bid> OrderBook::getBids() {
	// Return bids 
	return OrderBook::bids;
}

vector<Ask> OrderBook::getAsks() {
	// Return asks
	return OrderBook::asks;
}

void OrderBook::printBids() {
	cout << "BIDS:" << endl;
	cout << "Price:\t\tQuantity:" << endl;
	for (int i = 0; i < bids.size(); i++) {
		bids[i].printBid();
	}
	cout << endl;
}

void OrderBook::printAsks() {
	cout << "ASKS:" << endl;
	cout << "Price:\t\tQuantity:" << endl;
	for (int i = 0; i < asks.size(); i++) {
		asks[i].printAsk();
	}
	cout << endl;
}

void OrderBook::printOrderBook() {
	cout << "Last update ID: " << OrderBook::getLastUpdateId() << endl;;
	OrderBook::printBids();
	OrderBook::printAsks();
}
