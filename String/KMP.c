// Refrence
// http://www-igm.univ-mlv.fr/~lecroq/string/node8.html
#include <stdio.h>
#include <string.h>

void get_nextval(char *ss, int ss_length, int *nextval)
{
    int i, j;
    i = 0;
    j = -1;
    nextval[0] = -1;
    while (i<ss_length - 1)
    {
        if (j==-1 || ss[i]==ss[j])
        {
            i++;
            j++;

            if (ss[i] == ss[j])
            {
                nextval[i] = nextval[j];  // 若两字母相同，j 值往 nextval[j] 回溯
            }
            else
            {
                nextval[i] = j;  // 若两字母不同，j 值往 j 回溯
            }
        }
        else {
            j = nextval[j];
        }
    }
}

int Index_KMP(char *S, int S_length, char *ss, int ss_length, int pos)
{
    int nextval[200];
    get_nextval(ss, ss_length, nextval);

    int i = pos, j = 0;
    while (i < S_length && j < ss_length)
    {
        if (j == -1 || S[i] == ss[j])
        {
            i++;
            j++;
        }
        else
        {
            j = nextval[j];
        }
    }

    if (j == ss_length)
    {
        return i - ss_length;
    }
    else
    {
        return 555;
    }
}

int main()
{
    char S[10], ss[10];
    strcpy(S, "aaadead");
    strcpy(ss, "ae");

    int S_length, ss_length, pos = 3;
    S_length = strlen(S);
    ss_length = strlen(ss);

    pos = Index_KMP(S, S_length, ss, ss_length, pos);
    printf("%d", pos);
}
