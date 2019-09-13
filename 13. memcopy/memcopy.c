#include <stdio.h>
#include <stdlib.h>
#include<assert.h>

void* My_memcpy(void* dest, const void* src, size_t num)
{
  assert(dest);
  assert(src);
  void* p = dest;
  while (num--)
  {
    *(char*)dest = *(char*)src;
    dest = (char*)dest + 1;
    src = (char*)src + 1;
  }
  return p;
}

int main()
{
  char dest[56];
  char src[] = "abcb  xxxx zzzzzzzzzzzzy";
  printf("%s\n", My_memcpy(dest, src, strlen(src) + 1));
  system("pause");
  return 0;
}
