#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <vector>
#include <deque>

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &other)
    : vectorData(other.vectorData), dequeData(other.dequeData) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        vectorData = other.vectorData;
        dequeData  = other.dequeData;
    }
    return *this;
}

bool PmergeMe::isValidNumber(const std::string &str) const
{
    for (size_t i = 0; i < str.size(); ++i)
        if (str[i] < '0' || str[i] > '9') return false;
    return !str.empty();
}

bool PmergeMe::loadData(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::string s(argv[i]);
        if (!isValidNumber(s))
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        int value = std::atoi(s.c_str());
        if (value <= 0)
        {
            std::cerr << "Error" << std::endl;
            return false;
        }
        vectorData.push_back(value);
        dequeData.push_back(value);
    }
    return true;
}

int PmergeMe::jacobsthal(int n) const
{
    if (n == 0) return 0;
    if (n == 1) return 1;
    return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

void PmergeMe::insertPendingVector(std::vector<int> &mainChain, const std::vector<int> &pendingChain)
{
    for (size_t i = 0; i < pendingChain.size(); ++i)
    {
        std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[i]);
        mainChain.insert(pos, pendingChain[i]);
    }
}

void PmergeMe::insertPendingDeque(std::deque<int> &mainChain, const std::deque<int> &pendingChain)
{
    for (size_t i = 0; i < pendingChain.size(); ++i)
    {
        std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), pendingChain[i]);
        mainChain.insert(pos, pendingChain[i]);
    }
}

void PmergeMe::mergeInsertSortVector()
{
    std::vector<int> mainChain;
    std::vector<int> pendingChain;
    int n = vectorData.size();

    for (int i = 0; i + 1 < n; i += 2)
    {
        if (vectorData[i] <= vectorData[i + 1])
        {
            mainChain.push_back(vectorData[i + 1]);
            pendingChain.push_back(vectorData[i]);
        }
        else
        {
            mainChain.push_back(vectorData[i]);
            pendingChain.push_back(vectorData[i + 1]);
        }
    }
    if (n % 2 != 0)
        pendingChain.push_back(vectorData[n - 1]);

    std::sort(mainChain.begin(), mainChain.end());
    insertPendingVector(mainChain, pendingChain);
    vectorData = mainChain;
}

void PmergeMe::mergeInsertSortDeque()
{
    std::deque<int> mainChain;
    std::deque<int> pendingChain;
    int n = dequeData.size();

    for (int i = 0; i + 1 < n; i += 2)
    {
        if (dequeData[i] <= dequeData[i + 1])
        {
            mainChain.push_back(dequeData[i + 1]);
            pendingChain.push_back(dequeData[i]);
        }
        else
        {
            mainChain.push_back(dequeData[i]);
            pendingChain.push_back(dequeData[i + 1]);
        }
    }
    if (n % 2 != 0)
        pendingChain.push_back(dequeData[n - 1]);

    std::sort(mainChain.begin(), mainChain.end());
    insertPendingDeque(mainChain, pendingChain);
    dequeData = mainChain;
}

void PmergeMe::sortAndDisplay()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorData.size(); ++i)
        std::cout << vectorData[i] << " ";
    std::cout << std::endl;

    clock_t startVec = clock();
    mergeInsertSortVector();
    clock_t endVec = clock();

    clock_t startDq = clock();
    mergeInsertSortDeque();
    clock_t endDq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vectorData.size(); ++i)
        std::cout << vectorData[i] << " ";
    std::cout << std::endl;

    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDq  = double(endDq - startDq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vectorData.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << dequeData.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDq << " us" << std::endl;
}
