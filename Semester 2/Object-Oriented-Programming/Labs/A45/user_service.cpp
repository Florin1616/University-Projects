#include "user_service.h"

UserService::UserService() {

}

DynamicVector<Movie> UserService::getAllUserService() {
	return this->userRepo.getAllUserRepo();
}

void UserService::addUserService(Movie movie) {
	this->userRepo.addUserRepo(movie);
}

DynamicVector<Movie> UserService::listMoviesByGenre(DynamicVector<Movie> validMovies, string givenGenre, DynamicVector<Movie> repo) {
	int counter = 0;
	int index;
	int length = repo.getSize();
	for (index = 0; index < length; index++) {
		Movie movie = repo.getElement(index);
		string title = movie.getTitle();
		string genre = movie.getGenre();
		int yearOfRelease = movie.getYearOfRelease();
		int numberOfLikes = movie.getNrOfLikes();
		string trailer = movie.getTrailer();
		Movie copyOfMovie = Movie(title, genre, trailer, yearOfRelease, numberOfLikes);
		if (givenGenre == copyOfMovie.getGenre()) {
			validMovies.addElem(copyOfMovie);
			counter++;
		}
	}
	return validMovies;
}

bool UserService::deleteMovieFromWatchlist(string title) {
	int index = this->userRepo.findByTitleUser(title);
	if (index != -1) {
		this->userRepo.deleteUserRepo(index);
		return true;
	}
	return false;
}

UserService::~UserService() {

}