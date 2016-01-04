#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <pHash.h>
using namespace std;

int main()
{
  ulong64* hash;
  int x;
  hash=ph_dct_videohash("rec1.mp4",x);
  printf("%llx",hash[0]);
  
   }
