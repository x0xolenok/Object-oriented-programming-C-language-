#include <iostream>

class Point2f // class for a 2D point
{
protected:

    float X; // field for X
    float Y; // field for Y

public:

    Point2f(); // default constructor

    Point2f(const float& otherX, const float& otherY);  // constructor with two parameters X and Y

    void set_X(const float& otherX); // setter for X

    void set_Y(const float& otherY); // setter for Y

    float get_X() const; // getter for X

    float get_Y() const; // getter for Y

    virtual void output_info() const; // virtual method for outputting point information
};

Point2f::Point2f()
{
    this->X = 0;
    this->Y = 0;
}

Point2f::Point2f(const float& otherX, const float& otherY)
{
    this->X = otherX;
    this->Y = otherY;
}

void Point2f::set_X(const float& otherX)
{
    this->X = otherX;
}

void Point2f::set_Y(const float& otherY)
{
    this->Y = otherY;
}

float Point2f::get_X() const
{
    return this->X;
}

float Point2f::get_Y() const
{
    return this->Y;
}

void Point2f::output_info() const
{
    std::cout << "(" << this->X << ", " << this->Y << ")";
}

class Point3f : public Point2f  // class for a 3D point (inherits from 2D point)
{
protected: // in case there will be further descendants

    float Z; // field for Z

public:

    Point3f(); // default constructor

    Point3f(const float& otherX, const float& otherY, const float& otherZ);  // constructor with three parameters X, Y, and Z

    void set_Z(const float& otherZ); // setter for Z

    float get_Z() const; // getter for Z

    virtual void output_info() const override; // virtual and overridden method for outputting point information (virtual in case there is a further descendant, such as Point4f)
};

Point3f::Point3f() : Point2f::Point2f() // calling the default constructor of the base class
{
    this->Z = 0;
}

Point3f::Point3f(const float& otherX, const float& otherY, const float& otherZ) : Point2f::Point2f(otherX, otherY) // calling the constructor with parameters of the base class
{
    this->Z = otherZ;
}

void Point3f::set_Z(const float& otherZ)
{
    this->Z = otherZ;
}

float Point3f::get_Z() const
{
    return this->Z;
}

void Point3f::output_info() const
{
    std::cout << "(" << this->X << ", " << this->Y << ", " << this->Z << ")";
}

void OutputAny(const Point2f* point) // function to output any object passed to a pointer of the base class (polymorphism)
{
    point->output_info(); // late binding
    std::cout << std::endl;
}

int main()
{
    Point2f* point1 = new Point2f(-1, 2); // creating a pointer to a Point2f object with dynamic memory allocation and calling the constructor with parameters
    Point3f* point2 = new Point3f(3, -4, 53); // creating a pointer to a Point3f object with dynamic memory allocation and calling the constructor with parameters
    Point2f* point3 = new Point3f(44, 11, -3); // creating a pointer to a Point2f object with dynamic memory allocation for Point3f (due to inheritance) and calling the constructor with parameters

    OutputAny(point1); // calling the output function using late binding
    OutputAny(point2); // calling the output function using late binding
    OutputAny(point3); // calling the output function using late binding

    Point3f point4(-1, -2, -3); // creating a Point3f object with the constructor with parameters
    point4.output_info(); // early binding

    delete point1; // cleaning up dynamic memory
    delete point2; // cleaning up dynamic memory
    delete point3; // cleaning up dynamic memory
    return 0;
}
