#include<stdio.h>
#include<unistd.h>
int positionX[40]={0};
int positionY[40]={0};//位置数组
int check=0;//判断是否重开
int n=0;
//绘制边框
void bounder(){
    printf("*******************************************\n");
    for(int j=0;j<21;j++){
    printf("*                                         *\n");
    }
    printf("*******************************************");
    printf("\033[H"); 
}

void clear(){
    printf("\033[2J"); // 清除屏幕
    printf("\033[H");  
}
//移动
void movement(int x,int y){
    clear();
    bounder();

    if(n==0){
        printf("\033[%d;%dH",positionX[n]+2,positionY[n]+2);
        printf("#");
    }
    else{
        printf("\033[%d;%dH",positionX[n-1]+2,positionY[n-1]+2);
        printf("#");
    }

    printf("\033[H");
    for(int i=0;i<24;i++){
    printf("\n");
    }


    printf("please enter the Y distance you want to change(%d/20)\n",positionX[n-1]);
    scanf("%d",&x);
    printf("please enter the X distance you want to change(%d/40)\n",positionY[n-1]);
    scanf("%d",&y);

    positionX[n]=positionX[n-1]+x;
    positionY[n]=positionY[n-1]+y;
    if(positionX[n]>20){
        positionX[n]=20;
    }
    else if(positionX[n]<0){
        positionX[n]=0;
    }

    if(positionY[n]<0){
        positionY[n]=0;
    }
    else if(positionY[n]>40){
        positionY[n]=40;
    }

    clear();
    bounder();

    printf("\033[%d;%dH",positionX[n]+2,positionY[n]+2);
    printf("#");

    printf("\033[H");
    for(int i=0;i<24;i++){
    printf("\n");
    }

    n++;

    printf("start to repalay and exit?(enter 1 to replay,enter 0 to continue changing position\n)");
    scanf("%d",&check);
    clear();
}
//将保存的位置数组读取从而实现重放
void replay(){
    for(int i=0;i<n;i++){
        clear();
        bounder();
        printf("\033[%d;%dH",positionX[i]+2,positionY[i]+2);
        printf("#");
        sleep(1);
        clear();
    }
}


int main(){
    int x,y;
    x=0;
    y=0;
    do{
        movement(x,y);
    }
    while(check!=1);
    replay();
    return 0;
}