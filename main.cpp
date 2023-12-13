#include <iostream>
#include "array_library.h" //only the header file. not the .cpp EVER
#include <sstream>

using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

int main() {
    int data[] = {7, 4, 1, 9, 0, 11, 21, 3, 8, 5};
    const unsigned int SIZE = sizeof(data) / sizeof(data[0]);

    int position = LinearSearch(data, SIZE, 8);
    cout << "9 found in position " << position << endl;
    int max = FindMax(data, SIZE);
    cout << "Max: " << max << endl;
    int min = FindMin(data, SIZE);
    cout << "Min: " << min << endl;
    double average = FindAverage(data, SIZE);
    cout << "Average: " << average << endl;
    assert(LinearSearch(data, SIZE, 7) == 0);
    assert(LinearSearch(data, SIZE, 4) == 1);
    assert(LinearSearch(data, SIZE, 1) == 2);
    assert(LinearSearch(data, SIZE, 9) == 3);
    assert(LinearSearch(data, SIZE, 0) == 4);
    assert(LinearSearch(data, SIZE, 11) == 5);
    assert(LinearSearch(data, SIZE, 21) == 6);
    assert(LinearSearch(data, SIZE, 3) == 7);
    assert(LinearSearch(data, SIZE, 8) == 8);
    assert(LinearSearch(data, SIZE, 5) == 9);
    assert(LinearSearch(data, SIZE, 100) == -1);

    assert(BinarySearch(data, SIZE, 0) == 0);
    assert(BinarySearch(data, SIZE, 1) == 1);
    assert(BinarySearch(data, SIZE, 3) == 2);
    assert(BinarySearch(data, SIZE, 4) == 3);
    assert(BinarySearch(data, SIZE, 5) == 4);
    assert(BinarySearch(data, SIZE, 7) == 5);
    assert(BinarySearch(data, SIZE, 8) == 6);
    assert(BinarySearch(data, SIZE, 9) == 7);
    assert(BinarySearch(data, SIZE, 11) == 8);
    assert(BinarySearch(data, SIZE, 21) == 9);

    assert(FindMax(data, SIZE) == 21);
    assert(FindMin(data, SIZE) == 0);
    assert(FindAverage(data, SIZE) == 6.9);
    assert(FindAverage(data, SIZE) - 6.9 < 0.00000001);

    stringstream input ("0 7 2 8 1 10 6 11 9 3");
    ReadArray(input, data, SIZE);
    assert(data[0] == 0);
    assert(data[1] == 7);
    assert(data[2] == 2);
    assert(data[3] == 8);
    assert(data[4] == 1);
    assert(data[5] == 10);
    assert(data[6] == 6);
    assert(data[7] == 11);
    assert(data[8] == 9);
    assert(data[9] == 3);
    stringstream output;
    PrintArray(output, data, SIZE);
    assert(output.str() == "0 7 2 8 1 10 6 11 9 3 ");

    cout << "Tests passed" << endl;

    return 0;
}
