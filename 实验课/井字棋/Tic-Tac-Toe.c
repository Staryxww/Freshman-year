//1.游戏主菜单（包含与人机对战，与真人对战）
//2.两种模式都需要的：a.可视化的棋盘(3*3) b.相互落子(只能在棋盘范围内，落了的地方不能落) c.胜利条件（三种情况 O获胜，X获胜，平局）
//数组1 棋盘的图像 落子图像（移动光标并且打一个x/o？） 数组2 两个人落子（一个人一组还是两个人共用一个数组？） 数组3 胜利条件判定？需要这个数组吗（三个一行/一列/一对角线该如何表示呢）

#include<stdio.h>
int boardA[3][3]={0};
int boardB[3][3]={0};
void restart(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            boardA[i][j]=0;
            boardB[i][j]=0;
        }
    }
}
void clear_screen() {
    printf("\033[2J"); // 清除屏幕
    printf("\033[H");  // 将光标移动到左上角
}
int menu(){
    printf("\033[1;36m*****************\n***Tic-Tac-Toe***\n*****************\n\033[0menter 1 to start single player mode\nenter 2 to start multi player mode\nenter 3 to exit the game\n ");
}//菜单
void printbroad(){
    printf("* * * * * * *\n*   *   *   *\n* * * * * * *\n*   *   *   *\n* * * * * * *\n*   *   *   *\n* * * * * * *\n"); 
}//打印棋盘
void placecheck(){
    printbroad();
    int l,m,col,row;
    for(l=0;l<3;l++){
    for(m=0;m<3;m++){
        if(boardA[l][m]==1){
            col=4*m+3;
            row=2*l+2;
            printf("\033[%d;%dH",row,col);
            printf("O");
        }
    }
}
    for(l=0;l<3;l++){
        for(m=0;m<3;m++){
            if(boardB[l][m]==1){
                col=4*m+3;
                row=2*l+2;
                printf("\033[%d;%dH",row,col);
                printf("X");
            }
        }
    printf("\033[%d;%dH",9,1);
    }
}//落子
void placeA(){
    int pos;
    int i,j;
    loop:
    printf("A please enter the place you want to put,such as 12 is (1,2): ");
    scanf("%d",&pos);
    clear_screen();
    i=(pos/10)-1;
    j=(pos%10)-1;
    if(boardA[i][j]==1 && boardB[i][j]==1){
        printf("can not place the chess here\n");
        goto loop;
    }
    else{
        
        boardA[i][j]=1;
        placecheck();
    }

}//落子
void placeB(){
    int pos;
    int i,j;
    loop:
    printf("B please enter the place you want to put,such as 12 is (1,2): ");
    scanf("%d",&pos);
    clear_screen();
    i=(pos/10)-1;
    j=(pos%10)-1;
    if(boardB[i][j]==1 && boardA[i][j]==1){
        printf("can not place the chess here\n");
        goto loop;
    }
    else{
        boardB[i][j]=1;
        placecheck();
    }


}//落子
int check_winner(int board[][3]) {
    // 检查每一行
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != 0 && board[i][0] == board[i][1] && board[i][0] == board[i][2]) {
            return 1; // 有玩家获胜
        }
    }
    // 检查每一列
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != 0 && board[0][j] == board[1][j] && board[0][j] == board[2][j]) {
            return 1; // 有玩家获胜
        }
    }
    // 检查主对角线
    if (board[0][0] != 0 && board[0][0] == board[1][1] && board[0][0] == board[2][2]) {
        return 1; // 有玩家获胜
    }
    // 检查副对角线
    if (board[0][2] != 0 && board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
        return 1; // 有玩家获胜
    }
    return 0; // 没有玩家获胜
}
void singel(){
}
void multi(){
    clear_screen();
    int awin,bwin;
    do{
        placeA();
        bwin=check_winner(boardB);
        awin=check_winner(boardA);
        if (bwin==1) {
            printf("Player B wins!\n");
            break;
        }        
        else if(awin==1){
            printf("player A wins!\n");
            break;
        }
        placeB();
        bwin=check_winner(boardB);
        awin=check_winner(boardA);
        if (bwin==1) {
            printf("Player B wins!\n");
            break;
        }        
        else if(awin==1){
            printf("player A wins!\n");
            break;
        }

    }
    while((awin!=1)||(bwin!=1));
}

int main(){
    int mode;
    do {
        menu();
        scanf("%d",&mode);
        switch(mode){
        case 1:
            restart();
            singel();
            break;
        case 2:
            restart();
            multi();
            break;
        case 3:
            break;
        default:
            printf("\n\033[31mplease enter 1  2  or 3 \n\n");
            break;
        }
    }
    while (mode != 3 );
    return 0;
}//主循环