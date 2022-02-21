import java.lang.*;
import java.util.*;

public class Multithreades extends Thread {
public int value;

public void setVal(int a) {
value = a;
}

public void run() {
sync();
}

synchronized void sync() {
try {
if (this.getName() == "Generator Thread") {
int n = 5;
while (n > 0) {
n--;
gen();
this.wait(1000);
}

} else if (this.getName() == "Odd Thread") {
System.out.println("Thread name : " + this.getName());
System.out.println("Cube of " + value + " is : " + (value * value * value));
} else {
System.out.println("Thread name : " + this.getName());
System.out.println("Square of " + value + " is : " + (value * value));
}

} catch (Exception e) {
System.out.println("Exception Found : " + e);
}
}

void gen() {
Random r = new Random();
int a = r.nextInt(100);
Thread odds = new Multithreades();
odds.setName("Odd Thread");
Thread evens = new Multithreades();
evens.setName("Even Thread");
if (a % 2 == 0) {
((Multithreades) evens).setVal(a);
evens.start();
} else {
((Multithreades) odds).setVal(a);
odds.start();
}
}

public static void main(String[] args) {
Thread ob = new Multithreades();
ob.setName("Generator Thread");

ob.start();
}
}
