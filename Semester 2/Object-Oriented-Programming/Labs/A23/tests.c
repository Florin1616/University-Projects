#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "tests.h"

//DOMAIN TESTS
void testDomain() {
    Country country1 = createCountry("Romania", "Europe", 100);
    assert(strcmp(country1.name, "Romania") == 0);
    assert(strcmp(country1.continent, "Europe") == 0);
    assert(country1.population == 100);
    Country country2 = createCountry("Moldova", "Europe", 100);
    assert(strcmp(country1.name, country2.name) != 0);
    assert(strcmp(country2.continent, "Africa") != 0);
    assert(country2.population != 200);
    assert(strcmp(getName(&country1), "Romania") == 0);
    assert(strcmp(getContinent(&country1), "Europe") == 0);
    assert(getPopulation(&country1) == 100);
    char str[100];
    toString(country1, str);
    assert(strcmp(str, "Country Romania is a country from Europe and its population is 100.") == 0);
}

//DYNAMIC ARRAY TESTS
void testDynamicArray() {
    DynamicArray dynamic_array = createDynamicArray(2);
    assert(dynamic_array.length == 0);
    assert(dynamic_array.capacity == 2);
    Country country1 = createCountry("Romania", "Europe", 100);
    addElement(&dynamic_array, country1);
    assert(dynamic_array.length == 1);
    Country country2 = createCountry("Moldova", "Europe", 100);
    addElement(&dynamic_array, country2);
    assert(dynamic_array.length == 2);
    Country country3 = createCountry("Ungaria", "Europe", 100);
    addElement(&dynamic_array, country3);
    assert(dynamic_array.length == 3);
    assert(dynamic_array.capacity == 4);
    deleteElement(&dynamic_array, 2);
    assert(dynamic_array.length == 2);
    assert(dynamic_array.capacity == 4);
    Country update = createCountry("Roumanie", "Europe", 200);
    updateElement(&dynamic_array, 1, update);
    assert(strcmp(dynamic_array.data[1].name, "Roumanie") == 0);
    assert(strcmp(dynamic_array.data[1].continent, "Europe") == 0);
    assert(dynamic_array.data[1].population == 200);
    assert(arrayCapacity(&dynamic_array) == 4);
    assert(arrayLength(&dynamic_array) == 2);
    destroyDynamicArray(&dynamic_array);
}

//REPOSITORY TESTS
void testRepository() {
    Repository repo = createRepository();
    assert(repo.dynamicArray.length == 10);
    assert(repo.dynamicArray.capacity == 10);
    Country country1 = createCountry("Romania", "Europe", 100);
    addCountry(&repo, country1);
    assert(repo.dynamicArray.length == 11);
    assert(repo.dynamicArray.capacity == 20);
    int index_ro = findByName(&repo, country1.name);
    assert(index_ro == 10);
    Country update = createCountry("Roumanie", "Europe", 200);
    updateCountry(&repo, index_ro, update);
    assert(strcmp(repo.dynamicArray.data[index_ro].name, "Roumanie") == 0);
    assert(strcmp(repo.dynamicArray.data[index_ro].continent, "Europe") == 0);
    assert(repo.dynamicArray.data[index_ro].population == 200);
    Country country2 = createCountry("Moldova", "Europe", 100);
    addCountry(&repo, country2);
    assert(repo.dynamicArray.length == 12);
    migrationUpdate(&repo, 11, 10, 100);
    assert(repo.dynamicArray.data[11].population == 0);
    assert(repo.dynamicArray.data[10].population == 300);
    deleteCountry(&repo, findByName(&repo, "Moldova"));
    assert(repo.dynamicArray.length == 11);
    destroyDynamicArray(&repo.dynamicArray);
}

