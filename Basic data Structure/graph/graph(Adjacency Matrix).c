#include<stdio.h>   
#include<stdlib.h>
#include<limits.h>
/*
createGraph(&G)函数存在问题，无法正常读取输入的顶点信息，解决办法是
*/
#define MAX 10
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OK 1
#define NOTOK 0
#define INFINITY INT_MAX

//邻接矩阵
typedef struct Graph
{
    int vexnum; //顶点数
    int arcnum; //边数
    char vexs[MAX]; //顶点集合
    int arcs[MAX][MAX]; //邻接矩阵
}Graph,*ptrGraph;

//把顶点集合映射到数组中
int LocateVex(Graph G, char x){
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i] == x)
            return i;
    }
    return ERROR;
}


//创建无向图
void createGraph(ptrGraph PtrG){
    int i,j,k;
    char v1,v2;
    int weight;
    printf("请输入顶点数和边数：\n");
    scanf("%d %d",&PtrG->vexnum,&PtrG->arcnum);
    printf("请输入顶点信息：\n");
    for(i=0;i<(PtrG->vexnum);i++){
        scanf(" %c",&PtrG->vexs[i]);//scanf中%c前的空格是为了清除缓冲区中上一轮输入残留的回车
    }
    for(i=0;i<PtrG->vexnum;i++){
        for(j=0;j<PtrG->vexnum;j++){
            PtrG->arcs[i][j]=0;
        }
    }
    printf("请按格式输入边的信息(如:A B 1);\n");
    for(k=0;k<PtrG->arcnum;k++){
        scanf(" %c %c %d",&v1,&v2,&weight);
        i=LocateVex(*PtrG,v1);
        j=LocateVex(*PtrG,v2);
        PtrG->arcs[i][j]=weight;
        PtrG->arcs[j][i]=weight;
        printf("还有%d个边待输入\n",PtrG->arcnum-k-1);
    }
}
//初始化图
void initGraph(ptrGraph ptrG){
    ptrG->vexnum=0;
    ptrG->arcnum=0;
    int i,j;
    for(i=0;i<MAX;i++){
        ptrG->vexs[i]=0;
        for(j=0;j<MAX;j++){
            ptrG->arcs[i][j]=0;
        }
    }
}

//判断图G中是否存在边<x,y>
int isEdge(Graph G, char x, char y){
int xNum=LocateVex(G,x);
int yNum=LocateVex(G,y);
if(xNum == -1 || yNum == -1)
    return NOTOK;
else{
    if(G.arcs[xNum][yNum] == 1)
        return OK;
    else
        return NOTOK;
}
}
//判断图G中是否存在顶点v
int isVex(Graph G, char x)
{
    int i;
    for(i=0; i<G.vexnum; i++)
    {
        if(G.vexs[i] == x)
            return OK;
    }
    return FALSE;
}

//列出图G中与顶点x邻接的边
char Neighbors(Graph G, char x){
//遍历邻接矩阵的第x行(或第x列)，如果有值为1的元素，则说明与x邻接
    int i;
    int xNum = LocateVex(G, x);
    if(xNum == -1)
        return ERROR;
    else{
        for(i=0; i<G.vexnum; i++){
            if(G.arcs[xNum][i] == 1)
                printf("%c ", G.vexs[i]);
        }
        printf("\n");
    }

}

//在图G中插入顶点x
int InsertVertex(ptrGraph PtrG,char x){
    if(PtrG->vexnum == MAX)
        return NOTOK;
    PtrG->vexs[PtrG->vexnum] = x;
    PtrG->vexnum++;
    return OK;
}

//从图G中删除顶点x
int DeleteVertex(ptrGraph PtrG,char x){
    int i,j;
    int xNum = LocateVex(*PtrG, x);
    if(xNum == -1){
        printf("顶点不存在,无法进行删除\n");
        return NOTOK;
    }
    else{
        for(i=xNum; i<PtrG->vexnum-1; i++){
            PtrG->vexs[i] = PtrG->vexs[i+1];//x后面的顶点向前移动，覆盖x
        }
        PtrG->vexnum--;
        for(i=0; i<PtrG->vexnum; i++){//从第一行开始，把列号大于xNum的元素向左移动，覆盖x所在的列
            for(j=xNum; j<PtrG->vexnum-1; j++){
                PtrG->arcs[i][j] = PtrG->arcs[i][j+1];
            }
        }
        for(i=xNum; i<PtrG->vexnum; i++){//从第一列开始，把行号大于xNum的元素向上移动，覆盖x所在的行
            for(j=0; j<PtrG->vexnum; j++){
                PtrG->arcs[i][j] = PtrG->arcs[i+1][j];
            }
        }
        return OK;
    }
}

