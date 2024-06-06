#include<stdio.h>
void C(){
    printf("* * * * *\n*\n*\n*\n*\n*\n* * * * *\n");
}
void E(){
    printf("* * * * *\n*\n*\n* * * * *\n*\n*\n* * * * *\n");
}
void T(){
    printf("* * * * *\n    *    \n    *    \n    *    \n    *    \n    *    \n    *    \n");

}
void O(){
    printf("* * * * *\n*       *\n*       *\n*       *\n*       *\n*       *\n* * * * *\n");
}
void U(){
    printf("*       *\n*       *\n*       *\n*       *\n*       *\n*       *\n* * * * *\n");
}
//使用不同的函数来打印不同的字母
int main(){
    char A[6]={'\0'};
    int i,j,k;
    printf("please enter the character(choose any character from CETOU)(5 max)\n");
    scanf("%s",&A);

    for(i=0;i<5;i++){
        if(A[i]=='c') {C();
        }
        else if(A[i]=='e') {E();
        }
        else if(A[i]=='t') {T();
        }
        else if(A[i]=='i') {O();
        }
        else if(A[i]=='u') {U();
        }//对输入的字符串中的每一个字母逐个进行判断并针对性输出对应的图案

    }
}

