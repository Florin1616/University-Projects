#include <stdio.h>
#include <string.h>
#include "domain.h"

Country createCountry(char name[], char continent[], unsigned long int population) {
    Country country;
    strcpy(country.name, name);
    strcpy(country.continent, continent);
    country.population = population;
    return country;
}

char* getName(Country* country) {
    return country->name;
}

char* getContinent(Country* country) {
    return country->continent;
}

unsigned long int getPopulation(Country* country) {
    return country->population;
}

void toString(Country country, char str[]) {
    sprintf(str, "Country %s is a country from %s and its population is %ld.", country.name, country.continent, country.population);
}