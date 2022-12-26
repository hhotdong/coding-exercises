using System;

public class Solution {
    private static readonly string[] kSpeakableWords = new string[] { "aya", "ye", "woo", "ma" };
    
    public int solution(string[] babbling) {
        int answer = 0;
        for (int i = 0; i < babbling.Length; i++)
        {
            if (IsSpeakable(babbling[i]))
                ++answer;
        }
        return answer;
    }

    private bool IsSpeakable(string word)
    {
        int offset = 0;
        while (offset < word.Length)
        {
            int speakableWordSize = SizeOfFirstSpeakableWordIn(word.Substring(offset));
            if (speakableWordSize == -1)
                return false;

            offset += speakableWordSize;
        }
        return true;
    }

    private int SizeOfFirstSpeakableWordIn(string word)
    {
        if (string.IsNullOrEmpty(word))
            return -1;

        int compCnt = kSpeakableWords.Length;
        for (int swi = 0; swi < compCnt; ++swi)
        {
            if (word.IndexOf(kSpeakableWords[swi]) == 0)
                return kSpeakableWords[swi].Length;
        }
        return -1;
    }
}
