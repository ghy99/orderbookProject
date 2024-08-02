#include <nlohmann/json.hpp>
#include <iostream> 

using namespace std;
using json = nlohmann::json;

bool checkInputValidity(json result) {
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
}