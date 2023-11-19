/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabad <yabad@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:38:10 by yabad             #+#    #+#             */
/*   Updated: 2023/11/19 19:48:12 by yabad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data    mydata = { 42 };
    Data*   dataptr = &mydata;
    uintptr_t   serialized = Serializer::serialize(dataptr);
    Data*   deserialized = Serializer::deserialize(serialized);
    std::cout << deserialized->key << std::endl;
    return (0);
}