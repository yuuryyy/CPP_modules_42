#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <sys/time.h>
#include <climits>

//define red color
#define RED "\033[31m"
#define RESET "\033[0m"

class PmergeMe {
private:

    std::vector<int>    _vector;
    std::list<int>      _list;
    long long           _vectorTime;
    long long           _listTime;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void sortAndPrint(int argc, char **argv);

private:
    // Vector-specific implementation
    void fordJohnsonVector(std::vector<int>& vec);
    void parseAndInsert(int argc, char **argv);
    // Deque-specific implementation
    void fordJohnsonlist(std::list<int>& lst);
};

#endif