#pragma once
#include <iostream>

using namespace std;

class Exception
{
public:

	virtual void what() {}
};

class Division_by_zero : public Exception 
{
private:
	char* message;

public:
	Division_by_zero() : message{ new char[strlen("На 0 делить нельзя!\n")+1]}
	{
		strcpy_s(message, strlen("На 0 делить нельзя!\n") + 1, "На 0 делить нельзя!\n");
	};

	void what()
	{
		printf(message);
	}
};

class File_open_exc : public Exception
{
private:
	char* message;

public:
	File_open_exc() : message{ new char[strlen("Ошибка открытия файла\n") + 1] }
	{
		strcpy_s(message, strlen("Ошибка открытия файла\n") + 1, "Ошибка открытия файла\n");
	};

	void what()
	{
		printf(message);
	}
};

class File_close_exc : public Exception
{
private:
	char* message;

public:
	File_close_exc() : message{ new char[strlen("Ошибка закрытия файла\n") + 1] }
	{
		strcpy_s(message, strlen("Ошибка закрытия файла\n") + 1, "Ошибка закрытия файла\n");
	};

	void what()
	{
		printf(message);
	}
};

class Stack_overflow : public Exception
{
private:
	char* message;

public:
	Stack_overflow() : message{ new char[strlen("Переполнение буфера\n") + 1] }
	{
		strcpy_s(message, strlen("Переполнение буфера\n") + 1, "Переполнение буфера\n");
	};

	void what()
	{
		printf(message);
	}
};