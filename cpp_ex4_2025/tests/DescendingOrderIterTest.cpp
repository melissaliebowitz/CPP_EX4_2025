//melissaliebowitz@yahoo.com
#include "doctest.h"
#include "MyContainer.hpp"
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Descending Order Iterator Test")
{
    MyContainer<double> con;
    con.add(-4.7);
    con.add(2.65);
    con.add(8.7);
    con.add(-1.23);

    std:: vector<double> results;
    for (auto it = con.begin_descending_order(); it != con.end_descending_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK(results == std:: vector<double>{8.7, 2.65, -1.23, -4.7});

    MyContainer<std:: string> con2;
    con2.add("Bar");
    con2.add("Car");
    con2.add("Kar");
    con2.add("Mar");
    con2.add("Jar");

    std:: vector<std:: string> res;
    for (auto it = con2.begin_descending_order(); it != con2.end_descending_order(); ++it)
    {
        res.push_back(*it);
    }

    CHECK(res == std::vector<std:: string>{"Mar", "Kar", "Jar", "Car", "Bar"});
    
}

struct Person{
    std:: string name;
    int age;
        
    Person(std:: string name, int age): name(name), age(age){}
};

bool operator>(const Person& p1, const Person& p2)
{
    return p1.age > p2.age;
}

TEST_CASE("Descending Order Iterator Test on struct:")
{
    MyContainer<Person> per_con;
    per_con.add({"Alice", 20});
    per_con.add({"Bob", 80});
    per_con.add({"Charlie", 9});

    std:: vector<Person> results;
    for (auto it = per_con.begin_descending_order(); it != per_con.end_descending_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK_EQ(results[2].name, "Charlie");
    CHECK_EQ(results[1].name, "Alice");
    CHECK_EQ(results[0].name, "Bob");
}
