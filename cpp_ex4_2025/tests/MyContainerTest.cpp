//melissaliebowitz@yahoo.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "MyContainer.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Add To Container Test")
{
    MyContainer<int> con;
    con.add(5);
    con.add(1);

    CHECK_EQ(con.size(), 2);
    
    con.add(2);
    con.add(-4);
    con.add(10);
    CHECK_EQ(con.size(), 5);

    MyContainer<std:: string> con2;
    con2.add("hello");
    con2.add("world");
    con2.add("nice");
    con2.add("neat"); 

    CHECK_EQ(con2.size(), 4);
}

TEST_CASE("Remove From Container Test")
{
    MyContainer<double> con;
    con.add(9.2);
    con.add(3.1415);
    con.add(7.0);
    con.add(-2.98);
    con.add(-0.8);

    CHECK_EQ(con.size(), 5);

    con.remove(9.2);

    CHECK_EQ(con.size(), 4);

    con.remove(-2.98);
    con.remove(3.1415);

    CHECK_EQ(con.size(), 2);

    CHECK_THROWS_WITH(con.remove(3.6), "Element not found in container.");
}

TEST_CASE("Size of Container Size")
{
    MyContainer<std:: string> con;
    con.add("aa");
    con.add("cc");
    con.add("aab");

    CHECK_EQ(con.size(), 3);
    con.add("er");
    con.add("ty");

    CHECK_EQ(con.size(), 5);
    con.remove("cc");
    CHECK_EQ(con.size(), 4);
    con.remove("er");
    CHECK_EQ(con.size(), 3);
}

TEST_CASE("isEmpty Test")
{
    MyContainer<double> con;
    CHECK_EQ(con.isEmpty(), true);

    con.add(8.9);
    CHECK_EQ(con.isEmpty(), false);
}