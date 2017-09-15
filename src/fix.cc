#include "fix.h"

#include <cassert>
#include <vector>
#include <boost/algorithm/string.hpp>

#include <iostream>

const size_t PRECISION = 8;

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

    return s;
}

int64_t Fixed::internal() const{
    return _internal;
}

bool operator<(const Fixed &lhs, const Fixed &rhs){
    return lhs.internal() < rhs.internal();
}

bool operator>(const Fixed &lhs, const Fixed &rhs){
    return lhs.internal() > rhs.internal();
}

bool operator<=(const Fixed &lhs, const Fixed &rhs){
    return lhs.internal() <= rhs.internal();
}

bool operator>=(const Fixed &lhs, const Fixed &rhs){
    return lhs.internal() >= rhs.internal();
}

bool operator==(const Fixed &lhs, const Fixed &rhs){
    return lhs.internal() == rhs.internal();
}
