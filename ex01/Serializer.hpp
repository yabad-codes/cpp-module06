/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:06:00 by yabad             #+#    #+#             */
/*   Updated: 2023/11/19 16:01:49 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>

struct Data {
    int key;
};

class Serializer {
    private:
        Serializer();
        Serializer(const Serializer&);
        ~Serializer();
        Serializer& operator=(const Serializer&);
    public:
        static uintptr_t    serialize(Data* ptr);
        static Data*    deserialize(uintptr_t raw);
};

#endif