#include "Service.h"
#include "MovieValidator.h"


Service::Service(Repository& repo, MovieValidator validator) : repo{repo}, validator{validator}
{
}

Service::~Service()
{
}

vector<Movie>& Service::getAllService() {

	return this->repo.getAllRepo();
}

int Service::getSizeService() {

	return this->repo.getSizeRepo();
}

void Service::addService(string add_title, string add_genre, string add_trailer, int add_year_of_release, int add_likes) {
	Movie new_movie(add_title, add_genre, add_trailer, add_year_of_release, add_likes);
	this->validator.validate(Movie(add_title, add_genre, add_trailer, add_year_of_release, add_likes));
	this->repo.addRepo(new_movie);
}



void Service::removeService(string delete_title) {

	int delete_index = this->repo.findByTitle(delete_title);
	this->repo.removeRepo(delete_index);

}

void Service::updateService(string update_title, string update_genre, string update_trailer, int update_likes, int update_year) {

	this->validator.validate(Movie(update_title, update_genre, update_trailer, update_likes, update_year));
	int update_index = this->repo.findByTitle(update_title);
	this->repo.updateRepo(update_index, Movie(update_title, update_genre, update_trailer, update_likes, update_year));
}


void Service::updateLikesService(string title)
{
	int index = this->repo.findByTitle(title);
	Movie newMovie = Movie(title, this->repo.getAllRepo()[index].getGenre(), this->repo.getAllRepo()[index].getTrailer(), this->repo.getAllRepo()[index].getYearOfRelease(), this->repo.getAllRepo()[index].getNrOfLikes() + 1);

	//Movie newMovie = Movie(title, this->repo.getAllRepo().getElement(index).getGenre(), this->repo.getAllRepo().getElement(index).getTrailer(), this->repo.getAllRepo().getElement(index).getYearOfRelease(), this->repo.getAllRepo().getElement(index).getNrOfLikes() + 1);
	this->repo.updateRepo(index, newMovie);
}

void Service::validate_genre(string genre) {
	this->validator.validate_genre(genre);
}

void Service::validate_year(string year_of_release) {
	this->validator.validate_year(year_of_release);
}

void Service::validate_likes(string likes) {
	this->validator.validate_likes(likes);
}