#include "service.h"
Service::Service() {
	
}

DynamicVector<Movie> Service::getAllService() {
	return this->repo.getAllRepo();
}

int Service::getSizeService() {
	return this->repo.getSizeRepo();
}

int Service::getCapacityService() {
	return this->repo.getCapacityRepo();
}

int Service::addService(string title, string genre, string trailer, int yearOfRelease, int nrOfLikes) {
	int index;
	int length = this->repo.getSizeRepo();
	DynamicVector<Movie> list = this->repo.getAllRepo();
	for (index = 0; index < length; index++) {
		string titleOfMovie = list.getElement(index).getTitle();
		if (titleOfMovie == title)
			return 1;
	}
	this->repo.addMovieRepo(Movie(title, genre, trailer, yearOfRelease, nrOfLikes));
	return 0;

}
Service::~Service() {

}

int Service::removeService(string title) {
	int index = this->repo.findByName(title);
	if (index == -1)
		return 1;
	else {
		this->repo.deleteMovieRepo(index);
		return 0;
	}
}
int Service::updateService(string oldTitle, string newTitle, string newGenre, string newtrailer, int newnrOfLikes, int newyearOfRelease) {
	int index = this->repo.findByName(oldTitle);
	if (index == -1)
		return -1;
	Movie newMovie = Movie(newTitle, newGenre, newtrailer, newyearOfRelease, newnrOfLikes);
	this->repo.updateMovieRepo(index, newMovie);
	return 0;
}

void Service::initialiaseService() {
	this->repo.initialiseRepo();
}

void Service::updateLikesService(string title) {
	int index = this->repo.findByName(title);
	Movie newMovie = Movie(title, this->repo.getAllRepo().getElement(index).getGenre(), this->repo.getAllRepo().getElement(index).getTrailer(), this->repo.getAllRepo().getElement(index).getYearOfRelease(), this->repo.getAllRepo().getElement(index).getNrOfLikes() + 1);
	this->repo.updateMovieRepo(index, newMovie);
}
