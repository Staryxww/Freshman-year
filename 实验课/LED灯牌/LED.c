#include<stdio.h>
#include<unistd.h>
int n=1;
int k=3;
void clear(){
    printf("\033[2J"); // 清除屏幕
    printf("\033[H");  
}

void bounder(){
    printf("|                                   |");
    printf("\033[1;2H"); 
}
int main(){
    int positon;
    do{
        do{
        clear();
        bounder();
        for(int i=0;i<n;i++){
            printf(" ");
        }
        printf("\033[41;33mVictory Day!\033[0m");
        n++;
        usleep(125000);
        }
        while(n<23);
        do{
            clear();
            bounder();
            for(int i=n;i>0;i--){
            printf(" ");
            }
            printf("\033[41;33mVictory Day!\033[0m");
            n--;
            usleep(125000);        
        }   
        while(n>0);
        k--;
    }
    while(k>0) ;
    return 0;   
}

