/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package javaapplication1;
import java.math.BigInteger;

/**
 *
 * @author Tolga
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
        BigInteger result=new BigInteger("1");
        BigInteger result2=new BigInteger("0");
            
        for(int i=1;i<=100;i++)
        {
            
            result=result.multiply(BigInteger.valueOf(i));
        }
       
         while(result.compareTo(BigInteger.ZERO)==1)      
        {
           result2=result2.add(result.mod(BigInteger.TEN));
            result=result.divide(BigInteger.TEN);
        }
          System.out.println(result2);
    }
    
}
