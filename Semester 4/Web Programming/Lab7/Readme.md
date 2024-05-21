# Project Description

This lab involves developing a server-side web application in PHP. The web application will manipulate a MySQL database and implement base operations on the tables: select, insert, delete, update. The application will also use AJAX for getting data asynchronously from the web server and should contain at least 5 web pages (client-side HTML or server-side PHP).

## Database

For the database, you can use the MySQL database on www.scs.ubbcluj.ro. On this MySQL server, you have an account, a password, and a database, all identical to your username and password on the SCS network.

## Security

Please make sure that you avoid SQL-injection attacks when working with the database.

## User Experience

Have in mind the user experience when you implement the problem:

- Add different validation logic for input fields.
- Do not force the user to input an ID for an item if he wants to delete/edit/insert it; this should happen automatically.
- Add confirmation when the user deletes/cancels an item.
- Do a bare minimum CSS that at least aligns the various input fields.

## Web Application

Write a web application for managing vacation destinations. A destination has in the database besides the name of the location (i.e. city etc.), the country name, description, tourist targets in that location and an estimated cost per day. The user can add, delete or modify the destinations and he can also browse the vacation destinations grouped by countries (use AJAX for this). Vacation destination browsing should be paged - destinations are displayed on pages with maximum 4 vacation destinations on a page (you should be able to go to the previous and the next page).
