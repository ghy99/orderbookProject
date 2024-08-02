#include <nlohmann/json.hpp>
#include <iostream> 

using namespace std;
using json = nlohmann::json;

bool checkInputValidity(json result) {
	// This function is used to check the validity of the result. 
	// If the json response is an error, it will display the error and return a false. 
	// If the json response has no error, it will return true and the program will continue running. 
	// the input result is a json object which stores the response from the HTTP GET request. 

	string code = "code";
	string msg;
	string lastUpdateId = "lastUpdateId";

	if (result.contains(lastUpdateId)) {
		cout << "valid result" << endl;
		return true;
	}
	else if (result.contains(code)) {
		cout << "invalid result: " << code << endl;
		cout << "Message: " << result[code] << endl;
		return false;
	}
	return false;
}