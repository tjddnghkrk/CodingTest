#include <string>
#include <vector>
#include <iostream>

using namespace std;

int result;

void FIND(int start, int n)
{
    int num = 0;
    
    for (int i = start; i < n; i++)
    {
        num += i;
        if (num == n)
        {
            //cout << start << endl;
            result += 1;
            return;
        }
        if (num > n)
            return;
    }
}

int solution(int n) {
        
    for(int i = 1; i <= int(n / 2); i++) //1 -> 1 2 -> 1
        FIND(i, n);
    
    return result + 1;
}
