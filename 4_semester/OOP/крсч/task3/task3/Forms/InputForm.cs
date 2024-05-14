using System;
using System.Windows.Forms;

namespace task3.Forms
{
    public partial class InputForm : Form
    {
        private int _groupNum;
        private int _mathGrade;
        private int _physicsGrade;
        private int _russianGrade;
        private int _informaticsGrade;
        private int _belorussianGrade;
        public InputForm()
        {
            InitializeComponent();
        }

        private void addToListButton_Click(object sender, EventArgs e)
        {
            // @todo придумать более красивый вариант для этой функции
            if (!ValidateGrade(mathTextBox, out _mathGrade)) 
            {
                MessageBox.Show("Значение оценки математики является некорректным!"); 
            }else if (!ValidateGrade(physicsTextBox, out _physicsGrade))
            {
                MessageBox.Show("Значение оценки физики является некорректным!");
            }else if (!ValidateGrade(russianTextBox, out _russianGrade))
            {
                MessageBox.Show("Значение оценки русского языка является некорректным!");
            }
            else if (!ValidateGrade(informaticsTextBox, out _informaticsGrade))
            {
                MessageBox.Show("Значение оценки информатики является некорректным!");
            }
            else if (!ValidateGrade(belorussianTextBox, out _belorussianGrade))
            {
                MessageBox.Show("Значение оценки белорусского языка является некорректным!");
            }else if (!int.TryParse(groupnumTextBox.Text, out _groupNum))
            {
                MessageBox.Show("Значение номера группы является некорректным!");
            }
            else if (fieldsIsEmpty())
            {
                MessageBox.Show("Поля не должны быть пустыми");
            }
            else
            {
                this.Close();
            }
        }

        private bool fieldsIsEmpty()
        {
            if (fullnameTextBox.Text == "" || groupnumTextBox.Text == "" || mathTextBox.Text == "" || physicsTextBox.Text == ""
                || russianTextBox.Text == "" || informaticsTextBox.Text == "" || belorussianTextBox.Text == "")
            {
                return true;
            }
            return false;
        }

        private bool ValidateGrade(TextBox textBox, out int grade)
        {
            if (!int.TryParse(textBox.Text, out grade) || grade < 0 || grade > 10)
            {
                return false;
            }

            return true;
        }

        public Student GetOrder()
        {
            int[] grades = new int[] { _mathGrade, _physicsGrade, _russianGrade, _belorussianGrade, _informaticsGrade };
            try
            {
                return new Student(this.fullnameTextBox.Text, _groupNum, grades);
            }
            catch (System.FormatException e)
            {
                return null;
            }
        }

    }
}
