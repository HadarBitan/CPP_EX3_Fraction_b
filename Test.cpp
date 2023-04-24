#include "doctest.h"
#include "sources/Fraction.hpp"

using namespace ariel;
using namespace doctest;

TEST_CASE("Binary operators")
{
    Fraction a(1,5), b(3,7);
    Fraction resFF1(22,35), resFF2(-8,35), resFF3(3,35), resFF4(7,15);
    Fraction resFN1(397,500), resFN2(0,5), resFN3(32,25), resFN4(1,5);
    Fraction resNF1(134,35), resNF2(33,200), resNF3(24,7), resNF4(0,7);
    CHECK((a+b) == resFF1);
    CHECK((a-b) == resFF2);
    CHECK((a*b) == resFF3);
    CHECK((a/b) == resFF4);
    CHECK((a+0.59438) == resFN1);
    CHECK((a-0.2) == resFN2);
    CHECK((a*6.4) == resFN3);
    CHECK((a/1) == resFN4);
    CHECK((3.4+b) == resNF1);
    CHECK((0.59438-b) == resNF2);
    CHECK((8.0*b) == resNF3);
    CHECK((0/b) == resNF4);
}

TEST_CASE("boolean operators")
{
    Fraction a(1,5), b(3,7);
    CHECK((a>b) == false);
    CHECK((a<b) == true);
    CHECK_FALSE(a==b);
    CHECK((a<=b) == true);
    CHECK((a>=b) == false);
    CHECK((a<0.2) == false);
    CHECK((a>0.1) == true);
    CHECK((a==0.2) == true);
    CHECK((a<=0.25) == true);
    CHECK((a>=0.568412) == false);
    CHECK((0.5<b) == false);
    CHECK((0.2>b) == false);
    CHECK((0.694==b) == false);
    CHECK((0.428<=b) == true);
    CHECK((0.428>=b) == true);
}

TEST_CASE("increasing and decreasing by one")
{
    Fraction a(1,5), b(13,4);
    Fraction res1(6,5), res2(9,4);
    CHECK(a++ == res1);
    CHECK(++a == res1);
    CHECK(b-- == res2);
    CHECK(--b == res2);
}

TEST_CASE("throwing exection")
{
    Fraction a(1,5), b(8, 0);
    CHECK_THROWS(b+a);
    CHECK_THROWS(b-a);
    CHECK_THROWS(b*a);
    CHECK_THROWS(b/a);

    CHECK_THROWS(b+2.6);
    CHECK_THROWS(b-1.5);
    CHECK_THROWS(b*0.2564);
    CHECK_THROWS(b/0.5);

    CHECK_THROWS(2.6+b);
    CHECK_THROWS(1.5-b);
    CHECK_THROWS(0.2564*b);
    CHECK_THROWS(0.5/b);

    CHECK_THROWS(a/0);
}