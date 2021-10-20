#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Max 101
#define MIN(X, Y) (((X)<(Y))?(X):(Y))
#define MAX(X, Y) (((X)>(Y))?(X):(Y))

typedef struct _input{
    
    int x;
    int y;
    int d;
    int g;
    
}input;

int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};

int map[Max][Max];
input inputs[20];
int result;


int Input()
{
    int N;
    int i;
    int num=0;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++)
    {
        scanf("%d %d %d %d", &inputs[i].x, &inputs[i].y, &inputs[i].d, &inputs[i].g);
        num++;
    }
    /*
    printf("%d", num);
    
    for(i=0; i<N; i++)
    {
        printf("%d %d %d %d\n", inputs[i].x, inputs[i].y, inputs[i].d, inputs[i].g);
    }    
    */
    
    return num;
}

void mark(int num)
{
    int i, j, k;
    int endx, endy;
    int tmpx, tmpy;
    
    
    for(i =0; i<num; i++)
    {
        int xx[10000] = {0, };
        int yy[10000] = {0, };
        int len=0;
        
        int x = inputs[i].x;
        int y = inputs[i].y;
        int d = inputs[i].d;
        int g = inputs[i].g;
        
        endx = x;
        endy = y;
        map[y][x] = 1;
        
        xx[len] = endx;
        yy[len] = endy;
        len++;
        
        tmpy = endy+dy[d];
        tmpx = endx+dx[d];
        map[tmpy][tmpx] = 1;
        
        xx[len] = tmpx;
        yy[len] = tmpy;
        len++;
        
        
        for(j=0; j<g; j++)
        {
            
            endy = tmpy;
            endx = tmpx;
            //printf("end : %d %d %d\n", endy, endx, g);

            int nowlen = len;
            
            for(k = nowlen-1; k>=0; k--)
            {
                int ygap = endy-yy[k]; //0
                int xgap = endx-xx[k]; //1
                
                tmpx = endx+ygap; //4+0
                tmpy = endy-xgap; //3+1
                
                if(tmpx<0 || tmpx>=Max || tmpy<0 || tmpy>=Max)
                    continue;
                
                map[tmpy][tmpx] = 1;
               // printf("result : %d %d %d\n", tmpy, tmpx, g);
                
                xx[len] = tmpx;
                yy[len] = tmpy;
                len++;
                
            }
        }
    }
}


void check()
{
    int y, x;
    for(y=0; y<Max-1; y++)
    {
        for(x=0; x<Max-1; x++)
        {
            if(map[y][x] == 1 && map[y][x+1] == 1 && map[y+1][x] == 1 && map[y+1][x+1] == 1)
            {
              //  printf("%d %d\n", y, x);
                result++;
            }
        }
    }
}


int main(){
    
    int num;
    num = Input();
    //printf("%d", num);
    mark(num);
    check();
    printf("%d", result);
    
    return 0;
    
}
