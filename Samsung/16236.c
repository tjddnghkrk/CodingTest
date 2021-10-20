#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _shark{

    int y, x;
    int s, d, z;
    int dead;
    int num;
}Shark;



int dy[] = {0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 1, -1}; //위 아래 오른쪽 왼쪽

int change[] = { 0, 2, 1, 4, 3};

int result = 0;

int main() {


    int R, C, M; //행, 열, 상어
    int i, j;

    int turn = 0;

    int nowx, nowy;
    int tmpx, tmpy;
    int nowdirect, tmpdirect;

    int ss;

    scanf("%d %d %d", &R, &C, &M);

    int **map = (int **) malloc(sizeof(int *) * R);

    for (i = 0; i < R; i++) {
        map[i] = (int *) malloc(sizeof(int) * C);
    }


    Shark * sharks = (Shark *) malloc(sizeof(Shark) * (M + 1));

    for (i = 1; i <= M; i++) {
        scanf("%d %d %d %d %d", &sharks[i].y, &sharks[i].x, &sharks[i].s, &sharks[i].d, &sharks[i].z);
        sharks[i].dead = 0;
        sharks[i].num = i;
    }

    for (i = 1; i <= M; i++) {
        map[(sharks[i].y) - 1][(sharks[i].x) - 1] = sharks[i].num;
    }


    while (turn < C) {

        //printf("%d turn!!\n", turn);

        for (i = 0; i < R; i++) {
            if (map[i][turn] != 0) {
                result += sharks[map[i][turn]].z;
                sharks[map[i][turn]].dead = 1;
                //printf("delete : %d\n", map[i][turn]);
                map[i][turn] = 0;
                break;
            }
        }

        for (i = 1; i <= M; i++) //delete all
        {
            if (sharks[i].dead == 1)
                continue;
            map[(sharks[i].y) - 1][(sharks[i].x) - 1] = 0;
        }

        for (i = 1; i <= M; i++) {
            //printf("i : %d \n", i);
            if (sharks[i].dead == 1)
                continue;
            nowx = (sharks[i].x) - 1;
            nowy = (sharks[i].y) - 1;
            nowdirect = sharks[i].d;

            ss = sharks[i].s;

            if (nowdirect <= 2) {
                ss = ss % ((R - 1) * 2);
            } else {
                ss = ss % ((C - 1) * 2);
            }

            for (j = 0; j < ss; j++) {

                //printf("j : %d \n", j);

                tmpy = nowy + dy[nowdirect];
                tmpx = nowx + dx[nowdirect];

                if (tmpx < 0 || tmpx >= C || tmpy < 0 || tmpy >= R) {
                    nowdirect = change[nowdirect];

                    tmpy = nowy + dy[nowdirect];
                    tmpx = nowx + dx[nowdirect];
                }

                //printf("%d %d\n", tmpy, tmpx);
                nowx = tmpx;
                nowy = tmpy; //find nowx, nowy
            }

           if (map[nowy][nowx] == 0) {
                map[nowy][nowx] = i;
                sharks[i].x = nowx + 1;
                sharks[i].y = nowy + 1;
                sharks[i].d = nowdirect;
            } else {
                if (sharks[map[nowy][nowx]].z > sharks[i].z) {
                    sharks[i].dead = 1;
                } else {
                    sharks[map[nowy][nowx]].dead = 1;
                    map[nowy][nowx] = i;
                    sharks[i].x = nowx + 1;
                    sharks[i].y = nowy + 1;
                    sharks[i].d = nowdirect;
                }
            }
        }
/*
        for(i=1; i<=M-1; i++)
        {
            if(sharks[i].dead == 1)
                continue;
            for(j=i+1; j<=M; j++)
            {
                if(sharks[j].dead == 1)
                    continue;

                if(sharks[i].x == sharks[j].x && sharks[i].y == sharks[j].y)
                {
                    if(sharks[i].z > sharks[j].z)
                        sharks[j].dead = 1;
                    else
                        sharks[i].dead = 1;
                }
            }
        }
*/
/*
        for(i=0; i<R; i++)
        {
            memset(map[i], 0, sizeof(int)*C);
        }
        */

/*
        for(i=0; i<R; i++)
        {
            for(j=0; j<C; j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
*/


        turn++;
    }

    printf("%d", result);

    for (i = 0; i < R; i++) {
        free(map[i]);
    }

    free(map);

    return 0;
}
