
#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <conio.h>
#include <stdio.h>
#include<io.h>
#include<fstream>
#include<string>
#include <MMSystem.h>
#pragma comment (lib, "winmm")
using namespace std;
void gotoxy(short x, short y);
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue,
	LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background = Black);

class Time
{
	int dd;
	int hh;
	int mm;
	int ss;
	static string Type;
	static int Year;
public:
	Time()
	{
		dd = 0;
		hh = 0;
		mm = 0;
		ss = 0;
	}
	void reset(Time& t);
	Time operator --(int n);
	Time operator ++(int n);
	Time operator +(Time t);

	Time operator -(Time t);

	Time operator *(int n);
	
	Time operator /(int n);

	Time operator %(int n);
	
	bool operator >(Time t);

	bool operator <(Time t);

	bool operator ==(Time t);
	
	bool operator !=(Time t);

	void Print_time_bool(bool a);

	int Converter_s(Time& t);

	Time Converter_h_m_s(int _s);

	static void Type_time(Time& t);


	friend ostream& operator<<(ostream & os, Time & t);
	friend istream& operator>>(istream & is, Time & t);
};

