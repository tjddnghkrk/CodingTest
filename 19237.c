#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SHARK{

    int y;
    int x;
    int direct;
    int isdead;

}Shark;

int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

int main() {


    int N, M, k;
    int i, j;

    scanf("%d %d %d", &N, &M, &k);

    int ** map = (int **)malloc(sizeof(int*)*N);

    for(i=0; i<N; i++)
    {
        map[i] = (int*)malloc(sizeof(int)*N);
    }


    int ** smellmap = (int **)malloc(sizeof(int*)*N);

    for(i=0; i<N; i++)
    {
        smellmap[i] = (int*)malloc(sizeof(int)*N);
    }

    //memset(smellmap, 0, sizeof(int)*N*N);


    int ** smellcolormap = (int **)malloc(sizeof(int*)*N); //make color

    for(i=0; i<N; i++)
    {
        smellcolormap[i] = (int*)malloc(sizeof(int)*N);
    }

    //memset(smellcolormap, 0, sizeof(int)*N*N);



    Shark * Sharks = (Shark*)malloc(sizeof(Shark)*(M+1));



    //input

    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &map[i][j]);

            if(map[i][j]!=0) {
                Sharks[map[i][j]].y = i; //save i, j
                Sharks[map[i][j]].x = j;
            }
        }
    }


    for(i=0; i<M; i++)
    {
        Sharks[i].isdead = 0;
    }



    for(i=1;i<=M;i++)
    {
        scanf("%d", &Sharks[i].direct);
    }

    int *** order = (int***)malloc(sizeof(int**)*M);

    for(i=0; i<M; i++)
    {
        order[i] = (int**)malloc(sizeof(int*)*4);
    }

    for(i=0; i<M;i++)
    {
        for(j=0; j<4; j++)
        {
            order[i][j] = (int*)malloc(sizeof(int)*4);
        }
    }


    for(i=0; i<M;i++)
    {
        for(j=0; j<4; j++)
        {
            for(int s =0; s<4; s++) {
                scanf("%d", &order[i][j][s]);
            }
        }
    }

    //finish input
/*
    for(i=0; i<M;i++)
    {
        for(j=0; j<4; j++)
        {
            for(int s =0; s<4; s++) {
                printf("%d", order[i][j][s]);
            }
            printf("\n");
        }
        printf("\n");
    }
*/
    for(i=0; i<N; i++)
    {
        for(j=0;j<N;j++)
        {
            if(map[i][j]!=0)
            {
                smellmap[i][j] = k;
                smellcolormap[i][j] = map[i][j];
            }
        }
    }


