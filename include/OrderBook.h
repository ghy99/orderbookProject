#pragma once
#include "curl/curl.h"
#include <vector>
#include <string>
#include <iomanip>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

class Bid {
private:
	float price;
	float qty;
public:
	Bid(float price, float qty);
	void setPrice(float price);
	void setQty(float qty);
	float getPrice();
	float getQty();
	void printBid();
};

class Ask {
private:
	float price;
	float qty;
public:
	Ask(float price, float qty);
	void setPrice(float price);
	void setQty(float qty);
	float getPrice();
	float getQty();
	void printAsk();
};

class OrderBook
{
private:
	std::string lastUpdateId;
	std::vector<Bid> bids;
	std::vector<Ask> asks;
public:
	OrderBook();
	void setOrderBook(json result);
	void setLastUpdateId(std::string lastUpdateId);
	void setBids(std::vector<Bid> bids);
	void setAsks(std::vector<Ask> asks);

	std::string getLastUpdateId();
	std::vector<Bid> getBids();
	std::vector<Ask> getAsks();
	void printBids();
	void printAsks();
	void printOrderBook();
};

