#ifndef FRACTION_HPP
#define FRACTION_HPP

#pragma once

#include <iostream>
#include <string>


//i used this sites: https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm
//https://www.programiz.com/cpp-programming/operator-overloading
//https://www.freecodecamp.org/news/how-to-overload-operators-in-cplusplus/
namespace ariel
{
    class Fraction
    {
        private:
            int numerator;
            int denominator;

        public:
            Fraction(int numerator, int denominator);
            Fraction(float num);
            Fraction() : numerator(1), denominator(1){}
            int getNumerator() const{return this->numerator;}
            int getDenominator() const{return this->denominator;}
            Fraction operator+(const Fraction& frac);
            Fraction operator-(const Fraction& frac);
            Fraction operator*(const Fraction& frac);
            Fraction operator/(const Fraction& frac);
            Fraction operator+(float value);
            Fraction operator-(float value);
            Fraction operator*(float value);
            Fraction operator/(float value);
            friend Fraction operator+(float value, const Fraction& frac);
            friend Fraction operator-(float value, const Fraction& frac);
            friend Fraction operator*(float value, const Fraction& frac);
            friend Fraction operator/(float value, const Fraction& frac);


            Fraction operator++();
            Fraction operator--();
            Fraction operator++(int);
            Fraction operator--(int);   

            bool operator>(const Fraction& frac) const;
            bool operator<(const Fraction& frac) const;
            bool operator<=(const Fraction& frac) const;
            bool operator>=(const Fraction& frac) const;
            bool operator==(const Fraction& frac) const;
            bool operator>(float value);
            bool operator<(float value);
            bool operator<=(float value);
            bool operator>=(float value);
            bool operator==(float value);
            friend bool operator>(float value, const Fraction& frac);
            friend bool operator<(float value, const Fraction& frac);
            friend bool operator<=(float value, const Fraction& frac);
            friend bool operator>=(float value, const Fraction& frac);
            friend bool operator==(float value, const Fraction& frac);



            friend std::ostream& operator<<(std::ostream& outs, const Fraction& frac);
            friend std::istream& operator>>(std::istream& ins, Fraction& frac);
    };
    Fraction floatToFraction(float num) ;
}

#endif