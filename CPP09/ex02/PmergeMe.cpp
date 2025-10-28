#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) 
{
    *this = other;
}

PmergeMe&
PmergeMe::operator=(const PmergeMe& other) 
{
    if (this != &other) {
        _vector = other._vector;
        _list = other._list;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}


void PmergeMe::parseAndInsert(int argc, char **argv)
{
    if (argc < 2)
        throw std::invalid_argument("No numbers provided.");

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        // Rule 1: Must not be empty and must contain only digits.
        if (arg.empty()) {
            throw std::invalid_argument("empty argument");
        }
        for (size_t j = 0; j < arg.length(); ++j) {
            if (!std::isdigit(arg[j])) {
                throw std::invalid_argument("non-digit character");
            }
        }

        char* end = NULL;
        long long value = std::strtol(argv[i], &end, 10);
        if (value > INT_MAX)
            throw std::invalid_argument("value too large");

        int int_value = static_cast<int>(value);
        if (std::find(_vector.begin(), _vector.end(), int_value) == _vector.end()) {
            _vector.push_back(int_value);
            _list.push_back(int_value);
        }
        else
            throw std::invalid_argument("duplicate value");
    }

    if (_vector.empty())
        throw std::invalid_argument("no valid numbers found");
    std::vector<int> sorted_vector = _vector;
    std::sort(sorted_vector.begin(), sorted_vector.end());
    if (sorted_vector == _vector)
        throw std::invalid_argument("input is already sorted");
}


void
PmergeMe::fordJohnsonlist(std::list<int>& lst)
{
    if (lst.size() < 2)
        return;

    int straggler = -1;
    if (lst.size() % 2 != 0)
    {
        straggler = lst.back();
        lst.pop_back();
    }

    std::list<std::pair<int, int> > pairs;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end();)
    {
        int a = *it++;
        int b = *it++;
        if (a < b)
            pairs.push_back(std::make_pair(b, a));
        else
            pairs.push_back(std::make_pair(a, b));
    }

    std::list<int> main_chain;
    std::list<int> pend_chain;
    for (std::list<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); ++it)
    {
        main_chain.push_back(it->first);
        pend_chain.push_back(it->second);

    }
    fordJohnsonlist(main_chain);

    for (std::list<int>::iterator it = pend_chain.begin(); it != pend_chain.end(); ++it)
    {
        std::list<int>::iterator pos = main_chain.begin();
        while (pos != main_chain.end() && *pos < *it) {
            ++pos;
        }
        main_chain.insert(pos, *it);
    }

    if (straggler != -1)
    {
        std::list<int>::iterator pos = main_chain.begin();
        while (pos != main_chain.end() && *pos < straggler) {
            ++pos;
        }
        main_chain.insert(pos, straggler);
    }

    lst = main_chain;
}
void
PmergeMe::fordJohnsonVector(std::vector<int>& vec)
{
    if (vec.size() < 2)
        return;

    int straggler = -1;
    if (vec.size() % 2 != 0)
    {
        straggler = vec.back();
        vec.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < vec.size(); i += 2) {
        if (vec[i] < vec[i + 1]) {
            pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
        } else {
            pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
        }
    }

    std::vector<int> main_chain;
    std::vector<int> pend_chain;
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main_chain.push_back(pairs[i].first);
        pend_chain.push_back(pairs[i].second);

    }
    fordJohnsonVector(main_chain);

    for (size_t i = 0; i < pend_chain.size(); ++i)
    {
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[i]);
        main_chain.insert(it, pend_chain[i]);
    }

    if (straggler != -1)
    {
        std::vector<int>::iterator it = std::lower_bound(main_chain.begin(), main_chain.end(), straggler);
        main_chain.insert(it, straggler);
    }

    vec = main_chain;
}
    
void
PmergeMe::sortAndPrint(int argc, char **argv)
{
    parseAndInsert(argc, argv);

    std::cout << "Unsorted vector: ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Unsorted list: ";
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "=====================================================================================" << std::endl;

    timeval start_vec, end_vec;
    gettimeofday(&start_vec, NULL);
    fordJohnsonVector(_vector);
    gettimeofday(&end_vec, NULL);

    timeval start_list, end_list;
    gettimeofday(&start_list, NULL);
    fordJohnsonlist(_list);
    gettimeofday(&end_list, NULL);

    std::cout << "Sorted vector: ";
    for (size_t i = 0; i < _vector.size(); ++i) {
        std::cout << _vector[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sorted list: ";
    for (std::list<int>::const_iterator it = _list.begin(); it != _list.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl << "=====================================================================================" << std::endl;

    long seconds_vec = end_vec.tv_sec - start_vec.tv_sec;
    long micros_vec = end_vec.tv_usec - start_vec.tv_usec;
    _vectorTime = seconds_vec * 1000000.0 + micros_vec;

    long seconds_list = end_list.tv_sec - start_list.tv_sec;
    long micros_list = end_list.tv_usec - start_list.tv_usec;
    _listTime = seconds_list * 1000000.0 + micros_list;


    std::cout << "Time taken for std::vector to sort " << _vector.size() << " elements: " << _vectorTime << " microseconds" << std::endl;
    std::cout << "Time taken for std::list to sort " << _list.size() << " elements: " << _listTime << " microseconds" << std::endl;
}

