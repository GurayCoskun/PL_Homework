#ifndef midterm
#define midterm
struct s {
	int boyut;
	int tepe;
	int * dizi;
};
int num;
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
