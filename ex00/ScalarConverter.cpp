/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:33:47 by yabad             #+#    #+#             */
/*   Updated: 2023/11/19 14:58:09 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#define NPOS std::string::npos

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {(void)other;}

ScalarConverter::~ScalarConverter() {}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return (*this);
}

bool    isInfType(const std::string& input) {
    return (input == "+inf" || input == "+inff" ||\
            input == "-inf" || input == "-inff");
}

bool    isIntType(const std::string& input, size_t length) {
    size_t  pos = 0;
    try {
        std::stoi(input, &pos);
        if (pos == length && input.find('.') == NPOS)
            return (true);
    } catch (...) {}
    return (false);
}

bool    isCharType(const std::string& input, size_t length) {
    return (length == 1 && !std::isdigit(input[0]));
}

bool    isFloatType(const std::string& input, size_t length) {
    size_t  pos = 0;
    try {
        std::stof(input, &pos);
        if (pos == length - 1 && input[pos] == 'f' && input.find('.') != NPOS)
            return (true);
    } catch (...) {}
    return (false);
}

bool    isDoubleType(const std::string& input, size_t length) {
    size_t  pos = 0;
    try {
        std::stod(input, &pos);
        if (pos == length && input.find('.') != NPOS)
            return (true);
    } catch (...) {}
    return (false);
}

scalarType  detectType(const std::string& input) {
    size_t  length = input.length();
    if (isInfType(input))
        return (INF);
    else if (isIntType(input, length))
        return (INT);
    else if (isCharType(input, length))
        return (CHAR);
    else if (isFloatType(input, length))
        return (FLOAT);
    else if (isDoubleType(input, length))
        return (DOUBLE);
    else
        return (NAN);
}

void    printNanCase() {
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << "nanf" << std::endl;
    std::cout << "double: " << "nan" << std::endl;
}

void    printInfCase(const std::string& input) {
    char    sign = input[0];
    std::cout << "char: " << "impossible" << std::endl;
    std::cout << "int: " << "impossible" << std::endl;
    std::cout << "float: " << sign << "inff" << std::endl;
    std::cout << "char: " << sign << "inf" << std::endl;
}

void    convertChar(const std::string& input, scalarType type) {
    if (type == CHAR)
        std::cout << "'" << input << "'" << std::endl;
    else {
        try {
            int result = std::stoi(input, nullptr);
            if (result > 31 && result < 127)
                std::cout << "'" << static_cast<char>(result) << "'" << std::endl;
            else if (result >= 0 && result <= 31)
                std::cout << "Non displayable" << std::endl;
            else
                throw ScalarConverter::ErrorException();
        } catch (...) {
            throw ScalarConverter::ErrorException();
        }
    }
}

void    convertInt(const std::string& input, scalarType type) {
    if (type == CHAR)
        std::cout << static_cast<int>(input[0]) << std::endl;
    else {
        try {
            double result = std::stod(input, nullptr);
            if (result > INT_MAX || result < INT_MIN)
                throw ScalarConverter::ErrorException();
            std::cout << static_cast<int>(result) << std::endl;
        } catch (...) {
            throw ScalarConverter::ErrorException();
        }
    }
}

void    convertFloat(const std::string& input, scalarType type) {
    if (type == CHAR) {
        std::cout << static_cast<int>(input[0]) << ".0f" << std::endl;
        return ;
    }
    try {
        float   result = std::stof(input, nullptr);
        if (result - static_cast<int>(result) == 0)
            std::cout << static_cast<int>(result) << ".0f" << std::endl;
        else
            std::cout << std::setprecision(4) << result << "f" << std::endl;    
    } catch (...) {
        throw ScalarConverter::ErrorException();
    }    
}

void    convertDouble(const std::string& input, scalarType type) { 
    if (type == CHAR) {
        std::cout << static_cast<int>(input[0]) << ".0" << std::endl;
        return ;
    }
    try {
        double  result = std::stod(input, nullptr);
        if (result - static_cast<int>(result) == 0)
            std::cout << static_cast<int>(result) << ".0" << std::endl;
        else
            std::cout << std::setprecision(4) << result << "f" << std::endl;   
    } catch (...) {
        throw ScalarConverter::ErrorException();
    }
}

void    printNormalCase(const std::string& input, scalarType type) {
    std::string types[4] = { "char", "int", "float", "double" };
    void    (*func[])(const std::string&, scalarType) = {convertChar, convertInt, convertFloat, convertDouble};
    for (int i = 0; i < 4; i++) {
        try {
            std::cout << types[i] << ": ";
            func[i](input, type);
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    }
}

void    printConversion(scalarType type, const std::string& input) {
    if (type == NAN)
        printNanCase();
    else if (type == INF)
        printInfCase(input);
    else
        printNormalCase(input, type);
}

void    ScalarConverter::convert(const std::string& input) {
    scalarType  type = detectType(input);
    printConversion(type, input);
}

const char *ScalarConverter::ErrorException::what() const throw() {
    return ("impossible");
}