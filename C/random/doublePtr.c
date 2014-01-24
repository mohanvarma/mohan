#include<stdio.h>
#include<stdlib.h>
void allocate(void **ptr)
{
  *ptr = malloc(10);
}
int main()
{
  int *ptr = NULL;
  allocate((void**)&ptr);
  if(ptr)
  {
    printf("!NULL");
    free(ptr);
  }
  return 0;
}
