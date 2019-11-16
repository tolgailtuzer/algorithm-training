using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_euler
{
    class _16
    {
        static void Main(string[] args)
        {
            String parse;
            String opr=null;
            UInt64 add =0, result=0;
            UInt64 sum = 0, number2,number1;

            parse = Convert.ToString(Convert.ToUInt64(Math.Pow(2, 50)));
            ArrayList number = new ArrayList();
            number1 = Convert.ToUInt64(Math.Pow(2, 50));
            number2 = number1;
            for (UInt64 i = 1; i <= number2; i++)
            {
                sum += number1;

            }
            // UInt64 [] number = new UInt64[parse.Length];

            /*for (int i = 0; i < parse.Length; i++)
            {
                number.Add(Convert.ToUInt64(parse[i].ToString()));
            }
           
            for(int a=0;a<10;a++)
            {
                opr = null;
                for (int i = 0; i < number.Count; i++)
                {
                    number2 = (UInt64)number[i];
                    number2 += add;
                    number2 *= Convert.ToUInt64(Math.Pow(2, 50));
                    add = number2 / 10;
                    result = number2 % 10;
                    if (i + 1 == number.Count)
                    {
                        
                        opr += (add+result); break;
                    }
                    opr += result;
                                   
                }
                number.Clear();
                for (int i = (opr.Length - 1); i >= 0; i--)
                {
                    number.Add(Convert.ToUInt64(opr[i].ToString()));               
                }
                
            
           }
           for(int i=0;i<opr.Length;i++)
            {
                sum += Convert.ToUInt64(opr[i]);
            }*/
            Console.WriteLine(sum);
            Console.ReadKey();
        }
    }
}
