#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
      char str[80];
      scanf("%s",str);
      for (int i = strlen(str) - 1; i >= 0; i--)
        switch(str[i]) {
            case 'C': case 'c':
                str[i] = 'X';
                break;
            case 'D': case 'd':
                str[i] = 'Y';
                break;
        }
      printf("%s\n",str);
      return 0;
}