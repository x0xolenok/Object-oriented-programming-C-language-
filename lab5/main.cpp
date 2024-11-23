#include <iostream>
#include <cstring>

using namespace std;

#define N 100

// Enumeration to define different swimming styles
enum Styles {
    freestyle,
    backstroke,
    breaststroke,
    butterfly
};

// Class to store championship date
class Date {
public:
    int year;
    int month;
    int day;

    // Constructor to initialize the date
    Date(int y = 0, int m = 0, int d = 0) : year(y), month(m), day(d) {}

    // Method to print the date
    void print_date() const {
        cout << "Championship Date: " << day << "/" << month << "/" << year << endl;
    }
};

// Class to store the venue information
class Venue {
public:
    char country[20];
    char city[20];

    // Constructor to initialize the venue information
    Venue(const char* c = "", const char* ci = "") {
        strcpy(country, c);
        strcpy(city, ci);
    }

    // Method to print the venue information
    void print_place() const {
        cout << "Championship Venue: " << city << ", " << country << endl;
    }
};

// Class to store swimmer information
class Swimmer {
public:
    char name[30];
    enum Styles style;
    float record;
    int nationality;
    char team[20];
    char coach[20];
    int count_of_swims;

    // Constructor to initialize swimmer information
    Swimmer(const char* n = "", Styles st = freestyle, float r = 0.0f, int nat = 0, const char* t = "", const char* c = "", int swims = 0) {
        strcpy(name, n);
        style = st;
        record = r;
        nationality = nat;
        strcpy(team, t);
        strcpy(coach, c);
        count_of_swims = swims;
    }

    // Method to print swimmer details
    void print_participant() const {
        cout << "Swimmer: " << name << endl;
        cout << "Style: " << style << endl;
        cout << "Record: " << record << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Team: " << team << endl;
        cout << "Coach: " << coach << endl;
        cout << "Count of swims: " << count_of_swims << endl;
    }

    // Method to check if the swimmer can participate in the competition
    bool can_participate() const {
        if (record > 50) { // If the record time is more than 50 seconds, swimmer is not allowed
            return false;
        }
        if (count_of_swims > 5) { // If the swimmer has participated in more than 5 events, they are not allowed
            return false;
        }
        return true;
    }
};

// Class to manage championship details, including swimmers, dates, and venues
class Championship {
public:
    Date dates[N];           // Array to store championship dates
    Venue venues[N];         // Array to store championship venues
    Swimmer swimmers[N];     // Array to store swimmer information
    int swimmer_count;       // Number of swimmers in the competition

    // Constructor to initialize the championship
    Championship() : swimmer_count(0) {}

    // Method to add a swimmer to the championship
    void add_swimmer(const Swimmer& swimmer) {
        if (swimmer_count < N) {
            swimmers[swimmer_count] = swimmer;
            swimmer_count++;
        } else {
            cout << "Cannot add swimmer: The team is full!" << endl;
        }
    }

    // Method to print the championship dates
    void print_date() const {
        for (int i = 0; i < swimmer_count; i++) {
            dates[i].print_date();
        }
    }

    // Method to print the championship venues
    void print_place() const {
        for (int i = 0; i < swimmer_count; i++) {
            venues[i].print_place();
        }
    }

    // Method to print swimmer details and check their participation
    void print_participant(int index) const {
        if (index >= 0 && index < swimmer_count) {
            swimmers[index].print_participant();
            if (swimmers[index].can_participate()) {
                cout << "Swimmer can participate in the championship!" << endl;
            } else {
                cout << "Swimmer cannot participate in the championship." << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    Championship championship;

    // Creating swimmers
    Swimmer swimmer1("Michael Phelps", freestyle, 47.52, 1, "USA", "Bob Bowman", 3);
    Swimmer swimmer2("Katie Ledecky", freestyle, 53.13, 1, "USA", "Gregg Troy", 4);

    // Adding swimmers to the championship
    championship.add_swimmer(swimmer1);
    championship.add_swimmer(swimmer2);

    // Printing information about participants and their participation status
    for (int i = 0; i < championship.swimmer_count; i++) {
        championship.print_participant(i);
    }

    // Printing championship dates and places
    championship.print_date();
    championship.print_place();

    return 0;
}
