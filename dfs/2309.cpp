#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int height[9];

void DFS(int now, int count, int sum, vector<int> &v)
{
    //cout << now << " " << sum << endl;
    if(count == 7 && sum == 100)
    {
        sort(v.begin(), v.end());
        for(auto & i : v)
        {
            cout << i << endl;
        }
        exit(0);
    }

    if(count == 7)
        return;

    for (int i = now + 1; i < 9; i++)
    {
        v.push_back(height[i]);
        DFS(i, count + 1, sum + height[i], v);
        v.pop_back();
    }
}


int main() {

    int i = 0;
    int tmp;
    vector <int> v;

    while(i < 9)
    {
        cin >> tmp;
        height[i] = tmp;
        i++;
    }

    DFS(-1, 0, 0, v);

    return 0;
}
