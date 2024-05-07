#include "PmergeMe.hpp"

int isNumeric(char *num)
{
    int i = 0;
    while (num[i] && isspace(num[i]))
        i++;
    if (num[i] == '+' || num[i] == '-')
        i++;
    while (num[i] && isdigit(num[i]))
        i++;
    if (!num[i])
        return 1;
    return 0;
}

template <typename T>
int PmergeMe::Duplicates(T& container)
{
    typename T::iterator it = container.begin();
    typename T::iterator it2;

    while (it != container.end())
    {
        it2 = it + 1;
        while (it2 != container.end())
        {
            if (*it == *it2)
                return 0;
            it2++;
        } 
        it++;
    }
    return 1;
}

template <typename T>
void    PmergeMe::Display(T& container)
{
    typename T::iterator it;
    it = container.begin();
    while (it != container.end())
    {
		std::cout << *it << " ";
        it++;
    }
    std::cout<<std::endl;
}

PmergeMe::PmergeMe(int argc, char **argv)
{
    int i = 1;
    while (i < argc)
    {
        if (isNumeric(argv[i]))
        {
            vec.push_back(std::atoi(argv[i]));
            deq.push_back(std::atoi(argv[i]));
        }
        else
            throw std::runtime_error("Error : not a number");
        i++;
    }
    if (!Duplicates(this->vec) || !Duplicates(this->deq))
        throw std::runtime_error("Error: Duplicated numbers");
    this->Magic();
}

void    PmergeMe::Magic()
{
    std::cout<<"Before : ";
    this->Display(this->vec);
    std::cout<<"After : ";
    clock_t deq_time = this->sort(this->deq);
    clock_t vec_time = this->sort(this->vec);
    this->Display(this->vec);
    std::cout<<"Time to process a range of "<<this->vec.size()<<" elements with std::vector : "<<static_cast<double>(vec_time)<<" us"<<std::endl;
    std::cout<<"Time to process a range of "<<this->deq.size()<<" elements with std::deque : "<<static_cast<double>(deq_time)<<" us"<<std::endl;   
}

template <typename T>
clock_t PmergeMe::sort(T& vec)
{
    clock_t start, end;
    T lower_nums;
    start = clock();
    if (vec.size() > 1)
    {
        for (size_t i = 0; i < vec.size() - 1; i++)
        {
            if (vec[i] < vec[i + 1])
            {
                lower_nums.push_back(vec[i]);
                vec.erase(vec.begin() + i);
            }
            else
            {
                lower_nums.push_back(vec[i + 1]);
                vec.erase(vec.begin() + i + 1);
            }
        }
        this->sort(vec);
    }
    while (lower_nums.size() > 0)
    {
        int index = this->BinarySearch(0, vec.size() - 1, lower_nums[0], vec);
        vec.insert(vec.begin() + index, lower_nums[0]);
        lower_nums.erase(lower_nums.begin());
    }
    end = clock();
    return (end - start);
}

template <typename T>
int PmergeMe::BinarySearch(int left, int right, int value, T& vec)
{
    if (right >= left)
    {
        int mid = left + (right - left) / 2;
        if (vec[mid] > value)
            return (this->BinarySearch(left, mid - 1, value, vec));
        return (this->BinarySearch(mid + 1, right, value, vec));
    }
    return (left);
}

PmergeMe::~PmergeMe() {}