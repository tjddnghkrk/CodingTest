#include <stdio.h>
#include <string.h>

char arr[12][6];
int dupli[12][6];

dx[] = {-1, 1, 0, 0};
dy[] = {0, 0, -1, 1};

int xx[1000];
int yy[1000];

int makezero(int front)
{
    for(int k = 0; k<=front; k++)
    {
        arr[xx[k]][yy[k]] = '.';
    }
/*
    for(int i = 0; i<12; i++)
    {
        for(int j = 0; j<6; j++)

        {
            printf("%c", arr[i][j]);
        }
        printf("\n");

    }

    */
}

int check(int i, int j)
{

    int x = i;
    int y = j;
    int tmx;
    int tmy;

    memset(xx, 0, sizeof(xx));
    memset(yy, 0, sizeof(yy));
    memset(dupli, 0, sizeof(dupli));


    xx[0] = x;
    yy[0] = y;
    dupli[x][y] = 1;

    int front = 0;
    int tail = -1;

    while(front != tail)
    {
        x = xx[++tail];
        y = yy[tail];


        for(int k = 0; k<4; k++)
        {
            tmx = x+dx[k];
            tmy = y+dy[k];

            if(tmx < 0 || tmx >11 || tmy <0 || tmy>5 || dupli[tmx][tmy] == 1)
                continue;

            if(arr[tmx][tmy] == arr[i][j])
            {
                dupli[tmx][tmy] = 1;
                xx[++front] = tmx;
                yy[front] = tmy;
            }
        }

    }

    if(front>=3) {

        makezero(front);
        return 1;
    }
    else
        return 0;


}

int main(){


    int num = 0;
    int result = 0;

    int i, j;

    for(i = 0; i<12; i++)
    {
        for(j = 0; j<6; j++)

        {
            scanf("%c", &arr[i][j]);
        }
        getchar();

    }

/*
    for(i = 0; i<12; i++)
    {
        for(j = 0; j<6; j++)

        {
            printf("%c", arr[i][j]);
        }
        printf("\n");

    }
*/


    while(1) {

        result = 0;


        for (i = 0; i < 12; i++) {
            for (j = 0; j < 6; j++) {

                if (arr[i][j] == '.')
                    continue;

                else {
                    result += check(i, j);
                  //  printf("result = %d\n", result);
                }
            }

        }

        for(int w = 11; w>=1; w--)
        {
            for(int v = 5; v>=0; v--)
            {
                if (arr[w][v] == '.')
                {
                    for(int k = w-1; k>=0; k--)
                    {
                        if(arr[k][v] == '.')
                            continue;
                        else {
                            arr[w][v] = arr[k][v];
                            arr[k][v] = '.';
                            break;
                        }

                    }
                }
            }
        }
/*
        for (int m = 0; m < 12; m++) {
            for (int n = 0; n < 6; n++) {
                printf("%c", arr[m][n]);
            }
            printf("\n");
        }
*/
        if (result > 0)
            num++;
        else
            break;


   // printf("time");
    }

    printf("%d", num);



    return 0;
}

