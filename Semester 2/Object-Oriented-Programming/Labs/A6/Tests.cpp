#include "Tests.h"
#include <assert.h>
//create a function that tests the domain class	
void testDomain() {
	
    Movie m("The Godfather", "Crime", "https://www.youtube.com/watch?v=sY1S34973zA", 1972, 100);
    assert(m.getTitle() == "The Godfather");
    assert(m.getGenre() == "Crime");
    assert(m.getTrailer() == "https://www.youtube.com/watch?v=sY1S34973zA");
    assert(m.getYearOfRelease() == 1972);
    assert(m.getNrOfLikes() == 100);
  
    Movie movie("The Matrix", "Action", "https://www.youtube.com/watch?v=m8e-FF8MsqU", 1999, 1000);
    string expected = "Title: The Matrix | Genre: Action | Trailer: https://www.youtube.com/watch?v=m8e-FF8MsqU | Year of Release: 1999 | Number of likes: 1000";
    string actual = movie.toString();
    assert(actual == expected);

}

void testRepo(){

	Repository repo;

	// Test initialiseRepo()
	repo.initialiseRepo();
	assert(repo.getSizeRepo() == 10);

	// Test addRepo() and getAllRepo()
	Movie new_movie("The Matrix", "Science Fiction", "https://www.youtube.com/watch?v=m8e-FF8MsqU", 1999, 1200);
	repo.addRepo(new_movie);
	assert(repo.getSizeRepo() == 11);
	assert(repo.getAllRepo()[10].getTitle() == "The Matrix");

	// Test removeRepo()
	repo.removeRepo(10);
	assert(repo.getSizeRepo() == 10);
	assert(repo.findByTitle("The Matrix") == -1);

	// Test updateRepo()
	Movie updated_movie("The Shawshank Redemption", "Drama", "https://www.youtube.com/watch?v=6hB3S9bIaco", 1994, 2000);
	repo.updateRepo(0, updated_movie);
	assert(repo.getAllRepo()[0].getNrOfLikes() == 2000);

	// Test findByTitle()
	assert(repo.findByTitle("The Dark Knight") == 2);
	assert(repo.findByTitle("The Lion King") == -1);
}


void testService() {
    // Test addService function
    Repository repo;
    Service service;

    service.initialiaseService();
    assert(service.getAllService().size() == 10);

    int result = service.addService("Test Movie", "Action", "www", 2022, 0);
    assert(result == 0);

 


    result = service.addService("Test Movie", "Action", "www", 2022, 0);
    assert(result == 1);

    // Test removeService function
    result = service.removeService("Nonexistent Movie");
    assert(result == 1);
    result = service.removeService("Test Movie");
    assert(result == 0);

    // Test updateService function
    service.addService("Old Title", "Action", "https://test-trailer.com", 2022, 0);
    result = service.updateService("Old Title", "New Title", "Comedy", "https://new-trailer.com", 1, 2023);
    assert(result == 1);
    result = service.updateService("Nonexistent Movie", "New Title", "Comedy", "https://new-trailer.com", 1, 2023);
    assert(result == -1);

    // Test updateLikesService function
    service.addService("Test Likes Movie", "Action", "https://test-trailer.com", 2022, 0);
    Movie movie = service.getAllService().back();
    int initialLikes = movie.getNrOfLikes();
    service.updateLikesService(movie.getTitle());
    movie = service.getAllService().back();
    int updatedLikes = movie.getNrOfLikes();
    assert(updatedLikes == initialLikes + 1);

    
}


void testUserRepo() {
    Movie m1("Inception", "Thriller", "https://www.youtube.com/watch?v=YoHD9XEInc0", 2010, 0);

    // Create a user repository
    UserRepository userRepo;

    // Test addUserRepo method
    userRepo.addUserRepo(m1);
    assert(userRepo.getSizeUserRepo() == 1);

    // Test getAllUserRepo method
    vector<Movie> movieList = userRepo.getAllUserRepo();
    assert(movieList.size() == 1);
    assert(movieList[0].getTitle() == "Inception");

    // Test deleteUserRepo method
    userRepo.deleteUserRepo(0);
    assert(userRepo.getSizeUserRepo() == 0);

    // Test findByTitleUser method
    userRepo.addUserRepo(m1);
    assert(userRepo.findByTitleUser("Inception") == 0);
    assert(userRepo.findByTitleUser("The Matrix") == -1);
}

void testUserService() {
    UserService userService;
    Repository repo;
    UserService user_service;

    assert(user_service.getSizeUserService() == 0);

    Movie movie1("Title1", "Genre1", "Trailer1", 2021, 10);
    user_service.addUserService(movie1);
    assert(user_service.getSizeUserService() == 1);

    vector <Movie> allMovies = user_service.getAllUserService();

    Movie movie2 = Movie("test", "test", "test", 0, 0);
    user_service.addUserService(movie2);
    assert(user_service.getSizeUserService() == 2);
    assert(user_service.deleteMovieFromWatchlist("Title1") == true);
    assert(user_service.deleteMovieFromWatchlist("Title1") == false);

    vector<Movie> validMovies;
    Movie movie3("Movie1", "Action", "www", 2020, 100);
    Movie movie4("Movie2", "Comedy", "www", 2015, 200);
    Movie movie5("Movie3", "Action", "www", 2010, 300);
    validMovies.push_back(movie3);
    validMovies.push_back(movie4);
    validMovies.push_back(movie5);

    string givenGenre = "Drama";
    vector<Movie> expected = user_service.listMoviesByGenre(expected, givenGenre, validMovies); 
    assert(expected.size() == 0);

    givenGenre = "Action";
    vector<Movie> expected2 = user_service.listMoviesByGenre(expected2, givenGenre, validMovies);
    assert(expected2.size() == 2);


    
}
void testAll() {
	testDomain();
	testRepo();
	testService();
	testUserRepo();
	testUserService();
}