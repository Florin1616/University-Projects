#include "MoviesQT.h"
#include <QtWidgets/QApplication>
#include <memory>
#include "GUI.h"
#include "Service.h"
#include "UserService.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    string movieFilename = R"(C:\Users\Florin\source\repos\MoviesQT\MoviesQT\Movies.txt)";
    Repository repo(movieFilename);
    //UserService userService();
    MovieValidator validator;
    Service service(repo, validator);
    repo.initialiseRepo();
    //Service service;
    GUI gui(service);
    MoviesQT w;
    gui.show();

    return a.exec();
}
