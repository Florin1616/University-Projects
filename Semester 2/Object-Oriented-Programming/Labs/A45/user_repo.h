#pragma once
#include "domain.h"
#include "dynamicarray.h"
#include "repository.h"
using namespace std;
class UserRepo {

	private:
	DynamicVector<Movie> Watchlist;
	public:
		UserRepo();
		DynamicVector<Movie> getAllUserRepo();
		void addUserRepo(const Movie& movie);
		void deleteUserRepo(int index);
		int findByTitleUser(string title);
		~UserRepo();
};
		