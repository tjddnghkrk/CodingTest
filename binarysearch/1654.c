#include <stdio.h>

long long map[10000];

int main() {
    long long K;
    long long N;
    long long max = 0;
    long long min = 999999999;
    long long point;
    long long n = 0;

    scanf("%lld", &K);
    scanf("%lld", &N);

    for(int i=0; i<K; i++)
    {
        scanf("%lld", &map[i]);
        if(max < map[i])
            max = map[i];
    }
    max += 1;
    min = 0;
    point = (max + min) / 2;

    while(min != max - 1)
    {
        n = 0; // point 로 계산한 개수
        for(int i = 0; i < K; i++)
        {
            n += map[i] / point;
        }
        if (n < N)
        {
            max = point;
            point = (point + min) / 2;
        }
        else if (n > N)
        {
            min = point;
            point = (point + max) / 2;
        }
        else
        {
            min = point;
            point = (min + max) / 2;
        }
    }

    printf("%lld", min);

    return 0;
}
