#include "Domain.h"
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Utils.h"


Movie::~Movie() {

}



Movie::Movie(string title, string genre, string trailer, int yearOfRelease, int nrOfLikes) {
	this->title = title;
	this->genre = genre;
	this->trailer = trailer;
	this->yearOfRelease = yearOfRelease;
	this->numberOfLikes = nrOfLikes;
}

string Movie::getTitle() {
	return this->title;
}
string Movie::getGenre() {
	return this->genre;
}
string Movie::getTrailer() {
	return this->trailer;
}
int Movie::getYearOfRelease() {
	return this->yearOfRelease;
}
int Movie::getNrOfLikes() {
	return this->numberOfLikes;
}

string Movie::toString() const {
	return "Title: " + this->title + " | " + "Genre: " + this->genre + " | " + "Trailer: " + this->trailer + " | " + "Year of Release: " + to_string(this->yearOfRelease) + " | " + "Number of likes: " + to_string(this->numberOfLikes);
}


//void Movie::operator = (const Movie& movie) {
//	this->title = movie.title;
//	this->genre = movie.genre;
//	this->numberOfLikes = movie.numberOfLikes;
//	this->trailer = movie.trailer;
//	this->yearOfRelease = movie.yearOfRelease;
//}

istream& operator >> (istream& is, Movie& movie) {
	string line;
	getline(is, line);
	vector<string> tokens = tokenize(line, '|');
	if (tokens.size() != 5) // make sure all the starship data was valid
		return is;
	movie.title = tokens[0];
	movie.genre = tokens[1];
	movie.trailer = tokens[2];
	movie.yearOfRelease = stoi(tokens[3]);
	movie.numberOfLikes = stoi(tokens[4]);
	return is;
}

ostream& operator << (ostream& os, const Movie& movie) {
	os << movie.title << "|" << movie.genre << "|" << movie.trailer << "|" << movie.yearOfRelease << "|" << movie.numberOfLikes;
	return os;
}
