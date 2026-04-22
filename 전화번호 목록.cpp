#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool IsPrefix(const string& prefix, const string& phoneNumber)
{
    bool isSame = true;
    for(int i = 0; i < prefix.size(); i++)
    {
        if(prefix[i] != phoneNumber[i])
        {
            isSame = false;
            break;
        }
    }
    
    return isSame;
}

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    int len = phone_book.size();
    
    sort(phone_book.begin(), phone_book.end());
    
    for(int i = 0; i < len - 1; i++)
    {
        if(IsPrefix(phone_book[i], phone_book[i + 1]))
        {
            answer = false;
            break;
        }
    }
    
    return answer;
}