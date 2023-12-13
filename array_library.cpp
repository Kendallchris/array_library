//
// Created by Chris Kendall on 10/5/22.
//

#include "array_library.h"
// #include <> means it will search within the C++ directory, not the current directory this file is in

int LinearSearch(int array[], unsigned int size, int key) {
    for (int i = 0; i < size; i++) {
        if (array[i] == key) {
            return i;
        }
    }
    return -1;
}

int FindMax(int array[], unsigned int size){
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

int FindMin(int array[], unsigned int size){
    int min = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] < min) {
            min = array[i];
        }
    }
    return min;
}

double FindAverage(int array[], unsigned int size){
    double sum = 0.0;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

unsigned int MinimumPosition(int array[], unsigned int size, unsigned int startPosition){
    int minimum = array[startPosition];
    unsigned int minimumPosition = startPosition;
    for (int i = startPosition; i < size; ++i) {
        if (minimum > array[i]){
            minimum = array[i];
            minimumPosition = i;
        }
    }
    return minimumPosition;
}

void Swap(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}

void SelectionSort(int array[], unsigned int size){
    unsigned int temp;
    for (int i = 0; i < size; i++) {
        temp = MinimumPosition(array, size, i);
        Swap(array[i], array[temp]);
    }
}
/**
 * To study:
 * 1. Binary search here
 * 2. on other program make function to calc student, course, class average
 * 3. Display it beautifully
 * DO THIS AT HOME (IF I WANT)
 * @param array
 * @param size
 * @param key
 * @return
 */
int BinarySearch(int array[], unsigned int size, int key){ //array must be sorted for this to work
    SelectionSort(array, size);
    unsigned int start = 0;
    unsigned int end = size - 1;
    unsigned int x = 1;
    while (x == 1) {
        if (start <= end) {
            int mid = (start + end) / 2;
            if (array[mid] == key)
                return mid;
            if (array[mid] > key)
                end = end - 1;
            if (array[mid] < key)
                end = end + 1;
        } else {
            x = 0;
        }
    }
    return -1;
}

void PrintArray(ostream& output, int array[], unsigned int size){
    for (int i = 0; i < size; ++i) {
        output << array[i] << " ";
    }
}

void ReadArray(istream& input, int array[], unsigned int size){
    for (int i = 0; i < size; ++i) {
        input >> array[i];
    }
}




