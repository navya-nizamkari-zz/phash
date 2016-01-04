#include <iostream>
#include<stdlib.h>
#include<stdio.h>
#include <pHash.h>

using namespace std;

int main()
{
    
    int i;char str[7];int s;
   char str2[5]=".jpg";
    char str3[7];
    ulong64 myhash[73]={0};
    ulong64 myhash2=0;
    ph_dct_imagehash("70.jpg",myhash2);
    for(i=0;i<38;i++)
    {
      sprintf(str,"%d",i+62);
      strcat(str,str2);
      ph_dct_imagehash(str,myhash[i]);
      s=ph_hamming_distance( myhash2,myhash[i]);
     cout<<myhash[i]<<endl;
     /*if(s<10)
    { printf("belongs to this set\n");
     exit(0);
     }*/
    }
   //  cout<<myhash2<<endl;
   // ph_dct_imagehash("3.jpg", myhash);
   
   
    //cout<<myhash<<endl;
}
