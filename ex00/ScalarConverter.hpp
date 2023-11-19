/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 10:14:06 by yabad             #+#    #+#             */
/*   Updated: 2023/11/19 14:18:21 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <limits.h>

enum scalarType {
    NAN,
    INT,
    CHAR,
    FLOAT,
    DOUBLE,
    INF
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter&);
        ScalarConverter& operator=(const ScalarConverter&);
        ~ScalarConverter();
    public:
        static void convert(const std::string&);
        class ErrorException: public std::exception {
            public:
                const char  *what() const throw();
        };
};

#endif