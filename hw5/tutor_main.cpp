#include <iostream>
//#include "rational.h"
#include <vector>
using namespace std;

template <typename T>
void my_swap(T &t1, T &t2)
{
    T tmpT;
    tmpT = t1;
    t1 = t2;
    t2 = tmpT;
}

void TEST_my_swap(void)
{
    int a = 2, b = 3;
    // my_swap(2, 3); //
    my_swap(a, b); // my_swap<int> (a, b)
    cout << "a: " << a << ", b: " << b << endl;

    float fa = 2, fb = 3;
    my_swap(fa, fb);
    cout << "fa: " << fa << ", fb: " << fb << endl;

    char ca = 'a', cb = 'b';
    my_swap(ca, cb);
    cout << "ca: " << ca << ", cb: " << cb << endl;
}

template <typename T>
T avg(const T *beg, const T *end)
{
    T sum{};
    int cnt = 0;
    while (beg != end)
    {
        sum += *beg;
        ++beg;
        ++cnt;
    }
    return sum / cnt;
}

void TEST_avg(void)
{
    int a[] = {1, 2, 3, 4, 5};
    cout << "avg: " << avg(a, a + 5) << endl;

    char b[] = {'1', '2', '3', '4', '5'};
    cout << "avg: " << (int)avg(b, b+3) << endl;
}

template <typename T1, typename T2>
class HetPair
{
public:
    HetPair();
    HetPair(T1 t1, T2 t2) : t1_(t1), t2_(t2)
    {
        cout << "t1: " << t1 << "; t2: " << t2 << endl;
    };

    void print();

private:
    T1 t1_;
    T2 t2_;
};

void swap_int(int &a, int &b)
{
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    // TEST_my_swap();
    TEST_avg();

    // HetPair<int, int> h(1, 2);
    // h.print();

    // int a, b;
    // HetPair h(a, b);
}
