#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

#define MAX_COLS 80
#define MAX_ROWS 25
#define DELAY 25

const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

void gotoxy(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    CONSOLE_CURSOR_INFO cursorInfo;
    cursorInfo.bVisible = FALSE;
    cursorInfo.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    srand(time(NULL));
    hideCursor();

    int cols[MAX_COLS];
    int clear_cols[MAX_COLS];
    int lengths[MAX_COLS];
    char col_chars[MAX_COLS][10]; // 每列最多10个字符

    // 初始化列的位置、长度和字符
    for (int i = 0; i < MAX_COLS; i++) {
        cols[i] = rand() % MAX_ROWS;
        clear_cols[i] = cols[i];
        lengths[i] = 3 + rand() % 8; // 随机生成长度为3到10的字符串
        for (int j = 0; j < lengths[i]; j++) {
            col_chars[i][j] = charset[rand() % (sizeof(charset) - 1)];
        }
    }

    while (1) {
        for (int i = 0; i < MAX_COLS; i++) {
            int col = i;
            int row = cols[i];

            // 清除前一个位置的字符
            for (int j = 0; j < lengths[i]; j++) {
                gotoxy(col, (clear_cols[i] - j + MAX_ROWS) % MAX_ROWS);
                printf(" ");
            }

            // 打印当前列的固定字符
            for (int j = 0; j < lengths[i]; j++) {
                gotoxy(col, (row - j + MAX_ROWS) % MAX_ROWS);
                if (j == 0) {
                    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY); // 白色
                } else {
                    setColor(FOREGROUND_GREEN); // 绿色
                }
                printf("%c", col_chars[i][j]);
            }

            clear_cols[i] = row;
            cols[i] = (cols[i] + 1) % MAX_ROWS;
        }
        Sleep(DELAY);
    }

    return 0;
}