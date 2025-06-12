//melissaliebowitz@yahoo.com
#include <iostream>
#include <string>
#include "MyContainer.hpp"
using namespace container;

int main()
{   
    MyContainer<int> con;
    con.add(1);
    con.add(2);
    con.add(3);
    con.add(4);
    con.add(5);
    

    MyContainer<std:: string> container;
    container.add("hello");
    container.add("world");
    container.add("jar");
    container.add("doll");


    std:: cout << "Size of con: " << con.size() << std:: endl;
    con.print();
    std:: cout << std:: endl;

    std:: cout << "Size of container: " << con.size() << std:: endl;
    container.print();
    std:: cout << std:: endl;

    std:: cout << "Iterators: " << std:: endl;

    std:: cout << "Ascending Order: " << std:: endl;
    for (auto it = container.begin_ascending_order(); it != container.end_ascending_order(); ++it)
    {
        std:: cout << *it << " ";
    }
    std:: cout << std:: endl;
    std:: cout << std:: endl;

    std:: cout << "Descending Order: " << std:: endl;
    for (auto it = con.begin_descending_order(); it != con.end_descending_order(); it++)
    {
        std:: cout << *it << " ";
    }
    std:: cout << std:: endl;
    std:: cout << std:: endl;


    std:: cout << "Normal Order: " << std:: endl;
    for (auto i = container.begin_order(); i != container.end_order(); ++i)
    {
        std:: cout << *i << " ";
    }
    std:: cout << std:: endl;
    std:: cout << std:: endl;


    std:: cout << "Reverse Order: " << std:: endl;
    for (auto i = container.begin_reverse_order(); i != container.end_reverse_order(); i++)
    {
        std:: cout << *i << " ";
    }
    std:: cout << std:: endl;
    std:: cout << std:: endl;


    std:: cout << "Criss Cross Order" << std:: endl;
    for (auto it = container.begin_sidecross_order(); it != container.end_sidecross_order(); it++)
    {
        std:: cout << *it << " ";
    }

    std:: cout << std:: endl;
    std:: cout << std:: endl;


    std:: cout << "Middle Out Of Order:" << std:: endl;
    for (auto it = con.begin_middle_order(); it != con.end_middle_order(); ++it)
    {
        std:: cout << *it << " ";
    }
    std:: cout << std:: endl;
  
    return 0;
}