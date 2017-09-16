#include "fix.h"

#include <cassert>
#include <vector>
#include <boost/algorithm/string.hpp>

#include <iostream>

const size_t PRECISION = 8;

int64_t pow(const int64_t &base, const int64_t &exp){
    assert(base >= 1);
    assert(exp >= 1);

    int64_t r = 1;
    for(int64_t e = 1; e <= exp; e++){
        r *= base;
    }

    return r;
}

namespace fix {

    Fixed::Fixed(const int &i){
        _internal = i * pow(10, PRECISION);
    }

    Fixed::Fixed(){
        _internal = 0;
    }

    Fixed::Fixed(const std::string &str){
        std::vector<std::string> tokens;
        split(tokens, str, boost::is_any_of("."));

        const size_t num_tokens = tokens.size();

        if(num_tokens != 2){
            throw FIX_E_INPUT();
        }
        else{
            const std::string fractional = [](std::string b){
                if(b.size() > PRECISION){
                    throw FIX_E_INPUT();
                }
                else if(b.size() == PRECISION){

                }
                else if(b.size() < PRECISION){
                    b.append( PRECISION - b.size(), '0');
                }
                else{
                    assert(false);
                }

                return b;
            }(tokens[1]);

            const std::string padded = tokens[0] + fractional;

            _internal = std::stoll(padded, nullptr, 10);

            std::cout << _internal << std::endl;
        }
    }

    std::string Fixed::str() const{
        std::string s = std::to_string(_internal);

        if(s.size() < PRECISION){
            s.insert(0, PRECISION - s.size(), '0');
        }

        assert(s.size() >= PRECISION);

        s.insert(s.size() - PRECISION, 1, '.');

        if(s.front() == '.'){
            s.insert(0, 1, '0');
        }

        while(s.back() == '0'){
            s.pop_back();
        }

        if(s.back() == '.'){
            s.push_back('0');
        }

        return s;
    }

    int64_t Fixed::internal() const{
        return _internal;
    }

    bool Fixed::operator<(const Fixed &other) const{
        return _internal < other.internal();
    }

    bool Fixed::operator>(const Fixed &other) const{
        return _internal > other.internal();
    }

    bool Fixed::operator<=(const Fixed &other) const{
        return _internal <= other.internal();
    }

    bool Fixed::operator>=(const Fixed &other) const{
        return _internal >= other.internal();
    }

    bool Fixed::operator==(const Fixed &other) const{
        return _internal == other.internal();
    }

}

std::ostream& operator<<(std::ostream& os, const fix::Fixed& f){
    return os << f.str();
}
