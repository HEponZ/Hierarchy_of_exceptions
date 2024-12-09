#include "Exception.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Division_by_zero exc;
	File_open_exc file_exc1;
	File_close_exc file_exc2;
	Stack_overflow over_exc;
	FILE* file;
	int num, den, size;
	char word[10]{ "\0" }, buf[100]{ "\0" };
	try
	{
		cout << "\tДеление\n\nВведите числитель: ";
		cin >> num;
		cout << "Введите знаменатель: ";
		cin >> den;
		if (den == 0)
		{
			throw exc;
		}
	}
	catch (Division_by_zero exception)
	{
		exception.what();
	}

	cout << "\n\tРабота с файлом\n";
	try
	{
		if (fopen_s(&file, "PhoneBook.txt", "r") != NULL)
		{
			throw file_exc1;
		}
		cout << "Всё ОК\n";
	}
	catch (File_open_exc exception)
	{
		exception.what();
	}
	try
	{
		if (fclose(file) != 0)
		{
			throw file_exc2;
		}
		cout << "Всё ОК\n";
	}
	catch (File_close_exc exception)
	{
		exception.what();
	}

	try
	{
		cout << "\n\tНехватка пямяти\nВведите строку: ";
		cin.ignore();
		gets_s(buf);
		if (strlen(buf)+1>10)
		{
			throw over_exc;
		}
		cout << "Всё ОК\n";
	}
	catch (Stack_overflow exception)
	{
		exception.what();
	}

	return 0;
}