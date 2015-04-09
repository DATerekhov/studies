using System;
/*using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;*/

namespace OOP_Lab2
{
    class Project
    {
        #region Fields

        private readonly int _cost;
        private readonly int _key;
        private readonly string _title;

        #endregion

        #region Properties

        public int InitialCost { get { return _cost; } }
        public int Key { get { return _key; } }
        public string Title { get { return _title; } }

        #endregion

        #region Constructor

        public Project(int cost, int key, string title)
        {
            _cost = cost;
            _key = key;
            _title = title;
        }

        #endregion

        #region Methods

        public static Project NewCreate()
        {
            Console.WriteLine("Введите ключевую строку (Key) заказа: ");
            var keyValue = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Введите назание проекта");
            var nameValue = Console.ReadLine();

            Console.WriteLine("Введите бюджет проекта");
            var costValue = Convert.ToInt32(Console.ReadLine());

            return new Project(costValue, keyValue, nameValue);
        }

        public static void Print(Project value)
        {
            Console.WriteLine(value._key);
            Console.WriteLine(value._cost);
            Console.WriteLine(value._title);
        }

        #endregion
    }
}