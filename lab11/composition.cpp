#include <iostream>

struct Point // Helper structure for a point
{
    int X = 0;
    int Y = 0;
};

class Rectangle // Rectangle class
{
private:
    Point m_Position; // Position of the rectangle
    int m_XSize; // X size
    int m_YSize; // Y size

public:
    Rectangle(); // Default constructor
    Rectangle(const Point otherPosition, const int otherXSize, const int otherYSize); // Constructor with parameters

    void set_position(const Point otherPosition); // Set position
    void set_size(const int otherXSize, const int otherYSize); // Set size

    Point get_position() const; // Get position
    int get_XSize() const; // Get X size
    int get_YSize() const; // Get Y size

    // Methods for area and perimeter
    int get_area() const; // Get area
    int get_perimeter() const; // Get perimeter
};

// Implementation of Rectangle methods
Rectangle::Rectangle()
{
    this->m_XSize = 0;
    this->m_YSize = 0;
}

Rectangle::Rectangle(const Point otherPosition, const int otherXSize, const int otherYSize)
    : m_Position(otherPosition), m_XSize(otherXSize), m_YSize(otherYSize) {}

void Rectangle::set_position(const Point otherPosition)
{
    this->m_Position = otherPosition;
}

void Rectangle::set_size(const int otherXSize, const int otherYSize)
{
    if (otherXSize >= 0 && otherYSize >= 0)
    {
        this->m_XSize = otherXSize;
        this->m_YSize = otherYSize;
    }
}

Point Rectangle::get_position() const
{
    return this->m_Position;
}

int Rectangle::get_XSize() const
{
    return this->m_XSize;
}

int Rectangle::get_YSize() const
{
    return this->m_YSize;
}

// Implementation of area and perimeter methods
int Rectangle::get_area() const
{
    return this->m_XSize * this->m_YSize;
}

int Rectangle::get_perimeter() const
{
    return 2 * (this->m_XSize + this->m_YSize);
}

class Window
{
private:
    Rectangle m_Rect; // Rectangle object (composition)

public:
    Window(); // Default constructor
    Window(const Point otherPosition, const int otherXSize, const int otherYSize); // Constructor with parameters

    void move(const Point coords); // Move the window
    void move_to(const Point coords); // Set the new position of the window
    void resize(const int otherXSize, const int otherYSize); // Resize the window

    void output_info() const; // Output information
};

Window::Window() {}

Window::Window(const Point otherPosition, const int otherXSize, const int otherYSize)
{
    this->m_Rect.set_position(otherPosition);
    this->m_Rect.set_size(otherXSize, otherYSize);
}

void Window::move(const Point coords)
{
    this->m_Rect.set_position({ this->m_Rect.get_position().X + coords.X, this->m_Rect.get_position().Y + coords.Y });
}

void Window::move_to(const Point coords)
{
    this->m_Rect.set_position(coords);
}

void Window::resize(const int otherXSize, const int otherYSize)
{
    if (otherXSize >= 0 && otherYSize >= 0)
    {
        this->m_Rect.set_size(otherXSize, otherYSize);
    }
}

void Window::output_info() const
{
    std::cout << "     Window info" << std::endl;
    std::cout << "Position:   (" << this->m_Rect.get_position().X << ", " << this->m_Rect.get_position().Y << ")" << std::endl;
    std::cout << "Size:       " << this->m_Rect.get_XSize() << " * " << this->m_Rect.get_YSize() << std::endl;
    std::cout << "Area:       " << this->m_Rect.get_area() << std::endl; // Call get_area() from Rectangle
    std::cout << "Perimeter:  " << this->m_Rect.get_perimeter() << std::endl; // Call get_perimeter() from Rectangle
}

int main()
{
    Window win1({ 100, 100 }, 0, 0);
    win1.move({ 200, 300 });
    win1.resize(1000, 500);
    win1.output_info();

    std::cout << std::endl;
    std::cout << std::endl;

    Window win2;
    win2.move_to({ 200, 300 });
    win2.resize(1100, 600);
    win2.output_info();

    return 0;
}
