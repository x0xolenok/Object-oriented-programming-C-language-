#include <iostream>
#include <string>
using namespace std;

// Driver struct stores information about a driver
struct Driver {
    string surname;
    int year;
    float mark;
};

// Typedef for better readability
typedef Driver* tdriver;

// Overloaded input functions with default parameters
void inputdriver(Driver& driver, string surname = "Ivanov", int year = 1, float mark = 4.0f);  // All default values
void inputdriver(Driver& driver, int year, float mark = 4.0f);  // Default surname "Ivanov"
void inputdriver(Driver& driver, float mark, string surname = "Ivanov");  // Default year = 1

// Function to output the driver information
void output(tdriver drivers, int size);

int main() {
    // Dynamically allocate memory for 8 drivers
    Driver* drivers = new Driver[8];

    string surname = "Sergeev";
    int year = 2;
    float mark = 3.0f;

    // Populate the drivers array using different combinations of parameters
    inputdriver(drivers[0]);  // Default values
    inputdriver(drivers[1], surname);  // Default year, default mark
    inputdriver(drivers[2], surname, year);  // Default mark
    inputdriver(drivers[3], surname, year, mark);  // No defaults
    inputdriver(drivers[4], mark);  // Default surname, default year
    inputdriver(drivers[5], year);  // Default surname, default mark
    inputdriver(drivers[6], mark, surname);  // Default year
    inputdriver(drivers[7], year, mark);  // Default surname

    // Output all drivers' information
    output(drivers, 8);

    // Deallocate dynamically allocated memory
    delete[] drivers;
    return 0;
}

// Function definitions for the overloaded inputdriver functions
void inputdriver(Driver& driver, string surname, int year, float mark) {
    driver.surname = surname;
    driver.year = year;
    driver.mark = mark;
}

void inputdriver(Driver& driver, int year, float mark) {
    driver.surname = "Ivanov";  // Default surname
    driver.year = year;
    driver.mark = mark;
}

void inputdriver(Driver& driver, float mark, string surname) {
    driver.surname = surname;
    driver.year = 1;  // Default year
    driver.mark = mark;
}

// Function to output the details of all drivers
void output(tdriver drivers, int size) {
    for (int i = 0; i < size; i++) {
        cout << "Surname: " << drivers[i].surname
             << " Year: " << drivers[i].year
             << " Mark: " << drivers[i].mark << endl;
    }
}
