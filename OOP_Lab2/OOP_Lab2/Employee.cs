using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    class Employee
    {
        #region Fields

        private readonly string _fullName;
        private readonly int _number;
        private readonly int _rating;

        #endregion

        #region Properties

        public string FullName
        {
            get { return _fullName; }
        }

        public int Number
        {
            get { return _number; }
        }

        public int Rating
        {
            get { return _rating; }
        }

        #endregion

        #region Constructor

        public Employee(int rating, int number, string fullName)
        {
            _rating = rating;
            _number = number;
            _fullName = fullName;
        }

        #endregion
    }
}
