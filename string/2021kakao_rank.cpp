#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int DP[1000][3];

int N;
int MIN = 99999999;


int main() {

    cin >> N;

    int tmp[3];

    DP[0][0] = 0;
    DP[0][1] = 0;
    DP[0][2] = 0;

    for(int i=1; i<=N; i++)
    {
        cin >> tmp[0] >> tmp[1] >> tmp[2];
        DP[i][0] = min(DP[i-1][1] + tmp[0], DP[i-1][2] + tmp[0]);
        DP[i][1] = min(DP[i-1][0] + tmp[1], DP[i-1][2] + tmp[1]);
        DP[i][2] = min(DP[i-1][0] + tmp[2], DP[i-1][1] + tmp[2]);
    }

    for(int i=0; i<3; i++)
    {
        if(DP[N][i] < MIN)
            MIN = DP[N][i];
    }

    cout << MIN;

    return 0;
}
