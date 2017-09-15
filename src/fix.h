#include <string>

class FIX_E_INPUT {};

class Fixed {

    public:
        Fixed(const std::string &str);
        std::string str() const;
        int64_t internal() const;

    private:
        int64_t _internal;

};

bool operator<(const Fixed &lhs, const Fixed &rhs);
bool operator>(const Fixed &lhs, const Fixed &rhs);
bool operator<=(const Fixed &lhs, const Fixed &rhs);
bool operator>=(const Fixed &lhs, const Fixed &rhs);
bool operator==(const Fixed &lhs, const Fixed &rhs);
