#include <iostream>
#include <thread>
#include <vector>
std::vector<int> fibonaccies;
void fib(int x)
{
    if(x == 0)
    {
        fibonaccies[0] = 0;
        return;
    }
    else if(x == 1)
    {
        fibonaccies[0] = 0;
        fibonaccies[1] = 1;
        return;
    }
    fibonaccies[0] = 0;
    fibonaccies[1] = 1;
    for(int i = 2; i <= x; i++) 
    {
        fibonaccies[i] = fibonaccies[i-1] + fibonaccies[i-2];
    }
}

int main() 
{
    int number;
    std::cout << "Enter the number of fibonaccies you wish to generate\n";
    std::cin >> number;
    fibonaccies.insert(fibonaccies.begin(), number+1, 0);
    std::thread t1(fib, number);
    t1.join();

    for(unsigned int i = 0; i < fibonaccies.size(); i++) 
    {
        std::cout << fibonaccies[i] << ' ';
        if(i % 10 == 0 && i != 0) 
        {
            std::cout << '\n';
        }
    }
    return 0;
}