#include<stdio.h>
int main(){
    /*char a[]={"C!YYDS!"};
    long long *b=a;
    printf("%lld",*b);
    这里是获取C！YYDS！这一个字符串对应的数字的代码，在c语言中使用printf输出时无论目标是什么实际上都是在读取存储的二进制数，
    而获取的这个数字对应的二进制数与C!YYDS！对应的二进制数是相同的，也就是说使用%s输出这个数时输出结果便是C!YYDS！。*/

    long long x =9380227253346627;
    printf("%s",&x);
    return 0;
}
