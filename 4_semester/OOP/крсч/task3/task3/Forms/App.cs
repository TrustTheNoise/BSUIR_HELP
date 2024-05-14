using System;
using System.ComponentModel;
using System.IO;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Windows.Forms;

namespace task3.Forms
{
    public partial class App : Form
    {
        // SortableBindingList предоставляет возможность сортировки элементов
        private SortableBindingList<Student> _students;

        public SortableBindingList<Student> Students //привязка приватного поля к публичному
        {
            get => _students;
            set
            {
                _students = value;
                OnPropertyChanged();
            }
        }

        public App()
        {
            InitializeComponent();
            Students = new SortableBindingList<Student>();

            // Настройка столбцов DataGridView1

            dataGridView1.AutoGenerateColumns = false;
            dataGridView2.AutoGenerateColumns = false;

            // Создание нового столбца типа DataGridViewTextBoxColumn 
            DataGridViewTextBoxColumn fullNameColumn1 = new DataGridViewTextBoxColumn
            {
                // Установка имени столбца, которое будет использоваться для доступа к нему в коде
                Name = "FullName",

                // Установка заголовка столбца, который будет отображаться в таблице
                HeaderText = "Фамилия и инициалы",

                // Установка имени свойства из источника данных для dataGridView1,
                // которое будет связано со столбцом и отображаться в нем
                DataPropertyName = "FullName"
            };
            dataGridView1.Columns.Add(fullNameColumn1);


            DataGridViewTextBoxColumn groupNumberColumn1 = new DataGridViewTextBoxColumn
            {
                Name = "GroupNumber",
                HeaderText = "Номер группы",
                DataPropertyName = "GroupNumber"
            };
            dataGridView1.Columns.Add(groupNumberColumn1);

            string[] gradeNames = { "Математика", "Физика", "Русский язык", "Белорусский язык", "Информатика" };
            string[] grades = { "MathGrade", "PhysicsGrade", "RussianGrade", "BelorussianGrade", "InformaticsGrade" };
            for (int i = 0; i < 5; i++)
            {
                DataGridViewTextBoxColumn gradeColumn = new DataGridViewTextBoxColumn
                {
                    Name = $"Grade{i}",
                    HeaderText = gradeNames[i],
                    DataPropertyName = grades[i]
                };
                dataGridView1.Columns.Add(gradeColumn);
            }

            // Установка источника данных для DataGridView, чтобы отображать список студентов
            dataGridView1.DataSource = Students;
        }


        private void SaveButton_Click(object sender, EventArgs e)
        {
            using (SaveFileDialog saveFileDialog = new SaveFileDialog())
            {
                saveFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*"; // Фильтр файлов для сохранения
                saveFileDialog.FilterIndex = 1; // Устанавливаем индекс выбранного фильтра
                saveFileDialog.RestoreDirectory = true; // Восстанавливаем путь к последней директории
                saveFileDialog.FileName = "save.txt"; // Устанавливаем имя файла по умолчанию

                if (saveFileDialog.ShowDialog() == DialogResult.OK) // Если пользователь выбрал файл для сохранения
                {
                    using (StreamWriter sw = new StreamWriter(saveFileDialog.FileName))
                    {
                        foreach (var student in Students)
                        {
                            sw.WriteLine(student.toString());
                        }
                    }
                }
            }
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            InputForm inputForm = new InputForm();
            inputForm.ShowDialog();
            var dataFromInput = inputForm.GetOrder();
            if (dataFromInput != null)
            {
                Students.Add(dataFromInput);
            }
            dataGridView1.Sort(dataGridView1.Columns[0], ListSortDirection.Ascending);
        }


        private void DelButton_Click(object sender, EventArgs e)
        {
            // удаляем выбранные элементы
            foreach (DataGridViewRow row in dataGridView1.SelectedRows)
            {
                dataGridView1.Rows.Remove(row);
            }
        }

        private void LoadButton_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "Text files (*.txt)|*.txt|All files (*.*)|*.*"; // Фильтр файлов для открытия
                openFileDialog.FilterIndex = 1; // Устанавливаем индекс выбранного фильтра
                openFileDialog.RestoreDirectory = true; // Восстанавливаем путь к последней директории

