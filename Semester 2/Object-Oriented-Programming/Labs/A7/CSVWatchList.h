#pragma once
#include "FileUserRepo.h"

class CSVWatchList : public FileUserRepo
{
public:
	CSVWatchList(const string& filename) : FileUserRepo{ filename } {};
	~CSVWatchList() {};

	void writeToFile() override;
	void displayWatchlist() override;
};