#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    multiset<string> ms(participant.begin(), participant.end());
    
    for (const auto& name : completion)
    {
        ms.erase(ms.find(name));
    }
    
    return *ms.begin();
}