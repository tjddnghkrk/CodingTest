#include <stdio.h>

int N;
int map[20][20];
int check[21] = {0, };

int MIN = 98765432;


int ans(int i){
    
    return i<0 ? (-1)*i : i;
}



void solution(int def, int current)
{
    
    int i, j;
    int team1 = 0;
    int team2 = 0;
    int res;
    
    if(current == (N/2))
    {
        
        for(i=0; i<N-1; i++)
        {
            for(j=i+1; j<N; j++)
            {
                
                if(check[i] == 1 && check[j] == 1 ){
                    team1 += map[i][j];
                    team1 += map[j][i];
                    
                }
                if(check[i] == 0 && check[j] == 0)
                {
                    team2 += map[i][j];
                    team2 += map[j][i];
                }
                
            }
        }
        
        res = ans(team1 - team2);
        
        if(res < MIN)
            MIN = res;
        
       // printf("finish\n");
        return;   
        
    }
    
    

    for(i=def+1; i<N; i++)
    {
        check[i] = 1;
        solution(i, current+1);
        check[i] = 0;
    }

    
}


int main(){
    
    int i, j;
    
    scanf("%d", &N);
    
    for(i=0; i<N; i++)
    {
        for(j=0; j<N; j++)
        {
            scanf("%d", &map[i][j]);
        }
    }
    
    solution(0, 0);
    
    printf("%d", MIN);
    
}
