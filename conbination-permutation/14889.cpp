#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Map[20][20];
int MIN = 999999;

int Gap(vector<int> &checkPer, vector<int> &anotherPer, int N)
{
    int firstSum = 0;
    int secondSum = 0;

    for (int i = 0; i < N/2 - 1; i++) {
        for (int j = i + 1; j < (N / 2); j++) {
            firstSum += Map[checkPer[i] - 1][checkPer[j] - 1];
            firstSum += Map[checkPer[j] - 1][checkPer[i] - 1];
        }
    }

    for (int i = 0; i < N/2 - 1; i++) {
        for (int j = i + 1; j < (N / 2); j++) {
            secondSum += Map[anotherPer[i] - 1][anotherPer[j] - 1];
            secondSum += Map[anotherPer[j] - 1][anotherPer[i] - 1];
        }
    }
    return abs(firstSum - secondSum);

}

void Permutation(int now, int N, vector<int> &checkPer)
{

    int gap;

    if ((int)checkPer.size() == (N / 2))
    {

        vector <int> anotherPer;
        for (int i = 1; i <= N; i++)
        {
            auto it = find(checkPer.begin(), checkPer.end(), i);
            if (it == checkPer.end())
                anotherPer.push_back(i);
        }

        gap = Gap(checkPer, anotherPer, N);
        if (gap < MIN)
            MIN = gap;
        return;
    }

    for(int i = now; i < N; i++) {
        checkPer.push_back(i + 1);
        Permutation(i + 1, N, checkPer);
        checkPer.pop_back();
    }
}

int main() {

    int N;

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cin >> Map[i][j];
    }

    vector<int> checkPer;
    Permutation(0, N, checkPer);

    cout << MIN;

}
