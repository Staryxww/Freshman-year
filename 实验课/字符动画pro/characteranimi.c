#include<stdio.h>
#include<unistd.h>
int positionX[40]={0};
int positionY[40]={0};//位置数组
int check=0;
int n=0;
char imagehalf1[]={"\033[31m  # #    \033[0m"};
char imagehalf2[]={"\033[31m #   #   \033[0m"};
char imagehalf3[]={"\033[31m# #   #  \033[0m"};
char imagehalf4[]={"\033[31m   #   # \033[0m"};
char imagehalf5[]={"\033[31m    #   #\033[0m"};
char imagehalf6[]={"\033[31m     # # \033[0m"};
char imagehalf7[]={"\033[31m  #   #  \033[0m"};
char imagehalf8[]={"\033[31m # # # # \033[0m"};
char imagehalf9[]={"\033[31m#   #   #\033[0m"};//图形
//图形相对位置（逐行绘制）（第一次绘制）
void image1(){
    printf("\033[%d;%dH",positionX[n]+2,positionY[n]+2);
    printf("%s",imagehalf1);
    printf("\033[%d;%dH",positionX[n]+3,positionY[n]+2);
    printf("%s",imagehalf2);
    printf("\033[%d;%dH",positionX[n]+4,positionY[n]+2);
    printf("%s",imagehalf3);
    printf("\033[%d;%dH",positionX[n]+5,positionY[n]+2);
    printf("%s",imagehalf4);
    printf("\033[%d;%dH",positionX[n]+6,positionY[n]+2);
    printf("%s",imagehalf5);
    printf("\033[%d;%dH",positionX[n]+7,positionY[n]+2);
    printf("%s",imagehalf6);
    printf("\033[%d;%dH",positionX[n]+8,positionY[n]+2);
    printf("%s",imagehalf7);
    printf("\033[%d;%dH",positionX[n]+9,positionY[n]+2);
    printf("%s",imagehalf8);
    printf("\033[%d;%dH",positionX[n]+10,positionY[n]+2);
    printf("%s",imagehalf9);
}
//第一次以后的绘制
void image2(){
    printf("\033[%d;%dH",positionX[n-1]+2,positionY[n-1]+2);
    printf("%s",imagehalf1);
    printf("\033[%d;%dH",positionX[n-1]+3,positionY[n-1]+2);
    printf("%s",imagehalf2);
    printf("\033[%d;%dH",positionX[n-1]+4,positionY[n-1]+2);
    printf("%s",imagehalf3);
    printf("\033[%d;%dH",positionX[n-1]+5,positionY[n-1]+2);
    printf("%s",imagehalf4);
    printf("\033[%d;%dH",positionX[n-1]+6,positionY[n-1]+2);
    printf("%s",imagehalf5);
    printf("\033[%d;%dH",positionX[n-1]+7,positionY[n-1]+2);
    printf("%s",imagehalf6);
    printf("\033[%d;%dH",positionX[n-1]+8,positionY[n-1]+2);
    printf("%s",imagehalf7);
    printf("\033[%d;%dH",positionX[n-1]+9,positionY[n-1]+2);
    printf("%s",imagehalf8);
    printf("\033[%d;%dH",positionX[n-1]+10,positionY[n-1]+2);
    printf("%s",imagehalf9);   
}
//重放绘制
void image3(int i){
    printf("\033[%d;%dH",positionX[i]+2,positionY[i]+2);
    printf("%s",imagehalf1);
    printf("\033[%d;%dH",positionX[i]+3,positionY[i]+2);
    printf("%s",imagehalf2);
    printf("\033[%d;%dH",positionX[i]+4,positionY[i]+2);
    printf("%s",imagehalf3);
    printf("\033[%d;%dH",positionX[i]+5,positionY[i]+2);
    printf("%s",imagehalf4);
    printf("\033[%d;%dH",positionX[i]+6,positionY[i]+2);
    printf("%s",imagehalf5);
    printf("\033[%d;%dH",positionX[i]+7,positionY[i]+2);
    printf("%s",imagehalf6);
    printf("\033[%d;%dH",positionX[i]+8,positionY[i]+2);
    printf("%s",imagehalf7);
    printf("\033[%d;%dH",positionX[i]+9,positionY[i]+2);
    printf("%s",imagehalf8);
    printf("\033[%d;%dH",positionX[i]+10,positionY[i]+2);
    printf("%s",imagehalf9);
}
//边框绘制
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
//移动图形
void movement(int x,int y){
    clear();
    bounder();

    if(n==0){
        image1();
    }
    else{
        image2();
    }

    printf("\033[H");
    for(int i=0;i<24;i++){
    printf("\n");
    }


    printf("please enter the Y distance you want to change(%d/12)\n",positionX[n-1]);
    scanf("%d",&x);
    printf("please enter the X distance you want to change(%d/31)\n",positionY[n-1]);
    scanf("%d",&y);

    positionX[n]=positionX[n-1]+x;
    positionY[n]=positionY[n-1]+y;
    if(positionX[n]>12){
        positionX[n]=12;
    }
    else if(positionX[n]<0){
        positionX[n]=0;
    }

    if(positionY[n]<0){
        positionY[n]=0;
    }
    else if(positionY[n]>31){
        positionY[n]=31;
    }

    clear();
    bounder();

    image1();

    printf("\033[H");
    for(int i=0;i<24;i++){
    printf("\n");
    }

    n++;

    printf("start to save your repalay ,replay or continue?\n(enter 1 to replay,enter 0 to continue changing position,enter 3 to save your replay and exit)\n");
    scanf("%d",&check);
    clear();
}
//重放
void replay(){
    for(int i=0;i<n;i++){
        clear();
        bounder();
        image3(i);
        sleep(1);
        clear();
    }
}
//保存上一个数组文件，从而在后面用于读取
void save(char* saving){
    FILE* file = fopen(saving,"w");
    if(file == NULL ){
        perror("Error opening file for writing");
        return;
    }
    for(int i =0; i<n;i++){
        fprintf(file,"%d %d\n",positionX[i],positionY[i]);
    }
    fclose(file);
}
//读取保存的数组文件
void load(char* saving){
    FILE* file = fopen(saving, "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    n = 0;
    while (fscanf(file, "%d %d", &positionX[n], &positionY[n]) == 2) {
        n++; // 成功读取一对坐标，数组索引加一
    }
    fclose(file);
}
//主菜单，包括读档，开始和结束程序三个功能，并绘制了一定的GUI
void menu(int x,int y){
    int mode;
    do {
        printf("\033[1;36m***********************\n***characteranimipro***\n***********************\n\033[0menter 1 to start(continue) drawing your animi\nenter 2 to load other's animi\nenter 3 to exit the program\nenter 4 to redraw your animi\n ");
        scanf("%d",&mode);
        switch(mode){
        case 1:
            do{
                movement(x,y);
            }
            while(check!=1&&check!=3);
            if(check==1){
                replay();
            }
            else if(check == 3){
                save("saving.txt");
            }
            break;
        case 2:
            load("saving.txt");
            replay();
            break;
        case 3:
            break;
        case 4:
            for(int i = 0;i<n;i++){
               positionX[i]=0;
               positionY[i]=0; 
            }
            printf("clear!\n");
            break; 
        default:
            printf("\n\033[31mplease enter 1  2  3 or 4 \n\n");
            break;
        }
    }
    while (mode != 3 );
}

int main(){
    int x,y;
    x=0;
    y=0;
    menu(x,y);
    clear();
    return 0;
}