#include<stdio.h>   //题干有问题，示例的返回值应该是6
int A[2][3] = {{1,2,3},{4,5,6}};
int two_dim_array_access(int *x,int i, int j, int m ,int n,int C);
int main(){
    
    printf("%d \n",two_dim_array_access(&A[0][0],0,0,1,2,3));
    printf("%d \n",two_dim_array_access(&A[1][2],1,2,1,2,3));
    return 0;
    }

int two_dim_array_access(int *x,int i, int j, int m ,int n,int C){
    int tar;
    int *target=&A;
    tar=*(target+m+n+2);
    return tar; //根据上一个题目我们知道数组在内存中是按行存放的，那么下标为m,n的数 就赢存放在数组对应第一个数内存的+m+n+2的内存位置上
}