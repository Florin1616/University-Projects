#pragma once

#include <string>
#include<vector>
#include "Domain.h"

class MovieException {
private:
	vector <string> errors;

public:
	MovieException(vector<string> _errors) : errors{ _errors } {}
	vector<string> getErrors() const { return this->errors; }
};

class MovieValidator {
public:
	MovieValidator() {}
	~MovieValidator() {}
	void validate(Movie m);
};