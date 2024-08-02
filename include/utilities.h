#pragma once
#include <nlohmann/json.hpp>

using json = nlohmann::json;

bool checkInputValidity(json result);