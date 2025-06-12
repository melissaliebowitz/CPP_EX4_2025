//melissaliebowitz@yahoo.com
#include "doctest.h"
#include "MyContainer.hpp"
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Middle Out Order Iterator")
{
    MyContainer<int> con;
    con.add(1);
    con.add(2);
    con.add(3);
    con.add(4);
    con.add(5);
    con.add(6);

    std:: vector<int> results;
    for (auto it = con.begin_middle_order(); it != con.end_middle_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK(results == std:: vector<int>{4,3,5,2,6,1});

    MyContainer<std:: string> con2;
    con2.add("hi");
    con2.add("bye");
    con2.add("hello");
    con2.add("goodbye");
    con2.add("byebye");

    std:: vector<std:: string> res;
    for (auto it = con2.begin_middle_order(); it != con2.end_middle_order(); ++it)
    {
        res.push_back(*it);
    }
    
    CHECK(res == std:: vector<std:: string>{"hello", "bye", "goodbye", "hi", "byebye"});
    
}

struct Person{
    std:: string name;
    int age;
        
    Person(std:: string name, int age): name(name), age(age){}
};
