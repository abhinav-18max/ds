import java.util.*;
class Quick_sort
{
List<String>names;
Quick_sort(List<String>names)
{
this.names=names;
sort();
}

public void sort()
{
names.sort(null);
}
void display() {
System.out.println("The sorted list is ");
for(String name : names)
{
System.out.println(name);
}
}
}

public class Quicksort {

public static void main(String[] args) {

Scanner sc=new Scanner (System.in);
List<String>names=new ArrayList<String>();
System.out.println("Enter the number of strings");
int n=sc.nextInt();
System.out.println("Enter the strings");
for(int i=0;i<n;i++)
{
names.add(sc.next());
}
Quick_sort q=new Quick_sort(names);
q.display();
sc.close();
}

}

