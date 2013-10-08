#include<stdio.h>
// bit_fields1.cpp
// compile with: /LD
struct Date {
  unsigned short nWeekDay  : 3;    // 0..7   (3 bits)
  unsigned short nMonthDay : 6;    // 0..31  (6 bits)
  unsigned short nMonth    : 5;    // 0..12  (5 bits)
  unsigned short nYear     : 8;    // 0..100 (8 bits)
};

int main()
{
  /*

    Day  MDay    M   pad   Year    pad  

    ===|======|=====|==||========|========
    0                                    31

    Note that nYear is 8 bits long and would overflow the word boundary of the declared type, unsigned short. Therefore, it is begun at the beginning of a new unsigned short. It is not necessary that all bit fields fit in one object of the underlying type; new units of storage are allocated, according to the number of bits requested in the declaration.

    unsigned           : 0;    // Force alignment to next boundary.
    If the declaration of a structure includes an unnamed field of length 0, as shown in the above example,
    http://msdn.microsoft.com/en-us/library/ewwyfdbe.aspx
  */
  printf("%d\n", sizeof(unsigned short int));
  printf("%d\n", sizeof(struct Date));
  return 0;
}
