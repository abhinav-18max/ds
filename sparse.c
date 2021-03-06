#include <stdio.h>
#include <stdlib.h>
int tup1[50][50],tup2[50][50],trans1[50][50],trans2[50][50],s1,s2,sum[50][50];
int read_matrix(int a[50][50],int r, int c){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			scanf("%d",&a[i][j]);
			}
		}
	}
	int disply_matrix(int a[50][50], int r, int c){
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				printf("%d\t",a[i][j]);
				}
			printf("\n");
			}
		}
	int tupleform(int a[50][50], int r, int c,int tup[50][50]){
		tup[0][0]=r;
		tup[0][1]=c;
		int count=1;
		for(int i=0;i<r;i++){
			for(int j=0;j<c;j++){
				if(a[i][j]!=0){
					tup[count][0]=i;
					tup[count][1]=j;
					tup[count][2]=a[i][j];
					count=count+1;
					}
				}
			}
			tup[0][2]=count-1;
			disply_matrix(tup, count, 3);
			}
			int transpose(int trans[50][50],int a[50][50],int s, tup[50][50]){
				trans[0][0]=tup[0][1];
				trans[0][1]=tup[0][0];
				trans[0][2]=tup[0][2];
				int k=1;
				int m= tup[0][1];
				int n=tup[0][2];
				for(int i=0;i<m;i++){
					for(int j=0;j<=n;j++){
						if(tup[j][1]==i){
							trans[k][0]=tup[j][1];
							trans[k][1]=tup[j][0];
							trans[k][2]=tup[j][2];
							k=k+1;
							}
						}
					}
					s = k;
					disply_matrix(trans, k,3);
				}
			int normal_form(int trans[50][50],int r,int c){
				int n[50][50];
				int row=trans[0][0];
				int column=trans[0][1];
			    for(int i=0;i<row;i++){
			    	for(int j=0;j<column;j++){
			    		n[i][j]=0;
			    		}
			    	}
			    	r=trans[0][2]+1;
			    	for(int i=0;i<r;i++){
			    		int ro=trans[i][0];
			    		int co=trans[i][1];
			    		n[ro][co] = trans[i][2];
			    		}
			    		disply_matrix(n,row,column);
			    	}
			    int sum_matrix(int t1[50][50], int t2[50][50]){
			    	int k=1;
			    	int r1=t1[0][2];
			    	int r2=t2[0][2];
			    	int c=t1[0][1];
			    	int r=t1[0][0];
			    	sum[0][0]=t1[0][0];
			    	sum[0][1]=t1[0][1];
			    	int start1=1;
			    	int start2=1;
			    	for(int i=0;i<r;i++){
			    		for(int j=0;j<c;j++){
			    			int e1=t1[start1][0];
			    			int e2=t1[start1][1];
			    			int h1=t2[start2][0];
			    			int h2=t2[start2][1];
			    			if(e1==i && e2==j && h1==i && h2==j){
			    				int result = t1[start1][2] + t2[start2][2];
			    				if(result != 0){
			    					sum[k][0]=i;
			    					sum[k][1]=j;
			    					sum[k][2]=result;
			    					k=k+1;
			    				}
			    				start1++;
			    				start2++;
			    			}
			    		else if(h1==i && h2==j){
			    			sum[k][0]=i;
			    			sum[k][1]=j;
			    			sum[k][2]=t2[start2][2];
			    			start2++;
			    			k=k+1;
			    		}
			    	else if(e1==i && e2==j){
			    		sum[k][0]=i;
			    		sum[k][1]=j;
			    		sum[k][2]=t1[start1][2];
			    		start1++;
			    		k=k+1;
			    	}
			    }
			 }
			 sum[0][2]=k-1;
			 disply_matrix(sum,k,3);
			}
		int main(){
			int row1, column1, row2, column2, arr1[50][50],arr2[50][50];
			printf("enter the number of rows and columns in first matrix:");
			scanf("%d%d",&row1,&column1);
			printf("enter the elements for first matrix:");
			read_matrix(arr1,row1,column1);
			printf("enter the number of rows and columns in second matrix:");
			scanf("%d%d",&row2,&column2);
			printf("enter the elements for second matrix:");
			read_matrix(arr2,row2,column2);
			printf("\n first matrix:\n");
			disply_matrix(arr1, row1, column1);
			printf("\n second matrix:\n");
			disply_matrix(arr2, row2, column2);
			int choice;
			while(1){
				printf("options are: \n 1.Tuple form\n 2.Transpose in tuple form \n 3.Transpose in normal form \n 4.sum \n 5.Exit \n ");
				printf("\n enter the choice");
				scanf("%d",&choice);
				switch(choice){
					case 1: printf("\n Tuple form of first matrix is : \n");
					tupleform(arr1,row1,column1,tup1);
					  printf("\n Tuple form of second matrix is :\n"); tupleform(arr2, row2, column2, tup2);
					  break;
					case 2: printf("Transpose of first matrix in tuple form:\n");
					 transpose(trans1,arr1,s1,tup1);
					 printf("Transpose of second matrix in tuple form:\n");  transpose(trans2,arr2,s2,tup2);
					 break;
				   case 3: printf("Transposed matrix1 in normalform:\n");
				   normal_form(trans1,s1,3);
				    printf("Transposed matrix2 in normalforn:\n");
				   normal_form(trans2,s2,3);
				   break;
				   case 4:printf("\n sum\n");
					      int r1=tup1[0][0];
				          int c1=tup1[0][1];
				          int r2=tup2[0][0];
				          int c2=tup2[0][1];
				         if(r1==r2 && c1==c2){
				         	printf("sum in tuple form\n");
				         	sum_matrix(tup1,tup2);
				         	printf("sum in normal form\n");
				         	normal_form(sum, sum[0][0], sum[0][1]);
				         	}
				         else{
				         	printf("\n cannot be added!\n\t");
				         	}
				         	break;
				         case 5: printf("\n Exited\n");
				         	exit(0);
				         	break;
				         }
				        }
				       }