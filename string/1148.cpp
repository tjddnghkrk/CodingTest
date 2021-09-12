#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int Input[200000][26];

int main() {

    string tmp;
    int index=0;

    while(1)
    {
        tmp = "";
        cin >> tmp;
        if(tmp == "-")
            break;

        for(int i=0; i<tmp.length(); i++) { //check
            Input[index][tmp[i]-'A']++;
        }
        index++;
    }



    while(1)
    {
        vector<char> Min;
        vector<char> Max;
        tmp = "";
        cin >> tmp;
        if(tmp == "#")
            break;

        int hash[26] = {0, };
        int Alpha[26] = {0, };
        bool check;
        int MAX = 0;
        int MIN = 99999999;
        int num = 0;

        for(int i=0; i<tmp.length(); i++)
        {
            num = tmp[i]-'A';
            Alpha[num]++;
        }

        for(int i=0; i<index; i++) //words
        {
            check = true;
            int tmphash[26] = {0, };
            for(int j=0; j<26; j++)
            {
                if(Input[i][j] > Alpha[j]) { //can make?
                    check = false;
                    break;
                }
            }
            if(check) //can make
            {
                for(int j=0; j<26; j++)
                {
                    if(Input[i][j])
                    {
                        if(tmphash[j]==1)
                            continue;
                        else
                        {
                            tmphash[j]++;
                            hash[j]++; //check to hash
                        }
                    }
                }
            }
        }
/*
        cout << "hash"<<endl;

        for(auto & i : hash)
            cout << i;
        cout << endl;
*/

        for(int i=0; i<26; i++)
        {
            if(!Alpha[i]) //in alpha
                continue;
            if(hash[i] < MIN) //find min
                MIN = hash[i];
            if(hash[i] > MAX)
                MAX = hash[i]; //find max
        }

        for(int i=0; i<26; i++)
        {
            if(!Alpha[i])
                continue;
            if(hash[i] == MIN)
            {
                Min.push_back((char)(i+'A'));
            }
            if(hash[i] == MAX)
                Max.push_back((char)(i+'A'));
        }

        sort(Min.begin(), Min.end());
        sort(Max.begin(), Max.end());

        for(auto & i : Min)
        {
            cout << i;
        }
        cout << " "<< MIN << " ";

        for(auto & i : Max)
        {
            cout << i;
        }
        cout << " "<< MAX << endl;

    }



    return 0;
}


