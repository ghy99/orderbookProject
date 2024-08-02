#ifndef APICALLER_H
#define APICALLER_H

#include <string>
#include <unordered_map>
#include "curl/curl.h"

size_t write_to_string(void* ptr, size_t size, size_t count, void* stream);
std::string setSymbol(std::string& url, std::string& symbol);
std::string snapshot(std::string& symbol);


#endif
