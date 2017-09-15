#include <iostream>
#include <limits>

#include "fix.h"

int main(){

    std::cout << std::numeric_limits<int64_t>::max() << std::endl;

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


    return 0;
}
