//Big Endian - MSB is stored at least address location.
//Alternaice solution is to create a union with int and char[4];int i = 0xABCDEF12;union charmember[0]==0XAB?big endian:little
#include<stdio.h>
int main()
{
  int i=0xABCD1234;
  int k=1;
  int j = *(char*)&k==1?(((i&0xFF000000)>>24)|((i&0x00FF0000)>>8)|((i&0x0000FF00)<<8)|((i&0x000000FF)<<24)):i;
  printf("%X",j);
  return 0;
}
