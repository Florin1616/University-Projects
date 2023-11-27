#pragma once
#include "Repository.h"
#include "MovieValidator.h"
class Service {

private:
	//Repository repo;
	Repository& repo;
	MovieValidator validator;

public:

	Service(Repository& repo, MovieValidator validator);
	//Service();
	~Service();

	vector<Movie>& getAllService();

	int getSizeService();

	void addService(string title, string genre, string trailer, int yearOfRelease, int nrOfLikes);
	void removeService(string title);
	void updateService(string newTitle, string newGenre, string trailer, int nrOfLikes, int yearOfRelease);
	//void initialiaseService();
	void updateLikesService(string title);

	void validate_genre(string title);
	void validate_year(string year_of_release);
	void validate_likes(string likes);


	//void readFromFile();
	//void writeToFile();

};



