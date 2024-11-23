#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>
#include <cmath>

// Custom exception class for handling cases where denominator is zero
class FractionDNullFailException : public std::exception {
    const char* what() const noexcept override {
        return "Denominator cannot be zero!";
    }
};

// Fraction class represents a mathematical fraction (numerator/denominator)
class Fraction {
private:
    long numerator;  // numerator of the fraction
    long denominator;  // denominator of the fraction

    // Euclidean algorithm to find the greatest common divisor (GCD)
    long euclidean(long a, long b) {
        while (b != 0) {
            long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

public:
    // Default constructor sets fraction to 0/1 (a valid fraction)
    Fraction() : numerator(0), denominator(1) {}

    // Static method to create a Fraction from a double value
    static Fraction FromDouble(double Number) {
        long denominator = 1000000;  // setting precision to 6 decimal places
        long numerator = static_cast<long>(Number * denominator);  // scale up the double to an integer
        return Fraction(numerator, denominator);  // create and return the Fraction
    }

    // Static method to create a Fraction from a string in the form "numerator/denominator"
    static Fraction FromString(const std::string& FractionString) {
        size_t delimiter_pos = FractionString.find('/');
        if (delimiter_pos == std::string::npos) {
            throw std::invalid_argument("Invalid fraction format");  // if no '/' found, invalid format
        }

        long numerator = std::stol(FractionString.substr(0, delimiter_pos));  // extract numerator
        long denominator = std::stol(FractionString.substr(delimiter_pos + 1));  // extract denominator

        if (denominator == 0) {
            throw FractionDNullFailException();  // throw an exception if denominator is zero
        }

        return Fraction(numerator, denominator);  // create and return the Fraction
    }

    // Constructor for creating Fraction from numerator and denominator
    Fraction(long numerator, long denominator) {
        if (denominator == 0) {
            throw FractionDNullFailException();  // prevent creating a fraction with zero denominator
        }
        this->numerator = numerator;
        this->denominator = denominator;
        reduce();  // simplify the fraction
    }

    // Getter methods for numerator and denominator
    long getNumerator() const { return numerator; }
    long getDenominator() const { return denominator; }

    // Convert the fraction to string format (e.g., "3/4")
    std::string getString() const {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    // Setter methods for numerator and denominator
    void setNumerator(long Numerator) { this->numerator = Numerator; }
    void setDenominator(long Denominator) {
        if (Denominator == 0) {
            throw FractionDNullFailException();  // prevent setting a zero denominator
        }
        this->denominator = Denominator;
    }

    // Method to reduce the fraction to its simplest form
    bool reduce() {
        long gcd = euclidean(numerator, denominator);  // find GCD
        if (gcd > 1) {
            numerator /= gcd;  // divide both by GCD to reduce
            denominator /= gcd;
            return true;  // fraction was reduced
        }
        return false;  // fraction was already in simplest form
    }

    // Convert the fraction to double
    double convertFractionToDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

    // Convert a double value into a Fraction
    void convertDoubleToFraction(double Number) {
        long denominator = 1000000;  // precision to 6 decimal places
        long numerator = static_cast<long>(Number * denominator);  // convert the double into integer form
        this->numerator = numerator;
        this->denominator = denominator;
        reduce();  // simplify the fraction
    }

    // Overloading comparison operators
    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;  // compare fractions
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);  // not equal if fractions are not equal
    }

    bool operator<(const Fraction& other) const {
        return static_cast<double>(*this) < static_cast<double>(other);  // compare fractions as doubles
    }

    bool operator>(const Fraction& other) const {
        return static_cast<double>(*this) > static_cast<double>(other);  // compare fractions as doubles
    }

    // Overloading the stream output operator to display the fraction in "numerator/denominator" format
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
        os << frac.numerator << "/" << frac.denominator;
        return os;
    }

    // Overloading the stream input operator to read a fraction from a string (e.g., "3/4")
    friend std::istream& operator>>(std::istream& is, Fraction& frac) {
        std::string input;
        is >> input;
        try {
            frac = Fraction::FromString(input);  // try to create Fraction from input string
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;  // print error if input is invalid
        }
        return is;
    }

    // Overloading the string conversion operator to easily convert a fraction to a string
    operator std::string() const {
        return getString();
    }

    // Conversion operator to double for implicit conversion from Fraction to double
    operator double() const {
        return static_cast<double>(numerator) / denominator;  // convert fraction to double
    }
};

int main() {
    try {
        // Create fractions using different methods
        Fraction f1 = Fraction::FromString("3/4");  // create fraction from string
        Fraction f2 = Fraction::FromDouble(0.75);   // create fraction from double

        std::cout << "Fraction 1: " << f1 << std::endl;
        std::cout << "Fraction 2: " << f2 << std::endl;

        // Convert fraction to double and print
        std::cout << "Fraction 1 as double: " << f1.convertFractionToDouble() << std::endl;

        // Modify fraction f3 and print after conversion
        Fraction f3(1, 2);
        std::cout << "Fraction 3: " << f3 << std::endl;

        // Convert a double to a fraction and display it
        f3.convertDoubleToFraction(1.5);
        std::cout << "Fraction 3 after conversion from double: " << f3 << std::endl;

    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;  // catch and display any exceptions
    }

    return 0;
}
