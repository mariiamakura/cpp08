#include "include/MutantStack.hpp"
#include <list>

void pdfTest() {
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    std::cout << "-----------------" << std::endl;
    mstack.pop(); //Removes the element on top of the stack, effectively reducing its size by one.
    std::cout << "size: " << mstack.size() << std::endl;
    std::cout << "-----------------" << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737); //[...] mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    //std::cout << "TOP " << mstack.top() << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    //added
    MutantStack<int> test(mstack);
}

void listTest() {
    std::list<int> lstack;
    std::cout << "#######LIST############" <<std::endl;
    lstack.push_front(5);
    lstack.push_front(17);
    std::cout << lstack.front() << std::endl;
    std::cout << "-----------------" << std::endl;
    lstack.pop_front(); //Removes the element on top of the stack, effectively reducing its size by one.
    std::cout << lstack.size() << std::endl;
    std::cout << "-----------------" << std::endl;
    lstack.push_front(3);
    lstack.push_front(5);
    lstack.push_front(737); //[...] lstack.push_front(0);
    std::list<int>::reverse_iterator it = lstack.rbegin();
    std::list<int>::reverse_iterator ite = lstack.rend();
    ++it;
    --it;
    //std::cout << "TOP " << lstack.front() << std::endl;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    //std::stack<int> s(lstack);

    //added
    std::list<int> test(lstack);
}

int main()
{
    pdfTest();
    listTest();


}