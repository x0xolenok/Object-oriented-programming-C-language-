#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

class Rectangle {
private:
    double height; // First side of the rectangle
    double weight; // Second side of the rectangle
public:
    // Constructor for Rectangle class with 2 parameters (sides): (1 - width of the rectangle, 2 - height of the rectangle)
    Rectangle(double weight, double height) {
        this->weight = weight;
        this->height = height;
    }

    // Constructor for Rectangle class with 1 parameter (side): creates a square
    Rectangle(double side) {
        this->weight = side;
        this->height = side;
    }

    // Calculate the perimeter of the rectangle
    double perimeterOfRectangle() const {
        return weight + weight + height + height;
    }

    // Calculate the area of the rectangle
    double squareOfRectangle() const {
        return height * weight;
    }

    // Getter for the height
    double getHeight() const {
        return height;
    }

    // Getter for the weight
    double getWeight() const {
        return weight;
    }

    // Check if the rectangle is a square
    bool isSquare() const {
        return weight == height;
    }

    void print() const {
        cout << boolalpha << fixed << setprecision(5)
            << "The first side of Rectangle: " << this->weight << ".  "
            << "The second side of Rectangle: " << this->height
            << ". The area of Rectangle: " << this->squareOfRectangle()
            << ". The perimeter of Rectangle: " << this->perimeterOfRectangle()
            << ".  Is Rectangle a square: " << this->isSquare() << ".\n";
    }
};

int main() {

    Rectangle rectangle(6, 3);
    Rectangle* rectangle1 = new Rectangle(7);

    rectangle.print();
    rectangle1->print();

    // Create an array of 5 Rectangle objects, each with dynamically calculated dimensions
    Rectangle* rectangle2[5];
    for (int i = 0; i < 5; ++i) {
        // Calculate sides dynamically using mathematical functions (absolute value and square root)
        rectangle2[i] = new Rectangle(abs((i + 9) * sin(i + 9)), sqrt(abs((i + 9) * sin(i + 9))));
        rectangle2[i]->print();
    }

    return 0;
}
