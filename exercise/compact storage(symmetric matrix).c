//对称矩阵的压缩存储,数组实现
#include <stdio.h>//printf
#include <stdlib.h>//malloc,free
//先用二维数组读取存储一个对称矩阵
typedef struct M{
    int* array;
    int size;
}Matrix;

//本程序算法采用行优先

//初始化矩阵，设定M.size和给数组分配空间
int initMatrix(Matrix* ptrM,int size){
    ptrM->size=size;
    ptrM->array=(int*)malloc(size*size*sizeof(int));
    if(ptrM->array==NULL){
        printf("malloc failed\n");
        return -1;
    }
    printf("请输入矩阵的元素（按行输入，每行元素用空格分隔，回车结束每行）:\n");
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            scanf("%d",ptrM->array+(i*(size)+j));    //i*size是第i行的起始地址，j是第i行的偏移量
        }
    }
    printf("输入完成。\n");
    return 0;
}
//压缩对称矩阵，把二维数组存储的对称矩阵转换为压缩存储的一维数组存储的对称矩阵,行优先
int* compactMatrix(Matrix* ptrM){
    int* compMatrix;
    int size = ptrM->size;
    compMatrix=(int*)malloc(size*(size+1)/2*sizeof(int));//Sn=n(a1+an)/2，等差数列求和
    int index=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i>=j){//把行标大于等于列标的元素存储到一维数组中，即把下三角存储到一维数组中
                *(compMatrix+index)=*(ptrM->array+i*(size)+j);
                index++;
            }
        }
    }
    return compMatrix;
}
//解压缩矩阵，把一维数组存储的压缩对称矩阵转换为二维数组存储的无压缩对称矩阵
int* uncompactMatrix(int* ptrCM){
    int size;
    
    int matrix[size][size];//要用等差数列求和公式来算出原矩阵的大小，然后再给数组分配空间
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i>=j){
                matrix[i][j]=;
            }
        }
    }
} 
// //建立映射，知道原矩阵的行列号，求出压缩矩阵的下标
// int map(int size,int row,int column){
//     if(row>=column){
//         return row*(size)+column;
//     }
//     else{
//         return column*(size)+row;
//     }
// }
// //打印矩阵
// int printMatrix(Matrix M){
//     for(int i=0;i<M.size;i++){
//         for(int j=0;j<M.size;j++){
//             printf("%d ",*(M.array+i*(M.size)+j));
//         }
//         printf("\n");
//     }
//     return 0;
// }

// //从压缩后的矩阵中读取元素
// int getElement(const int* CM,int row,int column){//row是行，column是列
//     int size;
//     if(row>=column){
//         return *(CM+row*(size)+column);
//     }
//     else{
//         return *(CM+column*(size)+row);
//     }
// }

int main(){
    Matrix M;
    int Size;
    int* CompMatrix;
    printf("请输入对称矩阵的大小:");
    scanf("%d",&Size);
    initMatrix(&M,Size);
    printMatrix(M);
    CompMatrix=compactmatrix(M);
}


