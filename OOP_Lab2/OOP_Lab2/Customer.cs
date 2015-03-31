using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace OOP_Lab2
{
    class Customer
    {
        #region Fields
        private readonly string _email;
        private readonly string _person;
        private readonly string _phone;
        private readonly string _name;
        #endregion

        #region Properties
        public string ContactEmail { get { return _email; } }
        public string ContacPerson { get { return _person; } }
        public string ContactPhone { get { return _phone; } }
        public string Name { get { return _name; } }
        #endregion

        #region Constructor
        public Customer(string emailValue, string personValue, string phoneValue, string nameValue)
        {
            _email = emailValue;
            _name = nameValue;
            _person = personValue;
            _phone = phoneValue;
        }
        #endregion

        #region Methods
        #endregion
    }
}
