#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <pHash.h>
#include<time.h>
#define NUM_THREADS 24
clock_t begin, end;
double time_spent;
ulong64 myhash[1200]={0};
  /*takes up the hash values*/ 
   using namespace std;
int signo=0;

struct arguement{
		int j;
		int k;
		};


void *dct_calculator(void *arg)
{
int i,k,j;
struct arguement *arg2;
arg2=(struct arguement *)arg;
j=arg2->j;
k=arg2->k;
ulong64 myhash2=0;
    
ph_dct_imagehash("3005.jpg",myhash2);

char str[7];
int s;
   
char str2[5]=".jpg";
	for(i=1;i<51;i++)
    
   {
      int l=(k*1000)+i+(j*50);
	sprintf(str,"%d",l);
      
	strcat(str,str2);
      
	ph_dct_imagehash(str,myhash[i+(j*50)]);
      
	s=ph_hamming_distance( myhash2,myhash[i+(j*50)]);
     
	//cout<<myhash[i+j]<<endl;

	if(s<10)
    

	{ printf("the image may be from video %d\n", k);
     signo=1;
     end = clock();
time_spent = (double)(end - begin)/CLOCKS_PER_SEC;
printf("%f",time_spent);
     exit(0);
	break;
        }
     }
return 0;}
     

int main()
{
clock_t begin, end;
double time_spent;

 //begin = clock(); 
struct arguement *arg;
int rc,k=1;
pthread_t threads[NUM_THREADS];
long j; 
arg= (struct arguement*)malloc(sizeof(struct arguement));

for(k=1;k<5;k++)
 {
for(j=0;j<6;j++)
    
{
       arg->k=k;
       arg->j=j;


	{
	
	rc=pthread_create(&threads[(k-1)*6+j],NULL,dct_calculator, (void *)arg);
	
	if(rc)
	{printf("error in creating thread\n");}
	pthread_join(threads[(k-1)*6+j],NULL);
	}
}}
printf("not found");
if(signo==1){pthread_exit(NULL);}


  
//  cout<<myhash2<<endl;
   
// ph_dct_imagehash("3.jpg", myhash);
   
   
    
//cout<<myhash<<endl;
}




