#pragma once
#pragma warning(disable:4996)
#include <iostream>
using namespace std;
class MyString
{
	char* str{nullptr};
	size_t cap{0};
	
public:
	MyString();
	MyString(const char* s);
	MyString(size_t s);
	explicit MyString(const MyString& obj);
	MyString(MyString&& obj)noexcept;
	~MyString();

	size_t capacity()const;
	size_t size()const;
	char& operator[](size_t index); 
	char operator[](size_t index)const;

	void input();
	void print()const;
	
	operator const char* ()const;

	MyString& operator=(const MyString& obj);
	MyString& operator=(MyString&& obj)noexcept;

	MyString& operator+=(const MyString& obj);
	MyString& operator+=(const char* s);
	MyString& operator+=(char x);
	MyString& operator+=(const string& s);

	MyString operator+(const MyString& obj)const;
	MyString operator+(const char* s)const;
	MyString operator+(char x)const;
	MyString operator+(const string& s)const;

	bool operator==(const MyString& obj)const;
	bool operator==(const char* s)const;
	
	bool operator!=(const MyString& obj)const;
	bool operator!=(const char* s)const;

	
	bool operator>=(const MyString& obj)const;
	bool operator>=(const char* s)const;
	bool operator>=(const string& s)const;
	
	bool operator<=(const MyString& obj)const;
	bool operator<=(const char* s)const;
	bool operator<=(const string& s)const;

	bool operator>(const MyString& obj)const;
	bool operator>(const char* s)const;
	bool operator>(const string& s)const;

	bool operator<(const MyString& obj)const;
	bool operator<(const char* s)const; 
	bool operator<(const string& s)const;

	friend ostream& operator<<(ostream& dest, const MyString& source);
	friend istream& operator>>(  istream& source, MyString& dest);

	const char* reverse()const;
};

