#include "UserRepo.h"

UserRepository::UserRepository()
{
}

UserRepository::~UserRepository()
{
}

vector<Movie>& UserRepository::getAllUserRepo() {
	return this->Watchlist;
}

void UserRepository::addUserRepo(Movie& movie) {
	this->Watchlist.push_back(movie);
}

void UserRepository::deleteUserRepo(int index) {
	this->Watchlist.erase(this->Watchlist.begin() + index);
}

int UserRepository::getSizeUserRepo() {
	return this->Watchlist.size();
}

int UserRepository::findByTitleUser(string title) {

	int searchedIndex = -1;
	int index = 0;
	int length = this->getSizeUserRepo();

	while (index < length && searchedIndex == -1)
	{
		if (this->Watchlist[index].getTitle() == title)
			searchedIndex = index;
		index++;
	}
	return searchedIndex;
}

