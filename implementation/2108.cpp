#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int inputCnt;
vector<int> numbers;

int CalculateMode(){

    if (inputCnt == 1)
        return numbers[0];

    int nowCnt = 0;
    int maxCnt = 0;

    int modeKey = -5000;
    int modeLastKey = -5000;


    for (int i = (inputCnt - 1); i > 0; --i)
    {
        if(numbers[i] == numbers[i-1])
        {
            nowCnt++;
        }
        else{
            if(nowCnt > maxCnt)
            {
                maxCnt = nowCnt;
                modeKey = numbers[i];
                modeLastKey = -5000;
            }
            else if(nowCnt == maxCnt)
            {
                modeLastKey = modeKey;
                modeKey = numbers[i];
            }
            nowCnt = 0;
        }
    }
    if(nowCnt > maxCnt)
    {
        maxCnt = nowCnt;
        modeKey = numbers[1];
        modeLastKey = -5000;
    }
    else if(nowCnt == maxCnt)
    {
        modeLastKey = modeKey;
        modeKey = numbers[1];

    }

    if (modeLastKey == -5000)
        return modeKey;
    return modeLastKey;

}

int main()
{
    int number;
    int total = 0;

    cin >> inputCnt;

    for (int i = 0; i < inputCnt; ++i)
    {
        cin >> number;
        total += number;
        numbers.push_back(number);
    }

    sort(numbers.begin(), numbers.end());

    // avg
    float avgResult = round(float(total) / float(inputCnt));
    if (avgResult == -0)
        avgResult = 0;
    cout << avgResult << "\n";

    // middle
    cout << numbers[(inputCnt - 1)/2] << "\n";

    // mode
    cout << CalculateMode() << "\n"; 

    // range
    int rangeResult = numbers[inputCnt - 1] - numbers[0];
    cout << (rangeResult >= 0 ? rangeResult : rangeResult * -1) << "\n";
    
}
