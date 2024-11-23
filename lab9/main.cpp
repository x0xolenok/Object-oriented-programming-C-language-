#include <iostream>
#include <math.h>

#define PI 3.14159265 // Pi constant

// Base class Figure
class Figure
{
protected:

public:
    // Method to calculate area (pure virtual function)
    virtual float get_area() const = 0;

    // Method to calculate perimeter (pure virtual function)
    virtual float get_perimeter() const = 0;

    // Method to output information about the figure (pure virtual function)
    virtual void output_info() const = 0;
};

// Rectangle class derived from Figure
class Rectangle : public Figure
{
private:
    float m_Length; // Length of the rectangle
    float m_Height; // Height of the rectangle

public:
    // Default constructor
    Rectangle();

    // Constructor with parameters
    Rectangle(const float& otherLength, const float& otherHeight);

    // Setters and getters for length and height
    void set_length(const float& otherLength);
    void set_height(const float& otherHeight);

    float get_length() const;
    float get_height() const;

    // Override methods for area, perimeter, and output information
    float get_area() const override;
    float get_perimeter() const override;
    void output_info() const override;
};

// Default constructor implementation
Rectangle::Rectangle()
{
    this->m_Length = 0;
    this->m_Height = 0;
}

// Constructor with parameters implementation
Rectangle::Rectangle(const float& otherLength, const float& otherHeight) : Rectangle::Rectangle()
{
    if (otherLength > 0)
    {
        this->m_Length = otherLength;
    }
    if (otherHeight > 0)
    {
        this->m_Height = otherHeight;
    }
}

// Setter for length
void Rectangle::set_length(const float& otherLength)
{
    if (otherLength > 0)
    {
        this->m_Length = otherLength;
    }
}

// Setter for height
void Rectangle::set_height(const float& otherHeight)
{
    if (otherHeight > 0)
    {
        this->m_Height = otherHeight;
    }
}

// Getter for length
float Rectangle::get_length() const
{
    return this->m_Length;
}

// Getter for height
float Rectangle::get_height() const
{
    return this->m_Height;
}

// Method to calculate the area of the rectangle
float Rectangle::get_area() const
{
    return this->m_Height * this->m_Length;
}

// Method to calculate the perimeter of the rectangle
float Rectangle::get_perimeter() const
{
    return this->m_Height * 2 + this->m_Length * 2;
}

