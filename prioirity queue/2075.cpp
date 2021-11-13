#include <iostream>
#include <queue>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    priority_queue<int, vector<int>, greater<>> pq;
    int num;
    int value;
    cin >> num;


    for(int i=0; i< num * num; i++)
    {
        cin >> value;
        pq.push(value);

        if(pq.size() > num)
            pq.pop();
    }

    cout << pq.top();

}
