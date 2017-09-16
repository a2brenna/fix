#include <iostream>
#include <limits>
#include <map>

#include "fix.h"

int main(){

    std::cout << std::numeric_limits<int64_t>::max() << std::endl;

    std::cout << "10 ** 8 = " << pow(10, 8) << std::endl;

    {
        const std::string t = "0.0001";
        fix::Fixed f(t);
        std::cout << f.str() << std::endl;
    }
    {
        const std::string t = "1.0001";
        fix::Fixed f(t);
        std::cout << f.str() << std::endl;
    }
    {
        const std::string t = "10000.0001";
        fix::Fixed f(t);
        std::cout << f.str() << std::endl;
    }
    {
        const std::string t = "92233720368.54775807";
        fix::Fixed f(t);
        std::cout << f.str() << std::endl;
    }
    {
        const std::string t = "-92233720368.54775807";
        fix::Fixed f(t);
        std::cout << f.str() << std::endl;
    }
    {
        const std::string t = "0.0001";
        fix::Fixed f(t);
        std::cout << f.str() << std::endl;
    }
    {
        fix::Fixed f(1);
        std::cout << f.str() << std::endl;
    }

    std::cout << (fix::Fixed(1) > fix::Fixed(0)) << std::endl;
    std::cout << (fix::Fixed(1) < fix::Fixed(0)) << std::endl;
    std::cout << (fix::Fixed(1) == fix::Fixed(1)) << std::endl;

    std::map<fix::Fixed, fix::Fixed> m;
    m[fix::Fixed(1)] = fix::Fixed(0);

    return 0;
}