/*
    for(i=0; i<N; i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ", map[i][j]);
            }
        printf("\n");
    }
    printf("\n");

    for(i=0; i<N; i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ", smellmap[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    for(i=0; i<N; i++)
    {
        for(j=0;j<N;j++)
        {
            printf("%d ", smellcolormap[i][j]);
        }
        printf("\n");
    }

    printf("me!");

*/
    int roop = 0;
    int bbreak;


    while(1) {

        //printf("hi");

        if (roop > 1000) //5 to 1000
        {
            roop = -1;
            break;
        }

        bbreak = 0;


     //   printf("Start direction : ");
/*
        for(i=1; i<=M; i++)
        {
            printf( "%d ", Sharks[i].direct);

        }

        printf("\n");

*/

        for (i = 0; i < N; i++) // roop break
        {
            for (j = 0; j < N; j++) {
                if (map[i][j] != 0) {
                    bbreak++;
                }
            }
        }

        if (bbreak == 1)
            break;


        int nowx, nowy;
        int tmpx, tmpy;

        int tmpdirect, nowdirect;
        int check;






        for (i = 1; i <=M; i++) {

            //printf("hi");

            if (Sharks[i].isdead == 1)
                continue;

            nowx = Sharks[i].x;
            nowy = Sharks[i].y;
            nowdirect = Sharks[i].direct;
            check = 0;

            for (j = 0; j < 4; j++) //order
            {
                tmpdirect = order[i - 1][nowdirect-1][j];

                tmpy = nowy + dy[tmpdirect];
                tmpx = nowx + dx[tmpdirect];

                if (tmpy < 0 || tmpy >= N || tmpx < 0 || tmpx >= N)
                    continue;

                if (smellmap[tmpy][tmpx] == 0) //if no smell
                {

                    Sharks[i].y = tmpy;
                    Sharks[i].x = tmpx;
                    Sharks[i].direct = tmpdirect;

//                    map[tmpy][tmpx] = i;
                    map[nowy][nowx] = 0;

            //       smellmap[tmpy][tmpx] = k;
            //     smellcolormap[tmpy][tmpx] = i;

                    check = 1; // can go
                 //   printf("dy, dx = (%d, %d)]\n", dy[tmpdirect], dx[tmpdirect]);
                 //   printf("smellmap[tmpy][tmpx] = (%d, %d)]\n", tmpy, tmpx);
                 //   printf("After : %d:  %d times,  %d\n", i, j, tmpdirect);
                    break;
                }

            }

            if (check == 0) //can't go
            {
                for (j = 0; j < 4; j++) //order
                {
                    tmpdirect = order[i - 1][nowdirect-1][j];

                    tmpy = nowy + dy[tmpdirect];
                    tmpx = nowx + dx[tmpdirect];


                    if (tmpy < 0 || tmpy >= N || tmpx < 0 || tmpx >= N)
                        continue;

                    if (smellcolormap[tmpy][tmpx] == i) {
                        Sharks[i].y = tmpy;
                        Sharks[i].x = tmpx;
                        Sharks[i].direct = tmpdirect;


//                        map[tmpy][tmpx] = i;
                        map[nowy][nowx] = 0;
/*
                        smellmap[tmpy][tmpx] = k;
                        smellcolormap[tmpy][tmpx] = i;
*/

  //                      printf("back to me !!!! %d %d\n", i, tmpdirect);

                        break;
                    }
                }

            }


        }


        for (i = 1; i <= M; i++) {

            for(j=1; j<=M; j++)
            {
                if(i!=j && Sharks[i].isdead == 0 && Sharks[j].isdead == 0 &&Sharks[i].x == Sharks[j].x && Sharks[i].y == Sharks[j].y)
                {
                    if(i<j)
                    {
                        Sharks[j].isdead = 1;
                    }
                }

            }

        }



        for (i = 0; i < N; i++) //remove smell -1
        {
            for (j = 0; j < N; j++) {
                if (smellmap[i][j] > 0) {
                    smellmap[i][j]--;

                    if (smellmap[i][j] == 0) {
                        smellcolormap[i][j] = 0;
                    }
                }
            }
        }



        for(i=1; i<=M; i++)
        {
            if(Sharks[i].isdead == 1)
                continue;

            map[Sharks[i].y][Sharks[i].x] = i;
            smellmap[Sharks[i].y][Sharks[i].x] = k;
            smellcolormap[Sharks[i].y][Sharks[i].x] = i;

        }


     //   printf("\n\nafter :%d \n", roop);

/*
        for(i=0; i<N; i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%d ", map[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        for(i=0; i<N; i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%d ", smellmap[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        for(i=0; i<N; i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%d ", smellcolormap[i][j]);
            }
            printf("\n");
        }
        printf("\n");
*/




        roop++;



    }


    printf("%d", roop);





    //free




    for(i=0; i<M;i++)
    {
        for(j=0; j<4; j++)
        {
            free(order[i][j]);
        }
    }

    for(i=0; i<M; i++)
    {
        free(order[i]);
    }

    free(order);



    free(Sharks);

    for(i=0; i<N; i++)
    {
        free(smellmap[i]);
    }

    free(smellmap);

    for(i=0; i<N; i++)
    {
        free(map[i]);
    }

    free(map);




    return 0;
}
