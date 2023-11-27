#include <stdlib.h>
#include "undoredorepository.h"

UndoRedoRepository createUndoRedoRepo(int capacity) {
    UndoRedoRepository undo_redo_repository;
    undo_redo_repository.undo = (Repository*)malloc(capacity * sizeof(Repository)); // allocate space for the undo list
    undo_redo_repository.length_undo = 0;
    undo_redo_repository.capacity_undo = capacity;
    undo_redo_repository.redo = (Repository*)malloc(capacity * sizeof(Repository)); // allocate space for the redo list
    undo_redo_repository.length_redo = 0;
    undo_redo_repository.capacity_redo = capacity;
    return undo_redo_repository;
}

void destroyUndoRedoRepository(UndoRedoRepository* undo_redo_repo) {
    int index;
    for (index = 0; index < undo_redo_repo->length_redo; index++)
        free(undo_redo_repo->redo[index].dynamicArray.data); // deallocate all the arrays in the array redo
    free(undo_redo_repo->redo); // deallocate the redo array
    for (index = 0; index < undo_redo_repo->length_undo; index++)
        free(undo_redo_repo->undo[index].dynamicArray.data); // deallocate all the arrays in the array undo
    free(undo_redo_repo->undo);// deallocate the undo array
}

void addUndoElement(UndoRedoRepository* undo_redo_repo, Repository* repo) {
    if (undo_redo_repo->length_undo == undo_redo_repo->capacity_undo)
        resizeArrayUndo(undo_redo_repo);
    undo_redo_repo->undo[undo_redo_repo->length_undo].dynamicArray.data = (Country*)malloc(repo->dynamicArray.capacity * sizeof(Country));
    for (int index = 0; index < repo->dynamicArray.length; index++)
        undo_redo_repo->undo[undo_redo_repo->length_undo].dynamicArray.data[index] = repo->dynamicArray.data[index];
    undo_redo_repo->undo[undo_redo_repo->length_undo].dynamicArray.length = repo->dynamicArray.length;
    undo_redo_repo->undo[undo_redo_repo->length_undo].dynamicArray.capacity = repo->dynamicArray.capacity;
    undo_redo_repo->length_undo++;
}

void addRedoElement(UndoRedoRepository* undo_redo_repo, Repository* repo) {
    if (undo_redo_repo->length_redo == undo_redo_repo->capacity_redo)
        resizeArrayRedo(undo_redo_repo);
    undo_redo_repo->redo[undo_redo_repo->length_redo].dynamicArray.data = (Country*)malloc(repo->dynamicArray.capacity * sizeof(Country));
    for (int index = 0; index < repo->dynamicArray.length; index++)
        undo_redo_repo->redo[undo_redo_repo->length_redo].dynamicArray.data[index] = repo->dynamicArray.data[index];
    undo_redo_repo->redo[undo_redo_repo->length_redo].dynamicArray.length = repo->dynamicArray.length;
    undo_redo_repo->redo[undo_redo_repo->length_redo].dynamicArray.capacity = repo->dynamicArray.capacity;
    undo_redo_repo->length_redo++;
}

void popLastUndo(UndoRedoRepository* undo_redo_repo, Repository* repo) {
    free(repo->dynamicArray.data); // free the current repo
    //copy the elements
    repo->dynamicArray.data = undo_redo_repo->undo[undo_redo_repo->length_undo - 1].dynamicArray.data;
    repo->dynamicArray.length = undo_redo_repo->undo[undo_redo_repo->length_undo - 1].dynamicArray.length;
    repo->dynamicArray.capacity = undo_redo_repo->undo[undo_redo_repo->length_undo - 1].dynamicArray.capacity;
    Repository* temporary;
    temporary = (Repository*)malloc(undo_redo_repo->capacity_undo * sizeof(Repository));
    for (int index = 0; index < undo_redo_repo->length_undo - 1; index++)
        temporary[index] = undo_redo_repo->undo[index];
    free(undo_redo_repo->undo);
    undo_redo_repo->undo = temporary;
    undo_redo_repo->length_undo--;
}

void popLastRedo(UndoRedoRepository* undo_redo_repo, Repository* repo) {
    free(repo->dynamicArray.data); // free the current repo
    //copy the elements
    repo->dynamicArray.data = undo_redo_repo->redo[undo_redo_repo->length_redo - 1].dynamicArray.data;
    repo->dynamicArray.length = undo_redo_repo->redo[undo_redo_repo->length_redo - 1].dynamicArray.length;
    repo->dynamicArray.capacity = undo_redo_repo->redo[undo_redo_repo->length_redo - 1].dynamicArray.capacity;
    Repository* temporary;
    temporary = (Repository*)malloc(undo_redo_repo->capacity_redo * sizeof(Repository));
    for (int index = 0; index < undo_redo_repo->length_redo - 1; index++)
        temporary[index] = undo_redo_repo->redo[index];
    free(undo_redo_repo->redo);
    undo_redo_repo->redo = temporary;
    undo_redo_repo->length_redo--;
}

void resizeArrayUndo(UndoRedoRepository* undo_redo_repo) {
    Repository* temporary;
    temporary = (Repository*)malloc(undo_redo_repo->capacity_undo * 2 * sizeof(Repository));
    for (int index = 0; index < undo_redo_repo->length_undo - 1; index++)
        temporary[index] = undo_redo_repo->undo[index];
    free(undo_redo_repo->undo);
    undo_redo_repo->undo = temporary;
    undo_redo_repo->capacity_undo *= 2;
}

void resizeArrayRedo(UndoRedoRepository* undo_redo_repo) {
    Repository* temporary;
    temporary = (Repository*)malloc(undo_redo_repo->capacity_redo * 2 * sizeof(Repository));
    for (int index = 0; index < undo_redo_repo->length_redo - 1; index++)
        temporary[index] = undo_redo_repo->redo[index];
    free(undo_redo_repo->redo);
    undo_redo_repo->redo = temporary;
    undo_redo_repo->capacity_redo *= 2;
}