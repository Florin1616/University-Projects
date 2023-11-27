#include <stdlib.h>
#include "dynamicarray.h"

DynamicArray createDynamicArray(int capacity) {
    DynamicArray array;
    array.data = (Country*)malloc(capacity * sizeof(Country));
    array.length = 0;
    array.capacity = capacity;
    return array;
}

void destroyDynamicArray(DynamicArray* array) {
    free(array->data);
}

void addElement(DynamicArray* array, Country element) {
    if (array->length == array->capacity) // if the data array is full we need to resize the array
        resizeDynamicArray(array);
    array->data[array->length] = element;
    array->length++;
}

void deleteElement(DynamicArray* array, int delete_index) {
    int index;
    for (index = delete_index; index < array->length; index++)
        array->data[index] = array->data[index + 1]; // move one position to the left all the elements after the one that has to be deleted
    array->length--;
}

void updateElement(DynamicArray* array, int update_index, Country update_element) {
    array->data[update_index] = update_element;
}

void resizeDynamicArray(DynamicArray* array) {
    Country* new_data = (Country*)malloc(array->length * 2 * sizeof(Country));
    int index;
    for (index = 0; index < array->length; index++) {
        new_data[index] = array->data[index];
    }
    free(array->data);
    array->data = new_data;
    array->capacity *= 2;
}

int arrayCapacity(DynamicArray* array) {
    return array->capacity;
}

int arrayLength(DynamicArray* array) {
    return array->length;
}