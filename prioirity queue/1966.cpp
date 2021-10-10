#include <iostream>
#include <algorithm>
#include <queue>
 
using namespace std;
 
int main(){
    int test_case;
    cin >> test_case;
    vector<int> v;
    for(int i=0; i<test_case; i++){
        int N, M;
        cin >> N >> M;
 
        queue<pair<int, int> >  q;
        priority_queue<int, vector<int> > pq;

        for(int j=0; j<N; j++){
            int element;
            cin >> element;
            q.push(make_pair(j, element));
            pq.push(element);
        }
 
        int cnt = 0;
        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop();
            if(pq.top() == value){
                pq.pop();
                cnt++;
                if(index == M){
                    cout << cnt << "\n";
                    break;
                }
            }else q.push(make_pair(index, value));
        }
    }
 
    return 0;
}

