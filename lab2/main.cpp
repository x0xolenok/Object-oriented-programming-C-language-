#include <iostream>
#include <cstring>

using namespace std;

#define N 100

// Enum to represent swimming styles
enum Styles {
    freestyle,   // Freestyle
    backstroke,  // Backstroke
    breaststroke, // Breaststroke
    butterfly     // Butterfly
};

// Structure to store the date of the championship
struct Date {
    int year;
    int month;
    int day;
};

// Structure to store the venue of the championship (country and city)
struct Venue {
    char country[20];
    char city[20];
};

// Structure to store information about a swimmer
struct Swimmer {
    char name[30];             // Swimmer's name
    enum Styles style;         // Swimming style
    float record;              // Record time for the event
    int nationality;           // Swimmer's nationality (represented by an integer)
    char team[20];             // Swimmer's team
    char coach[20];            // Coach's name
    int count_of_swims;        // Number of swims the swimmer has participated in
};

// Structure to store all information about the championship
struct Information {
    Date n[N];                 // Array of dates for the championship
    Venue m[N];                // Array of venues (countries and cities)
    Swimmer s[N];              // Array of swimmers participating in the championship
    int swimmer_count;         // Total number of swimmers
};

// Function to print the date of the championship
void print_date(Information& inf) {
    for (int i = 0; i < inf.swimmer_count; i++) {
        cout << "Championship Date: " << inf.n[i].day << "/"
             << inf.n[i].month << "/" << inf.n[i].year << endl;
    }
}

// Function to print the venue (country and city) of the championship
void print_place(Information& inf) {
    for (int i = 0; i < inf.swimmer_count; i++) {
        cout << "Championship Venue: " << inf.m[i].city << ", " << inf.m[i].country << endl;
    }
}

// Function to print information about a participant (swimmer)
void print_participant(Information& inf, int index) {
    if (index >= 0 && index < inf.swimmer_count) {
        cout << "Swimmer: " << inf.s[index].name << endl;
        cout << "Style: " << inf.s[index].style << endl;  // Style is printed as an integer (enum value)
        cout << "Record: " << inf.s[index].record << endl;
        cout << "Nationality: " << inf.s[index].nationality << endl;
        cout << "Team: " << inf.s[index].team << endl;
        cout << "Coach: " << inf.s[index].coach << endl;
        cout << "Count of swims: " << inf.s[index].count_of_swims << endl;
    }
}

// Function to check if a swimmer can participate in the championship
// The swimmer's participation is checked based on their record and number of swims
bool check_info(Information& inf, int index) {
    if (index < 0 || index >= inf.swimmer_count) {
        return false; // Index out of range
    }

    // Example check: If the swimmer's record is greater than 50 seconds, they cannot participate
    if (inf.s[index].record > 50) {
        return false;
    }

    // Example check: If the swimmer has participated in more than 5 swims, they cannot participate
    if (inf.s[index].count_of_swims > 5) {
        return false;
    }

    return true;  // Swimmer can participate
}

// Function to add a swimmer to the championship
void add_swimmer(Information& inf, const Swimmer& swimmer) {
    if (inf.swimmer_count < N) {
        inf.s[inf.swimmer_count] = swimmer;  // Add swimmer to the array
        inf.swimmer_count++;  // Increment the number of swimmers
    } else {
        cout << "Cannot add swimmer: The team is full!" << endl;
    }
}

int main() {
    Information championship;  // Structure holding all information about the championship
    championship.swimmer_count = 0;  // Initially, no swimmers are added

    // Creating swimmer objects
    Swimmer swimmer1 = {"Michael Phelps", freestyle, 47.52, 1, "USA", "Bob Bowman", 3};
    Swimmer swimmer2 = {"Katie Ledecky", freestyle, 53.13, 1, "USA", "Gregg Troy", 4};

    // Adding swimmers to the championship
    add_swimmer(championship, swimmer1);
    add_swimmer(championship, swimmer2);

    // Printing information about each swimmer
    for (int i = 0; i < championship.swimmer_count; i++) {
        print_participant(championship, i);  // Print swimmer details
        if (check_info(championship, i)) {
            cout << "Swimmer can participate in the championship!" << endl;
        } else {
            cout << "Swimmer cannot participate in the championship." << endl;
        }
        cout << endl;
    }

    // Printing the championship date and venue
    print_date(championship);
    print_place(championship);

    return 0;
}
