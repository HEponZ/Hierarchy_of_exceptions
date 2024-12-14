#include "Exception.h"

int main()
{
	setlocale(LC_ALL, "rus");
	FILE* file;
	int num, den, index;
	vector<int> mas = { 100, 90, 80, 70, 60, 50 };
	char word[10]{ "\0" }, buf[100]{ "\0" };
	try
	{
		cout << "\tДеление\n\nВведите числитель: ";
		cin >> num;
		cout << "Введите знаменатель: ";
		cin >> den;
		if (den == 0)
		{
			throw Division_by_zero{"\nDivision by zero\n"};
		}
		cout << "Частное от деления: " << num / den;
	}
	catch (Division_by_zero exc)
	{
		cout << exc.what();
	}

	cout << "\n\tРабота с файлом\n";
	try
	{
		if (fopen_s(&file, "PhoneBook.txt", "r") != NULL)
		{
			throw File_open_exc{ "\nFile open error\n" };
		}
		cout << "Всё ОК\n";
	}
	catch (File_open_exc exc)
	{
		cout << exc.what();
	}
	try
	{
		if (fclose(file) != 0)
		{
			throw File_close_exc{ "\nFile close error\n" };
		}
		cout << "Всё ОК\n";
	}
	catch (File_close_exc exception)
	{
		cout << exception.what();
	}

	try
	{
		cout << "\n\nМассив\nВведите индекс для ввода: ";
		cin >> index;
		if (index > 4 || index < 0)
		{
			throw OutOfRange{ "\nOut Of Range\n" };
		}
		
		cout << mas.at(index);
	}
	catch (OutOfRange exception)
	{
		cout << exception.what();
	}

	return 0;
}