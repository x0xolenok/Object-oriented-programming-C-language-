#include <iostream>
#include <math.h>


#define PI 3.14159265


class Figure
{
protected:

public:

    virtual float get_area() const { return 0; };

    virtual float get_perimeter() const { return 0; };

    virtual void output_info() const = 0;
};

class Rectangle : public Figure
{
private:

    float m_Length;

    float m_Height;

public:

    Rectangle();

    Rectangle(const float& otherLength, const float& otherHeight);


    void set_length(const float& otherLength);

    void set_height(const float& otherHeight);


    float get_length() const;

    float get_height() const;


    float get_area() const override;

    float get_perimeter() const override;

    void output_info() const override;

};

Rectangle::Rectangle()
{
    this->m_Length = 0;
    this->m_Height = 0;
}

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


void Rectangle::set_length(const float& otherLength)
{
    if (otherLength > 0)
    {
        this->m_Length = otherLength;
    }
}

void Rectangle::set_height(const float& otherHeight)
{
    if (otherHeight > 0)
    {
        this->m_Height = otherHeight;
    }
}


float Rectangle::get_length() const
{
    return this->m_Length;
}

float Rectangle::get_height() const
{
    return this->m_Height;
}


float Rectangle::get_area() const
{
    return this->m_Height * this->m_Length;
}

float Rectangle::get_perimeter() const
{
    return this->m_Height * 2 + this->m_Length * 2;
}

void Rectangle::output_info() const
{
    std::cout << "     Rectangle info:" << std::endl;
    std::cout << "Length:    " << this->m_Length << std::endl;
    std::cout << "Height:    " << this->m_Height << std::endl;
    std::cout << "Area:      " << this->get_area() << std::endl;
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}




class Trianle : public Figure
{
private:

    float m_FirstSide;
    float m_SecondSide;
    float m_ThirdSide;

public:

    Trianle();

    Trianle(const float& otherFirst, const float& otherSecond, const float& otherThird);


    void set_firstSide(const float& otherFirst);

    void set_secondSide(const float& otherSecond);

    void set_thirdSide(const float& otherThird);


    float get_firstSide() const;

    float get_secondSide() const;

    float get_thirdSide() const;


    float get_area() const override;

    float get_perimeter() const override;

    void output_info() const override;

};


Trianle::Trianle()
{
    this->m_FirstSide = 0;
    this->m_SecondSide = 0;
    this->m_ThirdSide = 0;
}

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


void Trianle::set_firstSide(const float& otherFirst)
{
    if (otherFirst > 0)
    {
        this->m_FirstSide = otherFirst;
    }
}

void Trianle::set_secondSide(const float& otherSecond)
{
    if (otherSecond > 0)
    {
        this->m_SecondSide = otherSecond;
    }
}

void Trianle::set_thirdSide(const float& otherThird)
{
    if (otherThird > 0)
    {
        this->m_ThirdSide = otherThird;
    }
}


float Trianle::get_firstSide() const
{
    return this->m_FirstSide;
}

float Trianle::get_secondSide() const
{
    return this->m_SecondSide;
}

float Trianle::get_thirdSide() const
{
    return this->m_ThirdSide;
}


float Trianle::get_area() const
{
    float p = 0.5 * this->get_perimeter();
    return sqrt(p * (p - this->m_FirstSide) * (p - this->m_SecondSide) * (p - this->m_ThirdSide));
}

float Trianle::get_perimeter() const
{
    return this->m_FirstSide + this->m_SecondSide + this->m_ThirdSide;
}

void Trianle::output_info() const
{
    std::cout << "     Trianle info:" << std::endl;
    std::cout << "First side:  " << this->m_FirstSide << std::endl;
    std::cout << "Second side: " << this->m_SecondSide << std::endl;
    std::cout << "Third side:  " << this->m_ThirdSide << std::endl;
    std::cout << "Area:        " << this->get_area() << std::endl;
    std::cout << "Perimeter:   " << this->get_perimeter() << std::endl;
}



class Circle : public Figure
{
private:

    float m_Radius;

public:

    Circle();

    Circle(const float& otherRadius);


    void set_radius(const float& otherRadius);


    float get_radius() const;


    float get_area() const override;

    float get_perimeter() const override;

    void output_info() const override;

};

Circle::Circle()
{
    this->m_Radius = 0;
}

Circle::Circle(const float& otherRadius) : Circle::Circle()
{
    if (otherRadius > 0)
    {
        this->m_Radius = otherRadius;
    }
}


void Circle::set_radius(const float& otherRadius)
{
    if (otherRadius > 0)
    {
        this->m_Radius = otherRadius;
    }
}

float Circle::get_radius() const
{
    return this->m_Radius;
}


float Circle::get_area() const
{
    return PI * this->m_Radius * this->m_Radius;
}

float Circle::get_perimeter() const
{
    return 2 * PI * this->m_Radius;
}

void Circle::output_info() const
{
    std::cout << "     Circle info:" << std::endl;
    std::cout << "Radius:    " << this->m_Radius << std::endl;
    std::cout << "Area:      " << this->get_area() << std::endl;
    std::cout << "Perimeter: " << this->get_perimeter() << std::endl;
}


int main()
{
    //Figure fgr;
    int size = 3;
    Figure** figures = new Figure * [size];
    figures[0] = new Rectangle(33, 44);
    figures[1] = new Trianle(2, 3, 4);
    figures[2] = new Circle(9);



    for (size_t i = 0; i < size; i++)
    {
        figures[i]->output_info();
        std::cout << std::endl;
        std::cout << std::endl;
    }


    for (size_t i = 0; i < size; i++)
    {
        delete figures[i];
    }
    delete[] figures;
    return 0;
}