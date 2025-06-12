//melissaliebowitz@yahoo.com
#include "doctest.h"
#include "MyContainer.hpp"
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Reverse Order Iterator Test")
{
    MyContainer<double> con;
    con.add(1.78);
    con.add(6.89);
    con.add(1.5);
    con.add(-2.4);

    std:: vector<double> results;
    for(auto it = con.begin_reverse_order(); it != con.end_reverse_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK(results == std:: vector<double>{-2.4, 1.5, 6.89, 1.78});

    MyContainer<std:: string> con2;
    con2.add("aaa");
    con2.add("bb");
    con2.add("ccc");

    std:: vector<std:: string> res;
    for (auto it = con2.begin_reverse_order(); it != con2.end_reverse_order(); it++)
    {
        res.push_back(*it);
    }

    CHECK(res == std:: vector<std:: string>{"ccc", "bb", "aaa"});
    
}

struct Person{
    std:: string name;
    int age;
        
    Person(std:: string name, int age): name(name), age(age){}
};

TEST_CASE("Reverse Order Iterator Test on struct:")
{
    MyContainer<Person> per_con;
    per_con.add({"Alice", 20});
    per_con.add({"Bob", 80});
    per_con.add({"Charlie", 9});

    std:: vector<Person> results;
    for (auto it = per_con.begin_reverse_order(); it != per_con.end_reverse_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK_EQ(results[0].name, "Charlie");
    CHECK_EQ(results[2].name, "Alice");
    CHECK_EQ(results[1].name, "Bob");
}