#include<stdio.h>
#include<sys/types.h>
#include<stdint.h>


typedef union
{
    uint16_t value;
    unsigned char byte[2];
}tos;

typedef union 
{
    uint32_t value;
    unsigned char byte[4];
}tol;

void print_htons(uint16_t val)
{
    tos s;
    s.value = val;
    printf("0x%x\n",s.value);
    printf("0x%x%x",s.byte[0],s.byte[1]);
}


int main(void)
{
    uint16_t val = 0xaabb;
    print_htons(val);
}
