//melissaliebowitz@yahoo.com
#include "doctest.h"
#include "MyContainer.hpp"
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Order Iterator Test")
{
    MyContainer<int> con;
    con.add(1);
    con.add(2);
    con.add(3);
    con.add(4);
    con.add(5);

    std:: vector<int> result;
    for (auto it = con.begin_order(); it != con.end_order(); ++it)
    {
        result.push_back(*it);
    }

    CHECK(result == std:: vector<int>{1,2,3,4,5});

    MyContainer<std:: string> con2;
    con2.add("hello");
    con2.add("world");
    con2.add("ello");

    std:: vector<std::string> res;
    for (auto it = con2.begin_order(); it != con2.end_order(); it++)
    {
        res.push_back(*it);
    }

    CHECK(res == std:: vector<std:: string>{"hello", "world", "ello"});
    
}

struct Person{
    std:: string name;
    int age;
        
    Person(std:: string name, int age): name(name), age(age){}
};

TEST_CASE("Order Iterator Test on struct:")
{
    MyContainer<Person> per_con;
    per_con.add({"Alice", 20});
    per_con.add({"Bob", 80});
    per_con.add({"Charlie", 9});

    std:: vector<Person> results;
    for (auto it = per_con.begin_order(); it != per_con.end_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK_EQ(results[2].name, "Charlie");
    CHECK_EQ(results[0].name, "Alice");
    CHECK_EQ(results[1].name, "Bob");
}