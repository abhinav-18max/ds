package lab;
import java.io.*;
import java.util.Scanner;

public class file{
    public static void main(String[] args) throws IOException {
        try{
            Scanner sc = new Scanner(System.in);
            System.out.println("File Name of File 1:");
            String file1 = sc.nextLine();
            FileInputStream f1 = new FileInputStream(file1);
            System.out.println("File Name of File 2:");
            String file2 = sc.nextLine();
            FileOutputStream f2 = new FileOutputStream(file2);
            int c;
            do{
                c = f1.read();
                if (c != -1){
                    f2.write(c);
                }
            } while (c != -1);
            System.out.println();
            System.out.println();
            System.out.println("Items from "+file1+" copied to "+file2+".");
            f1.close();
            f2.close();
        }
        catch(FileNotFoundException e){
            System.out.println("FILE NOT FOUND.");
            return;
        }
    }
}