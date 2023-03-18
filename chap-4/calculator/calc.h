#define NUMBER '0'
#define SET_VAR '8'
#define GET_VAR '9'
#define MAXVAL 100

// Getop
int getop(char []);

// Getch
int getch(void);
void ungetch(int);
void ungets(char []);

// Stack
void push(double);
double pop(void);
double top();
void duplicate();
void swap();
void clear();
