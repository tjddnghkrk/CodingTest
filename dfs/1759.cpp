#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int L;
int C;
vector<char> v;
vector<char> tmpv;


void DFS(int now, int count)
{
    int ae = 0;
    int bc = 0;

    if(count == L) {
        for(auto & j : tmpv)
        {
            if (j == 'a' || j == 'e' || j == 'i' || j == 'o' || j == 'u')
                ae += 1;
            else
                bc += 1;
        }
        if (ae >= 1 && bc >= 2) {
            for (auto &j : tmpv)
                cout << j;
            cout << endl;
        }
        return;
    }
    for(int i = now+1; i < C; i++)
    {
        tmpv.push_back(v[i]);
        DFS(i, count + 1);
        tmpv.pop_back();
    }
}

int main() {

    int i;
    char tmp;

    i = 0;
    cin >> L >> C;

    while(i < C)
    {
        cin >> tmp;
        v.push_back(tmp);
        i++;
    }
    sort(v.begin(), v.end());
    DFS(-1, 0);

    //for(auto & k : v)
    //    cout << k << endl;
}
