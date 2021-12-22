#include <string>
#include <vector>

using namespace std;

vector<string> alpha = {"A", "E", "I", "O", "U"};
int answer = 0;
bool check = false;

void DFS(string tmp, string word){
    if (word.compare(tmp) == 0)
        check = 1;
    
    if (check) //break;
        return;
    
    answer++;
    
    if (tmp.length() == 5)
        return;
    for (int i=0; i<5; i++)
        DFS(tmp + alpha[i], word);
}

int solution(string word) {
    string tmp = "";
    
    for(int i=0; i<5; i++)
        DFS(tmp + alpha[i], word);
    
    return answer + 1;
}
