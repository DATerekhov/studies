using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace tryToFinishHim
{
    class Algorithm
    {
        public int F(int x, int y, int k)
        {
            if (Math.Abs(x) > k || Math.Abs(y) > k || Math.Abs(x + y) > k)
                return 0;
            if (k == 0)
                if (x == 0 && y == 0)
                    return 1;
                else
                    return 0;
            return F(x - 1, y, k - 1) + F(x + 1, y, k - 1) + F(x, y - 1, k - 1) + F(x, y + 1, k - 1);
        }
    }
}
