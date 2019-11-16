using System;
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
            String[] opt = null;
            int x = 0, a, b, enb = 75, yol = 75;
            int[,] matris = new int[15, 15];
            FileStream file = new FileStream("a.txt", FileMode.Open, FileAccess.Read);
            StreamReader sr = new StreamReader(file);
            while (!sr.EndOfStream)
            {
                opt = sr.ReadLine().Split(' ');
                for (int i = 0; i < 15; i++)
                {
                    if (opt.Length > i)
                    {
                        matris[x, i] = Convert.ToInt32(opt[i]);
                    }
                    else { matris[x, i] = 0; }
                }
                x++;
            }


            for (a = 13; a >= 0; a--)
            {
                for (b = 0; b < 14; b++)
                {

                    if (matris[a + 1, b] > matris[a + 1, b + 1]) matris[a, b] += matris[a + 1, b];
                    else matris[a, b] += matris[a + 1, b + 1];

                }
            }
            Console.WriteLine("-> " + matris[0, 0]);
        
        }
    }
}
