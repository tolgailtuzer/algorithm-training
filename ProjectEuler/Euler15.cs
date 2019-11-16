using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project_euler
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 21, b = 21;
            UInt64 [,] grid = new UInt64[a, b];
            int i, j;
            for (i = 0; i <b; i++)
            {
                grid[0, i] = 1;
            }
            for (j = 0; j < a; j++)
            {
                grid[j, 0] = 1;
            }

            for (i = 1; i < a; i++)
            {
                for (j = 1; j < b; j++)
                {
                    grid[i, j] = grid[i, j - 1] + grid[i - 1, j];
                }

            }
            //Console.WriteLine(grid[3, 3]+ " " + grid[4, 2]+" " +grid[4, 3]);
            Console.WriteLine(grid[20, 20]);
            Console.ReadKey();
        }
    }
}

