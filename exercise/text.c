#include <stdio.h>
#include<string.h>
int main(){
    char text[100];
    char pattern[100];//模式串，模式串不是子串，子串是主串的一部分，模式串不一定是主串的一部分
    printf("请输入主串；");
    fgets(text, sizeof(text), stdin);//fgets()函数用于从指定的流 stream 读取一行，并把它存储在 str 所指向的字符串内。当读取(n-1)个字符时，或者读取到换行符时，或者到达文件末尾时，它会停止，具体视情况而定。
    text[strcspn(text, "\n")] = '\0';//strcspn()函数用于检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，该匹配发生在字符串 str1 的前 n 个字符。如果成功，函数返回字符串 str1 中第一个匹配的字符的下标；如果不匹配，函数返回 0。
    printf("主串长度为：%d",strlen(text));
    return 0;
}