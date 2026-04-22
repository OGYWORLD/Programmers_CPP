#include <vector>
#include <set>
#include <cmath>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s(nums.begin(), nums.end());
    int answer = min((int)(nums.size() / 2), (int)s.size());
    
    return answer;
}