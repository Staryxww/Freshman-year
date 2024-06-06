#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_WORD_LEN 50

int main() {
    char *lines[MAX_LINES]; // 指针数组，每个元素指向一个字符串
    char word[MAX_WORD_LEN];
    int counts[MAX_LINES] = {0};
    int total_count = 0;
    int num_lines = 0;

    // 输入多行字符串
    printf("Enter lines of text (type 'END' to stop):\n");
    char line[MAX_WORD_LEN];
    while (num_lines < MAX_LINES && strcmp(fgets(line, MAX_WORD_LEN, stdin), "END\n") != 0) {
        lines[num_lines] = malloc(strlen(line) + 1); // 分配足够的内存
        strcpy(lines[num_lines], line); // 复制字符串到动态分配的内存中
        num_lines++;
    }

    // 输入要统计的单词
    printf("Enter a word to count: ");
    scanf("%s", word);

    // 统计单词在每一行出现的次数和总共出现的次数
    for (int i = 0; i < num_lines; i++) {
        char *token = strtok(lines[i], " ");
        while (token != NULL) {
            if (strcmp(token, word) == 0) {
                counts[i]++;
                total_count++;
            }
            token = strtok(NULL, " ");
        }
    }

    // 输出统计结果
    printf("\nWord\t\tLine Counts\tTotal Count\n");
    for (int i = 0; i < num_lines; i++) {
        printf("%s\t\t%d\t\t%d\n", word, counts[i], counts[i]);
    }

    // 释放动态分配的内存
    for (int i = 0; i < num_lines; i++) {
        free(lines[i]);
    }

    int total=0;
    for (int i = 0; i < num_lines; i++) {
        total=total+counts[i];
    }
    printf("all count is %d",total);
    return 0;
}
