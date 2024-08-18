// https://school.programmers.co.kr/learn/courses/30/lessons/120956
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const char* kSpeakableWords[] = { "aya", "ye", "woo", "ma" };

bool IsSpeakable(char* word)
{
    int wOffset = 0;
    int wLen = strlen(word);
    
    while (true)
    {
        bool foundAtLeastOneWordMatched = false;
        int compCnt = sizeof(kSpeakableWords) / sizeof(kSpeakableWords[0]);
    
        for (int swi = 0; swi < compCnt; ++swi)
        {
            int swLen = strlen(kSpeakableWords[swi]);
            if (wLen < swLen)
                continue;
            
            bool matched = true;
            for (int wi = 0; wi < swLen; ++wi)
            {
                if (word[wi + wOffset] != kSpeakableWords[swi][wi])
                {
                    matched = false;
                    break;
                }
            }
            
            if (matched == false)
                continue;
            
            foundAtLeastOneWordMatched = true;
            wOffset += swLen;
        }
        
        if (foundAtLeastOneWordMatched == false)
            break;
    }
    
    return wOffset == wLen;
}

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    for (int i = 0; i < babbling_len; i++)
    {
        if (IsSpeakable(babbling[i]))
            ++answer;
    }
    return answer;
}
