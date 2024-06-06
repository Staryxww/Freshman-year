#include<stdio.h>
void matrix_multi(double A[3][4], double B[4][5], double C[3][5]);
int main(){
    double A[3][4]={{1,3,4,5},{2,8,6,9},{3,1,6,3}};
    double B[4][5]={{2,3,6,6,1},{8,9,1,3,4},{6,7,5,3,9},{4,3,9,8,5}};
    double C[3][5]={0};
    matrix_multi(A,B,C);
    return 0;
}
//根据计算正确答案应该为
//70  73  74  67  74 
//140 147 131 126 133 
//62  69  76  63  76 
void matrix_multi(double A[3][4], double B[4][5], double C[3][5]){
    int i,j,k;
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
            for (k = 0; k < 4; k++) {
                C[i][j] += A[i][k] * B[k][j];   //矩阵乘法主体
            }
        }
    }
    for(i=0;i<3;i++){
        for(j=0;j<5;j++){
        printf("%.0f ", C[i][j]);
        }
        printf("\n");
    }   //输出计算结果
}