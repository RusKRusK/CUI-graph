#include <stdio.h>
#include <math.h>

//グラフ描画 等幅の太い線でグラフを描画します

#define GRAPH_HEIGHT 150
#define GRAPH_WIDTH 150
#define GRAPH_Y 7.0
#define GRAPH_X 7.0
#define THRESHOLD 0.05
#define MAX_DIF 100

#define f(x) x*2
#define POSX(x) x-(double)GRAPH_X/2.0
#define POSY(y) (double)GRAPH_Y/2.0-y
#define PCOL() printf("\x1b[48;5;%dm　\x1b[0m",color[graph[y][x]-1])
#define CHECK(x,y) fabs(x)<=y
#define CHECK2(x,y) 
#define THRE(t,a) t*sqrt(a*a+1)

int color[]={85,11,1,200};
int graph[GRAPH_HEIGHT][GRAPH_WIDTH];

void drowGraph(void);
int isLine(double,double,int);
int isLine2(double,double,int);
void Init(void);
double diff(double (*fun)(double x),double);

void drowGraph(void){
    for(int y=0;y<GRAPH_HEIGHT;y++){
        for(int x=0;x<GRAPH_WIDTH;x++){
            for(int c=0;c<sizeof(color)/sizeof(int);c++){
                if(isLine2(POSX(x*((double)GRAPH_X/(double)GRAPH_WIDTH)),POSY(y*((double)GRAPH_Y/(double)GRAPH_HEIGHT)),c))graph[y][x]=c+1;
            }
        }
    }

    for(int y=0;y<GRAPH_HEIGHT;y++){
        for(int x=0;x<GRAPH_WIDTH;x++){
            if(graph[y][x]){
                PCOL();
            }
            else if(x==GRAPH_WIDTH/2){
                if(y==0)printf("↑ ");
                else if(y==GRAPH_HEIGHT/2)printf("┼ ");
                else printf("│ ");
            }
            else if(y==GRAPH_HEIGHT/2){
                if(x==GRAPH_WIDTH-1)printf("→ ");
                else printf("─ ");
            }
            else printf("　");
        }
        putchar('\n');
    }
}

// 描画する自作関数の例 数式を入力した後にisLine2関数に追記することで描画する。書き方は他の例を参考に
double func(double x){
    return pow(x,3.0)-3*x*x+x+1;
}

int isLine2(double posx,double posy,int fn){
    switch(fn){
        case 0:return CHECK(posy-sin(posx),THRE(THRESHOLD,diff(sin,posx)))&&fabs(diff(sin,posx))<MAX_DIF;
        case 1:return CHECK(posy-cos(posx),THRE(THRESHOLD,diff(cos,posx)))&&fabs(diff(cos,posx))<MAX_DIF;
        case 2:return CHECK(posy-func(posx),THRE(THRESHOLD,diff(func,posx)))&&fabs(diff(func,posx))<MAX_DIF;
        case 3:return CHECK(posy-tan(posx),THRE(THRESHOLD,diff(tan,posx)))&&fabs(diff(tan,posx))<MAX_DIF;
        default: return 0;
    }
}

void Init(void){
    for(int i=0;i<GRAPH_HEIGHT;i++){
        for(int j=0;j<GRAPH_WIDTH;j++){
            graph[i][j]=0;
        }
    }
}

double diff(double (*fun)(double x),double xd){
    double slope;
    double h = pow(10.0,-10.0);
    slope = (fun(xd+h)-fun(xd))/h;
    return slope;
}

int main(void){
    Init();
    drowGraph();
    return 0;
}
