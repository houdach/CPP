#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>

class PmergeMe
{
private:
    std::vector<int> vectorData;
    std::deque<int>  dequeData;

    void mergeInsertSortVector();
    void mergeInsertSortDeque();

    int jacobsthal(int n) const;
    void insertPendingVector(std::vector<int> &mainChain, const std::vector<int> &pendingChain);
    void insertPendingDeque(std::deque<int> &mainChain, const std::deque<int> &pendingChain);

    bool isValidNumber(const std::string &str) const;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);

    bool loadData(int argc, char* argv[]);

    void sortAndDisplay();
};

#endif
