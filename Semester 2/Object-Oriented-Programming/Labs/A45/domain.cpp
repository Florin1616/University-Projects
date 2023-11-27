#include "domain.h"
#include <string>
#include <Windows.h>
#include <shellapi.h>
using namespace std;
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
Movie::~Movie() {

}

string Movie::toString() const {
	return "Title: " + this->title + " | " + "Genre: " + this->genre + " | " + " Year of Release: " + to_string(this->yearOfRelease) + " | " + " Number of likes: " + to_string(this->numberOfLikes) + " | " + " Trailer: " + this->trailer;
}

void Movie::operator = (const Movie& movie) {
	this->title = movie.title;
	this->genre = movie.genre;
	this->numberOfLikes = movie.numberOfLikes;
	this->trailer = movie.trailer;
	this->yearOfRelease = movie.yearOfRelease;
}


void Movie::playTrailer() {
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getTrailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}