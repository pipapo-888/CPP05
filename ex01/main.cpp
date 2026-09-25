#include <iostream>
#include "Bureaucrat.hpp"
// null　コンストラクタに入れたい
//　入れ子クラスとは
int main()
{
    try
    {
        Bureaucrat a("A", 2);
        std::cout << a;
        ++a;
        std::cout << a;
        ++a;
        std::cout << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    std::cout << "------------\n";

    try
    {
        Bureaucrat a("B", 0);
        std::cout << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "------------\n";
    try
    {
        Bureaucrat a("C", 148);
        std::cout << a;
        --a;
        std::cout << a;
        --a;
        std::cout << a;
        --a;
        std::cout << a;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }


    return (0);
}