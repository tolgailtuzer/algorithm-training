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
        BigInteger i=new BigInteger("1");
        BigInteger sonuc=new BigInteger("1");
        BigInteger temp=new BigInteger("1");
            
         int count = 2;
            
            String str = null;
            do
            {
                count++;
                temp = sonuc;
                sonuc =sonuc.add(i);
                i = temp;
                str = sonuc.toString();                             
            } while (str.length()!=1000);
           System.out.println(count);
    }
    
}
