#include <iostream>
#include <cmath>

class Point // Class representing a point of any dimension
{
private:
    float* m_pPoints;   // Array of point values
    int m_Size;         // Dimension of the point

public:
    Point();    // Default constructor
    Point(const int& otherSize);    // Constructor with a dimension parameter
    Point(const Point& point);      // Copy constructor
    ~Point();                       // Destructor

    void resize(const int& otherSize);  // Resize the point dimension
    int get_size() const;               // Get the dimension of the point
    float* points() const;              // Get the array of point values

    Point operator = (const Point& right);  // Assignment operator

    void output() const;    // Method to output information about the point
};

Point::Point()
{
    this->m_pPoints = nullptr;
    this->m_Size = 0;
}

Point::Point(const int& otherSize) : Point::Point()
{
    if (otherSize > 0)  // Check if the size is valid
    {
        this->m_Size = otherSize;   // Set the point dimension to the provided size
        this->m_pPoints = new float[this->m_Size];  // Allocate memory for the point's values
        for (size_t i = 0; i < this->m_Size; i++)   // Initialize all point values to zero
        {
            this->m_pPoints[i] = 0;
        }
    }
}

Point::Point(const Point& point) : Point::Point()
{
    if (point.m_Size)   // If the other point's size is non-zero
    {
        this->m_pPoints = new float[point.m_Size];  // Allocate memory for the point values
        for (size_t i = 0; i < point.m_Size; i++)
        {
            this->m_pPoints[i] = point.m_pPoints[i];   // Copy values from the original point
        }
        this->m_Size = point.m_Size;   // Set the current dimension to the copied point's dimension
    }
}

Point::~Point()
{
    delete[] this->m_pPoints;   // Free dynamically allocated memory
}

void Point::resize(const int& otherSize)
{
    if (otherSize >= 0)     // If the size is valid
    {
        float* newArr = new float[otherSize];   // Allocate memory for the new array
        for (size_t i = 0; i < this->m_Size && i < otherSize; i++)  // Copy values from the old array (up to the minimum size)
        {
            newArr[i] = this->m_pPoints[i];
        }
        if (otherSize > this->m_Size)
        {
            for (size_t i = this->m_Size; i < otherSize; i++)   // Initialize additional elements to zero if the new size is larger
            {
                newArr[i] = 0;
            }
        }
        delete[] this->m_pPoints;   // Free the old array
        this->m_pPoints = newArr;   // Point to the new array
        this->m_Size = otherSize;   // Set the new size
        if (!otherSize) // If the size is zero
        {
            this->m_pPoints = nullptr;
        }
    }
}

int Point::get_size() const
{
    return this->m_Size;
}

float* Point::points() const
{
    return this->m_pPoints;
}

Point Point::operator=(const Point& right)
{
    delete[] this->m_pPoints;   // Free the old array
    if (right.m_Size)   // If the right side point has a non-zero size
    {
        this->m_pPoints = new float[right.m_Size];  // Allocate memory for the new array
        for (size_t i = 0; i < right.m_Size; i++)  // Copy values from the right-side point
        {
            this->m_pPoints[i] = right.m_pPoints[i];
        }
    }
    else
    {
        this->m_pPoints = nullptr;  // Set to null if the right side point has zero size
    }
    this->m_Size = right.m_Size;       // Set the new size
    return *this;  // Return the current object for chain assignment
}

void Point::output() const
{
    std::cout << "(";
    for (size_t i = 0; i < this->m_Size; i++)
    {
        std::cout << this->m_pPoints[i];
        if (i < (this->m_Size - 1))
        {
            std::cout << ", ";
        }
    }
    std::cout << ")";
}

// Class representing a vector
class Vector
{
private:
    Point m_FirstPoint;     // First point of the vector
    Point m_SecondPoint;    // Second (end) point of the vector

public:
    Vector();   // Default constructor
    Vector(const Point& first, const Point& second);    // Constructor with two points
    Vector(const Vector& otherVector);                  // Copy constructor

