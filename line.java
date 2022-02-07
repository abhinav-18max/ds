package lab;

import java.io.*;
import java.util.*;
public class line
{
public static void main(String[] args) throws IOException {
int j=1;
char ch;
Scanner sc=new Scanner(System.in);
System.out.println("Enter File name:");
String str=sc.next();
FileInputStream f=new FileInputStream(str);
System.out.println("Content of the file is : ");
int n=f.available();
System.out.print(j+":");
for(int i=0;i<n;i++)
{   ch=(char)f.read();
   System.out.print(ch);
   if(ch=='\n')
   {
     j++;
     System.out.print( j + ":");
   }
}
f.close();
}
}
