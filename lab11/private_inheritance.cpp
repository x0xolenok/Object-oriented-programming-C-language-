#include <iostream>

struct Point // Auxiliary structure for the point
{
    int X = 0;
    int Y = 0;
};

class Rectangle  // Rectangle class
{
private:
    Point m_Position;  // Coordinates of the rectangle
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

    int get_area() const; // Get area
    int get_perimeter() const; // Get perimeter
};

Rectangle::Rectangle()
{
    this->m_XSize = 0;
    this->m_YSize = 0;
}

Rectangle::Rectangle(const Point otherPosition, const int otherXSize, const int otherYSize) : Rectangle::Rectangle()
{
    this->m_Position = otherPosition;
    if (otherXSize >= 0 && otherYSize >= 0)
    {
        this->m_XSize = otherXSize;
        this->m_YSize = otherYSize;
    }
}

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

int Rectangle::get_area() const
{
    return this->get_XSize() * this->get_YSize();
}

int Rectangle::get_perimeter() const
{
    return 2 * this->get_XSize() + 2 * this->get_YSize();
}

class Window : private Rectangle
{
public:
    Window(); // Default constructor
    Window(const Point otherPosition, const int otherXSize, const int otherYSize); // Constructor with parameters

    void move(const Point coords); // Move the window
    void move_to(const Point coords); // Set a new position for the window
    void resize(const int otherXSize, const int otherYSize); // Resize the window

    void output_info() const; // Output window information
};

Window::Window() : Rectangle::Rectangle()
{
}

Window::Window(const Point otherPosition, const int otherXSize, const int otherYSize)
    : Rectangle::Rectangle(otherPosition, otherXSize, otherYSize)
{
}

void Window::move(const Point coords)
{
    this->set_position({ this->get_position().X + coords.X, this->get_position().Y + coords.Y });
}

void Window::move_to(const Point coords)
{
    this->set_position(coords);
}

void Window::resize(const int otherXSize, const int otherYSize)
{
    if (otherXSize >= 0 && otherYSize >= 0)
    {
        this->set_size(otherXSize, otherYSize);
    }
}

void Window::output_info() const
{
    std::cout << "     Window info" << std::endl;
    std::cout << "Position:   (" << this->get_position().X << ", " << this->get_position().Y << ")" << std::endl;
    std::cout << "Size:       " << this->get_XSize() << " * " << this->get_YSize() << std::endl;
    std::cout << "Area:       " << this->get_area() << std::endl;
    std::cout << "Perimeter:  " << this->get_perimeter() << std::endl;
}

int main()
{
    Window win1({ 100, 100 }, 0, 0); // Create a window with initial position and size
    win1.move({ 200, 300 }); // Move the window by a certain offset
    win1.resize(1000, 500); // Resize the window
    win1.output_info(); // Output window information

    std::cout << std::endl;
    std::cout << std::endl;

    Window win2; // Create a default window
    win2.move_to({ 200, 300 }); // Move window to a specific position
    win2.resize(1100, 600); // Resize the window
    win2.output_info(); // Output window information

    return 0;
}
