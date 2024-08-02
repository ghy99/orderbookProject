#include "utilities.h"
#include <nlohmann/json.hpp>
#include <iostream> 

using namespace std;
using json = nlohmann::json;

bool checkInputValidity(json result) {
	string code = "code";
	string msg = "msg";
	string lastUpdateId = "lastUpdateId";

	if (result.contains(lastUpdateId)) {
		return true;
	}
	else if (result.contains(code)) {
		cout << "invalid result: " << result[code] << endl;
		cout << "Message: " << result[msg] << endl;
		return false;
	}
}