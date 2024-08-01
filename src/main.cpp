// orderbook.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <chrono>
#include <iostream>
#include <iomanip>
#include <thread>
#include <vector>
#include <nlohmann/json.hpp>
#include "APICaller.h"
#include "OrderBook.h"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
using json = nlohmann::json;

int main()
{
    OrderBook ob = OrderBook();
    string symbol;
    cout << "Enter your Binance-style symbol: ";
    cin >> symbol;
    while (1) {
        string result = snapshot(symbol);
        json result_json = json::parse(result);
        ob.setOrderBook(result_json);
        ob.printOrderBook();
        sleep_for(seconds(2));
        system("cls");
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
