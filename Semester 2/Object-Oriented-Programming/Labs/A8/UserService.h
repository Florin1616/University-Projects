#pragma once
#include "UserRepo.h"
#include "Repository.h"
#include "MovieValidator.h"
#include "FileUserRepo.h"

class UserService
{
private:
	//Repository repo;
	FileUserRepo* userRepo;
	MovieValidator movieValidator;


public:

	UserService(FileUserRepo* Watchlist, MovieValidator movieValidatorR) :
		userRepo{ Watchlist }, movieValidator{ movieValidatorR } {};
	~UserService();

	vector<Movie>& getAllUserService();

	int getSizeUserService();
	vector <Movie> listMoviesByGenre(vector<Movie> validMovies, string givenGenre, vector<Movie> repo);
	void addUserService(Movie& movie);
	bool deleteMovieFromWatchlist(string title);

	void WriteUserWatchListToFile();
	void openWatchList();

};
