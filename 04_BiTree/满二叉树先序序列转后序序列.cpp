#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PreToPost(char Pre[], char Post[], int b1, int e1, int b2, int e2) {
    if (e1 < b1 || e2 < b2) return;
    Post[e2] = Pre[b1];
    int len = (e1 - b1 ) / 2;
    PreToPost(Pre, Post, b1 + 1, b1 + len, b2, b2 + len - 1);
    PreToPost(Pre, Post, b1 + len + 1, e1, b2 + len, e2 - 1);
}

int main() {
    char Pre[100], Post[100];
    
    printf("请输入先序序列：");
    scanf("%s", Pre);
    
    PreToPost(Pre,Post,0,strlen(Pre)-1,0,strlen(Pre)-1);
    printf("对应的后序序列是：%s\n", Post);

    return 0;
}
