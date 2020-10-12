#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _horse{

    int y;
    int x;
    int direct;

}Horse;


int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};


void cparr(int ** dest, int ** src, int number, int length)
{


    int start = 0;
    int i;
    int j = 0;

    //printf("hi");
    /*
    for(i=0; i<length; i++)
    {

        printf("%d ", (*src)[i]);
    }
    printf("\n");
*/
    for(i=0; i<length; i++)
    {
        *(*(dest)+i) = 0;
    }

    for(i=0; i<length; i++)
    {
        if(*(*(src)+i) == number)
        {
            start = i;
            break;
        }
    }

    for(i = start; i<length; i++)
    {
        if(*(*(src)+i) == 0)
            break;
        else
        {
            *(*(dest)+j) = *(*(src)+i);
            *(*(src)+i) = 0;
            j++;
        }
    }


}


int move(int ** src, int ** dest, int length)
{

    int start = 0;
    int i;
    int j = 0;

    //printf("hi");
    /*
    for(i=0; i<length; i++)
    {

        printf("%d ", (*src)[i]);
    }
    printf("\n");
*/

    for(i=0; i<length; i++)
    {
        if(*(*(dest)+i) == 0)
        {
            start = i;
            break;
        }
    }

    for(i = start; i<length; i++)
    {
        if(*(*(src)+j) == 0)
            break;
        else
        {
            *(*(dest)+i) = *(*(src)+j);
            *(*(src)+j) = 0;
            j++;
        }
    }

    if(j+start >=4)
        return 1;
    else
        return 0;


}


int reversemove(int ** src, int ** dest, int length)
{

    int start = 0;
    int reverstart = 0;
    int firstrever = 0;
    int i;
    int j;

    //printf("hi");
    /*
    for(i=0; i<length; i++)
    {

        printf("%d ", (*src)[i]);
    }
    printf("\n");
*/

    for(i=0; i<length; i++)
    {
        if(*(*(dest)+i) == 0)
        {
            start = i;
            break;
        }
    }

    for(j=length-1; j>=0; j--)
    {
        if(*(*(src)+j) != 0)
        {
            reverstart = j;
            break;
        }
    }

    firstrever = reverstart;

    for(i = start; i<length; i++)
    {
        if(reverstart<0)
            break;
        else
        {
            *(*(dest)+i) = *(*(src)+reverstart);
            *(*(src)+reverstart) = 0;
            reverstart--;
        }
    }

    if(start+firstrever+1>=4)
        return 1;
    else
        return 0;


}



int main() {

    int N, K;
    int i, j;
    int turn = 0;

    scanf("%d %d", &N, &K);

    Horse * horses = (Horse *)malloc(sizeof(Horse)*(K+1));

    int ** colormap = (int**)malloc(sizeof(int*)*N);

    for(i=0; i<N; i++)
    {
        colormap[i] = (int*)malloc(sizeof(int)*N);
    }

    int ***map = (int***)malloc(sizeof(int**)*N);

    for(i=0; i<N; i++)
    {
        map[i] = (int**)malloc(sizeof(int*)*N);
    }

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            map[i][j] = (int*)malloc(sizeof(int)*K);
            //memset(map[i][j], 0, sizeof(int)*K);
        }
    }

    int * tmparr = (int*)malloc(sizeof(int)*K);



    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &colormap[i][j]);
        }
    }

    for(i=1; i<=K; i++)
    {
        scanf("%d %d %d", &horses[i].y, &horses[i].x, &horses[i].direct); //행, 열, 방향
    }
/*
    for(i=1; i<=K; i++){
        printf("%d %d %d\n", horses[i].x, horses[i].y, horses[i].direct);
    }
*/

    int x, y;


    for(i=1; i<=K; i++) // input x, y write map
    {
        x=horses[i].x;
        y=horses[i].y;

        map[y-1][x-1][0] = i;

    }
