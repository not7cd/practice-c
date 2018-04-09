#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
      char word[80];
      char inv[80];
      int i,n;
      printf("This program prints words backward.\n");
      printf("Please write a word: ");
      scanf("%s",word);
      n = strlen(word);
      for ( i=0; i<n; i++ ) {
        inv[i] = word[n-1-i];
      }
      inv[n] = '\0';
      printf("Your backward: %s\n",inv);
      return 0;
}
