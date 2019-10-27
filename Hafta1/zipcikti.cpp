#include <iostream>
#include <time.h>

using namespace std;

bool isPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    
    for (int i = 2; i < num; i++)
        if (num % i == 0) return false;
    
    return true;
}

bool isZipcikti(int num)
{
    int total = 0;
    int last = num % 10;
    while (num > 0)
    {
        total += num % 10;
        num /= 10;
    }

    if (((total - last) == (last + 1)) && isPrime(total))
        return true;
    else
        return false;
}

int main()
{
    int input;
    cin >> input;

    clock_t start;
    double duration;
    start = clock();
    
    for (int i = 10; i <= input; i++)
        if (isZipcikti(i)) cout << i << endl;
    
    duration = (clock() - start) / (double)CLOCKS_PER_SEC;
    cout << endl;
    cout << "total time: " << duration << endl;
    
    return 0;
}