#include<stdio.h>   //总体思路：将字母表转换为ascll码表，排序后再转换会字母表输出
int main(){

    int i,j,k;  //原表
    char A[5][6]={
        {'S','D','U','Y','E','S'},
        {'C','H','I','N','A','!'},
        {'A','F','T','E','R','X'},
        {'h','e','r','o','a','b'},
        {'C','y','y','D','S','!'}
    };
    
    printf("\n");
    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            printf("%c ",A[i][j]);
        }
        printf("\n");
    }

    int m;  //内排序
    int p;
    int chara[5][6];
    for (i=0;i<5;i++){
        for(j=0;j<6;j++){
            chara[i][j]=(int)A[i][j];
        }   //数组类型转换
        for(j=0;j<5;j++){   //外层循环，逐渐缩小数组范围
        m=chara[i][j];
        p=j;
        for(k=j+1;k<6;k++){
            if(chara[i][k]<m){
                m=chara[i][k];
                p=k;
            }
        }   //选择排序主体，将每一组的第一个数与后面所有数进行比较，将最小的数与第一个数位置调换
        chara[i][p]=chara[i][j];
        chara[i][j]=m;
        }
    }

    printf("\n");
    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            printf("%c ",chara[i][j]);
        }
        printf("\n");
    }

    int row[5];     //外排序
    for(i=0;i<5;i++){
        row[i]=0;
    }
    for(i=0;i<5;i++){
        for (j=0;j<6;j++){
            row[i]=row[i]+chara[i][j];
        }
    }

    for(i=0;i<5;i++){
        printf("%d ",row[i]);   
    }
    printf("\n");

    int min;    
    int pos;
    for(j=0;j<4;j++){
        min=row[j];
        pos=j;
        for(int k=j+1;k<5;k++){
            if(row[k]<min){
                min=row[k];
                pos=k;
            }
        }
        int temp = row[pos];
        row[pos] = row[j];
        row[j] = temp;
    }

    for(i=0;i<5;i++){
        printf("%d ",row[i]);   
    }
    printf("\n");
    
    char A2[5][6];//ascll码表整体排序
    int l;
    int row2;
    for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            row2=0;
            for(k=0;k<6;k++){
                row2+=chara[j][k];
            }
            if(row2==row[i]){
                for(l=0;l<6;l++){
                    A2[i][l]=chara[j][l];
                }
            } 
        }
    }

printf("\n");
    for(i=0;i<5;i++){
        for(j=0;j<6;j++){
            printf("%c ",A2[i][j]);
        }
        printf("\n");
    }   //输出结果

return 0;
}