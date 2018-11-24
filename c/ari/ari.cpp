#include <algorithm>
#include <cstdio>
using namespace std;
// const int MAX_N = 100;

int main()
{
  int l = 10;
  int n = 3;
  int a[] = {2, 6, 7};
  int max = 0;
  int min = 0;
  int min_distance = 0;
  for (int i = 0; i < n; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
    if (l - a[i] > max)
    {
      max = l - a[i];
    }

    if (a[i] < l - a[i])
    {
      min_distance = a[i];
    }
    else
    {
      min_distance = l - a[i];
    }
    if (min_distance > min)
    {
      min = min_distance;
    }
  }

  printf("min is %d, max is %d\n", min, max);
}
