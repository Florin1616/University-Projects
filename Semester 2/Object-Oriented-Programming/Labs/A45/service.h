#pragma once
#include "repository.h"

class Service {
private:
	Repository repo;
public:
	Service();
	~Service();
	DynamicVector<Movie> getAllService();
	int getSizeService();
	int getCapacityService();
	int addService(string title, string genre, string trailer, int yearOfRelease, int nrOfLikes);
	int removeService(string title);
	int updateService(string oldTitle, string newTitle, string newGenre, string trailer, int nrOfLikes, int yearOfRelease );
	void updateLikesService(string title);
	void initialiaseService();
};