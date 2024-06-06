#include<stdio.h>
int main(){
    int iArray[5];
    int min;
    int pos;
    int i,j;
    printf("please enter the number you want to sort(5 in total)\n");
    for(i=0;i<5;i++){
        printf("number[%d]\n",i+1);
        scanf("%d",&iArray[i]);
    }   //输入五个数
    for(i=1;i<5;i++){   //外层循环，从第一个数开始往后框   
        for(j=4;j>=i;j--){
            if(iArray[j]<iArray[j-1]){
                    min=iArray[j-1];
                    iArray[j-1]=iArray[j];
                    iArray[j]=min;
            }
        }   //冒泡排序，将第一个数及后面的所有数字两两比较选出最小的排到第一个
    }
    printf("result is ");
    for(i=0;i<5;i++){
        printf("%d ",iArray[i]);
    }   
    printf("\n");
    return 0;
}