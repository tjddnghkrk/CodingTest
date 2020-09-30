//테스트 케이스 5개 다 돌아가나 fail

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int x[50] = {0, };
int d[50] = {0, };
int k[50] = {0, };

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int Qx[100];
int Qy[100];

int search (int *** ptr, int X, int Y, int N, int M){

    int i;


    int ** check = (int **)malloc(sizeof(int *)*N);

    for(i = 0; i<N; i++)
    {
        check[i] = (int *)malloc(sizeof(int)*M);
    }

    int resultnum = 0;

    memset(Qx, 0, sizeof(Qx));
    memset(Qy, 0, sizeof(Qy));

    for(i =0; i<N; i++) {
        memset(check[i], 0, sizeof(int)*M);
    }

    int num = (*ptr)[X][Y];

    if (num == 0)
        return 0;

    check[X][Y] = 1;


    //printf("number : %d %d\n", X, Y);

    Qx[0] = X;
    Qy[0] = Y;

    int tmpx, tmpy;
    int tail, front;
    tail = -1;
    front = 0;

    while(tail!=front) {


        X = Qx[++tail];
        Y = Qy[tail];



        for (i = 0; i < 4; i++) {
            tmpx = X + dx[i];
            tmpy = Y + dy[i];

            tmpy = (tmpy+M)%M;

            if (tmpx < 0 || tmpx >= N || check[tmpx][tmpy] == 1)
                continue;

            if ((*ptr)[tmpx][tmpy] == num) {
                Qx[++front] = tmpx;
                Qy[front] = tmpy;
                check[tmpx][tmpy] = 1;
                resultnum++;

               // printf("x, y : %d %d\n", tmpx, tmpy);
            }

        }
        //printf(" ----- \n");


    }


    if(resultnum>0) {

        for (i = 0; i <= front; i++) {

            (*ptr)[Qx[i]][Qy[i]] = 0;
            //printf("queue : %d %d\n", Qx[i], Qy[i]);

        }
    }




    for(i = 0; i<N; i++)
    {
        free(check[i]);
    }

    free(check);

    return resultnum;

}

int main() {

    int N, M, T;
    int i, j;
    int ch;
    int result = 0;
    int sum;
    int nn;

    scanf("%d %d %d", &N, &M, &T);
    getchar();

    int **arr = (int **) malloc(sizeof(int *) * N);

    for (i = 0; i < N; i++) {
        arr[i] = (int *) malloc(sizeof(int) * M);
    }

    for (i = 0; i < N; i++) {
        memset(arr[i], 0, sizeof(int) * M);
    }


    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
        getchar();
    }


    for (i = 0; i < T; i++) {

        scanf("%d %d %d", &x[i], &d[i], &k[i]);
        getchar();

        //     printf("%d %d %d\n", x[i], d[i], k[i]);

    }


    int nowN;

    int *tmparr = (int *) malloc(sizeof(int) * M);


    //printf("hi\n");

    for (int kk = 0; kk < T; kk++) {

        //printf("roop\n");

        ch = 0;
        sum = 0;
        nn = 0;

        //printf("x : %d\n", x[kk]);



        nowN = x[kk];

// spin start

        while (nowN <= N) {


            if (d[kk] == 0) {

                for (i = 0; i < M; i++) {
                    //printf("now : %d", (i+k[kk])%M);
                    tmparr[(i + k[kk]) % M] = arr[nowN - 1][i];
                }

                for (i = 0; i < M; i++) {
                    arr[nowN - 1][i] = tmparr[i];
                }
            } else {

                for (i = 0; i < M; i++) {
                    //printf("now : %d", (i+k[kk])%M);
                    tmparr[(i - k[kk] + M) % M] = arr[nowN - 1][i];

                }

                for (i = 0; i < M; i++) {
                    arr[nowN - 1][i] = tmparr[i];
                }


            }

/*
            printf("round:\n");

            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    printf("%d ", arr[i][j]);
                }
                printf("\n");
            }
            printf("\n");

*/
            nowN *= 2;


        }


        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                ch += search(&arr, i, j, N, M);
            }
        }

        // printf("make zero : %d\n", ch);

        if (ch == 0) {

            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {
                    if (arr[i][j] > 0) {
                        nn++;
                        sum += arr[i][j];
                    }
                }
            }

            float ave = (float) sum / (float) nn;

            //  printf("ave : %f, nn: %d\n", ave, nn);

            for (i = 0; i < N; i++) {
                for (j = 0; j < M; j++) {

                    if (arr[i][j] > 0) {
                        if (arr[i][j] > ave) {
                            arr[i][j]--;
                        } else if (arr[i][j] < ave) {
                            arr[i][j]++;
                        }
                    }
                }
            }


        }
/*
        printf("after plus, minus: \n");
        for(i = 0; i<N; i++)
        {
            for(j = 0; j<M; j++)
            {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
*/

    }

    //   printf("reusult:\n");

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            result += arr[i][j];
            //   printf("%d ", arr[i][j]);
        }
        //printf("\n");
    }

     printf("%d", result);




/*
    for(i = 0; i<N; i++)
    {
        for(j = 0; j<M; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }


    for(i = 0; i<T; i++) {
        printf("%d %d %d", x[i], d[i], k[i]);
        printf("\n");
    }
*/



    free(tmparr);
    for (i = 0; i < N; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
