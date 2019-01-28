#include "header.h"

/**********************************************************************
@name           :
@description    :
@param
@return
**********************************************************************/
unsigned int generateRandom(int min, int max)
{
    unsigned int num = 0;
    unsigned int tmp = 0;
    struct timeval tp;

    gettimeofday(&tp, NULL);
    srand(tp.tv_usec);
    num = rand();

    /* restirict within min and max */
    tmp = (num % max) + min;

    /* Wrap around */
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

