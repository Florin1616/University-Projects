#pragma once
#include <string>
using namespace std;
class Movie {
private:
	string title;
	string	genre;
	string trailer;
	int yearOfRelease;
	int numberOfLikes;
public:
	Movie(string title = "empty", string genre = "empty", string trailer = "empty", int yearOfRelease = 0, int nrOfLikes = 0);
	string getTitle();
	string getGenre();
	string getTrailer();
	int getYearOfRelease();
	int getNrOfLikes();
	~Movie();
	//void operator = (const Movie& movie);
	string toString() const;
};