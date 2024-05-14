using System;
using System.Windows.Forms;
using task3.Forms;

namespace task3
{
    internal static class Program
    {
        // Главная точка входа для приложения.
        [STAThread]
        static void Main()
        {
            // включает визуальные стили Windows Forms
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            // запускает главный цикл приложения
            Application.Run(new App());
        }
    }
}
