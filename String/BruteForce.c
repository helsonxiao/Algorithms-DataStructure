#include <stdio.h>

int Find(char *s, char *p)
{
    int j = 0, i = 0, k = 0;
    int r = -1;
    while (r == -1 && s[i] != '\0')
    {
        while (p[j] == s[i] && p[j] != '\0')
        {
            i++;
            j++;
        }
        if (p[j] == '\0')
        {
            r = k;
        }
        else
        {
            j = 0;
            k++;
            i = k;
        }
    }
    return r;
}

int main()
{
    char s[20];
    char p[5];
    printf("Please input the source string:");
    scanf("%s", s);
    printf("Please input the goal string:");
    scanf("%s", p);
    printf("The result of finding is:%d\n", Find(s, p));
}

// int Index(String S, String T, int pos)
// {
//     int i = pos;
//     int j = 1;
//     while (i<= S[0] && j <= T[0])
//     {
//         if (S[i] == T[j])
//         {
//             i++;
//             j++;
//         }
//         else
//         {
//             i = i - j + 2;
//             j = 1;
//         }
//     }

//     if (j > T[0])
//     {
//         return i - T[0];
//     }
//     else
//     {
//         return 0;
//     }
// }
