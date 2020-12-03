#include <string.h>
#include <cstdlib>
#include <stdio.h>
#include <ctype.h>

const char *rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char *msg[] = {"不是回文字符串", "是回文字符串", "是镜像字符串", "是回文镜像串"};

char r(char ch)
{
    if (isalpha(ch))
        return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main()
{
    char s[20];
    while (scanf("%s", s) == 1)
    {
        int p = 1, m = 1;
        int len = strlen(s);
        for (int i = 0; i < (len + 1) / 2; i++)
        {
            if (s[i] != s[len - 1 - i])
                p = 0;
            if (r(s[i]) != s[len - 1 - i])
                m = 0;
        }
        printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
    }
    system("pause");
    return 0;
}