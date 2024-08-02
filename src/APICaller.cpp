#include "APICaller.h"
#include "curl/curl.h"
#include <iostream>

using namespace std;

size_t write_to_string(void* ptr, size_t size, size_t count, void* stream) {
	// Store the returned json response from the HTTP request in a string. 
	((string*)stream)->append((char*)ptr, 0, size * count);
	return size * count;
}

string setSymbol(string& url, string& symbol) {
	// Set the URL for the HTTP GET request. 
	url += "&symbol=" + symbol;
	return url;
}

string snapshot(string& symbol) {
	// Perform a HTTP GET request to the URL to retrieve the top 5 bids and asks for a given Binance symbol. 
	CURL* curl;
	CURLcode result;
	string url = "https://api.binance.com/api/v3/depth?limit=5";
	string response;

	cout << "### SNAPSHOT ###" << endl;
	cout << "symbol entered: " << symbol << endl;

	url = setSymbol(url, symbol);
	cout << "Posting request to: " << url << endl;

	curl_global_init(CURL_GLOBAL_DEFAULT);

	curl = curl_easy_init();

	if (curl) {
		//Set URL
		curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);
		curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_to_string);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		result = curl_easy_perform(curl);
		if (result != CURLE_OK) {
			cerr << "Error during curl request: " << curl_easy_strerror(result) << endl;
			//response = "";
		}
		curl_easy_cleanup(curl);
	}
	else {
		cerr << "Error initializing curl." << endl;
		//response = "";
	}
	curl_global_cleanup();
	return response;
}