//Undo Redo Repository tests
void testUndoRedoRepository() {
    UndoRedoRepository undo_redo = createUndoRedoRepo(1);
    assert(undo_redo.length_undo == 0);
    assert(undo_redo.length_redo == 0);
    assert(undo_redo.capacity_undo == 1);
    assert(undo_redo.capacity_redo == 1);
    Repository repo = createRepository();
    addUndoElement(&undo_redo, &repo);
    assert(undo_redo.length_undo == 1);
    Country c1 = createCountry("Romania", "Europe", 100);
    addCountry(&repo, c1);
    addRedoElement(&undo_redo, &repo);
    assert(undo_redo.length_redo == 1);
    addUndoElement(&undo_redo, &repo);
    assert(undo_redo.length_undo == 2);
    assert(undo_redo.capacity_undo == 2);
    addRedoElement(&undo_redo, &repo);
    assert(undo_redo.length_redo == 2);
    assert(undo_redo.capacity_redo == 2);
    popLastUndo(&undo_redo, &repo);
    assert(undo_redo.length_undo == 1);
    popLastRedo(&undo_redo, &repo);
    assert(undo_redo.length_redo == 1);
    destroyDynamicArray(&repo.dynamicArray);
    free(undo_redo.undo);
    free(undo_redo.redo);
}

void testService() {
    UndoRedoRepository undo_redo = createUndoRedoRepo(10);
    Repository repo = createRepository();
    bool valid = check_if_valid_continent("Europe");
    assert(valid == true);
    valid = check_if_valid_continent("Eu");
    assert(valid == false);
    int undone = ServiceUndo(&repo, &undo_redo);
    int redone = ServiceRedo(&repo, &undo_redo);
    assert(undone == 1);
    assert(redone == 1);
    int added = add_country(&repo, &undo_redo, "Bulgaria", "Europe", 100);
    assert(added == 1);
    added = add_country(&repo, &undo_redo, "Romania", "Europa", 100);
    assert(added == 2);
    added = add_country(&repo, &undo_redo, "Romania", "Europe", 100);
    assert(added == 0);
    bool deleted = delete_country(&repo, &undo_redo, "Moldova");
    assert(deleted == false);
    deleted = delete_country(&repo, &undo_redo, "Romania");
    assert(deleted == true);
    undone = ServiceUndo(&repo, &undo_redo);
    assert(undone == 0);
    redone = ServiceRedo(&repo, &undo_redo);
    assert(redone == 0);
    ServiceUndo(&repo, &undo_redo);
    int updated = update_country(&repo, &undo_redo, "USA", "SUA", "America", 100);
    assert(updated == 1);
    updated = update_country(&repo, &undo_redo, "Romania", "Roumanie", "Mars", 100);
    assert(updated == 2);
    updated = update_country(&repo, &undo_redo, "Romania", "Roumanie", "Europe", 100);
    assert(updated == 0);
    updated = update_country(&repo, &undo_redo, "Roumanie", "Romania", "Europe", 1000);
    assert(updated == 0);
    added = add_country(&repo, &undo_redo, "Moldova", "Europe", 100);
    assert(added == 0);
    int migrated = migration(&repo, &undo_redo, "Moldova", "Romania", 100);
    assert(migrated == 0);
    migrated = migration(&repo, &undo_redo, "Moldova", "Roumanie", 100);
    assert(migrated == 2);
    migrated = migration(&repo, &undo_redo, "Moldove", "Romania", 100);
    assert(migrated == 1);
    char filter_string1[] = "\0";
    Country* valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    int filter = filter_country(&repo, filter_string1, valid_countries);
    assert(filter == repo.dynamicArray.length);
    free(valid_countries);
    valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    filter = filter_country(&repo, "z", valid_countries);
    assert(filter == 0);
    free(valid_countries);
    valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    filter = filter_country(&repo, "Ro", valid_countries);
    assert(filter == 1);
    free(valid_countries);
    valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    int filter_sort = filter_sort_continent(&repo, valid_countries, filter_string1, 0);
    assert(filter_sort == repo.dynamicArray.length - 1);
    updated = update_country(&repo, &undo_redo, "Moldova", "Moldova", "Europe", 100);
    free(valid_countries);
    valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    filter_sort = filter_sort_continent(&repo, valid_countries, filter_string1, 0);
    assert(filter_sort == repo.dynamicArray.length);
    free(valid_countries);
    valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    filter_sort = filter_sort_continent(&repo, valid_countries, "EU", 0);
    assert(filter_sort == -1);
    free(valid_countries);
    valid_countries = (Country*)malloc(repo.dynamicArray.capacity * sizeof(Country));
    filter_sort = filter_sort_continent(&repo, valid_countries, "Asia", 100000);
    assert(filter_sort == 2);
    assert(valid_countries[0].population < valid_countries[1].population);
    free(valid_countries);
}


void testAll() {
    testDomain();
    testDynamicArray();
    testRepository();
    testUndoRedoRepository();
    testService();
}