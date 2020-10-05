#include <stdio.h>


#define max(a, b)  ((a)>(b)) ? (a) : (b)

struct FISH{
    int direc;
    int isdead;
    int y, x;
};

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1};
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1};

int answer = 0;


void cpmap(int dest[4][4], int src[4][4])
{
    for(int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)

            dest[i][j] = src[i][j];
    }
}

void cpfish(struct FISH dest[17], struct FISH src[17])
{
    for(int i=1; i<17; i++)
    {
            dest[i] = src[i];
    }
}




int solve(struct FISH shark, struct FISH fish[17], int map[4][4], int result)
{

    //printf("hi");

    int i;
    int j;
    int tmpy, tmpx;
    int nowy, nowx;

    int swap;
    int swapx;
    int swapy;

    int tmpdirect;
    int tmpmap[4][4];
    int tmpresult;

    cpmap(tmpmap, map); //copy map

    struct FISH tmpfish[17];
    cpfish(tmpfish, fish); //copy fish

    tmpfish[tmpmap[shark.y][shark.x]].isdead = 1; //shark kill fish



    struct FISH tmpshark = shark;

    tmpshark.direc = tmpfish[tmpmap[shark.y][shark.x]].direc; //shark get direction
    tmpfish[tmpmap[shark.y][shark.x]].direc = -1; //fish remove direc


    //printf("tmpshark.direc : %d\n", tmpshark.direc);

    //printf("%d \n", tmpmap[shark.y][shark.x]);

    tmpresult = result + tmpmap[tmpshark.y][tmpshark.x];
    tmpmap[tmpshark.y][tmpshark.x] = 0;

    //printf("result: %d\n", tmpresult);
    if(tmpresult > answer)
        answer = tmpresult;


    for(i=1; i<17; i++) //1 to 16 //1 time
    {

        if(tmpfish[i].isdead == 1)
            continue;


        nowy = tmpfish[i].y;
        nowx = tmpfish[i].x;

       // printf("now : %d %d\n", nowy, nowx);


        tmpdirect = tmpfish[i].direc;
        tmpdirect -=1; //0to7

        int dddirect;

        for(j=0; j<8; j++)
        {


            dddirect = (tmpdirect + j)%8;

            tmpy = nowy+dy[dddirect];
            tmpx = nowx+dx[dddirect];

            //printf("tmp : %d %d\n", tmpy, tmpx);



            if (tmpy>=0 && tmpy<4 && tmpx >=0 && tmpx <4)
            {
                if(tmpshark.x == tmpx && tmpshark.y == tmpy)
                    continue;

                if(tmpmap[tmpy][tmpx] == 0) {
                    tmpmap[tmpy][tmpx] = i;
                    tmpfish[i].y = tmpy;
                    tmpfish[i].x = tmpx;
                    tmpfish[i].direc = dddirect+1;

                    tmpmap[nowy][nowx] = 0; //delete old one

                    //printf("%d: %d %d %d\n", i, tmpy, tmpx, tmpdirect+1);
                    break;
                }
                else
                {
                    swapx = tmpfish[(tmpmap[tmpy][tmpx])].x;
                    swapy = tmpfish[(tmpmap[tmpy][tmpx])].y;
                    swap = tmpmap[tmpy][tmpx];

                    tmpfish[(tmpmap[tmpy][tmpx])].x = nowx;
                    tmpfish[(tmpmap[tmpy][tmpx])].y = nowy;
                    tmpmap[tmpy][tmpx] = tmpmap[nowy][nowx];

                    tmpfish[i].x = swapx;
                    tmpfish[i].y = swapy;
                    tmpmap[nowy][nowx] = swap;
                    tmpfish[i].direc = dddirect+1;

                    //printf("%d: %d %d %d\n", i, swapy, swapx, tmpdirect+1);


                    break;
                }
            }
        }


    }

/*
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d ", tmpmap[i][j]);
        }
        printf("\n");
    }
*/
    int tmpsharky, tmpsharkx;
    int firstsharky, firstsharkx;

    firstsharkx = tmpshark.x;
    firstsharky = tmpshark.y;


    for(int k=1; k<4; k++)
    {

        tmpshark.x = firstsharkx;
        tmpshark.y = firstsharky;

        tmpsharky = tmpshark.y + (dy[tmpshark.direc-1])*k;
        tmpsharkx = tmpshark.x + (dx[tmpshark.direc-1])*k;

        if(tmpsharky <0 || tmpsharky>3 || tmpsharkx<0 || tmpsharkx>3 || tmpmap[tmpsharky][tmpsharkx] == 0)
            continue;


        tmpshark.x = tmpsharkx;
        tmpshark.y = tmpsharky;

       // printf("SHARK GO : %d %d %d %d\n", tmpshark.direc, tmpsharky, tmpsharkx, tmpresult);

        solve(tmpshark, tmpfish, tmpmap, tmpresult);
    }


}


int main() {

    struct FISH fish[17];
    struct FISH shark;

    shark.x = 0;
    shark.y = 0;

    int map[4][4];

    int i, j;

    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            scanf("%d", &map[i][j]);
            scanf("%d",  &fish[map[i][j]].direc);
            fish[map[i][j]].isdead = 0;
            fish[map[i][j]].y = i;
            fish[map[i][j]].x = j;
        }
    }

    solve(shark, fish, map, 0);

    printf("%d", answer);


/*
    for(i=0; i<4; i++)
    {
        for(j=0; j<4; j++)
        {
            printf("%d \n", map[i][j]);
            //fish[map[i][j]].isdead = 0;
        }
    }

    for(i=1; i<17; i++)
        printf("%d %d %d\n", fish[i].y, fish[i].x, fish[i].direc);
*/

    return 0;
}
