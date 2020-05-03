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
	printf("TOP");
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
	printf("BOTTOM");
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
int main(){
	s *y;
	stack *main_stack = tanim();
	stack *helper_stack = tanim();
	stack *keep_type = tanim();
	stack *nrOfop =tanim();
	stack *allNum=tanim();
	y=(s *) malloc(sizeof(s));
	
	
	//while (x=getchar() != EOF){
	for (int i = 1; i>0;i++){	
		
		printf("\n Give number= \n");
		int result=scanf("%d",&y->number);
		
		if (result!=EOF){
			push(y->number,allNum);
				if(prime(y->number)==1){
					push(y->number*y->number,main_stack);
					push(NULL,helper_stack);
					y->t=PR;
					y->nrOfOpr=0;
					push(0,nrOfop);
					push2(PR,keep_type);

			}
			else if(square(y->number)<y->number && square(y->number) !=0){		
					
				push(square(y->number),main_stack);
				push(NULL,helper_stack);
				push(square2(y->number,0),nrOfop);
				push2(SQ,keep_type);
				y->t=SQ;
				
			}
			else{
				if(abudant(y->number)>y->number){
					y->t=AB;
					y->nrOfOpr=0;

					int number=abudant(y->number);
					int abudance=number-y->number;
			    	push(abudance,helper_stack);
					push(y->number-abudance,main_stack);
					push(0,nrOfop);
					push2(AB,keep_type);
				}
				else if(abudant(y->number)<y->number){
					y->t=DF;
					y->nrOfOpr=0;
					push(y->number,helper_stack);
					push(NULL,main_stack);
					push(0,nrOfop);
					push2(DF,keep_type);
				}
				else{

					y->t=PF;
					y->nrOfOpr=0;
					push(NULL,helper_stack);
					push(y->number,main_stack);
					push(0,nrOfop);
					push2(PF,keep_type);

				}
		}
			}
		else{
			reverseLinked(main_stack);
			bastir(main_stack);

			printf("\n");

			reverseLinked(helper_stack);
			printf("\n");
			bastir(helper_stack);
			reverseLinked(allNum);
			reverseLinked(nrOfop);
			reverseLinked(keep_type);
			bastir2(allNum,nrOfop,keep_type);
			break;
			}
			
		
		
		
		
		
	
	
		
	
		
	}
	
	

	
}
