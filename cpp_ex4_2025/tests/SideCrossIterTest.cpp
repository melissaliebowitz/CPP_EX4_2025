//melissaliebowitz@yahoo.com
#include "doctest.h"
#include "MyContainer.hpp"
#include <vector>
#include <string>
using namespace container;

TEST_CASE("Side Cross Iterator Test")
{
    MyContainer<int> con;
    con.add(1);
    con.add(2);
    con.add(3);
    con.add(4);
    con.add(5);

    std:: vector<int> results;
    for (auto it = con.begin_sidecross_order(); it != con.end_sidecross_order(); it++)
    {
        results.push_back(*it);
    }

    CHECK(results == std:: vector<int>{1,5,2,4,3});

    MyContainer<std:: string> con2;
    con2.add("abc");
    con2.add("aabc");
    con2.add("ff");
    con2.add("dd");

    std:: vector<std:: string> res;
    for (auto it = con2.begin_sidecross_order(); it != con2.end_sidecross_order(); ++it)
    {
        res.push_back(*it);
    }

    CHECK(res == std:: vector<std:: string>{"aabc", "ff", "abc", "dd"});    
    

}

