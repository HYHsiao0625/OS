#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    unsigned long page;
    unsigned long offset;
    unsigned long address;

    /* Page Number =  quotient of  address / 4KB and offset = remainder*/
    /*Below is the faster method of calculating the same*/
    address = atoll(argv[1]);

    page = address >> 12; /* Since page size is 4KB => 12 bits holding the virtual address*/
    offset = address & 0xfff;

    printf("The address %lu contains: \n", address);
    printf("page number = %lu\n",page);
    printf("offset = %lu\n", offset);


    return 0;
}