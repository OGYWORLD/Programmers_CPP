#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    
    unordered_map<string, int> um;
    for (const auto& cloth : clothes)
    {
        um[cloth[1]]++;
    }
    
    int answer = 1;

    for (const auto& pair : um)
    {
        answer *= (pair.second + 1);
    }

    return answer - 1;
}