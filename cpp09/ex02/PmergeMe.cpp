#include "PmergeMe.hpp"
#include <ctime>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <algorithm>

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
    if (str.empty()) return false;
    for (size_t i = 0; i < str.size(); ++i)
        if (str[i] < '0' || str[i] > '9') return false;
    return true;
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
        int value = atoi(s.c_str());
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

void PmergeMe::mergeVector(std::vector<int> &vec, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) L[i] = vec[left + i];
    for (int j = 0; j < n2; ++j) R[j] = vec[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) vec[k++] = L[i++];
        else vec[k++] = R[j++];
    }
    while (i < n1) vec[k++] = L[i++];
    while (j < n2) vec[k++] = R[j++];
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &vec)
{
    int n = vec.size();
    if (n <= 1) return;

    for (int size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n - size; left += 2*size)
        {
            int mid = left + size - 1;
            int right = std::min(left + 2*size - 1, n - 1);
            mergeVector(vec, left, mid, right);
        }
    }
}

void PmergeMe::mergeDeque(std::deque<int> &dq, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::deque<int> L, R;
    for (int i = 0; i < n1; ++i) L.push_back(dq[left + i]);
    for (int j = 0; j < n2; ++j) R.push_back(dq[mid + 1 + j]);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j]) dq[k++] = L[i++];
        else dq[k++] = R[j++];
    }
    while (i < n1) dq[k++] = L[i++];
    while (j < n2) dq[k++] = R[j++];
}

void PmergeMe::mergeInsertSortDeque(std::deque<int> &dq)
{
    int n = dq.size();
    if (n <= 1) return;

    for (int size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n - size; left += 2*size)
        {
            int mid = left + size - 1;
            int right = std::min(left + 2*size - 1, n - 1);
            mergeDeque(dq, left, mid, right);
        }
    }
}

void PmergeMe::sortAndDisplay()
{
    std::cout << "Before: ";
    for (size_t i = 0; i < vectorData.size(); ++i)
        std::cout << vectorData[i] << " ";
    std::cout << std::endl;

    std::vector<int> vecCopy = vectorData;
    clock_t startVec = clock();
    mergeInsertSortVector(vecCopy);
    clock_t endVec = clock();

    std::deque<int> dqCopy = dequeData;
    clock_t startDq = clock();
    mergeInsertSortDeque(dqCopy);
    clock_t endDq = clock();

    std::cout << "After: ";
    for (size_t i = 0; i < vecCopy.size(); ++i)
        std::cout << vecCopy[i] << " ";
    std::cout << std::endl;

    double timeVec = double(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDq  = double(endDq - startDq) / CLOCKS_PER_SEC * 1000000;

    std::cout << "Time to process a range of " << vecCopy.size()
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << timeVec << " us" << std::endl;

    std::cout << "Time to process a range of " << dqCopy.size()
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << timeDq << " us" << std::endl;
}
