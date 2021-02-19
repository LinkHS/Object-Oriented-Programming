#include "parity.h" // Don't add any additional libraries/namespaces!

int a[10];
int b[10];

int *a;
int *b;

1. 指针的地址
2. 指针的内容
3. 指针内容指向的内容


parity_a = parity_b;


Parity::Parity(const Parity &other)
{
    nEven_ = other.nEven_;
    nOdd_ = other.nOdd_;
    evens_ = new int[nEven_];
    odds_ = new int[nOdd_];

    this->evens_ = other.evens_;
    this->odds_ = other.odds_;

    this = other;

    // memcpy
    // for (size_t i = 0; i < nEven_; i++)
    // {
    //     evens_[i] = other.evens_[i];
    // }
    // for (size_t i = 0; i < nOdd_; i++)
    // {
    //     odds_[i] = other.odds_[i];
    // }
}

Parity::~Parity()
{
    delete[] evens_;
    delete[] odds_;
    evens_ = nullptr;
    odds_ = nullptr;
    nEven_ = nOdd_ = 0;
}

Parity &Parity::operator=(const Parity &rhs)
{
    if (nEven_ != rhs.nEven_)
    {
        delete[] this->evens_;
        evens_ = new int[rhs.nEven_ + rhs.nEven_%5];
        nEven_ = rhs.nEven;
    }

    for (size_t i = 0; i < rhs.nEven_; i++)
    {
        evens_[i] = rhs.evens_[i];
    }


    if (nOdd_ != rhs.nOdd_)
    {
        size_t size = 0;
        if ((rhs.nOdd_ % 5 == 0) || (rhs.nOdd_ % 5 == 5))
        {
            size = rhs.nOdd_;
        }
        else
        {
            size = (rhs.nOdd_ / 5 + 1) * 5;
        }
        nOdd_ = rhs.nOdd_;
        delete[] odds_;
        odds_ = new int[size];
    }
    for (size_t i = 0; i < rhs.nOdd_; i++)
    {
        odds_[i] = rhs.odds_[i];
    }
    return *this;
}

void Parity::insert(int val)
{
    size_t sizeeven = 0;
    size_t sizeodd = 0;
    if (val % 2 == 0)
    {
        sizeeven = nEven_;
        if ((nEven_ % CAP == 0) || (nEven_ % CAP == CAP))
        {
            sizeeven = nEven_ + CAP;
            int *arr = new int[sizeeven];
            for (size_t i = 0; i < nEven_; i++)
            {
                arr[i] = evens_[i];
            }
            delete[] evens_;
            evens_ = arr;
        }
        evens_[nEven_] = val;
        nEven_++;
    }
    else
    {
        sizeodd = nOdd_;
        if ((nOdd_ % CAP == 0) || (nOdd_ % CAP == CAP))
        {
            sizeodd = nOdd_ + CAP;
            int *arr = new int[sizeodd];
            for (size_t i = 0; i < nOdd_; i++)
            {
                arr[i] = odds_[i];
            }
            delete[] odds_;
            odds_ = arr;
        }
        odds_[nOdd_] = val;
        nOdd_++;
    }
}

int Parity::min() const
{
    int min = INT_MAX;
    for (int i = 0; i < nEven_; i++)
    {
        if (min > evens_[i])
        {
            min = evens_[i];
        }
    }
    for (int i = 0; i < nOdd_; i++)
    {
        if (min > odds_[i])
        {
            min = odds_[i];
        }
    }
    return min;
}

int Parity::max() const
{
    int max = INT_MIN;
    for (int i = 0; i < nEven_; i++)
    {
        if (max < evens_[i])
        {
            max = evens_[i];
        }
    }
    for (int i = 0; i < nOdd_; i++)
    {
        if (max < odds_[i])
        {
            max = odds_[i];
        }
    }
    return max;
}

bool Parity::odd() const
{
    if (nOdd_ % 2 == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}
// couts two lines of text representing the even and odd values, respectively
void Parity::printAll() const
{
    std::cout << "Evens: ";
    for (size_t i = 0; i < nEven_; i++)
        std::cout << evens_[i] << ", ";
    std::cout << "\nOdds: ";
    for (size_t i = 0; i < nOdd_; i++)
        std::cout << odds_[i] << ", ";
    std::cout << std::endl;
}