// Method to output rectangle information
void Rectangle::output_info() const
{
    std::cout << "     Rectangle info:" << std::endl;
    std::cout << "Length:    " << this->m_Length << std::endl;
    std::cout << "Height:    " << this->m_Height << std::endl;
    std::cout << "Area:      " << this->get_area() << std::endl;
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

// Triangle class derived from Figure
class Trianle : public Figure
{
private:
    float m_FirstSide;    // First side of the triangle
    float m_SecondSide;   // Second side of the triangle
    float m_ThirdSide;    // Third side of the triangle

public:
    // Default constructor
    Trianle();

    // Constructor with parameters
    Trianle(const float& otherFirst, const float& otherSecond, const float& otherThird);

    // Setters and getters for the sides
    void set_firstSide(const float& otherFirst);
    void set_secondSide(const float& otherSecond);
    void set_thirdSide(const float& otherThird);

    float get_firstSide() const;
    float get_secondSide() const;
    float get_thirdSide() const;

    // Override methods for area, perimeter, and output information
    float get_area() const override;
    float get_perimeter() const override;
    void output_info() const override;
};

// Default constructor implementation
Trianle::Trianle()
{
    this->m_FirstSide = 0;
    this->m_SecondSide = 0;
    this->m_ThirdSide = 0;
}

// Constructor with parameters implementation
Trianle::Trianle(const float& otherFirst, const float& otherSecond, const float& otherThird) : Trianle::Trianle()
{
    if (otherFirst > 0)
    {
        this->m_FirstSide = otherFirst;
    }
    if (otherSecond > 0)
    {
        this->m_SecondSide = otherSecond;
    }
    if (otherThird > 0)
    {
        this->m_ThirdSide = otherThird;
    }
}

// Setter for the first side
void Trianle::set_firstSide(const float& otherFirst)
{
    if (otherFirst > 0)
    {
        this->m_FirstSide = otherFirst;
    }
}

// Setter for the second side
void Trianle::set_secondSide(const float& otherSecond)
{
    if (otherSecond > 0)
    {
        this->m_SecondSide = otherSecond;
    }
}

// Setter for the third side
void Trianle::set_thirdSide(const float& otherThird)
{
    if (otherThird > 0)
    {
        this->m_ThirdSide = otherThird;
    }
}

// Getter for the first side
float Trianle::get_firstSide() const
{
    return this->m_FirstSide;
}

// Getter for the second side
float Trianle::get_secondSide() const
{
    return this->m_SecondSide;
}

// Getter for the third side
float Trianle::get_thirdSide() const
{
    return this->m_ThirdSide;
}

// Method to calculate the area of the triangle using Heron's formula
float Trianle::get_area() const
{
    float p = 0.5 * this->get_perimeter();
    return sqrt(p * (p - this->m_FirstSide) * (p - this->m_SecondSide) * (p - this->m_ThirdSide));
}

// Method to calculate the perimeter of the triangle
float Trianle::get_perimeter() const
{
    return this->m_FirstSide + this->m_SecondSide + this->m_ThirdSide;
}

// Method to output triangle information
void Trianle::output_info() const
{
    std::cout << "     Trianle info:" << std::endl;
    std::cout << "First side:  " << this->m_FirstSide << std::endl;
    std::cout << "Second side: " << this->m_SecondSide << std::endl;
    std::cout << "Third side:  " << this->m_ThirdSide << std::endl;
    std::cout << "Area:        " << this->get_area() << std::endl;
    std::cout << "Perimeter:   " << this->get_perimeter() << std::endl;
}

// Circle class derived from Figure
class Circle : public Figure
{
private:
    float m_Radius; // Radius of the circle

public:
    // Default constructor
    Circle();

    // Constructor with parameters
    Circle(const float& otherRadius);

    // Setter and getter for the radius
    void set_radius(const float& otherRadius);
    float get_radius() const;

    // Override methods for area, perimeter, and output information
    float get_area() const override;
    float get_perimeter() const override;
    void output_info() const override;
};

// Default constructor implementation
Circle::Circle()
{
    this->m_Radius = 0;
}

// Constructor with parameters implementation
Circle::Circle(const float& otherRadius) : Circle::Circle()
{
    if (otherRadius > 0)
    {
        this->m_Radius = otherRadius;
    }
}

// Setter for the radius
void Circle::set_radius(const float& otherRadius)
{
    if (otherRadius > 0)
    {
        this->m_Radius = otherRadius;
    }
}

// Getter for the radius
float Circle::get_radius() const
{
    return this->m_Radius;
}

// Method to calculate the area of the circle
float Circle::get_area() const
{
    return PI * this->m_Radius * this->m_Radius;
}

// Method to calculate the perimeter (circumference) of the circle
float Circle::get_perimeter() const
{
    return 2 * PI * this->m_Radius;
}

// Method to output circle information
void Circle::output_info() const
{
    std::cout << "     Circle info:" << std::endl;
    std::cout << "Radius:    " << this->m_Radius << std::endl;
    std::cout << "Area:      " << this->get_area() << std::endl;
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}

// Main function
int main()
{
    int size = 3; // Array size
    Figure** figures = new Figure * [size]; // Array of pointers to the base class Figure

    // Initialize the array with objects of different shapes
    figures[0] = new Rectangle(33, 44);
    figures[1] = new Trianle(2, 3, 4);
    figures[2] = new Circle(9);

    // Output the information for each figure
    for (int i = 0; i < size; ++i)
    {
        figures[i]->output_info();
        std::cout << std::endl;
    }

    // Cleanup dynamically allocated memory
    for (int i = 0; i < size; ++i)
    {
        delete figures[i];
    }
    delete[] figures; // Delete the array of pointers

    return 0;
}
