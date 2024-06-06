#include<stdio.h>
void putqueen(int capture[8][8],int queen[8][8],int diagonal1[15],int diagonal2[15],int i,int j);
int main(){
    int capture[8]={0};
    int queen[8][8]={0};
    int i,j;
    int diagonal1[15]={0};
    int diagonal2[15]={0};
    int kind;
    i=j=kind=0;
    putqueen(capture, queen, diagonal1, diagonal2, i,j);
    return 0;
}

void putqueen(int capture[8][8],int queen[8][8],int diagonal1[15],int diagonal2[15],int i,int j){
    int k,l;
    if(i==7){
        for(k=0;k<7;k++){
            for(l=0;l<7;l++){
                printf("%d ",queen[k][l]);
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    else{
            for(j=0;j<8;j++){ //不需要通过循环换行，通过递归换行就可以了，通过简化参数就可以让参数只传最关键的行数
                queen[i][j]=1;
                if((capture[i][j] != 1) && (diagonal1[i-j+7] != 1) && (diagonal2[i+j] != 1)){
                    capture[i][j]=queen[i][j];
                    diagonal1[i-j+7]=1;
                    diagonal2[i+j]=1;
                    for(l=0;l<8;l++){
                    capture[i][l]=1;
                    capture[l][j]=1;
                    }
                    i+=1;
                    j=0;
                    putqueen(capture,queen,diagonal1,diagonal2,i,j);
                }
                else{
                    queen[i][j] = 0;
                    capture[i][j] = 0;
                    diagonal1[i - j + 7] = 0;
                    diagonal2[i + j] = 0;
                    for(l=0;l<8;l++){
                    capture[i][l]=0;
                    capture[l][j]=0;
                    i+=1;
                    return;
                }      
            }
        }
    }
}
