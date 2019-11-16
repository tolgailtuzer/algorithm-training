using System;
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
            StreamReader sr = new StreamReader("names.txt");
            String[] str;
            String letter;
            int i, j;
            UInt64 sonucp = 0,sonucf=0;

            String a = sr.ReadToEnd();
            str = a.Split(',');
            for (i = 0; i < str.Length; i++)
            {
                str[i] = str[i].Trim('"');
            }
            Array.Sort(str);
            for (i = 0; i < str.Length; i++)
            {
                letter = str[i];
                for (j = 0; j < letter.Length; j++)
                {
                    sonucp += Convert.ToUInt64((((int)letter[j]) - 64));
                }
                //Console.WriteLine(sonucp);
                sonucp *= Convert.ToUInt64(i + 1);
                sonucf += Convert.ToUInt64(sonucp);
                sonucp = 0;
            }
            Console.WriteLine(sonucf);
            Console.ReadKey();
        }
    }
}
