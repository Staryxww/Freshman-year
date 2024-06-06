#include<stdio.h>
void generate(int n);
void print();
int result[8]={0};  //存储结果的数组
int column[8]={0};  //判断列是否被占用的数组
int d1[15]={0};     //主对角线
int d2[15]={0};     //副对角线
int number=0;
//通过设置全局变量的方式来简化参数传递
int main(){
    generate(0);
    return 0;
}

void generate(int n){
    int j;
    for(j=0;j<8;j++){
        if((column[j] != 1) && (d1[n-j+7] !=1) && (d2[n+j] != 1) ){
            result[n] = j;
            column[j] = 1;
            d1[n-j+7] = 1;
            d2[n+j] = 1; //判断能否在某个位置放皇后
            if(n<7){
                generate(n+1);  //递归
            }
            else{
                print();    //递归出完整解后即将其打印出来
            }
            column[j] = 0;
            d1[n-j+7] = 0;
            d2[n+j] = 0;    //回溯

        }
    }
}

void print(){
    int i,j,l;
    number++;
    printf("NO.%d \n",number);
    for(i=0;i<8;i++){
        for(j=0;j<result[i];j++){
            printf("0 ");
        }
        printf("1 ");
        for(j=j;j<7;j++){
            printf("0 ");
        }
        printf("\n");
    } //利用result中存储的每一个皇后的位置进行打印，0为空格，1为皇后
}
