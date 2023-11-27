#include "UserService.h"

//UserService::UserService()
//{
//}

UserService::~UserService()
{
}

vector<Movie>& UserService::getAllUserService() {
	return this->userRepo->getAllUserRepo();
	//return this->userRepo.get
}

int UserService::getSizeUserService() {
	return this->userRepo->getSizeUserRepo();
}


vector <Movie> UserService::listMoviesByGenre(vector<Movie> validMovies, string givenGenre, vector<Movie> allMoviesFromDatabase) {
	//vector<Movie> moviesByGenre;
	for (auto& movie : allMoviesFromDatabase)
	{
		if (movie.getGenre() == givenGenre)
		{
			validMovies.push_back(movie);
		}
	}
	return validMovies;
}

void UserService::addUserService(Movie& movie) {
	this->userRepo->addUserRepo(movie);
}

bool UserService::deleteMovieFromWatchlist(string title) {
	int index = this->userRepo->findByTitleUser(title);
	if (index == -1)
		return false;
	this->userRepo->deleteUserRepo(index);
	return true;
}

void UserService::WriteUserWatchListToFile()
{
	if (this->userRepo != nullptr)
		this->userRepo->writeToFile();
}

void UserService::openWatchList()
{
	if (this->userRepo != nullptr)
		this->userRepo->displayWatchlist();
}


