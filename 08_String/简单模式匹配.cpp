#include <iostream>
#include <string>

using namespace std;

int Index(string S, string T){
    int i = 1, j = 1, k = 1; 
    while(i <= S.length() && j <= T.length()){
        if(S[i] == T[j]){
            i++;  j++;
        }else{
            i = k + 1; j = 1; k++;
        }
    }
    return j > T.length() ? k : 0;
}


int main() {
    string S, T;
    
    cout << "请输入主串" << endl;
    cin >> S; // Read the main string
    cout << "请输入模式串" << endl;
    cin >> T; // Read the pattern string
    
    int result = Index(S, T);
    
    if (result > 0) {
        cout << "模式串的位置为: " << result << endl;
    } else {
        cout << "主串中没有模式串" << endl;
    }
    
    return 0;
}
