#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

class PmergeMe
{
private:
    std::vector<int> vectorData;
    std::deque<int>  dequeData;

    void mergeInsertSortVector();
    void mergeInsertSortDeque();

    void insertPendingVector(std::vector<int> &mainChain, const std::vector<int> &pendingChain);
    void insertPendingDeque(std::deque<int> &mainChain, const std::deque<int> &pendingChain);

    bool isValidNumber(const std::string &str) const;

public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    int jacobsthal(int n) const;
    bool loadData(int argc, char* argv[]);
    void sortAndDisplay();

    template <typename Container>
    void insertPendingGeneric(Container &mainChain, const Container &pendingChain)
    {
        int size = pendingChain.size();
        if (size == 0) return;

        Container copyPending = pendingChain;

        std::vector<int> order;
        int k = 0;
        while (true)
        {
            int j = jacobsthal(k);
            if (j >= size) break;
            if (order.empty() || order.back() != j)
                order.push_back(j);
            ++k;
        }
        std::vector<bool> used(size, false);
        for (size_t i = 0; i < order.size(); ++i) used[order[i]] = true;
        for (int i = 0; i < size; ++i)
            if (!used[i])
                order.push_back(i);

        for (size_t i = 0; i < order.size(); ++i)
        {
            int idx = order[i];
            typename Container::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), copyPending[idx]);
            mainChain.insert(pos, copyPending[idx]);
        }
    }

};

#endif
