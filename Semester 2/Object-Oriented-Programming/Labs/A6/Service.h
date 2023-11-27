#pragma once
#include "Repository.h"

class Service {

private:
	Repository repo;

public:

	Service();
	~Service();

	vector<Movie>& getAllService();

	int getSizeService();

	int addService(string title, string genre, string trailer, int yearOfRelease, int nrOfLikes);
	int removeService(string title);
	int updateService(string oldTitle, string newTitle, string newGenre, string trailer, int nrOfLikes, int yearOfRelease);
	void initialiaseService();
	void updateLikesService(string title);
};


	