                if (openFileDialog.ShowDialog() == DialogResult.OK) // Если пользователь выбрал файл для открытия
                {
                    Students.Clear(); // Очистка коллекции перед загрузкой данных из файла
                    using (StreamReader sr = new StreamReader(openFileDialog.FileName))
                    {
                        string line;
                        while ((line = sr.ReadLine()) != null) //
                        {
                            // разделяет прочитанную строку на массив строк с помощью символа-разделителя `
                            string[] splited = line.Split('`');
                            // добавляем сами строки
                            Students.Add(new Student(splited[0], int.Parse(splited[1]), int.Parse(splited[2]), int.Parse(splited[3]),
                                         int.Parse(splited[4]), int.Parse(splited[5]), int.Parse(splited[6])));
                        }
                        sr.Close();
                    }
                }
            }
            dataGridView1.Sort(dataGridView1.Columns[0], ListSortDirection.Ascending);
        }

        // обрабатывает кнопку "Полученная сумма" в которой мы вызываем диалоговое окно
        // с выбором нужного нам получателя затем мы узнаём сумму деняк у него на счету
        private void pioneerButton_Click(object sender, EventArgs e)
        {
            SortableBindingList<Student> pioneers = new SortableBindingList<Student>();
            dataGridView2.Columns.Clear();

            DataGridViewTextBoxColumn fullNameColumn2 = new DataGridViewTextBoxColumn
            {
                Name = "FullName",
                HeaderText = "Фамилия и инициалы",
                DataPropertyName = "FullName"
            };
            dataGridView2.Columns.Add(fullNameColumn2);

            DataGridViewTextBoxColumn groupNumberColumn2 = new DataGridViewTextBoxColumn
            {
                Name = "GroupNumber",
                HeaderText = "Номер группы",
                DataPropertyName = "GroupNumber"
            };
            dataGridView2.Columns.Add(groupNumberColumn2);
            dataGridView2.DataSource = pioneers;

            pioneers.Clear();
            foreach (var row in Students)
            {
                if (row.RussianGrade > 3 && row.InformaticsGrade > 3 && row.BelorussianGrade > 3 &&
                    row.PhysicsGrade > 3 && row.MathGrade > 3)
                {
                    pioneers.Add(row);
                }
            }
        }

        private void searchButton_Click(object sender, EventArgs e)
        {
            dataGridView2.Columns.Clear();

            SortableBindingList<Student> finded = new SortableBindingList<Student>();
            DataGridViewTextBoxColumn fullNameColumn = new DataGridViewTextBoxColumn
            {
                Name = "FullName",
                HeaderText = "Фамилия и инициалы",
                DataPropertyName = "FullName"
            };
            dataGridView2.Columns.Add(fullNameColumn);

            DataGridViewTextBoxColumn groupNumberColumn = new DataGridViewTextBoxColumn
            {
                Name = "GroupNumber",
                HeaderText = "Номер группы",
                DataPropertyName = "GroupNumber"
            };
            dataGridView2.Columns.Add(groupNumberColumn);

            string[] gradeNames = { "Математика", "Физика", "Русский язык", "Белорусский язык", "Информатика" };
            string[] grades = { "MathGrade", "PhysicsGrade", "RussianGrade", "BelorussianGrade", "InformaticsGrade" };
            for (int i = 0; i < 5; i++)
            {
                DataGridViewTextBoxColumn gradeColumn = new DataGridViewTextBoxColumn
                {
                    Name = $"Grade{i}",
                    HeaderText = gradeNames[i],
                    DataPropertyName = grades[i]
                };
                dataGridView2.Columns.Add(gradeColumn);
            }
            dataGridView2.DataSource = finded;

            foreach (var row in Students)
            {
                if (row.FullName.Contains(searchText.Text) || row.GroupNumber.ToString().Contains(searchText.Text))
                {
                    finded.Add(row);
                }
            }
        }

        // Информирование об изменении свойства.  Этот шаблон используется для
        // уведомления подписчиков об изменении значения свойства объекта.

        // Объявление события PropertyChanged, которое используется для
        // уведомления подписчиков об изменении любого свойства объекта
        public event PropertyChangedEventHandler PropertyChanged;

        // Защищенный виртуальный метод OnPropertyChanged, который вызывается из сеттеров свойств и вызывает событие PropertyChanged
        // Параметр propertyName содержит имя измененного свойства и автоматически получается с помощью атрибута [CallerMemberName]
        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            // Вызов события PropertyChanged с помощью оператора ?, который проверяет, не является ли событие null, прежде чем вызывать его
            // Если событие не равно null, оно вызывается с помощью метода Invoke, который принимает в качестве
            // параметров объект, вызвавший событие (this) и объект PropertyChangedEventArgs, содержащий имя измененного свойства
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

    }
}
