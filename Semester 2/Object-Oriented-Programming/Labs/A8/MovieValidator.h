#pragma once

#include <string>
#include<vector>
#include "Domain.h"

class MovieException : public exception  {
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
	bool checkForDigits(string string);
	void validate_genre(string title);
	void validate_year(string year_of_release);
	void validate_likes(string likes);
};