#ifndef midterm
#define midterm

int first;

typedef enum{
	SQ,
	PR,
	DF,
	PF,
	AB
}type;
typedef struct {
	type t;

	int boyut;
	int tepe;
	int * dizi;
 	char type[3];
	int nrOfOpr;
	int number;
} s;
struct node {
 s data;
 struct node *next;
};
int sqr;
int x;
typedef s stack;
int pop(stack *);
stack * tanim(){
	stack *s = (stack * ) malloc(sizeof (stack));
	s->dizi = NULL;
	s->boyut = 2;
	s->tepe=0;
	return s;
}
void push(int,stack *);
void push2(char a,stack *s );
void bastir2(stack *s,stack *s1 ,stack *s2 );
void reverseLinked(stack *s);
int square2(int x,int y);
void bastir(stack*);
int abudant(int );
int square(int );
int prime(int );

stack *main_stack = tanim();
stack *helper_stack = tanim();
stack *keep_type = tanim();
stack *nrOfop =tanim();
stack *allNum=tanim();
#endif
