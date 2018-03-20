#include "stdio.h"


int main(int argc, char const *argv[])
{
    int i = 0;
    loop:
    printf("%i\n", i);
    i++;
    if (i < 10) {
        goto loop;
    }

    for (i = 0; i < 10; ++i)
    {
        printf("%i\n", i);
        goto loop;
    }

    return 0;
}