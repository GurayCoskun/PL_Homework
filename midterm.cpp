#include <stdio.h>
#include <stdlib.h>
#include "midterm.h"
stack * tanim(){
	stack *s = (stack * ) malloc(sizeof (stack));
	s->dizi = NULL;
	s->boyut = 2;
	s->tepe=0;
	return s;
}
int pop(stack *s){
	if(s->tepe <= 0||s->dizi==NULL){
		printf("dizi boş");
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
void bastir(stack *s){
	for(int i = 0;i<s->tepe;i++){
		printf("%d ",s->dizi[i]);
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
	for(int i=0;i<x;i++){
		if (i*i==x){
			num=i;
			return square(i);			
		}	
		
	}
	
    return num;
}
int main(){
	stack *main_stack = tanim();
	stack *helper_stack = tanim();	
	
	while ((x = getchar()) != EOF){

		scanf("%d",&x);
		
		printf("asdasdasd \n");
	
			
		}
/*		
		if(prime(x)==1){
			push(x*x,main_stack);
			printf("prime");	
		}
		else if(square(x)<x && square(x) !=0){
			
			int num=square(x);
			printf("sqaure");

			push(num,main_stack);
		}
		else{
			if(abudant(x)>x){
				int num=abudant(x);
				int abudance=num-x;
				printf("abudant");

		    	push(abudance,helper_stack);
				push(x-abudance,main_stack);
			}
			else if(abudant(x)<x){
			
				push(x,helper_stack);
			}
			else{
				printf("perfect");
				push(x,main_stack);

			}
		}*/
	//	bastir(main_stack);
		
	
		

	
}
