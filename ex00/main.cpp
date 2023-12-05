#include "include/easyfind.hpp"

int main() {
    std::vector<int> vecTest;

    for (int i = 0; i < 10; i++) {
        vecTest.push_back(i);
    }

    easyfind(vecTest, 3);
    easyfind(vecTest, 9);
    easyfind(vecTest, 12);
}