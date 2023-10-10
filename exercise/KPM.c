//KMP算法的实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 255
#define TRUE 1
#define FALSE 0

typedef struct{
    char ch[MAXSIZE];
    int length;
}SString;
//PM表向右移动一位然后整体加一，然后把第一位（next[0]）赋值为-1,next[0]的值可以随便赋予
int* getNext(SString pattern){
    int* next=(int*)malloc(sizeof(int)*(pattern.length+1));//next数组的长度为模式串长度+1,因为next[0]废弃不用
    next[0]=0;//next[0]废弃不用，因为要和模式串对齐.
    next[1]=0;//next[1]的值为0，pm表中为-1,整体加一后变为0
    int i=1;//模式串的下标
    int j=0;//主串的下标，
    while(i<pattern.length){//i<pattern.length说明模式串还没有遍历完
        if(j==0||pattern.ch[i]==pattern.ch[j]){//模式串的第i个字符和第j个字符匹配时，或者j=0时,(j=0说明模式串的第一个字符和主串的第i个字符不匹配，所以j要回溯)
            i++;
            j++;
            next[i]=j;//让next[i]的值等于j,开始回溯.(示在i位置匹配失败时，让模式串的第j个字符和主串的第i个字符开始匹配)
        }else{
            j=next[j];//如果不匹配，j值回溯
        }
    }
    return next;
}

int KMP(SString text,SString pattern){
    int* next=getNext(pattern);//获取next数组
    int i=1;//主串的下标
    int j=1;//模式串的下标
    while(i<=text.length&&j<=pattern.length){
        if(j==0||text.ch[i]==pattern.ch[j]){
            i++;
            j++;
        }else{
            j=next[j];//如果不匹配，j值回溯
        }
    }
    if(j>pattern.length){//j>pattern.length说明匹配成功
        return i-pattern.length;//是模式串在主串中的位置
    }else{
        printf("匹配失败\n");
        return FALSE;
    }
}

int main(){
    SString text;
    SString pattern;
    printf("请输入主串：");
    //舍弃首字符，从text.ch[1]开始存储
    fgets(text.ch+1, sizeof(text.ch), stdin);//fgets()函数的第一个参数是一个字符数组，第二个参数是字符数组的长度，第三个参数是stdin，表示从标准输入读取数据
    text.length=strlen(text.ch+1)-1;//strlen是从ch[0]开始遍历到'\0'，而我们是从ch[1]开始存储，所以长度要减1，text.ch+1是为了跳过text.ch[0]，从text.ch[1]开始计算长度
    text.ch[text.length+1]='\0';//将text.ch[text.length]赋值为'\0'，表示字符串的结束
    printf("您输入的主串为：%s\n",text.ch+1);
    printf("主串长度为：%d\n",text.length);
    printf("请输入模式串：");
    fgets(pattern.ch+1, sizeof(pattern.ch), stdin);
    pattern.length=strlen(pattern.ch+1)-1;
    pattern.ch[pattern.length+1]='\0';
    printf("您输入的模式串为：%s\n",pattern.ch+1);
    printf("您输入的模式串长度为：%d\n",pattern.length);
    printf("开始匹配\n");
    int index=KMP(text,pattern);
    if(index!=FALSE){
        printf("匹配成功，匹配的位置为：%d\n",index);
    }else{
        printf("匹配失败\n");
    }
    return 0;
}
//该算法的时间复杂度为O(m+n),构建next数组的时间复杂度为O(n),匹配的时间复杂度为O(m)，n为模式串长度，m为主串长度
//该算法的空间复杂度为O(n),n为模式串长度
