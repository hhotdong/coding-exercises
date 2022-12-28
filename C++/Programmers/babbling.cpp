#include <string>
#include <vector>

using namespace std;

const string kSpeakableWords[] = { "aya", "ye", "woo", "ma" };

int SizeOfFirstSpeakableWordIn(string word)
{
    int compCnt = sizeof(kSpeakableWords) / sizeof(kSpeakableWords[0]);
    for (int swi = 0; swi < compCnt; ++swi)
    {
        if (word.find(kSpeakableWords[swi]) == 0)
            return kSpeakableWords[swi].size();
    }
    return -1;
}

bool IsSpeakable(string word)
{
    string::iterator it = word.begin();
    while (it != word.end())
    {
        int speakableWordSize = SizeOfFirstSpeakableWordIn(word.substr(it - word.begin()));
        if (speakableWordSize == -1)
            return false;

        it += speakableWordSize;
    }
    return true;
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
