#ifndef denemeler
#define denemeler
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
stack * tanim();
int pop(stack *);

void push(int,stack *);
void bastir(stack*);
int abudant(int );
int square(int );
int prime(int );
#endif
