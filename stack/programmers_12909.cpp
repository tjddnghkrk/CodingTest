#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<int> S;
    
    for (int i = 0 ; i < s.size(); i++)
    {
        if (s[i] == '(')
            S.push(1);
        else
        {
            if (S.empty())
                return false;
            else
                S.pop();
        }   
    }
    return (S.empty());
    /*
    if (S.empty())
        return true; 
    else
        return false;*/
}
