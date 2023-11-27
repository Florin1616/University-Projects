#pragma once
#include "UserRepo.h"
#include "Repository.h"

class UserService
{
private:
	Repository repo;
	UserRepository userRepo;
public:

	UserService();
	~UserService();

	vector<Movie>& getAllUserService();

	int getSizeUserService();
	vector <Movie> listMoviesByGenre(vector<Movie> validMovies, string givenGenre, vector<Movie> repo);
	void addUserService(Movie& movie);
	bool deleteMovieFromWatchlist(string title);

};
