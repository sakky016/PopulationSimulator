#include<iostream>
#include <sys/time.h>
#include<stdlib.h>
#include <time.h>


using namespace std;

unsigned int generateRandom(int min, int max)
{
    unsigned int num = 0;
    unsigned int tmp = 0;
    struct timeval tp;

    gettimeofday(&tp, NULL);
    srand(tp.tv_usec);

    num = rand();

    tmp = (num % max) + min;

    if (tmp > max)
    {
        num = min + (tmp - max);
    }
    else
    {
        num = tmp;
    }

    return num; 
}

int main()
{
    int min = 10;
    int max = 100;
    int num = 0;
    int i = 0;

    
    while (i < 10)
    {
        num = generateRandom(min, max);
        cout<<num<<endl;
        i++;
    }

    return 0;
}

