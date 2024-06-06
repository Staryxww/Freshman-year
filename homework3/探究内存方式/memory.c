#include<stdio.h>
int main(){
    int i,j;
    int A[2][3]={{1,2,3},{4,5,6}};

    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%p ",&A[i][j]);//直接打印地址
        }
    }
    printf("\n");
    return 0; //根据输出结果（000000000061FDE0 000000000061FDE4 000000000061FDE8 000000000061FDEC 000000000061FDF0 000000000061FDF4）其为按行存放
}