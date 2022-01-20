#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


int F, S, G, U, D;
int MIN = -1;


int main() {

    cin >> F >> S >> G >> U >> D;

    queue<pair<int, int>> Q;
    int now;
    int count;

    Q.push(make_pair(S, 0));
    vector<int> Check(F + 1, 0);

    while(!Q.empty())
    {
        now = Q.front().first;
        count = Q.front().second;
        //cout << now << " " << count << endl;
        if (now == G)
        {
            MIN = count;
            break;
        }
        Q.pop();

        if (now + U <= F && !Check[now + U]) {
            Q.push(make_pair(now + U, count + 1));
            Check[now + U] = 1;
        }
        if (now - D > 0 && !Check[now - D]) {
            Q.push(make_pair(now - D, count + 1));
            Check[now - D] = 1;
        }
    }
    if (MIN == -1)
        cout << "use the stairs";
    else
        cout << MIN;

}
