#include <string.h>
#include "service.h"

bool check_if_valid_continent(char continent[]) {
    const char* Continents[] = { "Europe", "Asia", "America", "Africa", "Australia" };
    int index = 0;
    bool valid = false;
    while (index < sizeof(Continents) / sizeof(const char*) && valid == false) {
        if (strcmp(continent, Continents[index]) == 0)
            valid = true;
        index++;
    }
    return valid;
}

int add_country(Repository* country_list, UndoRedoRepository* undo_redo_repo, char name[], char continent[], unsigned long int population) {
    int index;
    for (index = 0; index < country_list->dynamicArray.length; index++) {
        if (strcmp(getName(&country_list->dynamicArray.data[index]), name) == 0) // check if we already have the country
            return 1;
    }
    if (check_if_valid_continent(continent) == false) // check if the continent is valid
        return 2;
    Country new_country = createCountry(name, continent, population);
    addUndoElement(undo_redo_repo, country_list); // pass the current repo to the undo repo
    addCountry(country_list, new_country);
    return 0;
}

bool delete_country(Repository* country_list, UndoRedoRepository* undo_redo_repo, char name[]) {
    int deleted_index = findByName(country_list, name); // find the index of the element to be deleted
    if (deleted_index == -1)
        return false;
    else {
        addUndoElement(undo_redo_repo, country_list); // pass the current repo to the undo repo
        deleteCountry(country_list, deleted_index);
        return true;
    }
}

int update_country(Repository* country_list, UndoRedoRepository* undo_redo_repo, char old_name[], char name[], char continent[], unsigned long int new_population) {
    if (check_if_valid_continent(continent) == false) // check if the continent is valid
        return 2;
    int update_index = findByName(country_list, old_name); // find the index of the element to be updated
    if (update_index == -1)
        return 1;
    Country updated_country = createCountry(name, continent, new_population);
    addUndoElement(undo_redo_repo, country_list); // pass the current repo to the undo repo
    updateCountry(country_list, update_index, updated_country);
    return 0;
}

int migration(Repository* country_list, UndoRedoRepository* undo_redo_repo, char old_name[], char new_name[], unsigned long int migrators) {
    int index_of_old_country = findByName(country_list, old_name); // find the index of the old country
    int index_of_new_country = findByName(country_list, new_name); // find the index of the new country
    if (index_of_old_country == -1)
        return 1;
    else if (index_of_new_country == -1)
        return 2;
    else {
        addUndoElement(undo_redo_repo, country_list); // pass the current repo to the undo repo
        migrationUpdate(country_list, index_of_old_country, index_of_new_country, migrators);
        return 0;
    }
}

int filter_country(Repository* country_list, const char filter_string[], Country valid_countries[]) {
    int counter = 0;
    int index;
    if (filter_string[0] == '\0') 
        for (index = 0; index < country_list->dynamicArray.length; index++) {
            strcpy(valid_countries[counter].name, country_list->dynamicArray.data[index].name);
            strcpy(valid_countries[counter].continent, country_list->dynamicArray.data[index].continent);
            valid_countries[counter].population = country_list->dynamicArray.data[index].population; // copy everything in the array[counter]
            counter++;
        }
    else {
        for (index = 0; index < country_list->dynamicArray.length; index++) {
            if (strstr(country_list->dynamicArray.data[index].name, filter_string) != NULL) { // if the string can be found in the name, copy in array[counter]
                strcpy(valid_countries[counter].name, country_list->dynamicArray.data[index].name);
                strcpy(valid_countries[counter].continent, country_list->dynamicArray.data[index].continent);
                valid_countries[counter].population = country_list->dynamicArray.data[index].population;
                counter++;
            }
        }
    }
    return counter;
}

int filter_sort_continent(Repository* country_list, Country valid_countries[], char continent_input[], unsigned long int population) {
    int counter = 0;
    int index;
    if (continent_input[0] == '\0') {
        for (index = 0; index < country_list->dynamicArray.length; index++)
            if (country_list->dynamicArray.data[index].population > population) {
                strcpy(valid_countries[counter].name, country_list->dynamicArray.data[index].name);
                strcpy(valid_countries[counter].continent, country_list->dynamicArray.data[index].continent);
                valid_countries[counter].population = country_list->dynamicArray.data[index].population;
                counter++; 
            }
    }
    else if (check_if_valid_continent(continent_input) == false) 
        return -1;
    else {
        for (index = 0; index < country_list->dynamicArray.length; index++)
            if (strcmp(country_list->dynamicArray.data[index].continent, continent_input) == 0) 
                if (country_list->dynamicArray.data[index].population > population) {
                    strcpy(valid_countries[counter].name, country_list->dynamicArray.data[index].name);
                    strcpy(valid_countries[counter].continent, country_list->dynamicArray.data[index].continent);
                    valid_countries[counter].population = country_list->dynamicArray.data[index].population;
                    counter++;
                }
    }
   
    Country temp; 
    for (int i = 0; i < counter - 1; i++)
        for (int j = 0; j < counter - i - 1; j++)
            if (valid_countries[j].population > valid_countries[j + 1].population) { // if the elements correspond, do the swapping
                temp = valid_countries[j];
                valid_countries[j] = valid_countries[j + 1];
                valid_countries[j + 1] = temp;
            }
    return counter;
}

int ServiceUndo(Repository* country_list, UndoRedoRepository* undo_redo_repo) {
    if (undo_redo_repo->length_undo == 0)
        return 1;
    addRedoElement(undo_redo_repo, country_list); // add the current repo for the redo operation
    popLastUndo(undo_redo_repo, country_list);
    return 0;
}

int ServiceRedo(Repository* country_list, UndoRedoRepository* undo_redo_repo) {
    if (undo_redo_repo->length_redo == 0)
        return 1;
    addUndoElement(undo_redo_repo, country_list); // add the current repo for the undo operation
    popLastRedo(undo_redo_repo, country_list);
    return 0;
}