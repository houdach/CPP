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
    void insertPendingGeneric(Container &mainChain, const Container &pendingChain, const PmergeMe &pm)
    {
        int size = pendingChain.size();
        std::vector<int> order;
        int k = 1;
        while (pm.jacobsthal(k) < size)
        {
            order.push_back(pm.jacobsthal(k));
            ++k;
        }

        std::vector<bool> used(size + 1, false);
        for (size_t i = 0; i < order.size(); ++i)
            used[order[i]] = true;

        for (int i = 1; i <= size; ++i)
            if (!used[i])
                order.push_back(i);

        for (size_t i = 0; i < order.size(); ++i)
        {
            int idx = order[i] - 1;
            if (idx >= 0 && idx < size)
            {
                typename Container::iterator pos =
                    std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[idx]);
                mainChain.insert(pos, pendingChain[idx]);
            }
        }
    }
};

#endif
