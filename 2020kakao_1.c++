#include <string>
#include <vector>

using namespace std;

int solution(string s) {
     int i, j, k; 
    int len = s.size();
    int answer = len;
    
    int tmpresult;
    int count;
    bool check = true;
    
    for(i = 1; i<=len/2; i++) //문자열 개수
    {
        tmpresult = len;
        count = 1;
        
        for(j=0; j<len; j+=i) // 1회 찾기
        {
            
            check = 1;
            
            for(k=j; k<j+i; k++) //중복값 찾기
            {
                //cout << k<<endl;
                 
                if(k+i >= len || s[k] != s[k+i]) //다르면
                {
                    check = 0;
                    break;
                }
            }
            
            if(check){
                count ++; //1개 늘음
               // cout << "correct"<<endl;
            }
            else
            {
                if(count == 1)
                    continue;
                
                else{
                    //cout << "still is "<< count << endl;
                    
                    tmpresult -= (i*(count-1)); //빼주고

                    if(count >=100)
                        tmpresult += 3;
                    else if(count >=10)
                        tmpresult +=2;
                    else 
                        tmpresult +=1;
                    
                    count = 1; //개수 되돌려놓기
                    
                }
            }
        }
        
        if(tmpresult < answer)
        {
            answer = tmpresult;
        }
        
    }
    
    
    return answer;
}
