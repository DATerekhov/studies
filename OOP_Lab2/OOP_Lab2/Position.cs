using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    class Position
    {
        #region Fields

        private readonly int _code;
        private readonly string _name;
        private readonly int _hourlyRate;

        #endregion

        #region Properties

        public int HourlyRate
        {
            get { return _hourlyRate; }
        }

        public string Name
        {
            get { return _name; }
        }

        public int Code
        {
            get { return _code; }
        }

        #endregion

        #region Constructor

        public Position(int hourlyRate, int code, string name)
        {
            _hourlyRate = hourlyRate;
            _code = code;
            _name = name;
        }

        #endregion
    }
}
