#include "Utils.h"
#include <string>
#include <iostream>

#include <vector>
#include <sstream>
using namespace std;

vector<string> tokenize(string& str, char delimiter) {
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}
