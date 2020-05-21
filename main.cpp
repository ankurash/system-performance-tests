#include <iostream>
#include <exception>
#include <vector>
#include <thread>
#include <chrono>
// #define maxval 10000000
using namespace std;

void doubleMultiplication(double max)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    double x;
    try
    {
        for(double i=1.5; i<max; i++)
        {
            for(double j=max+0.5; j>=1; j--)
            {
                x = i*j;
            }
        }
    }
    catch(exception& e)
    {
        cout<<"Double Multiplication exception.\n";
        return;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout<<"Double Multiplication Completed. "<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<" ns\n";
}

void integerMultiplication(int max)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int x;
    try
    {
        for(int i=1; i<max; i++)
        {
            for(int j=max; j>=1; j--)
            {
                x = i*j;
            }
        }
    }
    catch(exception& e)
    {
        cout<<"Integer Multiplication Exception.\n";
        return;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout<<"Integer Multiplication Completed. "<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<" ns\n";
}

void integerDivision(int max)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    int x;
    try
    {
        for(int i=1; i<max; i++)
        {
            for(int j=max; j>=1; j--)
            {
                x = i/j;
            }
        }
    }
    catch(exception& e)
    {
        cout<<"Integer Division Exception.\n";
        return;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout<<"Integer Division Completed. "<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<" ns\n";
}

void doubleDivision(double max)
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    double x;
    try
    {
        for(double i=1.5; i<max; i++)
        {
            for(double j=max+0.5; j>=1; j--)
            {
                x = i/j;
            }
        }
    }
    catch(exception& e)
    {
        cout<<"Double Division Exception.\n";
        return;
    }
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout<<"Double Division Completed. "<<std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count()<<" ns\n";
}

int main(int args, char** argv)
{
    double maxval=1000000;
    cout<<"enter max: ";
    cin>>maxval;
    vector<thread> threads;

    threads.push_back(thread(&integerMultiplication, maxval));
    // threads.push_back(thread(&integerMultiplication, maxval));
    threads.push_back(thread(&doubleMultiplication, maxval));
    threads.push_back(thread(&integerDivision, maxval));
    // threads.push_back(thread(&integerDivision, maxval));
    threads.push_back(thread(&doubleDivision, maxval));
    for (auto& th : threads) {
        th.join();
    }
    return 0;
}