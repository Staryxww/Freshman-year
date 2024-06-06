#include <stdio.h>
#include <unistd.h>

int position = 1; // 文本的初始位置
int direction = 1; // 移动方向 (1 表示右移，-1 表示左移)
int bound_width = 34; // 边框的宽度

void clear_screen() {
    printf("\033[2J"); // 清除屏幕
    printf("\033[H");  // 将光标移到初始位置
}

void print_boundaries() {
    printf("|");
    for (int i = 0; i < bound_width - 2; i++) {
        printf(" ");
    }
    printf("|");
    printf("\033[1;2H"); // 将光标移到边框内的起始位置
}

int main() {
    while (1) {
        clear_screen();
        print_boundaries();
        
        // 根据当前的位置打印空格
        for (int i = 0; i < position; i++) {
            printf(" ");
        }
        
        // 打印文本
        printf("\033[41;33mVictory Day!\033[0m");

        // 更新文本的位置
        position += direction;

        // 如果文本到达边框，则反转方向
        if (position >= bound_width - 14 || position <= 0) {
            direction = -direction;
        }

        usleep(100000); // 休眠100毫秒
    }

    return 0;
}