/*
    printf("check\n"); //행, 열, 방향 출력

    for(i=1; i<=N; i++)
    {
        for(j=1; j<=N; j++)
        {
            printf("%d ", map[i-1][j-1][0]);
        }
        printf("\n");

    }

*/
/*
    for(i=1; i<=K; i++) // 말에 입력되었는지 출력
    {
        printf("%d %d\n", horses[i].y, horses[i].x);
        //map[(horses[i].y)-1][(horses[i].x)-1][0] = i;
    }
*/

    int nowx;
    int nowy;
    int nowdirect;

    int tmpx, tmpy, tmpdirect;

    tmpdirect = 0;
    int count;





    while(1)
    {
        turn++;

        if(turn > 1000 ) { // to 1000
            printf("%d", -1);
            break;
        }

        for(i=1; i<=K; i++)
        {
            count = 0;

            //printf("%d time\n", i);

            nowx= horses[i].x-1; //0 to N-1
            nowy = horses[i].y-1;
            nowdirect = horses[i].direct;

            cparr(&tmparr, &map[nowy][nowx], i, K); //copy

/*
            printf("print tmp \n"); //tmp에 담기는지 확인
            for(int g=0; g<K; g++)
            {
                printf("%d ", tmparr[g]);
            }
            printf("\n");
            */


            tmpx = nowx + dx[nowdirect];
            tmpy = nowy + dy[nowdirect];

            if(tmpx < 0 || tmpx >=N || tmpy < 0 || tmpy>=N || colormap[tmpy][tmpx] == 2)
            {
                if(nowdirect == 1)
                    tmpdirect = 2;
                else if (nowdirect == 2)
                    tmpdirect = 1;
                else if (nowdirect == 3)
                    tmpdirect = 4;
                else if (nowdirect == 4)
                    tmpdirect = 3;

                tmpx = nowx + dx[tmpdirect];
                tmpy = nowy + dy[tmpdirect];

                if(tmpx < 0 || tmpx >=N || tmpy < 0 || tmpy>=N || colormap[tmpy][tmpx] == 2) {

                   // printf("same!!!\n");
                    horses[i].direct = tmpdirect;
                    move(&tmparr, &map[nowy][nowx], K);
                    continue;
                }
                else if (colormap[tmpy][tmpx] == 0)
                {
                    for(int num =0 ; num<K; num++)
                    {
                        if(tmparr[num] == 0)
                            break;
                        else
                        {
                            horses[tmparr[num]].x = tmpx+1;
                            horses[tmparr[num]].y = tmpy+1;
                        }
                    }
                    horses[i].direct = tmpdirect;
                    count = move(&tmparr, &map[tmpy][tmpx], K);
                }
                else if (colormap[tmpy][tmpx] == 1)
                {

                    for(int num =0 ; num<K; num++)
                    {
                        if(tmparr[num] == 0)
                            break;
                        else
                        {
                            horses[tmparr[num]].x = tmpx+1;
                            horses[tmparr[num]].y = tmpy+1;
                        }
                    }
                    horses[i].direct = tmpdirect;
                    count = reversemove(&tmparr, &map[tmpy][tmpx], K);

                }


            }
            else
            {

                if(colormap[tmpy][tmpx] == 1)
                {
                    for(int num =0 ; num<K; num++)
                    {
                        if(tmparr[num] == 0)
                            break;
                        else
                        {
                            horses[tmparr[num]].x = tmpx+1;
                            horses[tmparr[num]].y = tmpy+1;
                        }
                    }
                    horses[i].direct = nowdirect;
                    count = reversemove(&tmparr, &map[tmpy][tmpx], K);
                }
                else
                {

                    for(int num =0 ; num<K; num++)
                    {
                        if(tmparr[num] == 0)
                            break;
                        else
                        {
                            horses[tmparr[num]].x = tmpx+1;
                            horses[tmparr[num]].y = tmpy+1;
                        }
                    }

                    horses[i].direct = nowdirect;
                    count = move(&tmparr, &map[tmpy][tmpx], K);

                }

            }

/*
            for(int g=0; g<N; g++)
            {
                for(int l = 0; l<N; l++)
                {
                    printf(" [");
                    for(int m =0; m<K; m++)
                    {
                        printf("%d ", map[g][l][m]);
                    }
                    printf("] ");
                }
                printf("\n");
            }

        printf("\n");
*/
/*
            for(int hey=0; hey<K; hey++) {
                //printf("horse y x : %d %d\n", horses[hey+1].y, horses[hey+1].x);
            }
            */


        if(count == 1)
        {
            printf("%d", turn);
            return -1;
        }

        }

/*
        printf("last! :\n");

        for(int g=0; g<N; g++)
        {
            for(int l = 0; l<N; l++)
            {
                printf(" [");
                for(int m =0; m<K; m++)
                {
                    printf("%d ", map[g][l][m]);
                }
                printf("] ");
            }
            printf("\n");
        }

        printf("\n");

        for(int hey=0; hey<K; hey++) {
            printf("horse direct : %d \n", horses[hey+1].direct);
        }


        for(int g=0; g<N; g++)
        {
            for(int l = 0; l<N; l++)
            {
                for(int m =0; m<K; m++)
                {
                    printf("%d ", map[g][l][m]);
                }
            }
            printf("\n");
        }

*/



    }

//free!!!


    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            free(map[i][j]);
        }
    }

    for(i=0; i<N; i++)
    {
        free(map[i]);
    }

    free(map);

    for(i=0; i<N; i++)
    {
        free(colormap[i]);
    }

    free(colormap);
    free(horses);




    return 0;


}
