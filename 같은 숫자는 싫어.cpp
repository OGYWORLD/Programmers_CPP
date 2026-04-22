#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;

    int arrSize = arr.size();
    
    stack<int> s;
    s.push(arr[arrSize - 1]);
    for(int i = arrSize - 2; i > -1; i--)
    {
        if(s.top() != arr[i])
        {
            s.push(arr[i]);
        }
    }
    
    while(!s.empty())
    {
        answer.push_back(s.top());
        s.pop();
    }

    return answer;
}