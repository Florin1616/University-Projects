#pragma once
#pragma once
#include <vector>
#include "Domain.h"


class UserRepository
{
private:
	vector<Movie> Watchlist;

public:

	UserRepository();
	~UserRepository();

	vector<Movie>& getAllUserRepo();
	void addUserRepo(Movie& movie);
	void deleteUserRepo(int index);
	int getSizeUserRepo();
	int findByTitleUser(string title);

	

};