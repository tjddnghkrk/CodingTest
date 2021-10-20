#include <stdio.h>
#include <stdlib.h>
#include <string.h>




void turnn(int ** ptr, int len)
{

    int i;
    int tmp = (*ptr)[len-1];

    for(i=len-1; i>0; i--)
    {
        (*ptr)[i] = (*ptr)[i-1];
    }
    (*ptr)[0] = tmp;


}


int main() {


    int i, j;
    int N, K;
    int turn = 1;

    scanf("%d %d", &N, &K);

    int * arr = (int*)malloc(sizeof(int)*2*N);
    int * robot = (int*)malloc(sizeof(int)*N);

    memset(arr, 0, sizeof(int)*2*N);
    memset(robot, 0, sizeof(int)*N);


    for(i = 0; i<2*N; i++)
    {
        scanf("%d", &arr[i]);
    }

    int count;

    while(1)
    {
        count = 0;



        turnn(&arr, 2*N);
        turnn(&robot, N);
        robot[0] = 0;

        if(robot[N-1] == 1)
            robot[N-1] = 0;

        for(i=N-2; i>0; i--)
        {

            if(robot[i]== 1 && robot[i+1] == 0 && arr[i+1]>0) {
                robot[i + 1] = 1;
                arr[i+1]--;
                robot[i] = 0;
            }

        }

        if(arr[0]!= 0) {
            robot[0] = 1;
            arr[0]--;
        }

/*
        printf("turn : %d \n", turn);

        for(i = 0; i<N; i++)
        {
            printf("%d ", robot[i]);
            if(i == N-1)
                printf("\n");
        }
        printf("\n");

    for(i = 0; i<2*N; i++)
    {
        printf("%d ", arr[i]);
        if(i == N-1)
            printf("\n");
    }
    printf("\n");
*/

        //escape
        for(i=0; i<2*N; i++)
        {
            if(arr[i] == 0)
                count++;

        }
        if(count>=K) {
            printf("%d", turn);
            break;
        }

        turn++;
    }



/*
    for(i = 0; i<2*N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
*/



    return 0;


}
