//melissaliebowitz@yahoo.com
#include "doctest.h"
#include "MyContainer.hpp"
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Ascending Order Iterator Test")
{
    MyContainer<int> con;
    con.add(2);
    con.add(-8);
    con.add(4);
    con.add(-1);
    con.add(3);

    std:: vector<int> results;
    for (auto it = con.begin_ascending_order(); it != con.end_ascending_order(); it++)
    {
       results.push_back(*it);
    }

    CHECK(results == std:: vector<int>{-8, -1, 2, 3, 4});

    MyContainer<std:: string> con2;
    con2.add("apples");
    con2.add("bananas");
    con2.add("grapes");
    con2.add("cherry");
    con2.add("aapples");

    std:: vector<std:: string> res;
    for (auto it = con2.begin_ascending_order(); it != con2.end_ascending_order(); ++it)
    {
        res.push_back(*it);
    }

    CHECK_EQ(res, std:: vector<std:: string>{"aapples", "apples", "bananas", "cherry", "grapes"});
    
}


struct Person{
    std:: string name;
    int age;
        
    Person(std:: string name, int age): name(name), age(age){}
};

bool operator<(const Person& p1, const Person& p2)
{
    return p1.age < p2.age;
}

TEST_CASE("Ascending Order Iterator Test on struct:")
{
    MyContainer<Person> per_con;
    per_con.add({"Alice", 20});
    per_con.add({"Bob", 80});
    per_con.add({"Charlie", 9});

    std:: vector<Person> results;
    for (auto it = per_con.begin_ascending_order(); it != per_con.end_ascending_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK_EQ(results[0].name, "Charlie");
    CHECK_EQ(results[1].name, "Alice");
    CHECK_EQ(results[2].name, "Bob");
}