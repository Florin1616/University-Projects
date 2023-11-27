#include "tests.h"
#include <cassert>
#include <cstring>

void domainTest() {
	Movie movie1("Superman", "Action", "https://www.youtube.com/watch?v=pUwxH4SM9Rg&ab_channel=DC", 1978, 3410);
	assert(movie1.getGenre() == "Action");
	assert(movie1.getNrOfLikes() == 3410);
	assert(movie1.getTitle() == "Superman");
	assert(movie1.getYearOfRelease() == 1978);
	assert(movie1.getTrailer() == "https://www.youtube.com/watch?v=pUwxH4SM9Rg&ab_channel=DC");
	string string = movie1.toString();
	assert(string == "Title: Superman | Genre: Action |  Year of Release: 1978 |  Number of likes: 3410 |  Trailer: https://www.youtube.com/watch?v=pUwxH4SM9Rg&ab_channel=DC");
}


void adminRepoTest() {
	Repository repo;
	repo.initialiseRepo();
	assert(repo.getSizeRepo() == 10);
	assert(repo.getSizeRepo() == 10);
	assert(repo.getAllRepo().getElement(0).getTitle() == "The Shawshank Redemption");
	Movie movie1 = Movie("Superman", "Action", "https://www.youtube.com/watch?v=pUwxH4SM9Rg&ab_channel=DC", 1978, 3410);
	repo.addMovieRepo(movie1);
	assert(repo.getSizeRepo() == 11);
	assert(repo.getCapacityRepo() == 20);
	assert(repo.findByName("Superman") == 10);
	repo.deleteMovieRepo(7);
    assert(repo.getSizeRepo() == 10);
	Movie movie2 = Movie("Ant Man", "Action", "https://www.youtube.com/watch?v=ZlNFpri-Y40&ab_channel=MarvelEntertainment", 2023, 1453);
	repo.updateMovieRepo(0, movie2);
	assert(repo.getAllRepo().getElement(11).getGenre() == "Action");
	assert(repo.getAllRepo().getElement(11).getNrOfLikes() == 1453);


}

