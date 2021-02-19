#include <iostream>
#include "lexicon.h"

using namespace std;

void swap(int &book, int money)
{
    int temp = book;
    book = money;
    money = temp;

    cout << "book: " << book << endl;
    cout << "money: " << money << endl;
}

void swap2(int *pbook, int *pmoney)
{
    //assert((pbook != nullptr) && (pmoney != nullptr));

    int temp = *pbook;
    *pbook = *pmoney;
    *pmoney = temp;
}

int main()
{
    int a1[] = {1, 2, 3};
    int *p = a1;

    int *p1 = new int;
    delete p1;
    
    return 0;
}