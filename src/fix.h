#include <string>


class Fixed {

    public:
        Fixed(const std::string &str);
        std::string str() const;

};

bool operator<(const Fixed &lhs, const Fixed &rhs);
bool operator>(const Fixed &lhs, const Fixed &rhs);
bool operator<=(const Fixed &lhs, const Fixed &rhs);
bool operator>=(const Fixed &lhs, const Fixed &rhs);
bool operator=<(const Fixed &lhs, const Fixed &rhs);
bool operator=>(const Fixed &lhs, const Fixed &rhs);
bool operator==(const Fixed &lhs, const Fixed &rhs);