    void set_points(const Point& first, const Point& second);   // Set two points of the vector
    Point get_first_point() const;  // Get the first point
    Point get_second_point() const;  // Get the second point
    Point get_vector_coords() const;    // Get the coordinates of the vector
    float get_length() const;           // Get the length of the vector
};

Vector::Vector()
{
}

Vector::Vector(const Point& first, const Point& second)
{
    if (first.get_size() == second.get_size())  // If dimensions are the same
    {
        this->m_FirstPoint = first;
        this->m_SecondPoint = second;
    }
}

Vector::Vector(const Vector& otherVector)
{
    this->m_FirstPoint = otherVector.m_FirstPoint;
    this->m_SecondPoint = otherVector.m_SecondPoint;
}

void Vector::set_points(const Point& first, const Point& second)
{
    if (first.get_size() == second.get_size())  // If dimensions are the same
    {
        this->m_FirstPoint = first;
        this->m_SecondPoint = second;
    }
}

Point Vector::get_first_point() const
{
    return this->m_FirstPoint;
}

Point Vector::get_second_point() const
{
    return this->m_SecondPoint;
}

Point Vector::get_vector_coords() const
{
    Point result(this->m_FirstPoint.get_size());    // Create a new point to hold vector coordinates
    for (size_t i = 0; i < this->m_FirstPoint.get_size(); i++)  // Iterate through each dimension
    {
        result.points()[i] = this->m_SecondPoint.points()[i] - this->m_FirstPoint.points()[i];  // Calculate the difference for each dimension
    }
    return result;
}

float Vector::get_length() const
{
    float result_length = 0;
    Point vector_coords = this->get_vector_coords(); // Get the vector coordinates
    for (size_t i = 0; i < vector_coords.get_size(); i++)   // Iterate through each dimension
    {
        result_length += pow(vector_coords.points()[i], 2); // Sum the squared values of the coordinates
    }
    return sqrt(result_length); // Return the square root of the sum of squared coordinates
}

float vector_length(const Vector& vec)  // External function to calculate vector length (works similarly to the method above)
{
    float result_length = 0;
    Point vector_coords = vec.get_vector_coords();
    for (size_t i = 0; i < vector_coords.get_size(); i++)
    {
        result_length += pow(vector_coords.points()[i], 2);
    }
    return sqrt(result_length);
}

void vector_output(const Vector& vec)   // Function to output vector information
{
    std::cout << "First point: ";
    vec.get_first_point().output();
    std::cout << ", second point: ";
    vec.get_second_point().output();
    std::cout << std::endl;
    std::cout << "Vector coordinates: ";
    vec.get_vector_coords().output();
    std::cout << std::endl;
    std::cout << "Vector length: " << vector_length(vec) << std::endl;
}

Point input_point(const int& measurement)   // Function to input a point
{
    Point newPoint(measurement);
    std::cout << "Enter point values: " << std::endl;
    for (size_t i = 0; i < measurement; i++)    // Loop to input each value of the point
    {
        std::cout << i + 1 << " value: ";
        std::cin >> newPoint.points()[i];
    }
    return newPoint;
}

int main()
{
    int measurement;    // Dimension of the point
    std::cout << "Enter measurement: ";
    std::cin >> measurement;

    if (measurement > 0)
    {
        Point pVec_first_point;     // First point of the vector
        Point pVec_second_point;    // Second point of the vector

        std::cout << "     Enter first point for pVec" << std::endl;
        pVec_first_point = input_point(measurement);
        std::cout << "     Enter second point for pVec" << std::endl;
        pVec_second_point = input_point(measurement);

        Vector pVec(pVec_first_point, pVec_second_point);    // Create the vector

        std::cout << std::endl;
        vector_output(pVec);   // Output the vector information
    }
    else
    {
        std::cout << "Invalid measurement value!" << std::endl;
    }
    return 0;
}
