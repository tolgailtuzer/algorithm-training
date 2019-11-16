using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_euler
{
    class _17
    {
        static void Main(string[] args)
        {

            int i, j, sum = 0, key = 0 ;
            UInt64 bigsum = 0;
            Dictionary<int, int> numbers = new Dictionary<int, int>();
            ArrayList res = new ArrayList();

            for (i=2;i< 10000;i++)
            {
                for(j=1;j<i;j++)
                {
                    if (i % j == 0) sum += j;
                }
                numbers.Add(i, sum);
                sum = 0;
                                
            }
            for (i = 2; i < 10000; i++)
            {
                if (numbers.ContainsValue(i))
                {
                    foreach (KeyValuePair<int, int> pair in numbers)
                    {
                        if (pair.Value == i)
                        {
                            key = pair.Key;
                            break;
                        }
                    }
                    if (key == numbers[i] && key!=i)
                    {
                        if(!res.Contains(i) && !res.Contains(key))
                        {
                            res.Add(i);
                            res.Add(key);
                            Console.WriteLine("(" + i + "," + key + ")");
                        }
                        

                    }
                }
            }

            for (i = 0; i < res.Count; i++)
            {
                bigsum += Convert.ToUInt64(res[i]);
            }
            Console.WriteLine(bigsum);
            Console.ReadKey();
        }

    }
}
