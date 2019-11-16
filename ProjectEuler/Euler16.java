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
        BigInteger result=new BigInteger("0");
        BigInteger a = new BigInteger("2");
        a=a.pow(1000);
        
        
        while(a.compareTo(BigInteger.ZERO)==1)      
        {
           result=result.add(a.mod(BigInteger.TEN));
            a=a.divide(BigInteger.TEN);
        }
        System.out.println(result);
        
    }
    
}
