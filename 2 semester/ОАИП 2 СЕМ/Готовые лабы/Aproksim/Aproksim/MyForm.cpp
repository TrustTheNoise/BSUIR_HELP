#include "MyForm.h"
#include "cmath"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Aproksim::MyForm form;
	Application::Run(% form);
}

double fx(int x) {
	return x * x * x - 5 * x * x;
}

double PN(double* mass_x, double* mass_y, double xt, int m) {
	double* differ = new double[m];
	for (int i = 0; i < m; i++) {
		differ[i] = mass_y[i];
	}
	double p = 1;
	double N = mass_y[0];
	for (int k = 1; k < m; k++) {
		for (int i = 0; i < m - k; i++) {
			double x1 = mass_x[i], x2 = mass_x[i + k];
			double d = differ[i], d1 = differ[i+1];

			differ[i] = (differ[i] - differ[i + 1]) / (mass_x[i]-mass_x[i+k]);
		}
		p *= (xt - mass_x[k-1]);
		N += p * differ[0];
	}
	delete[] differ;
	return N;
}

double PL(double* mass_x, double* mass_y, double xt, int m) {
	double p = 0;
	for (int k = 0; k <= m; k++)
	{
		double e = mass_y[k];

		for (int i = 0; i <= m; i++)
		{
			if (i != k)
			{
				e *= (xt - mass_x[i]) / (mass_x[k] - mass_x[i]);
			}
		}

		p += e;
	}

	return p;
}

System::Void Aproksim::MyForm::построитьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	double a, b; 
	int m, n;
	if (checkBoxTest1->Checked == 0 && (textBoxA->Text == "" || textBoxB->Text == "" || textBoxM->Text == "" || textBoxN->Text == ""))
	{
		MessageBox::Show("Введите значения", "Смотри в оба!");
		return;
	}
	else
		if (textBoxA->Enabled == 1 && checkBoxTest1->Checked == 1)
		{
			MessageBox::Show("Выключите параметр тестовых значение", "Ошибка!");
			return;
		}
	try
	{
		a = Convert::ToDouble(textBoxA->Text);
	}
	catch (FormatException^)
	{
		MessageBox::Show("Введите число a", "Ошибка!");
		return;
	}

	try
	{
		b = Convert::ToDouble(textBoxB->Text);
	}
	catch (FormatException^)
	{
		MessageBox::Show("Введите число b", "Ошибка!");
		return;
	}

	try
	{
		m = Convert::ToInt16(textBoxM->Text);
	}
	catch (FormatException^)
	{
		MessageBox::Show("Введите число m", "Ошибка!");
		return;
	}

	try
	{
		n = Convert::ToInt16(textBoxN->Text);
	}
	catch (FormatException^)
	{
		MessageBox::Show("Введите число n", "Ошибка!");
		return;
	}

	if (a > b)
	{
		MessageBox::Show("!(a > b)", "Ошибка!");
		return;
	}

	if (m < 0)
	{
		MessageBox::Show("\nВведите число m > 1\n", "Ошибка!");
		return;
	}

	if (n < 0)
	{
		MessageBox::Show("\nВведите число n > 1\n", "Ошибка!");
		return;
	}

	if (n > m)
	{
		MessageBox::Show("\nВведите число n <= m\n", "Ошибка!");
		return;
	}

	double h = (b - a) / m, y, x = a;
	double* mass_x = new double[m];
	double* mass_y = new double[m];
	double mass_y_t;

	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	this->chart1->Series[2]->Points->Clear();
	chart1->Visible = true;

	for (int i = 0; i<m; i++, x+=h) {
		mass_x[i] = x;
		y = fx(x);
		mass_y[i] = y;
		this->chart1->Series[0]->Points->AddXY(x, y);
	}
	this->chart1->Series[1]->IsVisibleInLegend = false;
	this->chart1->Series[2]->IsVisibleInLegend = false;


	if (checkBoxPL->Checked == 1) {
		this->chart1->Series[1]->IsVisibleInLegend = true;
		for (double xt = a, i=0; i<n; xt+=h, i++) {
			this->chart1->Series[1]->Points->AddXY(xt, PL(mass_x, mass_y, xt, n));
		}
	}
	if(checkBoxPN->Checked==1){
		this->chart1->Series[2]->IsVisibleInLegend = true;
		for (double xt = a, i = 0; i < n; xt += h, i++) {
			this->chart1->Series[2]->Points->AddXY(xt, PN(mass_x, mass_y, xt, n));
		}
	}
	delete[] mass_x;
	delete[] mass_y;
	return System::Void();
}

System::Void Aproksim::MyForm::очиститьГрафикToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	textBoxA->Text = L"";
	textBoxB->Text = L"";
	textBoxN->Text = L"";
	textBoxM->Text = L"";
	textBoxA->Enabled = true;
	textBoxB->Enabled = true;
	textBoxN->Enabled = true;
	textBoxM->Enabled = true;
	chart1->Visible = false;
	checkBoxTest1->Checked = 0;
	checkBoxPL->Checked = 0;
	this->chart1->Series[0]->Points->Clear();
	this->chart1->Series[1]->Points->Clear();
	return System::Void();
}

System::Void Aproksim::MyForm::выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (MessageBox::Show("Выйти?", "Внимание!", MessageBoxButtons::YesNo) == Windows::Forms::DialogResult::Yes) {
		Application::Exit();
	}
	return System::Void();
}

System::Void Aproksim::MyForm::checkBoxTest1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (checkBoxTest1->Checked == 1) {
		textBoxA->Enabled = false;
		textBoxB->Enabled = false;
		textBoxN->Enabled = false;
		textBoxM->Enabled = false;
		textBoxA->Text = L"-2";
		textBoxB->Text = L"5";
		textBoxN->Text = L"5";
		textBoxM->Text = L"5";
	}
	else {
		textBoxA->Enabled = true;
		textBoxB->Enabled = true;
		textBoxN->Enabled = true;
		textBoxM->Enabled = true;
		textBoxA->Text = "";
		textBoxB->Text = "";
		textBoxN->Text = "";
		textBoxM->Text = "";
	}
}
