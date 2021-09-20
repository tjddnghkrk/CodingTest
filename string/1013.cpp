#include<iostream>
#include<regex>
#include<string>
using namespace std;

int main(void)
{
    int index;
    int T;
    string a;

    index = 0;
    cin >> T;

    while (index++ < T)
    {
        a = "";
        cin >> a;
        cout << (regex_match(a, regex("(100+1+|01)+")) ? "YES" : "NO");
    }
}
