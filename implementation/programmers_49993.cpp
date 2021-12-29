#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Skill;

int orderCHECK(char a)
{
    int now = 0;
    for(int i = 0; i < Skill.length(); i++)
    {
        if (Skill[i] == a)
            return i;
        now++;
    }
    return -1;
}

int CHECK(string skill_tree)
{
    int tmp = 0;
    int now = 0; //skill point
    for(int i = 0; i < skill_tree.length(); i++)
    {
        tmp = orderCHECK(skill_tree[i]);
        //cout << tmp << endl;
        if (tmp != -1)
        {
            if (tmp != now)
                return 0;
            else
                now++;
        }
    }
    return 1;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    Skill = skill;
    for (int i=0; i < skill_trees.size(); i++)
        answer += CHECK(skill_trees[i]);
    
    return answer;
}
