using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace task3
{
    public class Student
    {
        private string _fullName;
        private int _groupNumber;
        private int[] _grades;

        [DisplayName("Фамилия и инициалы")]
        public string FullName
        {
            get => _fullName;
            set
            {
                _fullName = value;
                OnPropertyChanged();
            }
        }

        [DisplayName("Номер группы")]
        public int GroupNumber
        {
            get => _groupNumber;
            set
            {
                _groupNumber = value;
                OnPropertyChanged();
            }
        }

        public int[] Grades
        {
            get => _grades;
            set
            {
                _grades = value;
                
                // Вызов метода OnPropertyChanged для каждого свойства, которое зависит от значений массива оценок,
                // чтобы уведомить таблицу об изменении этих свойств

                // nameof - для того чтобы компилятор подставлял литерал во время компиляции,
                // а не во время выполнения
                OnPropertyChanged(nameof(MathGrade));
                OnPropertyChanged(nameof(PhysicsGrade));
                OnPropertyChanged(nameof(RussianGrade));
                OnPropertyChanged(nameof(BelorussianGrade));
                OnPropertyChanged(nameof(InformaticsGrade));
            }
        }

        public int MathGrade
        {
            get => _grades[0];
            set
            {
                _grades[0] = value;
                OnPropertyChanged();
            }
        }

        public int PhysicsGrade
        {
            get => _grades[1];
            set
            {
                _grades[1] = value;
                OnPropertyChanged();
            }
        }

        public int RussianGrade
        {
            get => _grades[2];
            set
            {
                _grades[2] = value;
                OnPropertyChanged();
            }
        }

        public int BelorussianGrade
        {
            get => _grades[3];
            set
            {
                _grades[3] = value;
                OnPropertyChanged();
            }
        }

        public int InformaticsGrade
        {
            get => _grades[4];
            set
            {
                _grades[4] = value;
                OnPropertyChanged();
            }
        }

        public Student(string fullName, int groupNumber, int[] grades)
        {
            this.FullName = fullName;
            this.GroupNumber = groupNumber;
            this.Grades = grades;
        }

        public Student(string fullName, int groupNumber, int mathGrade, int physicsGrade,
                        int russianGrade, int belorussianGrade, int informaticsGrade)
        {
            this.FullName = fullName;
            this.GroupNumber = groupNumber;
            int[] grades = new int[] { mathGrade, physicsGrade, russianGrade, belorussianGrade, informaticsGrade };
            this.Grades = grades;
        }

        public string GetFullName()
        {
            return this.FullName;
        }

        public int GetGroupNumber()
        {
            return this.GroupNumber;
        }

        public int[] GetGrades()
        {
            return this.Grades;
        }

        public string toString()
        {
            return this.FullName + "`" + this.GroupNumber + "`" + string.Join("`", this.Grades);
        }

        public event PropertyChangedEventHandler PropertyChanged;
        protected virtual void OnPropertyChanged([CallerMemberName] string propertyName = null)
            => PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
    }
}

