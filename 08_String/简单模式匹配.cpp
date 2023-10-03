#include <stdio.h>
#include <string.h>

#define MaxSize 100

typedef struct {
    char ch[MaxSize];
    int length;
} SString;

int Index(SString S, SString T){
    int i = 1, j = 1, k = 1; 
    while(i <= S.length && j <= T.length){
        if(S.ch[i] == T.ch[j]){
            i++;  j++;
        }else{
            i = k + 1; j = 1; k++;
        }
    }
    if(j > T.length)    return k;
    return 0;
}


int main() {
    SString S, T;
    
    printf("请输入主串\n");
    scanf("%s", S.ch + 1); // Read the main string
    S.length = strlen(S.ch + 1);
    
    printf("请输入模式串\n");
    scanf("%s", T.ch + 1); // Read the pattern string
    T.length = strlen(T.ch + 1);
    
    int result = Index(S, T);
    
    if (result > 0) {
        printf("模式串的位置为: %d\n", result);
    } else {
        printf("主串中没有模式串\n");
    }
    
    return 0;
}
