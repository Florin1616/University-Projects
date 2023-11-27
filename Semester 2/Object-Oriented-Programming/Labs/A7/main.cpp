#include "ui.h"
#include "tests.h"
#include "RepositoryExceptions.h"
#include "CSVWatchList.h"
#include "HTMLWatchList.h"
#include <Windows.h>
using namespace std;

//void run() {
//	Ui ui;
//	ui.start();
//}

int main() {

	system("color 0A");
	try
	{
		TestAdd testadd;
		testadd.addValidMovie("Joker", "Action", "https://www.youtube.com/watch?v=mqqft2x_Aa4&ab_channel=WarnerBros.Pictures", 1993, 245);
		testadd.addExistingMovieAndThrowException("Batman", "Action", "https://www.youtube.com/watch?v=mqqft2x_Aa4&ab_channel=WarnerBros.Pictures", 1993, 293);



		string fileName = "Movies.txt";
		Repository repo(fileName);
		repo.initialiseRepo();
		UserRepository userRepo;
		FileUserRepo* p = nullptr;
		cout << "What type of file would you like to use to store the playlist (CSV/HTML)?\n";
		string fileType{};
		getline(cin, fileType);
		if (fileType == "HTML")
			p = new HTMLWatchList { "Watchlist.html" };
		else
			p = new CSVWatchList { "Watchlist.csv" };
		Service admin_service(repo);
		UserService user_service(p, MovieValidator{});
		Ui ui(user_service, admin_service );
		ui.start();
		delete p;
	}
	catch (FileException&)
	{
		cout << "Repository file could not be opened! The application will terminate." << endl;
		return 1;
	}

	return 0;
}