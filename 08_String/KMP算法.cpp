#include <stdio.h>
#include <string.h>

#define MaxSize 100

typedef struct {
    char ch[MaxSize];
    int length;
} SString;

int Index(SString S, SString T){
    int i = 1, j = 1, k = 1; // Initialize k to 1
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

void get_next(SString T, int next[]){
    int i = 1, j = 0 ;
    next[1] = 0;
    while(i < T.length)
        if( !j || T.ch[i] == T.ch[j])
            next[++j] = ++i;
       else 
           j = next[j];     
}

void get_nextval(SString T, int nextval[]){
    int i = 1, j = 0;
    nextval[1] = 0;
    while(i < T.length){
        if( !j || T.ch[i] == T.ch[j]){
            ++i; ++j;
            if( T.ch[i] != T.ch[j])
                nextval[i] = j;
           else 
               nextval[i] = nextval[j];     
        }
        else 
            j = nextval[j];
    }
}


int KMP(SString S, SString T){
    int *next = new int[T.length];
    get_next(T , next);
    //get_nextval(T , next); 两个都可以
    int i = 1, j = 1;
    while(i <= S.length && j <= T.length){
        if( !j || S.ch[i] == T.ch[j]){
            i++; j++;
        }else
            j = next[j];
    }
    if(j > T.length)   
        return i-T.length;
    else
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
    
    printf("简单模式匹配认为\n");
    if (result > 0) {
        printf("模式串的位置为: %d\n", result);
    } else {
        printf("主串中没有模式串\n");
    }
    
    result = KMP(S, T);
    
    printf("KMP算法认为\n");
    if (result > 0) {
        printf("模式串的位置为: %d\n", result);
    } else {
        printf("主串中没有模式串\n");
    }
    
    return 0;
}
