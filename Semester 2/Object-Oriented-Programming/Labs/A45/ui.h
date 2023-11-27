#pragma once
#include "service.h"
#include "user_service.h"
class Ui {
private:
	Service service;
	UserService userService;
	;
public:
	Ui();
	bool validateString(string input);
	void addElemUi();
	void removeElemUi();
	void updateElemUi();
	void listAllElements();
	void printAdminMenu();
	void start();
	void printUserMenu();
	void printMainMenu();
	void AdminMode();
	void UserMode();
	void listAllUser();
	void startWatchList();
	void deleteMovieFromWatchlist();
	~Ui();
};
