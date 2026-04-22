#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;

    for (int i = 0; i < progresses.size(); i++)
    {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];

        if (remain % speeds[i] != 0)
        {
            day++;
        }

        days.push_back(day);
    }

    int current = days[0];
    int count = 1;

    for (int i = 1; i < days.size(); i++)
    {
        if (days[i] <= current)
        {
            count++;
        }
        else
        {
            answer.push_back(count);
            current = days[i];
            count = 1;
        }
    }

    answer.push_back(count);

    return answer;
}