using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    class Project
    {
        #region Fields
        private readonly ulong _cost;
        private readonly string _key;
        private readonly string _title;
        #endregion

        #region Properties
        public ulong InitialCost { get { return _cost; } }
        public string Key { get { return _key; } }
        public string Title { get { return _title; } }
        #endregion

        #region Constructor
        public Project(ulong costValue, string keyValue, string titleValue)
        {
            _cost = costValue;
            _key = keyValue;
            _title = titleValue;
        }
        #endregion

        #region Methods
        #endregion
    }
}
