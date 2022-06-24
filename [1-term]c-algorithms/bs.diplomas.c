#include <stdio.h>
int main ()
{
  unsigned long long w, h, n;
  scanf ("%lld%lld%lld", &w, &h, &n);
  unsigned long long l = 0, r = h * n, mid;
  while (l + 1 < r)
    {
      mid = (l + r) / 2;
      if ((mid / w) * (mid / h) >= n)
	r = mid;
      else
	l = mid;
    }
  printf ("%lld", r);
  return 0;
}
