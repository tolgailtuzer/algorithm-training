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
            int count = 0;
            DateTime date1 = new DateTime(1901,1,1);
            DateTime date2 = new DateTime(2000,12,31);

            for(DateTime date=date1;date<=date2;date=date.AddDays(1))
            {
                if(date.DayOfWeek==DayOfWeek.Sunday && date.Day==1)
                {
                    Console.WriteLine(date.Day);
                    count++;
                }
            }
            Console.WriteLine(count);

        }
    }
}
