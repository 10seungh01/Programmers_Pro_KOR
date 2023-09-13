#include <iostream>
#include <vector>

int pow(long n1, int n2)                     // pow function
{
    int res = 1;
    for (int i = 0; i < n2; i++)
    {
        res = res * n1;
    }
    return res;
}

long calc(long r, char C)                              // calc function
{
    std::vector<long> v(r, NULL);                     // room for 'y' value by 'x' value
    switch (C) {
    case 'B':                                       // case for bigger circle
        for (int i = 1; i < r; i++)
        {
            for (int j = r; j > 0; j--)
            {
                if (pow(i, 2) + pow(j, 2) <= pow(r, 2))     // include dot lying on circle line.
                {
                    v[i] = (long)j;
                    break;
                }

            }
        };
        break;
    case 'S':                                       // case for smaller circle
        for (int i = 1; i < r; i++)
        {
            for (int j = r; j > 0; j--)
            {
                if (pow(i, 2) + pow(j, 2) < pow(r, 2))      // exclude dot lying on circle line.
                {
                    v[i] = (long)j;
                    break;
                }

            }
        };
        break;
    }
    // End of Calculation.
    long res = 0;
    for (auto j : v)
    {
        res = res + j;             // Sum of dots on 1/4 face. 
    }
    return res;
}

long long solution(int r1, int r2) {
    long long answer = 0;

    long answer2 = (calc((long)r2, 'B')) * 4;          // All dots of bigger circle
    long answer1 = (calc((long)r1, 'S')) * 4;          // All dots of smaller circle
    answer = (answer2 - answer1) + (r2 - r1 + 1) * 4;                  // All dots in the middle of circles
    //std::cout << answer << std::endl;
    return answer;
}

int main()
{
    long r2 = 3;
    long r1 = 2;
    long res = solution(r1, r2);
}