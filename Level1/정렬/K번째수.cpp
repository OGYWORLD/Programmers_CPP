#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for(int i = 0; i < commands.size(); i++)
    {
        int srt = commands[i][0];
        int end = commands[i][1];
        int target = commands[i][2];
        
        multiset<int> ms;
        for(int j = srt - 1; j < end; j++)
        {
            ms.insert(array[j]);
        }
        
        auto it = ms.begin();
        advance(it, target - 1);
        answer.push_back(*it);
    }
    
    return answer;
}
