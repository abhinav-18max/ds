#include <stdio.h> #include <string.h> #include <ctype.h> #include<stdlib.h> int order(char );
void inftopost(); void evalpost();
void pushchar(char ); char popchar();
void pushint(int); int popint();
char stack_char[20]; int stack_int[20];
int top = -1;
void main()
{
int opt;
printf("\nChoose your option:\n\n"); printf("1.Convert infix expression to postfix.\n"); printf("2.Evaluate a postfix expression.\n\n"); printf("Choose option: ");
scanf("%d",&opt); if (opt == 1) inftopost();
else if (opt == 2) evalpost();
else
exit(1);
}
int order(char x)
{
if(x=='^')
return 3;
else if(x=='*' || x=='/') return 2;
else if(x=='+' || x=='-') return 1;
return 0;
}

void inftopost() // infix to postfix function {
int i,k=0;
char exp[20],post[20],value,len; printf("\nEnter the expression: ");
scanf(" %[^\n]",exp); len = strlen(exp); exp[len] = ')'; exp[len+1] = '\0'; pushchar('(');
for (i=0; exp[i]!='\0'; i++) {
if (isalnum(exp[i]))
{
post[k]=exp[i]; k++; post[k]='\0';
}
else if( exp[i]=='(') pushchar(exp[i]); else if(exp[i] == ')') {
while( ( value = popchar() ) != '(' ) {
post[k]=value;
k++;
post[k]='\0'; }}
else
{
while( order(stack_char[top]) >= order(exp[i]) ) {
post[k]=popchar();
k++;
post[k]='\0';
} pushchar(exp[i]); }}
printf("\nThe postfix expresson is: "); for(i=0; post[i]!='\0'; i++)
printf("%c ",post[i]);

printf("\n");
}
void evalpost() // evaluation of postfix expression
{
char exp[20];
int i,ans,val=0,val1,val2;
printf("\nEnter the expression to be evaluated: ");
scanf(" %[^\n]",exp);
for (i=0; exp[i]!='\0'; i++)
{
if ( isalnum(exp[i]) )
val = val*10 + (exp[i]-48);
else if (exp[i]=='+'|| exp[i]=='-'||exp[i]=='*'||exp[i]=='/')
{
val1 = popint();
val2 = popint();
switch(exp[i])
{
case '+':ans = val2 + val1;
break;
case '-':ans = val2 - val1;
break;
case '*':ans = val2 * val1;
break;
case '/':ans = val2 / val1;
break;
}
pushint(ans);
i++;
}
else if( exp[i] == ' ' )
{
pushint(val);
val=0;
}}
printf("\nThe answer on evaluation of postfix expression:%d\n",ans); }
void pushchar(char ch)
{
top++;
stack_char[top] = ch;

}
char popchar()
{
char value;
value = stack_char[top]; top--;
return value;
}
void pushint(int num)
{
top++;
stack_int[top] = num;
}
int popint()
{
int value;
value = stack_int[top]; top--;
return value;
}