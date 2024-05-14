using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Windows.Forms;

namespace task3
{
    public class SortableBindingList<T> : BindingList<T>
    {
        private bool isSortedValue;
        ListSortDirection sortDirectionValue;
        PropertyDescriptor sortPropertyValue;

        public SortableBindingList() //конструктор без параметров
        {
        }

        public SortableBindingList(IEnumerable<T> list) //конструктор для конвертации любой коллекции в эту
        {
            foreach (T o in list)
            {
                this.Add(o);
            }
        }

        protected override void ApplySortCore(PropertyDescriptor prop, ListSortDirection direction) //применение сортировочного ядра к коллекции
        {
            sortPropertyValue = prop;
            sortDirectionValue = direction;

            IEnumerable<T> query = base.Items;
            query = direction == ListSortDirection.Ascending
                ? query.OrderBy(i => prop.GetValue(i))
                : query.OrderByDescending(i => prop.GetValue(i)); // определение направления сортировки

            int newIndex = 0;
            foreach (T item in query)
            {
                this.Items[newIndex] = item;
                newIndex++;
            }

            isSortedValue = true;
            this.OnListChanged(new ListChangedEventArgs(ListChangedType.Reset, -1)); //отправка ивента об изменении значений
        }

        protected override PropertyDescriptor SortPropertyCore => sortPropertyValue;

        protected override ListSortDirection SortDirectionCore => sortDirectionValue;

        protected override bool SupportsSortingCore => true;

        protected override bool IsSortedCore => isSortedValue;

    }
}