#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
#include "Fraction.hpp"


namespace ariel
{
    //the reduce function i got from this site: https://www.geeksforgeeks.org/reduce-the-fraction-to-its-lowest-form/
    Fraction::Fraction(int numerator, int denominator)
    {
        if(denominator == 0)
        {
            std::cout << "denominator can't be o!";
            throw std::invalid_argument("");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        int d;
        d = std::gcd(numerator, denominator);
        this->numerator /= d;
        this->denominator /= d;
        if(this->denominator < 0)
        {
            this->denominator = this->denominator * (-1);
            this->numerator = this->numerator * (-1);
        }
    }

    Fraction::Fraction(float num)
    {
        if(num == 0.0)
        {
            std::cout << "number can't be o!";
            throw std::exception();
        }

        int numerator = num * 1000;
        int denominator = 1000;
        int d = std::gcd(numerator, denominator);
        numerator /= d;
        denominator /= d;
        this->denominator = denominator;
        this->numerator = numerator;
    }
    //Binary operatoes on the fraction
    //performing the operator with another fraction: fraction +,-,*,/ fraction
    Fraction Fraction::operator+(const Fraction& f)
    {
        if((this->numerator == std::numeric_limits<int>::max() && this->denominator == std::numeric_limits<int>::max()) 
            || (f.numerator == std::numeric_limits<int>::max() && f.denominator == std::numeric_limits<int>::max()))
        {
            int newNumerator = this->numerator * f.denominator + this->denominator * f.numerator;
            int newDenominator = this->denominator * f.denominator;
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::min() && this->denominator == std::numeric_limits<int>::min()) 
            || (f.numerator == std::numeric_limits<int>::min() && f.denominator == std::numeric_limits<int>::min()))
        {
            int newNumerator = this->numerator * f.denominator + this->denominator * f.numerator;
            int newDenominator = this->denominator * f.denominator;
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::max() || this->denominator == std::numeric_limits<int>::max()) 
            || (f.numerator == std::numeric_limits<int>::max() || f.denominator == std::numeric_limits<int>::max()))
        {
            throw std::overflow_error("");
        }
        if(this->numerator == std::numeric_limits<int>::min() || this->denominator == std::numeric_limits<int>::min() 
            || f.numerator == std::numeric_limits<int>::min() || f.denominator == std::numeric_limits<int>::min())
        {
            throw std::overflow_error("");
        }
        int newNumerator = this->numerator * f.denominator + this->denominator * f.numerator;
        int newDenominator = this->denominator * f.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator-(const Fraction& f)
    {
        if((this->numerator == std::numeric_limits<int>::max() && this->denominator == std::numeric_limits<int>::max()) 
            || (f.numerator == std::numeric_limits<int>::max() && f.denominator == std::numeric_limits<int>::max()))
        {
            int newNumerator = this->numerator * f.denominator - this->denominator * f.numerator;
            int newDenominator = this->denominator * f.denominator;
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::min() && this->denominator == std::numeric_limits<int>::min()) 
            || (f.numerator == std::numeric_limits<int>::min() && f.denominator == std::numeric_limits<int>::min()))
        {
            int newNumerator = this->numerator * f.denominator - this->denominator * f.numerator;
            int newDenominator = this->denominator * f.denominator;
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::max() || this->denominator == std::numeric_limits<int>::max()) 
            || (f.numerator == std::numeric_limits<int>::max() || f.denominator == std::numeric_limits<int>::max()))
        {
            throw std::overflow_error("");
        }
        if((this->numerator == std::numeric_limits<int>::min() || this->denominator == std::numeric_limits<int>::min()) 
            || (f.numerator == std::numeric_limits<int>::min() || f.denominator == std::numeric_limits<int>::min()))
        {
            throw std::overflow_error("");
        }
        if((this->numerator == std::numeric_limits<int>::max() - 1) && (f.numerator == std::numeric_limits<int>::min() + 1))
        {
            throw std::overflow_error("");
        }
        int newNumerator = this->numerator * f.denominator - this->denominator * f.numerator;
        int newDenominator = this->denominator * f.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator*(const Fraction& f)
    {
        if((this->numerator == std::numeric_limits<int>::max() && this->denominator == std::numeric_limits<int>::max()) 
            || (f.numerator == std::numeric_limits<int>::max() && f.denominator == std::numeric_limits<int>::max()))
        {
            int newNumerator = this->numerator * f.numerator;
            int newDenominator = this->denominator * f.denominator;
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::min() && this->denominator == std::numeric_limits<int>::min()) 
            || (f.numerator == std::numeric_limits<int>::min() && f.denominator == std::numeric_limits<int>::min()))
        {
            int newNumerator = this->numerator * f.numerator;
            int newDenominator = this->denominator * f.denominator;
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::max() || this->denominator == std::numeric_limits<int>::max()) 
            && (f.numerator == std::numeric_limits<int>::max() || f.denominator == std::numeric_limits<int>::max()))
        {
            throw std::overflow_error("");
        }
        if((this->numerator == std::numeric_limits<int>::min() || this->denominator == std::numeric_limits<int>::min()) 
            && (f.numerator == std::numeric_limits<int>::min() || f.denominator == std::numeric_limits<int>::min()))
        {
            throw std::overflow_error("");
        }
        int newNumerator = this->numerator * f.numerator;
        int newDenominator = this->denominator * f.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction Fraction::operator/(const Fraction& f)
    {
        if((this->numerator == std::numeric_limits<int>::max() && this->denominator == std::numeric_limits<int>::max()) 
            || (f.numerator == std::numeric_limits<int>::max() && f.denominator == std::numeric_limits<int>::max()))
        {
            int newNumerator = this->numerator * f.denominator;
            int newDenominator = this->denominator * f.numerator;
            if(newDenominator == 0)
            {
                throw std::runtime_error("");
            }
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::min() && this->denominator == std::numeric_limits<int>::min()) 
            || (f.numerator == std::numeric_limits<int>::min() && f.denominator == std::numeric_limits<int>::min()))
        {
            int newNumerator = this->numerator * f.denominator;
            int newDenominator = this->denominator * f.numerator;
            if(newDenominator == 0)
            {
                throw std::runtime_error("");
            }
            return Fraction(newNumerator, newDenominator);
        }
        if((this->numerator == std::numeric_limits<int>::max() || this->denominator == std::numeric_limits<int>::max()) 
            && (f.numerator == std::numeric_limits<int>::max() || f.denominator == std::numeric_limits<int>::max()))
        {
            throw std::overflow_error("");
        }
        if((this->numerator == std::numeric_limits<int>::min() || this->denominator == std::numeric_limits<int>::min()) 
            && (f.numerator == std::numeric_limits<int>::min() || f.denominator == std::numeric_limits<int>::min()))
        {
            throw std::overflow_error("");
        }
        int newNumerator = this->numerator * f.denominator;
        int newDenominator = this->denominator * f.numerator;
        if(newDenominator == 0)
        {
            throw std::runtime_error("");
        }
        return Fraction(newNumerator, newDenominator);
    }

    //i used this site for the function https://www.asafraction.net/number/0.536
    Fraction floatToFraction(float num) 
    {
        int numerator = num * 1000;
        int denominator = 1000;
        return Fraction(numerator, denominator);
    }

    //performing the operator with a number: fraction +,-,*,/ float
    Fraction Fraction::operator+(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this)+valueFrac;
    }

    Fraction Fraction::operator-(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this)-valueFrac;
    }

    Fraction Fraction::operator*(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this)*valueFrac;
    }

    Fraction Fraction::operator/(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this)/valueFrac;
    }

    //performing the operator with a number: float +,-,*,/ fraction
    Fraction operator+(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac+f;
    }

    Fraction operator-(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac-f;
    }

    Fraction operator*(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac*f;
    }

    Fraction operator/(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac/f;
    }

    //increasing and decreasing by one
    //prefix operators ++n/--n
    Fraction Fraction::operator++()
    {
        this->numerator += this->denominator;
        return *this;
    }

    Fraction Fraction::operator--()
    {
        this->numerator -= this->denominator;
        return *this;
    }

    //postfix operators n++/n--
    Fraction Fraction::operator++(int)
    {
        Fraction cpy(*this);
        this->numerator += this->denominator;
        return cpy;
    }

    Fraction Fraction::operator--(int)
    {
        Fraction cpy(*this);
        this->numerator -= this->denominator;
        return cpy;
    }

    //boolean operators on the fraction
    //performing the operator with another fraction: fraction >,<,==,<=,>= fraction
    bool Fraction::operator>(const Fraction& f) const
    {
        float thisFrac = (float)this->numerator / this->denominator;
        float fFrac = (float)f.numerator / f.denominator;
        return thisFrac > fFrac;
    }

    bool Fraction::operator<(const Fraction& f) const
    {
        float thisFrac = (float)this->numerator / this->denominator;
        float fFrac = (float)f.numerator / f.denominator;
        return thisFrac < fFrac;
    }

    bool Fraction::operator>=(const Fraction& f) const
    {
        float thisFrac = (float)this->numerator / this->denominator;
        float fFrac = (float)f.numerator / f.denominator;
        return thisFrac >= fFrac;
    }

    bool Fraction::operator<=(const Fraction& f) const
    {
        float thisFrac = (float)this->numerator / this->denominator;
        float fFrac = (float)f.numerator / f.denominator;
        return thisFrac <= fFrac;
    }

    bool Fraction::operator==(const Fraction& f) const
    {
        float thisFrac = (float)this->numerator / this->denominator;
        float fFrac = (float)f.numerator / f.denominator;
        thisFrac = round(thisFrac * 1000) / 1000.0f;
        fFrac = round(fFrac * 1000) / 1000.0f;
        return thisFrac == fFrac;
    }

    //performing the operator with number: fraction >,<,==,<=,>= float
    bool Fraction::operator>(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this) > valueFrac;
    }

    bool Fraction::operator<(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this) < valueFrac;
    }

    bool Fraction::operator>=(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this) >= valueFrac;
    }

    bool Fraction::operator<=(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this) <= valueFrac;
    }

    bool Fraction::operator==(float value)
    {
        Fraction valueFrac = floatToFraction(value);
        return (*this) == valueFrac;
    }

    //performing the operator with number: float >,<,==,<=,>= fraction
    bool operator>(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac > f;
    }

    bool operator<(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac < f;
    }

    bool operator<=(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac <= f;
    }

    bool operator>=(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac >= f;
    }
    
    bool operator==(float value, const Fraction& f)
    {
        Fraction valueFrac = floatToFraction(value);
        return valueFrac == f;
    }

    //std operators
    std::ostream& operator<<(std::ostream& os, const Fraction& f)
    {
        return os << f.numerator << "/" << f.denominator;
    }

    std::istream& operator>>(std::istream& is, Fraction& f)
    {
        //char slash;
        int numerator, denominator;
        if(is >> numerator >> denominator)
        {
            if (denominator == 0) 
            {
                // Handle division by zero error
                is.setstate(std::ios::failbit);
                throw std::runtime_error("");
            } 
            else 
            {
                if(denominator < 0)
                {
                    f.denominator = denominator * (-1);
                    f.numerator = numerator * (-1);
                }
                else
                {
                    f.numerator = numerator;
                    f.denominator = denominator;
                }
            }
        }
        else
        {
            std::cerr << "Error: Invalid input format. Expected numerator/denominator." << std::endl;
            // Set a failbit to indicate the error
            is.setstate(std::ios::failbit);
            throw std::runtime_error("");

        }
        return is;
    }
}