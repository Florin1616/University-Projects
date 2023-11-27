For your solution to the previous assignments (Assignments 04-05, 06), add the following features:<br/>

1. Store data in a text file. When the program starts, entities are read from the file. Modifications made during program execution are stored in the file. Implement <br/>
this using the iostream library. Create insertion and extraction operators for your entities and use these when reading/writing to files or the console.

2. Use exceptions to signal errors: <br/>

-from the repository;<br/>
-validation errors – validate your entities using Validator classes;<br/>
-create your own exception classes.<br/>
-validate program input.<br/>

3. Depending on your assignment, store your (adoption list, movie watch list, shopping basket or tutorial watch list) in a file. When the application starts, the user <br/>
should choose the type of file between CSV or HTML. Depending on the type, the application will save the list in the correct format.<br/>

Indications
The CSV file will contain each entity on one line and the attributes will be separated by comma<br/>
The HTML file will contain a table, in which each row holds the data of one entity. The columns of the table will contain the names of the data attributes.<br/>
These are exemplified in the example.csv and example.html files. CSV and HTML files are used to save and display data to the user; they act as program outputs, so data <br/>
should not be read from them!<br/>

4. Add a new command, allowing the user to see the:<br/>

-adoption list<br/>
-movie watch list<br/>
-shopping basket<br/>
-tutorial watch list<br/>
-Displaying the list means opening the saved file (CSV or HTML) with the correct application (CSV files using Notepad, Notepad++, Microsoft Excel etc. and HTML files <br/>
using a browser)<br/>
-Create a UML class diagram for your entire application. For this, you can use any tool that you like (StarUML or LucidChart are only some examples. Many other options exist.
