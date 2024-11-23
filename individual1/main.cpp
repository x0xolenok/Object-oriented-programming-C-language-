#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>  // For strcpy function

class Human
{
protected:
    char m_Surname[100] = ""; // surname
    char m_Name[100] = "";     // name
    int m_Age;                 // age

public:
    virtual void set_surname(std::string otherSurname) = 0; // setter for surname
    virtual void set_name(std::string otherName) = 0;       // setter for name
    virtual void set_age(int otherAge) = 0;                 // setter for age

    virtual std::string get_surname() const = 0; // getter for surname
    virtual std::string get_name() const = 0;    // getter for name
    virtual int get_age() const = 0;             // getter for age

    virtual void output() const = 0;             // virtual method for outputting information
};

class Employee : public Human // Employee class inherits from abstract Human
{
protected:
    int m_Experience;     // years
    int m_SalaryCoeficy;  // salary coefficient for the employee
    int m_EmplID;         // employee ID

    static int ID;        // static variable for ID

    static void update_ID() // increment the static ID by 1
    {
        Employee::ID++;
    }

public:
    Employee(); // default constructor
    Employee(std::string otherSurname, std::string otherName,
        int otherAge, int otherExperience); // constructor with parameters

    void set_surname(std::string otherSurname); // setter for surname
    void set_name(std::string otherName);       // setter for name
    void set_age(int otherAge);                 // setter for age
    void set_experience(int otherExperience);   // setter for work experience

    std::string get_surname() const; // getter for surname
    std::string get_name() const;    // getter for name
    int get_age() const;             // getter for age
    int get_experience() const;      // getter for work experience
    int get_salary() const;          // calculate and get salary
    int get_id() const;              // getter for ID

    virtual void output() const override; // virtual and overridden method for outputting information
};

int Employee::ID = 0; // initialization of static variable

Employee::Employee()
{
    Employee::update_ID(); // increment the static ID
    this->m_EmplID = Employee::ID; // initialize unique ID
    this->m_Age = 0;
    this->m_Experience = -1;
    this->m_SalaryCoeficy = 5000;
}

Employee::Employee(std::string otherSurname, std::string otherName,
    int otherAge, int otherExperience)
{
    Employee::update_ID();
    this->m_EmplID = Employee::ID;

    strcpy(this->m_Surname, otherSurname.c_str());
    strcpy(this->m_Name, otherName.c_str());
    if (otherAge >= 16 && otherAge < 100) // validate age
    {
        this->m_Age = otherAge;
        if (otherAge - otherExperience >= 16 && otherExperience >= 0) // validate experience
        {
            this->m_Experience = otherExperience;
        }
        else
        {
            this->m_Experience = -1;
        }
    }
    else
    {
        this->m_Age = 0;
    }
}

void Employee::set_surname(std::string otherSurname)
{
    strcpy(this->m_Surname, otherSurname.c_str());
}

void Employee::set_name(std::string otherName)
{
    strcpy(this->m_Name, otherName.c_str());
}

void Employee::set_age(int otherAge)
{
    if (otherAge >= 16 && otherAge < 100) // validate age
    {
        this->m_Age = otherAge;
    }
}

void Employee::set_experience(int otherExperience)
{
    if (this->m_Age - otherExperience >= 16 && otherExperience >= 0) // validate experience
    {
        this->m_Experience = otherExperience;
    }
    else
    {
        throw "Incorrect experience";
    }
}

std::string Employee::get_surname() const
{
    return this->m_Surname;
}

std::string Employee::get_name() const
{
    return this->m_Name;
}

int Employee::get_age() const
{
    return this->m_Age;
}

int Employee::get_experience() const
{
    return this->m_Experience;
}

int Employee::get_salary() const
{
    int result_salary = this->m_SalaryCoeficy * this->m_Experience;
    if (result_salary <= 0)
    {
        result_salary = this->m_SalaryCoeficy;
    }
    return result_salary;
}

int Employee::get_id() const
{
    return this->m_EmplID;
}

void Employee::output() const
{
    std::cout << "     Employee info: " << std::endl;
    std::cout << "ID:                    " << this->m_EmplID << std::endl;
    std::cout << "Surname:               " << this->m_Surname << std::endl;
    std::cout << "Name:                  " << this->m_Name << std::endl;
    std::cout << "Age:                   ";
    if (this->m_Age < 16)
    {
        std::cout << "Not known" << std::endl;
    }
    else
    {
        std::cout << this->m_Age << "y.o." << std::endl;
    }
    std::cout << "Experience:            ";
    if (this->m_Experience < 0)
    {
        std::cout << "Not known" << std::endl;
    }
    else
    {
        std::cout << this->m_Experience << "years" << std::endl;
    }
}

class Engineer : public Employee
{
private:
    char m_Education[100] = ""; // education

public:
    Engineer();
    Engineer(std::string otherSurname, std::string otherName,
        int otherAge, int otherExperience, std::string otherEducation);

    void set_education(std::string otherEducation);
    std::string get_education();

    void output() const override;
};

Engineer::Engineer() : Employee::Employee()
{
    this->m_SalaryCoeficy = 7000; // set initial salary
}

Engineer::Engineer(std::string otherSurname, std::string otherName, int otherAge,
    int otherExperience, std::string otherEducation)
    : Employee::Employee(otherSurname, otherName, otherAge, otherExperience)
{
    strcpy(this->m_Education, otherEducation.c_str());
    this->m_SalaryCoeficy = 7000;
}

void Engineer::set_education(std::string otherEducation)
{
    strcpy(this->m_Education, otherEducation.c_str());
}

std::string Engineer::get_education()
{
    return this->m_Education;
}

void Engineer::output() const
{
    std::cout << "     Engineer info: " << std::endl;
    std::cout << "ID:                    " << this->m_EmplID << std::endl;
    std::cout << "Surname:               " << this->m_Surname << std::endl;
    std::cout << "Name:                  " << this->m_Name << std::endl;
    std::cout << "Age:                   ";
    if (this->m_Age < 16)
    {
        std::cout << "Not known" << std::endl;
    }
    else
    {
        std::cout << this->m_Age << "y.o." << std::endl;
    }
    std::cout << "Experience:            ";
    if (this->m_Experience < 0)
    {
        std::cout << "Not known" << std::endl;
    }
    else
    {
        std::cout << this->m_Experience << "years" << std::endl;
    }
    std::cout << "Education:             " << this->m_Education << std::endl;
}

class Director : public Employee
{
private:
    int m_DirExperience; // director experience

public:
    Director(); // default constructor
    Director(std::string otherSurname, std::string otherName,
        int otherAge, int otherExperience, int otherDirExperience); // constructor with parameters

    void set_dir_experience(int otherDirExperience); // setter for director experience
};
