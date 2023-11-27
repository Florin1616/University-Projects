#include "user_repo.h"

UserRepo::UserRepo() {

}

DynamicVector<Movie> UserRepo::getAllUserRepo() {
	return this->Watchlist;
}

void UserRepo::addUserRepo(const Movie& movie) {
	this->Watchlist.addElem(movie);
}

void UserRepo::deleteUserRepo(int index) {
	this->Watchlist.deleteElem(index);
}


int UserRepo::findByTitleUser(string title) {
	int searchedIndex = -1;
	int index = 0;
	int length = this->Watchlist.getSize();
	while (index < length && searchedIndex == -1) {
		Movie movie = this->Watchlist.getElement(index);
		string otherTitle = movie.getTitle();
		if (otherTitle == title)
			searchedIndex = index;
		index++;
	}
	return searchedIndex;
}


UserRepo::~UserRepo() {

}