//若无向边(x,y)不存在，则在图G中插入边(x,y)
int AddEdge(ptrGraph ptrG, char x, char y){
    if(isEdge(*ptrG,x,y)){
        printf("边已存在，无法插入\n");
        return NOTOK;
    }
    else{
        int xNum = LocateVex(*ptrG, x);
        int yNum = LocateVex(*ptrG, y);
        if(xNum == -1 || yNum == -1){
            printf("顶点不存在，无法插入\n");
            return NOTOK;
        }
        else{
            ptrG->arcs[xNum][yNum] = 1;
            ptrG->arcs[yNum][xNum] = 1;
            ptrG->arcnum++;
            return OK;
        }
    
    }
}

//若无向边(x,y)存在，则在图G中删除边(x,y)
int RemoveEdge(ptrGraph ptrG, char x, char y){
if(isEdge(*ptrG,x,y)){
    int xNum = LocateVex(*ptrG, x);
    int yNum = LocateVex(*ptrG, y);
    ptrG->arcs[xNum][yNum]=0;
    ptrG->arcs[yNum][xNum]=0;
    ptrG->arcnum--;
    return OK;
}else{
    printf("所找边不存在，无法删除\n");
    return NOTOK;
}
}

//求图G中顶点x的第一个邻接点,若有则返回顶点号
//重点
char FirstNeighbor(Graph G, char x){
    int i;
    int xNum=LocateVex(G,x);
    for(i=0;i<G.vexnum;i++){
        if(G.arcs[xNum][i]==1)
            return G.vexs[i];
    }
    printf("没有找到与其相连的节点。\n");
    return ERROR;
}

//假设图G中顶点y是顶点x的一个邻接点，返回除y之外x的下一个邻接点的顶点号
//重点
char NextNeighbor(Graph G, char x, char y){
    int xNum=LocateVex(G,x);
    int yNum=LocateVex(G,y);
    int i=yNum+1;//从y的下一个节点开始找
    while(i!=yNum){
        if(G.arcs[xNum][i]==1)
            return G.vexs[i];
        i=(i+1)%G.vexnum;//这里是关键，如果i到了最后一个元素，就从头开始，直到i==yNum
    }
    printf("没有找到与其相连其他的节点。\n");
    return ERROR;
}

//获取图G中顶点x的入度
int GetInDegree(Graph G, char x){
    int i;
    int xNum=LocateVex(G,x);
    int count=0;
    for(i=0;i<G.vexnum;i++){
        if(G.arcs[i][xNum]==1)
            count++;
    }
    return count;
}

//获取图G中边(X,Y)的权值
int GetWeight(ptrGraph ptrG, char x, char y){
    int xNum=LocateVex(*ptrG,x);
    int yNum=LocateVex(*ptrG,y);
    if(xNum == -1 || yNum == -1){
        printf("顶点不存在,无法进行删除\n");
        return ERROR;
    }else{
        return ptrG->arcs[xNum][yNum];
    }
}

//设置图G中边(X,Y)的权值
int SetWeight(ptrGraph ptrG, char x, char y, int w){
    int xNum=LocateVex(*ptrG,x);
    int yNum=LocateVex(*ptrG,y);
    if(xNum == -1 || yNum == -1){
        printf("顶点不存在,无法进行删除\n");
        return ERROR;
    }else{
        ptrG->arcs[xNum][yNum]=w;
        return OK;
    }
}

// //深度优先遍历
// void DFS(Graph G){

// }

 //广度优先遍历
 void BFS(Graph G){
    
 }

//打印邻接矩阵
void PrintGraph(Graph G){
    int i=0,j=0;
    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++){
            printf("%5d ",G.arcs[i][j]);
        }
        printf("\n");
    }
}


int main(){
    Graph G;
    //createGraph(&G);
    initGraph(&G);
    InsertVertex(&G,'A');
    InsertVertex(&G,'B');
    InsertVertex(&G,'C');
    InsertVertex(&G,'D');
    InsertVertex(&G,'E');
    InsertVertex(&G,'F');

    AddEdge(&G,'A','B');
    AddEdge(&G,'A','C');
    AddEdge(&G,'A','D');
    AddEdge(&G,'B','E');
    AddEdge(&G,'C','E');
    AddEdge(&G,'B','F');
    AddEdge(&G,'D','F');

    PrintGraph(G);

    return 0;
}