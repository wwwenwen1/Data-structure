#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int StringBruteForceSearch(char text[],char pattern[]){
    int textLen=strlen(text);
    int patternLen=strlen(pattern);
    int i=0;
    int j=0;
    while(i<textLen-patternLen&&j<patternLen){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }else{
            i=i-j+1;
            j=0;
        }
    }
    if(j==patternLen){
            return i-j;
        }else{
            printf("匹配失败\n");
            return -1;
        }
}
int main(){
    char text[100];
    char pattern[100];//模式串，模式串不是子串，子串是主串的一部分，模式串不一定是主串的一部分
    printf("请输入主串；");
    fgets(text, sizeof(text), stdin);
    //fgets()函数用于从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取(n-1)个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
    text[strcspn(text, "\n")] = '\0';
    //strcspn()函数用于检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，该匹配发生在字符串 str1 的前 n 个字符。如果成功，函数返回字符串 str1 中第一个匹配的字符的下标；如果不匹配，函数返回 0。
    printf("请输入模式串：");
    fgets(pattern, sizeof(pattern), stdin);
    pattern[strcspn(pattern, "\n")] = '\0';
    printf("开始匹配\n");
    int index=StringBruteForceSearch(text,pattern);
    if(index!=-1){
        printf("匹配成功，匹配的位置为：%d",index+1);
    }
    return 0;
}
//该算法的时间复杂度为O(m*n),m为主串长度，n为模式串长度