#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define doublenum(a,b)  ((a%48)*10 + b%48)

int findNumWays(char *intString, int k) {
  int result = 0;
  if (k == 0)
      return 1;
  int pos = strlen(intString) - k;
  if(intString[pos] == '0')
      return 0;
  result  = findNumWays(intString, k-1);
  //space overhead of conversion
  /* char ptr[2]={0};
   ptr = intString+pos;
   memcpy(ptr,intString+pos,2);
  if (k >=2 && atoi(ptr) <= 26) */
  if (k >=2 && doublenum(intString[pos],intString[pos+1]) <=26)
      result+=findNumWays(intString,k-2);
  return result;
}

/*optmised solution using Dynamic approach*/
int findNumWays2(char *intString, int k, int *nresult) {
  int result = 0;
  if (k == 0)
      return 1;
  int pos = strlen(intString) - k;
  if(intString[pos] == '0')
      return 0;
  if (nresult[k] != 0)
      return nresult[k];
  result  = findNumWays2(intString, k-1, nresult);
  if (k >=2 && doublenum(intString[pos],intString[pos+1]) <=26)
      result+=findNumWays2(intString,k-2, nresult);
  nresult[k] = result;
  return result;
}
int main(int argc, char const *argv[]) {
  char intString[] = "123456789";
  int len = strlen(intString);
  int numWays = findNumWays(intString,len);
  printf("Number of ways is : %d\n", numWays);
  int nresult[20] = {0};
  int numWays2 = findNumWays2(intString,len, nresult);
  printf("Number of ways2 is : %d\n", numWays2);

  return 0;
}
