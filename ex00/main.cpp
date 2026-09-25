#include <iostream>
#include "Bureaucrat.hpp"
// null　コンストラクタに入れたい
//　入れ子クラスとは
int main()
{
    try
    {
        Bureaucrat a("A", 1);
        Bureaucrat b("B", 150);
        Bureaucrat c("C", 0);
        std::cout << a << b << c;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }



    return (0);
}