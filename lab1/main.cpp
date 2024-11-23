#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    int** arr = NULL; // creating a double pointer
    int size; // variable for storing the size of the matrix
    int cap2, tmpcap; // variables for defining the boundaries of nullification
    int i, j, m; // loop variables
    srand(time(0)); // initializing the seed for generating random numbers

    std::cout << "Enter the size:" << std::endl; // getting the matrix size from the user
    std::cin >> size;

    arr = new int* [size]; // memory allocation for the matrix
    for (j = 0; j < size; j++) {
        arr[j] = new int[size];
    }

    for (j = 0; j < size; j++) { // initializing the matrix
        for (i = 0; i < size; i++) {
            arr[j][i] = rand() % 100;
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }

    cap2 = size / 2; // initializing the left boundary for nullification
    tmpcap = size - 1; // initializing the right boundary for nullification
    for (j = tmpcap, m = 1; (j > cap2 && m < tmpcap); j--, m++) { // loop to nullify elements
        for (i = m; i < tmpcap; i++) {
            arr[i][j] = 0;
        }
        tmpcap--;
    }

    cout << "New Matrix:" << endl;

    for (j = 0; j < size; j++) { // displaying the matrix with the nullified area
        for (i = 0; i < size; i++) {
            cout << arr[j][i] << "\t";
        }
        cout << endl;
    }

    for (i = 0; i < size; i++) {
        delete[] arr[i]; // deallocating memory for each row
    }

    delete[] arr; // deallocating memory for the array

    system("pause");
    return 0;
}
