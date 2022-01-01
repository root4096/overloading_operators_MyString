#include "MyString.h"

MyString::MyString() :cap{ 80 }
{
  str =  new char[cap] {};
}


MyString::MyString(const char* s):str(_strdup(s)), cap{(strlen(s)+1)}
{
}

MyString::MyString(size_t s) : cap{ s }
{
	str= new char[cap] {};
}

MyString::MyString(const MyString& obj) : cap{ obj.cap }
{
	str=new char[cap]{};
	strcpy(str, obj.str);
}

MyString::MyString(MyString&& obj)noexcept
{
	swap(this->str, obj.str);
	swap(this->cap, obj.cap);
}

MyString::~MyString()
{
	delete[] str;
}

size_t MyString::capacity() const
{
	return cap;
}

size_t MyString::size() const
{
	return strlen(str);
}

char& MyString::operator[](size_t index)
{
	return str[index];
}

char MyString::operator[](size_t index) const
{
	return str[index];
}

void MyString::input()
{
	char buff[500]{};
	cin.getline(buff, 499); cin.ignore();
	if (cap > strlen(buff))
	{
		strcpy(str, buff);
	}
	else {
		cap = strlen(buff) + 1;
		delete[] str;
		str = new char[cap]{};
		strcpy(str, buff);
	}
}

void MyString::print() const
{
	cout << str<<'\n';
}

MyString::operator const char* () const
{
	return str;
}
MyString& MyString::operator=(const MyString& obj)
{
	if ((&obj == this)||obj.str==nullptr)
	{
		return*this;
	}
	else {
		delete[] str;
		cap = obj.cap;
		this->str = new char[cap] {};
		strcpy(str, obj.str);
	}
	return*this;
}
MyString& MyString::operator=(MyString&& obj)noexcept
{
	if (this == &obj) {
		return *this;
	}
	else {
		swap(this->str, obj.str);
		swap(this->cap, obj.cap);
	} 
	return *this;
}
MyString& MyString::operator+=(const MyString& obj)
{
	if ((size() + obj.size()) < cap)
	{
		strcat(this->str, obj.str);
	}
	else {
		MyString buff(size()+obj.size()+1);
		strcpy(buff.str, str);
		strcat(buff.str, obj.str);

		swap(this->str, buff.str);
		swap(this->cap, buff.cap);
	}
	return *this;

}
MyString& MyString::operator+=(const char* s)
{
	if (capacity() > (strlen(s) + size()))
	{
		strcat(str, s);
	}
	else {
		MyString buff(size() + strlen(s) + 1);
		strcpy(buff.str, this->str);
		strcat(buff.str, s);
		swap(this->cap, buff.cap);
		swap(this->str, buff.str);
	}
	return*this;
}
MyString& MyString::operator+=(char x)
{
	if (this->cap > (size() + 1))
	{
		str[size()] = x;
	}
	else {
		MyString buff(cap + 1);
		strcpy(buff.str, str);
		buff.str[size()] = x;
		swap(this->cap, buff.cap);
		swap(this->str, buff.str);
	}
	return*this;
}
MyString& MyString::operator+=(const string& s)
{
	if ((this->size() + s.size() + 1) <= capacity())
	{
		strcat(this->str, s.c_str());
	}
	else {
		MyString buff(this->str);
		buff += s.c_str();
		swap(this->str, buff.str);
		swap(this->cap, buff.cap);
	}
	return *this;
}

MyString MyString::operator+(const MyString& obj) const
{
	MyString buff(this->str);
	buff += obj;
	return buff;
}
MyString MyString::operator+(const char* s) const
{
	MyString buff(this->str);
	buff += s;
	return  buff;
}
MyString MyString::operator+(char x) const
{
	MyString buff(this->str);
	buff += x;
	return buff;
}
MyString MyString::operator+(const string& s) const
{
	MyString buff(this->str);
	buff += s;
	return buff;
}

bool MyString::operator==(const MyString& obj) const
{
	return strcmp(this->str, obj.str);
}
bool MyString::operator==(const char* s) const
{
	return strcmp(this->str, s);
}

bool MyString::operator!=(const MyString& obj) const
{
	return !strcmp(this->str, obj.str);
}
bool MyString::operator!=(const char* s) const
{
	return !strcmp(this->str, s);
}

bool MyString::operator>=(const MyString& obj) const
{
	return size()>=obj.size();
}
bool MyString::operator>=(const char* s) const
{
	return size()>=strlen(s);
}
bool MyString::operator>=(const string& s) const
{
	return size()>=s.size();
}

bool MyString::operator<=(const MyString& obj) const
{
	return size()<=obj.size();
}

bool MyString::operator<=(const char* s) const
{
	return size() <= strlen(s);
}

bool MyString::operator<=(const string& s) const
{
	return size()<=s.size();
}

bool MyString::operator>(const MyString& obj) const
{
	return size()>obj.size();
}

bool MyString::operator>(const char* s) const
{
	return size()>strlen(s);
}

bool MyString::operator>(const string& s) const
{
	return size()>s.size();
}

bool MyString::operator<(const MyString& obj) const
{
	return size()<obj.size();
}

bool MyString::operator<(const char* s) const
{ 
	return size()<strlen(s);
}

bool MyString::operator<(const string& s) const
{
	return size()<s.size();
}

const char* MyString::reverse() const
{
	char* buff = new char[strlen(str) + 1]{};
	
	for (size_t i = 0, k=size()-1; i < size()&&k>=0; i++, k--)
	{
		buff[i] = str[k];
	}
	
	return buff;
}

ostream& operator<<(ostream& dest, const MyString& source)
{
	dest << source.str << '\n';
	return dest;
}
istream& operator>>(  istream& source, MyString& dest)
{
	char buff[500]{};
	cin >> buff;
	if (dest.str)delete[] dest.str;
	dest.cap = strlen(buff) + 1;
	dest.str= new char[strlen(buff) + 1];
	strcpy(dest.str, buff);
	
	return source;
}
