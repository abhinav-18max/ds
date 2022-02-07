package lab;

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */

class sumtoken
{
            public static void main(String args[])
            {
                        Scanner scr=new Scanner(System.in);
System.out.println("\nEnter sequence of integers with space b/w them and press enter : ");
                        String digit=scr.nextLine();
                        StringTokenizer token=new StringTokenizer(digit);
                        int dig=0,sum=0;
                        System.out.println("\nEntered digits are : ");
                        while(token.hasMoreTokens())
                        {
                                    String s=token.nextToken();
                                    dig=Integer.parseInt(s);
                                    System.out.print(dig+" ");
                                    sum=sum+dig;
                        }
                        System.out.println();
                        System.out.println("Sum is : "+sum);
            }
}