// string is balanced or not

#include <stdio.h>
#include <string.h>

int validBraces(char *s)
{
    char a[100] = {'\0'};
    int j = 0, i = 0;
    int ret  = 0;
    
    if (strlen(s) <= 1)
    {
        return 0;    
    }
    
    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            a[j++] = s[i];
        }
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
        {
            if ((j > 0) && ((s[i] == ')' && a[j-1] == '(') || (s[i] == '}' && a[j-1] == '{') || 
                 (s[i] == ']' && a[j-1] == '[')))
            {
                a[--j] = '\0';
            }
            else
            {
                return 0;
            }
        }
    }
    

    if (strlen(a) == 0)
    {
        return 1;
    }
    
    return 0;
}


int main()
{
    char str[100] = {'(', '[', ']',')' };
    int ret = -1;
    
    ret = validBraces(str);
    if (ret == 1)
    {
       printf("String with proper braces\n"); 
    }
    else if (ret == 0)
    {
        printf("String with mismatched braces\n" );
    }
    
    return 0;
}