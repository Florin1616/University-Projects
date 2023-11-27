# Assignment 02-03

## Requirements
- Each student will be given one of the problems below.
- The solution must use the **C language**.
- The problem should be solved over 2 iterations, due `Week 3` and `Week 4`:

### Week 3
- Solve at least requirements **a** and **b**.
- The vector used in the repository can be statically allocated.

### Week 4
- Solve all problem requirements.
- Define a vector structure with specific operations using a dynamically allocated array.
- Use modular programming.
- Source code must be specified and include tests for all non-UI functions
- The program must not leak memory!
- Use a layered architecture for your application (domain, repository, controller, UI). User interface, domain and data access elements will be stored in different modules. The user interface module will only contain the user interface part.
- Have at least 10 entries available at application startup.
- Handle user input errors gracefully (replace program crashes with nice error messages :blush:).

## Problem Statement

### World Population Monitoring
The World Population Monitoring Organisation needs an application to help keep track of countries’ populations. Each **Country** has a unique `name`, the `continent` it belongs to (one of `Europe, America, Africa, Australia or Asia`), and a population (stored in millions).  The employees of the organisation need the application to help them in the following ways:\
**(a)** Add, delete or update a country. Updating must also consider the case of migration: a given number of people leave one country to migrate to another.\
**(b)** Display all countries whose name contains a given string (if the string is empty, all the countries should be considered).\
**(c)** Display all countries on a given continent (if the continent is empty, all countries will be considered), whose populations are greater than a given value, sorted ascending by population.\
**(d)** Provide multiple undo and redo functionality. Each step will undo/redo the previous operation performed by the user.
