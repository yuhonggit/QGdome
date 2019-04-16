#include "delay.h"

//定义延时函数
void mdelay(unsigned int t)
{

    unsigned char n;
    for(; t>0; t--)
        for(n=0; n<125; n++)

        {;}
}