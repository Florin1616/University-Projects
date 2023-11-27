#pragma once
#include "Service.h"
#include "UserService.h"

class Ui {
private:
    Service service;
    UserService userService;

public:

    Ui();
    ~Ui();
	void printUserMenu();// done	
	void printMainMenu(); //done	
	void printAdminMenu();	//done


	bool validateString(string input); //done

	void AdminMode();
	void addElemUi(); //done
	void removeElemUi(); // done
	void updateElemUi();
	void listAllElements();	//done


	void UserMode();
	void listAllUser();
	void startWatchList();
	void deleteMovieFromWatchlist();
    

	void start();
};


