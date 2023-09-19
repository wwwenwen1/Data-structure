#include <stdio.h>

int main() {
    int rows, cols;

    printf("请输入矩阵的行数: ");
    scanf("%d", &rows);
    printf("请输入矩阵的列数: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("请输入矩阵的元素（按行输入，每行元素用空格分隔，回车结束每行）:\n");

    // 逐行读取矩阵元素
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // 打印矩阵
    printf("您输入的矩阵是:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}