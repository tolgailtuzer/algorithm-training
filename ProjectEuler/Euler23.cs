using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_euler
{
    class _22
    {
        static void Main(string[] args)
        {
            int i, j,a,b,res=0;
            UInt64 result = 0;
            ArrayList abundant = new ArrayList();
            ArrayList Uabundant = new ArrayList();
            bool flag = false;

            for (i = 1; i < 28123; i++)
            {
                for(j=1;j<i;j++)
                {
                    if (i % j == 0) res += j;
                }
                if (res > 1) abundant.Add(i);
                res = 0;                
            }

            for(i=1;i<28123;i++)
            {
                flag = false;
                for(a=0;a<abundant.Count;a++)
                {
                    for (b = 0; b < abundant.Count; b++)
                    {
                        if (i == ((int)abundant[a] + (int)abundant[b]) && !Uabundant.Contains(abundant[a]) && !Uabundant.Contains(abundant[b]))
                        {
                            flag = true;
                            goto sa;
                        }
                    }
                }
                sa:
                if (flag == false) result += (UInt64)i;
            }

            Console.WriteLine(result);
        }
    }
}
