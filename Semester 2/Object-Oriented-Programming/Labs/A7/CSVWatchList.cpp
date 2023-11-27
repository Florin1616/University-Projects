#include "CSVWatchList.h"
#include <fstream>
#include <Windows.h>
#include "RepositoryExceptions.h"
#include "UserService.h"

void CSVWatchList::writeToFile()
{
	ofstream file(this->filename);
	if (!file.is_open())
		throw FileException("The file could not be opened!");
	for (auto movie : this->Watchlist)
		file << movie;
	file.close();
}

void CSVWatchList::displayWatchlist() 
{

	std::string aux = "\"" + this->filename + "\""; 
	ShellExecuteA(NULL, NULL, "C:\\Program Files\\LibreOffice\\program\\soffice.exe", aux.c_str(), NULL, SW_SHOWMAXIMIZED);


}