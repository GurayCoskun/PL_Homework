#include <stdio.h>
#include <stdlib.h>
#include "midterm.cpp"
int main(){
s *y;
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
