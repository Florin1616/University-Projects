#include "HTMLWatchList.h"
#include <fstream>
#include "RepositoryExceptions.h"
#include <Windows.h>
#include <vector>
using namespace std;

void HTMLWatchList::writeToFile()
{
    const string htmlHeader = R"(
        <!DOCTYPE html>
        <html>
        <head>
            <title>Watch List</title>
            <style>
                body {
                    font-family: Arial, sans-serif;
                    background-color: #f5f5f5;
                    margin: 0;
                    padding: 20px;
                }
                h1 {
                    text-align: center;
                    color: #333;
                }
                table {
                    border-collapse: collapse;
                    width: 100%;
                    margin-top: 20px;
                }
                th, td {
                    text-align: left;
                    padding: 10px;
                }
                th {
                    background-color: #f2f2f2;
                    color: #333;
                }
                tr:nth-child(even) {
                    background-color: #e9e9e9;
                }
                tr:hover {
                    background-color: #d4d4d4;
                }
                a {
                    color: #333;
                    text-decoration: none;
                }
                a:hover {
                    text-decoration: underline;
                }
            </style>
        </head>
        <body>
            <h1>Movie Watch List</h1>
            <table>
                <tr>
                    <th>Title</th>
                    <th>Genre</th>
                    <th>Trailer</th>
                    <th>Year</th>
                    <th>Likes</th>
                </tr>
    )";

    const string htmlFooter = R"(
            </table>
        </body>
        </html>
    )";

    ofstream file(this->filename.c_str());
    file << htmlHeader;

    for (auto movie : this->Watchlist)
    {
        file << R"(
                <tr>
                    <td>)" << movie.getTitle() << R"(</td>
                    <td>)" << movie.getGenre() << R"(</td>
                    <td><a href=")" << movie.getTrailer() << R"(" target="_blank">Watch Trailer</a></td>
                    <td>)" << movie.getYearOfRelease() << R"(</td>
                    <td>)" << movie.getNrOfLikes() << R"(</td>
                </tr>
        )";
    }

    file << htmlFooter;
    file.close();

}

void HTMLWatchList::displayWatchlist()
{
    ShellExecute(NULL, "open", "Watchlist.html", NULL, NULL, SW_SHOWNORMAL);
    //ShellExecuteA(NULL, NULL, "C:\\Users\\Administrator\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe", this->filename.c_str(), NULL, SW_SHOWMAXIMIZED);

}
