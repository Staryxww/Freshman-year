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
    for(i=0;i<4;i++){   //外层循环，逐渐缩小数组范围
        min=iArray[i];
        pos=i;
        for(j=i+1;j<5;j++){
            if(iArray[j]<min){
                min=iArray[j];
                pos=j;
            }
        }   //选择排序主体，将每一组的第一个数与后面所有数进行比较，将最小的数与第一个数位置调换
        iArray[pos]=iArray[i];
        iArray[i]=min;
    }
    printf("result is ");
    for(i=0;i<5;i++){
        printf("%d ",iArray[i]);
    }       //输出结果
    printf("\n");
    return 0;
}