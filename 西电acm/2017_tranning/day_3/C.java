import java.math.BigInteger;  
import java.util.*;
import java.io.*;  
  
public class Main  
{  
    public static void main(String args[])  
    {  
        Scanner cin = new Scanner(System.in);  
        BigInteger[] p=new BigInteger[2000+10];
        p[1]=new BigInteger("1");
        p[2]=new BigInteger("2");
        for(int i=3;i<1009;i++)
        {
            p[i]=new BigInteger(p[i-1].add(p[i-2]).toString());
        }
        
        int T;
        T=cin.nextInt();
        String c=cin.nextLine();
        while(T-- >0){
            String string=cin.nextLine();
            int len=string.length();
            System.out.println(p[len]);
        }
    }  
}  