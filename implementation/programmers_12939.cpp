#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    
    string answer = "";
    bool MINUS = false;
    int MAX = -99999999;
    int MIN = 99999999;
    int num = 0;
    
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ' ')
        {
            MINUS = false;
            if (num < MIN)
                MIN = num;
            if (num > MAX)
                MAX = num;
            num = 0;
            continue;
        }
        else if (s[i] == '-')
        {
            MINUS = true;
            continue;
        }
        else
        {
            if (MINUS && num == 0)
            {
                num = (s[i] - '0') * -1;
            }
            else
            {
                num *= 10;
                if(MINUS)
                    num -= (s[i] - '0');
                else
                    num += (s[i] - '0');
            }
        }
        
    }
    if (num < MIN)
        MIN = num;
    if (num > MAX)
        MAX = num;
    
    answer += to_string(MIN);
    answer.push_back(' ');
    answer += to_string(MAX);

    return answer;
}
