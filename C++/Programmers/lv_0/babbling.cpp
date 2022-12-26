#include <string>
#include <vector>

using namespace std;

const string kSpeakableWords[] = { "aya", "ye", "woo", "ma" };

bool IsSpeakable(string word)
{
    int wLen = word.size();
    
    while (true)
    {
        bool foundAtLeastOneWordMatched = false;
        int compCnt = sizeof(kSpeakableWords) / sizeof(kSpeakableWords[0]);
        for (int swi = 0; swi < compCnt; ++swi)
        {
            int swLen = kSpeakableWords[swi].size();
            if (wLen < swLen)
                continue;
            
            bool matched = true;
            for (int wi = 0; wi < swLen; ++wi)
            {
                if (word[wi] != kSpeakableWords[swi][wi])
                {
                    matched = false;
                    break;
                }
            }
            
            if (matched == false)
                continue;
            
            foundAtLeastOneWordMatched = true;
            word.erase(0, swLen);
        }
        
        if (foundAtLeastOneWordMatched == false)
            break;
    }
    
    return word.size() == 0;
}

int solution(vector<string> babbling) {
    int answer = 0;
    int size = babbling.size();
    for (int i = 0; i < size; i++)
    {
        if (IsSpeakable(babbling[i]))
            ++answer;
    }
    return answer;
}
