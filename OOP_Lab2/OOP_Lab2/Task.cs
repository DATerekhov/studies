using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    class Task
    {
        #region Fields

        private readonly DateTime _dueDateTime;
        private readonly DateTime _closeDateTime;
        private readonly bool _billable;
        private readonly string _description;
        private readonly int _number;
        private readonly double _hoursSpent;

        #endregion

        #region Properties

        public double HoursSpent
        {
            get { return _hoursSpent; }
        }

        public DateTime DueDateTime
        {
            get { return _dueDateTime; }
        }

        public DateTime CloseDateTime
        {
            get { return _closeDateTime; }
        }

        public bool Billable
        {
            get { return _billable; }
        }

        public string Description
        {
            get { return _description; }
        }

        public int Number
        {
            get { return _number; }
        }

        #endregion

        #region Constructor

        public Task(double hoursSpent, int number, string description, bool billable, DateTime closeDateTime, DateTime dueDateTime)
        {
            _hoursSpent = hoursSpent;
            _number = number;
            _description = description;
            _billable = billable;
            _closeDateTime = closeDateTime;
            _dueDateTime = dueDateTime;
        }

        #endregion
    }
}
