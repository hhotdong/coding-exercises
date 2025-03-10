// https://school.programmers.co.kr/learn/courses/30/lessons/49994?language=csharp
using System;
using System.Collections.Generic;

public class Movement
{
    public Coordinate From;
    public Coordinate To;
    
    public Movement(Coordinate from, Coordinate to)
    {
        From = from;
        To   = to;
    }
    
    public override bool Equals(object other)
    {
        Movement otherMove = other as Movement;
        if (ReferenceEquals(otherMove, null))
            return false;
        return this == otherMove;
    }
    
    public static bool operator==(Movement lhs, Movement rhs)
    {
        bool lhsIsNull = ReferenceEquals(lhs, null);
        bool rhsIsNull = ReferenceEquals(rhs, null);
        if (lhsIsNull && rhsIsNull)
            return true;
        
        if (lhsIsNull || rhsIsNull)
            return false;
        
        bool equalsExactly  = (lhs.From == rhs.From) && (lhs.To == rhs.To);
        bool equalsInversly = (lhs.From == rhs.To)   && (lhs.To == rhs.From);
        return equalsExactly || equalsInversly;
    }
    
    public static bool operator!=(Movement lhs, Movement rhs)
    {
        return !(lhs == rhs);
    }
    
    public override int GetHashCode()
    {
        return From.X + From.Y + To.X + To.Y;
    }
}

public struct Coordinate
{
    public int X;
    public int Y;
    
    public Coordinate(int x, int y)
    {
        X = x;
        Y = y;
    }
    
    public override bool Equals(object other)
    {
        if (ReferenceEquals(other, null) || (other is Coordinate) == false)
            return false;
        Coordinate otherCoord = (Coordinate)other;
        return this == otherCoord;
    }
    
    public static bool operator==(Coordinate lhs, Coordinate rhs)
    {
        return lhs.X == rhs.X && lhs.Y == rhs.Y;
    }
    
    public static bool operator!=(Coordinate lhs, Coordinate rhs)
    {
        return !(lhs == rhs);
    }
    
    public override int GetHashCode()
    {
        return HashCode.Combine(X, Y);
    }
}

public class Solution {
    public int solution(string dirs) {
        HashSet<Movement> movements = new HashSet<Movement>();
        Coordinate curCoord = new Coordinate(0, 0);
        
        for (int i = 0; i < dirs.Length; i++)
        {
            Coordinate prevCoord = curCoord;
            char ch = dirs[i];
            if      (ch == 'U' && curCoord.Y <  5) curCoord.Y++;
            else if (ch == 'D' && curCoord.Y > -5) curCoord.Y--;
            else if (ch == 'L' && curCoord.X > -5) curCoord.X--;
            else if (ch == 'R' && curCoord.X <  5) curCoord.X++;
            
            if (prevCoord != curCoord)
                movements.Add(new Movement(prevCoord, curCoord));
        }
        int answer = movements.Count;
        return answer;
    }
}