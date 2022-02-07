#include<stdio.h>
struct tuple{
int row,col,value;
}A[20],B[20],at[20],bt[20];
void tuple(struct tuple A[],int a[][20],int m,int n) { int i,j,k=0,l=1;
A[0].row=m; A[0].col=n; for(i=0;i<m;i++) for(j=0;j<n;j++) {
if(a[i][j]!=0)
{
A[l].row=i; A[l].col=j; A[l].value=a[i][j]; l++;

k++;
}}
A[0].value=k;
for(i=0;i<=A[0].value;i++)
{
printf("%d %d %d\n",A[i].row,A[i].col,A[i].value); }}
void transpose(struct tuple a[],struct tuple at[])
{
int i,j,t=1;
at[0].row=a[0].col;
at[0].col=a[0].row;
at[0].value=a[0].value;
for(i=0;i<a[0].col;i++)
{
for(j=1;j<=a[0].value;j++)
{
if(a[j].col==i)
{
at[t].col=a[j].row;
at[t].row=a[j].col;
at[t].value=a[j].value;
t++;
}}}
for(i=0;i<=at[0].value;i++)
{
printf("%d %d %d\n",at[i].row,at[i].col,at[i].value); }}
void add(struct tuple a[],struct tuple b[])
{
int i=1,j=1,res[20][20];
for(i=0;i<20;i++)
{
for(j=0;j<20;j++)
{

res[i][j]=0;
}
}
i=1,j=1; if(a[0].col==b[0].col&&a[0].row==b[0].row) {
while(i<=a[0].value&&j<=b[0].value) {
if(a[i].row==b[j].row)
{
if(a[i].col==b[j].col)
{ res[a[i].row][a[i].col]=a[i].value+b[j].value; i++;j++;
}
else if(a[i].col<b[j].col)
{
res[a[i].row][a[i].col]=a[i].value;
i++;
}
else if(a[i].col>b[j].col)
{
res[b[j].row][b[j].col]=b[j].value;
j++;
}
}
else if(a[i].row<b[j].row)
{
res[a[i].row][a[i].col]=a[i].value;
i++;
}
else
{
res[b[j].row][b[j].col]=b[j].value;
j++;

}}
while(i<=a[0].value)
{
res[a[i].row][a[i].col]=a[i].value;
i++;
}
while(j<=b[0].value)
{
res[b[j].row][b[j].col]=b[j].value;
j++;
}
for(i=0;i<b[0].row;i++)
{
for(j=0;j<b[0].col;j++)
{
printf("%d ",res[i][j]);
}
printf("\n");
}
}
else
{
printf("\nADDITION NOT DEFINED");
}}
void main()
{
int i,j,n,m,p,q,a[20][20],b[20][20];
printf("Enter the number of rows and columns of the first matrix:\n"); scanf("%d %d",&m,&n);
printf("Enter matrix elements: \n");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);
printf("Enter the number of rows and columns of the second matrix:\n"); scanf("%d %d",&p,&q);

printf("Enter matrix elements: \n");
for(i=0;i<p;i++)
for(j=0;j<q;j++)
scanf("%d",&b[i][j]);
printf("\nTUPLE FORM OF FIRST MATRIX: \n"); tuple(A,a,m,n);
printf("\nTUPLE FORM OF SECOND MATRIX: \n"); tuple(B,b,p,q);
printf("\nTRANSPOSE OF FIRST MATRIX: \n"); transpose(A,at);
printf("\nTRANSPOSE OF SECOND MATRIX: \n"); transpose(B,bt);
printf("\nSUM: \n");
add(A,B);
}