#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<graphics.h>
#define STR_SIZE 20
#define STR_NUM 128
#define STR_WIDTH 15
#define WIDTH 1024
#define HEIGHT 768

struct Rain
{
    int x;
    int y;
    int speed;
    char str[STR_SIZE];
}rain[STR_NUM]


char Creatcharrain(){
    char temp = 0;
    temp = rand()%26;
    return temp;
}

int main(){
    srand((unsigned)time(NULL));
    for(int i=0;i<20;i++){
        putchar(Creatcharrain());
    }
    getchar();
    return 0;
}