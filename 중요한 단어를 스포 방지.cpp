#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct WordInfo
{
    string text;
    int start;
    int end;
    int hiddenCount;
    bool isSpoilerWord;
};

vector<WordInfo> ParseWords(const string& message)
{
    vector<WordInfo> words;
    int n = (int)message.size();
    int i = 0;

    while (i < n)
    {
        if (message[i] == ' ')
        {
            i++;
            continue;
        }

        int start = i;
        string text;

        while (i < n && message[i] != ' ')
        {
            text += message[i];
            i++;
        }

        int end = i - 1;
        words.push_back({ text, start, end, 0, false });
    }

    return words;
}

int solution(string message, vector<vector<int>> spoiler_ranges)
{
    int n = (int)message.size();
    vector<bool> isSpoilerPos(n, false);

    for (const auto& range : spoiler_ranges)
    {
        int l = range[0];
        int r = range[1];

        for (int i = l; i <= r; i++)
        {
            isSpoilerPos[i] = true;
        }
    }

    vector<WordInfo> words = ParseWords(message);

    unordered_set<string> visibleWords;
    for (auto& word : words)
    {
        int hidden = 0;
        for (int i = word.start; i <= word.end; i++)
        {
            if (isSpoilerPos[i])
            {
                hidden++;
            }
        }

        word.hiddenCount = hidden;
        word.isSpoilerWord = (hidden > 0);

        if (!word.isSpoilerWord)
        {
            visibleWords.insert(word.text);
        }
    }

    int answer = 0;
    unordered_set<string> revealedSpoilerWords;
    int wordIdx = 0;

    for (const auto& range : spoiler_ranges)
    {
        int l = range[0];
        int r = range[1];

        while (wordIdx < (int)words.size() && words[wordIdx].end < l)
        {
            wordIdx++;
        }

        int idx = wordIdx;
        while (idx < (int)words.size() && words[idx].start <= r)
        {
            int overlapStart = max(words[idx].start, l);
            int overlapEnd = min(words[idx].end, r);

            if (overlapStart <= overlapEnd)
            {
                words[idx].hiddenCount -= (overlapEnd - overlapStart + 1);

                if (words[idx].hiddenCount == 0)
                {
                    if (visibleWords.find(words[idx].text) == visibleWords.end() &&
                        revealedSpoilerWords.find(words[idx].text) == revealedSpoilerWords.end())
                    {
                        answer++;
                    }

                    revealedSpoilerWords.insert(words[idx].text);
                }
            }

            idx++;
        }
    }

    return answer;
}