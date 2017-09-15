#include <string>
#include <ostream>

namespace fix {

    class FIX_E_INPUT {};

    class Fixed {

        public:
            Fixed(const std::string &str);
            Fixed(const int &i);
            std::string str() const;
            int64_t internal() const;

        private:
            int64_t _internal;

    };

};

bool operator<(const fix::Fixed &lhs, const fix::Fixed &rhs);
bool operator>(const fix::Fixed &lhs, const fix::Fixed &rhs);
bool operator<=(const fix::Fixed &lhs, const fix::Fixed &rhs);
bool operator>=(const fix::Fixed &lhs, const fix::Fixed &rhs);
bool operator==(const fix::Fixed &lhs, const fix::Fixed &rhs);

std::ostream& operator<<(std::ostream& os, const fix::Fixed& f);

int64_t pow(const int64_t &base, const int64_t &exp);
