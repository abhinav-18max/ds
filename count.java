package lab;

import java.io.*;
import java.util.Scanner;

public class count {
    public static void main(String[] args)
        throws IOException
    {
    	Scanner sc=new Scanner(System.in);
    	System.out.println("Enter File name:");
    	String str=sc.next();
        File file = new File(str);
        FileInputStream fileInputStream = new FileInputStream(file);
        InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream);
        BufferedReader bufferedReader = new BufferedReader(inputStreamReader);
  
        String line;
        int wordCount = 0;
        int characterCount = 0;
        int sentenceCount = 0;
  
        while ((line = bufferedReader.readLine()) != null) {
           
                characterCount += line.length();
                String words[] = line.split("\\s+");
                wordCount += words.length;
                String sentence[] = line.split("[!?.:]+");
                sentenceCount += sentence.length;
            
        }
       
        System.out.println("Total word count = "+ wordCount);
        System.out.println("Total number of lines = "+ sentenceCount);
        System.out.println("Total number of characters = "+ characterCount);
        
    }
}