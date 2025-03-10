// https://school.programmers.co.kr/learn/courses/30/lessons/49994?language=csharp
using System;
using System.Collections.Generic;

public class Solution {
    public int solution(string dirs) {
        HashSet<(int, int)> edges = new HashSet<(int, int)>();
        int x = 0, y = 0;
        
        for (int i = 0; i < dirs.Length; i++)
        {
            int px = x, py = y;
            if      (dirs[i] == 'U' && y <  5) ++y;
            else if (dirs[i] == 'D' && y > -5) --y;
            else if (dirs[i] == 'L' && x > -5) --x;
            else if (dirs[i] == 'R' && x <  5) ++x;

            if (px != x || py != y)
                edges.Add((px + x, py + y));
        }
        int answer = edges.Count;
        return answer;
    }
}