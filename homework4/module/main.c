// main.c

#include <stdio.h>
#include "module.h"

// 定义全局变量
int g_magic_number = 10;

int main() {
    // 调用并打印函数的返回值
    printf("Function 1 returns: %d\n", func1());
    printf("Function 2 returns: %d\n", func2());

    // 打印全局变量的值
    printf("Global variable value: %d\n", g_magic_number);

    return 0;
}
