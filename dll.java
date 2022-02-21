import java.util.*;
public class double_linked {

public static void main(String[] args) {
LinkedList<Integer>list=new LinkedList<Integer>();
Scanner sc=new Scanner(System.in);
int choice ,element;
do
{
System.out.println("1.Insert at begining\n2.Insert at end\n3.Delete from begining\n4.Delete from end\n5.Display\n6.Exit");
System.out.println("Enter your choice");
choice=sc.nextInt();
switch(choice)
{
case 1:
System.out.println("Enter th element ");
element =sc.nextInt();
list.addFirst(element);
System.out.println("The list is");
for(int i: list)
{
System.out.println(i);
}
break;
case 2:
System.out.println("Enter element");
element =sc.nextInt();
list.addLast(element);
System.out.println("The list is");
for(int i: list)
{
System.out.println(i);
}
break;
case 3:
list.removeFirst();
System.out.println("The list is");
for(int i: list)
{
System.out.println(i);
}
break;
case 4:
list.removeLast();
System.out.println("The list is");
for(int i: list)
{
System.out.println(i);
}
break;
case 5:
if(list.isEmpty())
{
System.out.println("The list is empty");
}
else
{
System.out.println("The list is");
for(int i: list)
{
System.out.println(i);
}


}
break;

}
}while(choice!=6);

}

}
