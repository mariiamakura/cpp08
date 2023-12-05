#pragma once

#include <iostream>
# include <string>
# include <exception>
# include <algorithm>

template <typename T>
bool easyfind(T &container, int num) {
    typename T::iterator res = std::find(container.begin(), container.end(), num);
    if (res != container.end()) {
        std::cout << "Value found" << std::endl;
        return (true);
    } else {
        std::cout << "Value not found" << std::endl;
        return (false);
    }

}