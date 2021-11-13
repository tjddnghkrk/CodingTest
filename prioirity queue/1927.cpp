#include <iostream>
#include <queue>

using namespace std;
int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    int now;

    priority_queue<int, vector<int>, greater<>> pq;

    cin >> count;

    for(int i=0; i<count; i++) {
        cin >> now;
        if (now == 0) {
            if (pq.empty())
                cout << 0 << '\n';
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        } else {
            pq.push(now);
        }
    }

    return 0;
}
