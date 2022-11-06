#include "Header.h"
int Time::Year = 2022;
string Time::Type = " ";

void gotoxy(short x, short y)
{
	COORD coord = { x, y };
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(h, coord);
}



void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

ostream& operator<<(ostream& os, Time& t)
{
	t.Type_time(t);
	if (t.hh < 0 || t.hh>24 || t.mm < 0 || t.mm>59 || t.ss < 0 || t.ss>59)
		cout << "Error" << endl;
	else
	{
		if (t.hh <= 9)
			os << "0" << t.hh << ":";
		else
			os << t.hh << ":";
		if (t.mm <= 9)
			os << "0" << t.mm << ":";
		else
			os << t.mm << ":";
		if (t.ss <= 9)
			os << "0" << t.ss << " " << t.Type << " Day " << t.dd << " Year " << t.Year << endl;

		else
			os << t.ss << " " << t.Type << " Day " << t.dd << " Year " << t.Year << endl;
		return os;
	}
}

istream& operator>>(istream& is, Time& t)
{
	cout << "Set hours" << endl;
	is >> t.hh;
	if (t.hh < 0 || t.hh>24)
		cout << "Error" << endl;
	else
	{
		cout << "Set minutes" << endl;
		is >> t.mm;

		if (t.mm < 0 || t.mm>59)
			cout << "Error" << endl;
		else
		{
			cout << "Set seconds" << endl;
			is >> t.ss;
		}
	}
	if (t.ss < 0 || t.ss>59)
		cout << "Error" << endl;
	else
		return is;
}

void Time::reset(Time& t)
{
	t.hh = 0;
	t.mm = 0;
	t.ss = 0;
}

Time Time::operator--(int n)
{
	if (ss == 0 && mm > 0)
	{
		ss = 59;
		mm--;
		if (mm < 1 && hh > 0)
		{
			mm = 59;
			hh--;
		}
	}

	else if (ss > 0)
	{
		ss--;
		if (ss == 0 && mm > 0)
		{
			ss = 59;
			mm--;
			if (mm < 1 && hh > 0)
			{
				mm = 59;
				hh--;
			}
		}
	}
	else
	{
		reset(*this);
	}
	return *this;
}

Time Time::operator++(int n)
{
	ss++;
	if (ss > 59)
	{
		ss = 0;
		mm++;
		if (mm > 59)
		{
			mm = 0;
			hh++;
			if (hh == 24)
				reset(*this);
		}
	}
	return *this;
}

Time Time::operator+(Time t)
{
	Time tmp;
	int _s1, _s2, sum;
	_s1 = Converter_s(*this);
	_s2 = Converter_s(t);
	sum = _s1 + _s2;
	tmp = Converter_h_m_s(sum);
	return tmp;
}

Time Time::operator-(Time t)
{
	Time tmp;
	int _s1, _s2, sum;
	_s1 = Converter_s(*this);
	_s2 = Converter_s(t);
	sum = _s1 - _s2;
	tmp = Converter_h_m_s(sum);
	return tmp;
}

Time Time::operator*(int n)
{
	Time tmp;
	int _s1, sum;
	_s1 = Converter_s(*this);
	sum = _s1 * n;
	tmp = Converter_h_m_s(sum);
	return tmp;
}

Time Time::operator/(int n)
{
	Time tmp;
	int _s1, sum;
	_s1 = Converter_s(*this);
	sum = _s1 / n;
	tmp = Converter_h_m_s(sum);
	return tmp;
}

Time Time::operator%(int n)
{
	Time tmp;
	int _s1, sum;
	_s1 = Converter_s(*this);
	sum = (_s1 * n) / 100;
	tmp = Converter_h_m_s(sum);
	return tmp;
}

bool Time::operator>(Time t)
{
	int _s1, _s2;
	_s1 = Converter_s(*this);
	_s2 = Converter_s(t);
	return _s1 > _s2;
}

bool Time::operator<(Time t)
{
	int _s1, _s2;
	_s1 = Converter_s(*this);
	_s2 = Converter_s(t);
	return _s1 < _s2;
}

bool Time::operator==(Time t)
{
	int _s1, _s2;
	_s1 = Converter_s(*this);
	_s2 = Converter_s(t);
	return _s1 == _s2;
}

bool Time::operator!=(Time t)
{
	int _s1, _s2;
	_s1 = Converter_s(*this);
	_s2 = Converter_s(t);
	return _s1 != _s2;
}

void Time::Print_time_bool(bool a)
{
	if (a == true)
		cout << "true" << endl;
	else
		cout << "false" << endl;
}

int Time::Converter_s(Time& t)
{
	int s;
	s = (t.hh * 3600) + (t.mm * 60) + t.ss;
	return s;
}

Time Time::Converter_h_m_s(int _s)
{
	Time tmp;
	tmp.dd = _s / 86400;
	tmp.hh = _s % 86400 / 3600;
	tmp.mm = _s % 3600 / 60;
	tmp.ss = _s % 60;
	return tmp;
}

void Time::Type_time(Time& t)
{
	if (t.hh < 12)
		Type = "AM";
	else
		Type = "PM";
}
