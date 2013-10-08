#include<stdio.h>


int main()

{
  struct one
  {
    char a;
    int b;
    short int c;
    double d;
  };

  struct two
  {
    double a;
    char b;
    short int c;
    int d;
  };

  struct __attribute__((__packed__)) three 
  {
    char a;
    int b;
    short int c;
    double d;
  };

  struct __attribute__((__packed__)) four
  {
    double a;
    char b;
    short int c;
    int d;
  };

  printf("%d %d\n", sizeof(struct one), sizeof(struct two));
  printf("%d %d\n", sizeof(struct three), sizeof(struct four));
  return 0;
}


