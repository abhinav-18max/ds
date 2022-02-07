#include <stdio.h>
#include<stdlib.h>
void linearsearch (int searchkey, int a[100],int n);
void binarysearch(int searchkey,int a[100],int n);

int main()
{
    int a[100],searchkey,i,j,low,high,n,location,choice,x;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    printf("Enter the elements of the array:");
    for(i=0;i<n;i++)
    {
        scanf("%i",&a[i]);
    }
    printf("Enter the search key:");
    scanf("%d",&searchkey);
    do{
        printf("\n1.LINEAR SEARCH\n2.BINARY SEARCH\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            linearsearch(searchkey,a,n);
            break;
            case 2:
            binarysearch(searchkey,a,n);
            break;
            default:
            exit(0);    
    }
    printf("\nDo you want to continue??(yes=1,no=0)");
    scanf("%d",&x);
    }while(x==1);
}
void linearsearch(int searchkey,int a[100],int n)
{
    int i,location,pos;
    for(i=0;i<n;i++){
        if(searchkey==a[i]){
            int pos=-1;
            location=i;
            pos=1;
            printf("\n%d is located at index %d",searchkey,location);
            printf("\n");
        }
    }
    if(pos==-1){
        printf("Element not found");
    }
}
    
    void binarysearch(int searchkey,int a[100],int n)
    {
        int temp,middle,i,j,first,last;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++){
             if(a[i]>a[j]){
                 temp=a[i];
                 a[i]=a[j];
                 a[j]=temp;
             }   
            }
        }
        printf("Sorted array is:\n");
        for(i=0;i<n;i++)
            printf("%d\n",a[i]);
            first=0;
            last=n-1;
            middle=(first+last)/2;
            i=1;
            while(first<=last){
                if(a[middle]<searchkey)
                first=middle+1;
                else if(a[middle]==searchkey)
                {
                printf("%d found at location %d\n",searchkey,middle);
                break;
                }
                else
                    last = middle-1;
                middle=(first+last)/2;
            }        
                if(first>last)
                    printf("\nNot found\n");
                
        }