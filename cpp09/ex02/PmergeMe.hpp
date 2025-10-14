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

    void mergeInsertSortVector(std::vector<int> &vec);
    void mergeInsertSortDeque(std::deque<int> &dq);

    void mergeVector(std::vector<int> &vec, int left, int mid, int right);
    void mergeDeque(std::deque<int> &dq, int left, int mid, int right);

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
