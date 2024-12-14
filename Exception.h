#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Exception
{
public:
	Exception() {}

	virtual string what() const noexcept { return "\nException\n"; }

	virtual ~Exception() = default;
};

class Division_by_zero : public Exception 
{
private:
	string message;

public:
	Division_by_zero() = delete;
	Division_by_zero(string message_S) : message{ message_S } {}

	virtual string what() const noexcept { return message; }

	virtual ~Division_by_zero() = default;
};

class File_open_exc : public Exception
{
private:
	string message;

public:
	File_open_exc() = delete;
	File_open_exc(string message_S) : message{ message_S } {}

	virtual string what() const noexcept { return message; }

	virtual ~File_open_exc() = default;
};

class File_close_exc : public Exception
{
private:
	string message;

public:
	File_close_exc() = delete;
	File_close_exc(string message_S) : message{ message_S } {}

	virtual string what() const noexcept { return message; }

	virtual ~File_close_exc() = default;
};

class OutOfRange : public Exception
{
private:
	string message;

public:
	OutOfRange() = delete;
	OutOfRange(string message_S) : message{ message_S } {}

	virtual string what() const noexcept { return message; }

	virtual ~OutOfRange() = default;
};