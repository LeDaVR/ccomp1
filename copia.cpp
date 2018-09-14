#include <iostream>
using namespace std;
#define LIMIT 2000000
int i[LIMIT];
int main()
 {
   long long int n = 0, k, sum = 0;
  for(n = 0; n < LIMIT; n++)
    i[n] = 1;
  i[0] = 0;
  i[1] = 0;

  long long int p = 2;

  while (p*p < LIMIT)
  {
    k = 2;
    while (p*k <LIMIT)
    {
        i[p*k] = 0;
        k++;
    }
    p++;
  }

  for(n = 0; n < LIMIT; n++)
    if (i[n] == 1)
    {
        sum += n;
    }
  cout<<sum;

  return 0;
}
