using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection.Emit;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace tryToFinishHim
{
    class Program
    {
        static int Fun(int x, int y, int k)
        {
            if (Math.Abs(x) > k || Math.Abs(y) > k || Math.Abs(x + y) > k)
                return 0;
            if (k == 0)
                if (x == 0 && y == 0)
                    return 1;
                else
                    return 0;
            return Fun(x - 1, y, k - 1) + Fun(x + 1, y, k - 1) + Fun(x, y - 1, k - 1) + Fun(x, y + 1, k - 1);
        }

        static void Main(string[] args)
        {

            var temp = Fun(1,0,3);
            Console.WriteLine(temp);
            Console.ReadKey();
            /*FileInfo file = new FileInfo("input.txt");
            file.OpenRead();
            FileInfo file2 = new FileInfo("output.txt");
            file2.OpenWrite();
            int k, x, y;
            StreamReader streamReader = new StreamReader("input.txt");
            String str = "";
            while (!streamReader.EndOfStream)
            {
                str += streamReader.ReadLine();
            }
            str.*/

        }
    }
}


/*
ifstream fin;
ofstream fout;
 
int F(int x, int y, int k){
    if(abs(x)>k || abs(y)>k || abs(x+y)>k)
        return 0;
    if(k==0)
        if(x==0 && y==0)
            return 1;
        else
            return 0;
    return F(x-1, y, k-1) + F(x+1, y, k-1) + F(x, y-1, k-1) + F(x, y+1, k-1);
}
 
void main(){
    fin.open("robot.in");
    fout.open("robot.out");
    int K, X, Y;
    fin >> K >> X >> Y;
    fout << F(X, Y, K);
}
 */