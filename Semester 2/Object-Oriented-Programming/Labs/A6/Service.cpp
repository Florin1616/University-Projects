#include "Service.h"

Service::Service()
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

int Service::addService(string add_title, string add_genre, string add_trailer,int add_year_of_release, int add_likes) {

	vector<Movie> movie_list = this->getAllService();

	vector<Movie>::iterator iterator;

	iterator = find_if(movie_list.begin(), movie_list.end(), [add_title](Movie movie) {return (movie.getTitle() == add_title); });

	if (iterator != movie_list.end())
	{
		return 1;
	}
	else
		this->repo.addRepo(Movie(add_title, add_genre, add_trailer,add_year_of_release, add_likes));
	return 0;
}



int Service::removeService(string delete_title) {

	int array_length = this->getSizeService();

	vector<Movie> movie_list = this->getAllService();

	for (auto& movie : movie_list)
	{
		if (movie.getTitle() == delete_title)
		{
			int index = &movie - &movie_list[0];
			this->repo.removeRepo(index);
			return 0;
		}
	}
	return 1;
}

int Service::updateService(string old_title, string update_title, string update_genre, string update_trailer, int update_likes,int update_year) {

	int array_length = this->getSizeService();

	vector<Movie> movie_list = this->getAllService();

	for (auto& movie : movie_list)
	{
		if (movie.getTitle() == old_title)
		{
			int i = &movie - &movie_list[0];
			Movie newMovie = Movie(update_title, update_genre, update_trailer, update_year, update_likes);
			this->repo.updateRepo(i, newMovie);
			return 1;
		}
	}

	return -1;
}

void Service::initialiaseService()
{
	this->repo.initialiseRepo();
}


void Service::updateLikesService(string title)
{
	int index = this->repo.findByTitle(title);
	Movie newMovie = Movie(title, this->repo.getAllRepo()[index].getGenre(), this->repo.getAllRepo()[index].getTrailer(), this->repo.getAllRepo()[index].getYearOfRelease(), this->repo.getAllRepo()[index].getNrOfLikes() + 1);

	//Movie newMovie = Movie(title, this->repo.getAllRepo().getElement(index).getGenre(), this->repo.getAllRepo().getElement(index).getTrailer(), this->repo.getAllRepo().getElement(index).getYearOfRelease(), this->repo.getAllRepo().getElement(index).getNrOfLikes() + 1);
	this->repo.updateRepo(index, newMovie);
}
