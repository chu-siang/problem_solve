#include <stdio.h>
#include "lib1044.h"
int main(void)
{
  long long g,n,i,j;
  n = Initialize();
  g = Guess(n);
  i = 1,j = n;
  while(i <= j){
    g = Guess((i+j)/2);
    if(g)
        j = (i + j)/2-1;
    else
        i = (i + j)/2+1;
  }
  Report(i);
  return 0;
}