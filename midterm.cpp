#include <stdio.h>
#include <stdlib.h>
#include "midterm.h"

int pop(stack *s){
	if(s->tepe <= 0||s->dizi==NULL){
		printf("dizi boþ");
		return -1;
	}
	if(s->tepe<=s->boyut/4&&s->boyut>2){
		int *dizi2 = (int*)malloc(sizeof(int)*s->boyut/2);
                for(int i = 0;i<s->tepe ; i++)
                        dizi2[i] = s->dizi[i];
                free(s->dizi);
                s->dizi = dizi2;
                s->boyut /= 2;

	}
	return s->dizi[--s->tepe];
}
void push(int a,stack *s ){
	if(s->dizi == NULL){
		s->dizi = (int*)malloc(sizeof(int)*2);
	}
	if(s->tepe>=s->boyut-1){
		int *dizi2 = (int*)malloc(sizeof(int)*s->boyut*2);
		for(int i = 0;i<s->boyut ; i++)
			dizi2[i] = s->dizi[i];
		int * temp = s->dizi;
		s->dizi = dizi2;
		free(temp);
		s->boyut *= 2;
	}
	s->dizi[s->tepe++] = a;
}
void push2(char a,stack *s ){
	if(s->dizi == NULL){
		s->dizi = (int*)malloc(sizeof(int)*2);
	}
	if(s->tepe>=s->boyut-1){
		int *dizi2 = (int*)malloc(sizeof(int)*s->boyut*2);
		for(int i = 0;i<s->boyut ; i++)
			dizi2[i] = s->dizi[i];
		int * temp = s->dizi;
		s->dizi = dizi2;
		free(temp);
		s->boyut *= 2;
	}
	s->dizi[s->tepe++] = a;
}
void bastir(stack *s){
	printf("TOP -->");
	for(int i = 0;i<s->tepe;i++){
		printf("%d ",s->dizi[i]);
		printf("-->");

	}
	printf("BOTTOM");
}
void bastir2(stack *s,stack *s1 ,stack *s2 ){
	printf("\n");
	printf("    ***TOP***");
	printf("\n");

	for(int i = 0;i<s->tepe;i++){
		printf("%d ",s->dizi[i]);
		printf("  ,  ");
		printf("%d",s1->dizi[i]);
		printf("  ,  ");

		if(s2->dizi[i]==0){
			printf("SQ");
		}
		else if(s2->dizi[i]==1){
			printf("PR");
		}
		else if(s2->dizi[i]==2){
			printf("DF");
		}
		else if(s2->dizi[i]==3){
			printf("PF");
		}
		else if(s2->dizi[i]==4){
			printf("AB");
		}
		printf("\n");

	}
	printf("    ***BOTTOM***");
}	

void reverseLinked(stack *s)
{
   	stack *main_stack2 = tanim();
   	while(s->tepe!= 0)
		{	
			push(pop(s),main_stack2);
		}
	for(int i = 0;i<main_stack2->tepe;i++){
		push(main_stack2->dizi[i],s);
	}
}
int prime(int x){
	int square_of_prime;
	bool isPrime = true;
	for(int i = 2; i <= x / 2; ++i)
  {
      if(x % i == 0)
      {
          isPrime = false;
          break;
      }
  }
	if (isPrime){

		return 1;
		}
	else{
		return 0;
	}
 
}
int abudant(int x){
	int sum=0;	
	
	for(int i = 1; i<x;i++){
    		int bolum=x % i;
    		if(bolum==0){
    			sum=sum+i;
    		}
    		else if( i > x/2){
    			break;
			}
    	}
    return sum;

}
int square(int x){
	int first=0;

	for(int i=0;i<x;i++){
		if (i*i==x){
			x=square(i);
						
		}	
		
	}
	return x;
}
int square2(int x,int y){
	
	for(int i=0;i<x;i++){
		if (i*i==x){
			y=y+1;
			return square2(i,y);
						
		}	
		
	}
	return y;
}

