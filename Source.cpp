#include "Header.h"

void main()
{
	srand(time(NULL));
	int k = 1;
	char en = 0;
	Time t1;
	Time t2;
	Time t3;
	bool res;

	do
	{
		cout << endl;
		if (en == 80)
		{
			k++;
			if (k == 4)
				k = 1;
		}
		if (en == 72)
		{
			k--;
			if (k == 0)
				k = 3;
		}
		if (en == 13)
		{
			system("cls");
			if (k == 1)
			{

				bool key_1;
				do
				{
					system("cls");

					cout << " Choose action: '+'; '-'; '*'; '/'; '%'" << endl << endl;
					char key;
					cout << endl;
					cin >> key;
					cout << endl;
					system("cls");
					switch (key)
					{
					case '+':
					{
						cin >> t1;
						system("cls");
						cin >> t2;
						t3 = t1 + t2;
						system("cls");
						cout << t3;

					}

					break;

					case '-':
					{
						cin >> t1;
						system("cls");
						cin >> t2;
						t3 = t1 - t2;
						system("cls");
						cout << t3;
					}


					break;

					case '*':
					{
						int n;
						cin >> t1;
						system("cls");
						cout << "Enter the number" << endl;
						cin >> n;
						t3 = t1 * n;
						system("cls");
						cout << t3;
					}

					break;

					case '/':
					{
						int n;
						cin >> t1;
						system("cls");
						cout << "Enter the number" << endl;
						cin >> n;
						t3 = t1 / n;
						system("cls");
						cout << t3;
					}
					break;
					case '%':
					{
						int n;
						cin >> t1;
						system("cls");
						cout << "Enter the percentage" << endl;
						cin >> n;
						t3 = t1 % n;
						system("cls");
						cout << t3;
					}
					break;
					}

					cout << "  " << endl;
					cout << "Continue? 1 - yes, 0 - no" << endl;
					cout << endl;
					cin >> key_1;
				} while (key_1);

			}
			system("cls");
			if (k == 2)
			{
				short key_1;
				do
				{
					system("cls");

					cout << " Choose action: 1: '>'; 2: '<'; 3: '=='; 4: '!='" << endl << endl;
					short key;
					cout << endl;
					cin >> key;
					cout << endl;
					system("cls");
					switch (key)
					{
					case 1:
					{
						cin >> t1;
						system("cls");
						cin >> t2;
						res = (t1 > t2);
						system("cls");
						t1.Print_time_bool(res);

					}

					break;

					case 2:
					{
						cin >> t1;
						system("cls");
						cin >> t2;
						res = (t1 < t2);
						system("cls");
						t1.Print_time_bool(res);
					}


					break;

					case 3:
					{
						cin >> t1;
						system("cls");
						cin >> t2;
						res = (t1 == t2);
						system("cls");
						t1.Print_time_bool(res);
					}

					break;

					case 4:
					{
						cin >> t1;
						system("cls");
						cin >> t2;
						res = (t1 != t2);
						system("cls");
						t1.Print_time_bool(res);
					}
					break;
					}

					cout << "  " << endl;
					cout << "Continue? 1 - yes, 0 - no" << endl;
					cout << endl;
					cin >> key_1;
				} while (key_1);


			}

			system("cls");
			if (k == 3)
			{
				short key_1;
				do
				{
					system("cls");

					cout << " Choose action: 1 - timer goes forward; 2 - timer goes back " << endl << endl;
					short key;
					cout << endl;
					cin >> key;
					cout << endl;
					system("cls");
					switch (key)
					{
					case 1:
					{
						cin >> t1;
						system("cls");
						while (!_kbhit())
						{
							cout << "Press any button to stop" << endl << endl;
							t1++;
							Time::Type_time(t1);
							cout << t1;
							Sleep(1000);
							system("cls");
						}

					}

					break;

					case 2:
					{
						cin >> t1;
						system("cls");
						while (!_kbhit())
						{
							cout << "Press any button to stop" << endl << endl;
							t1--;
							Time::Type_time(t1);
							cout << t1;
							Sleep(1000);
							system("cls");
						}
					}


					break;

					}

					cout << "  " << endl;
					cout << "Continue? 1 - yes, 0 - no" << endl;
					cout << endl;
					cin >> key_1;
				} while (key_1);
				system("cls");
			}


		}
		gotoxy(28, 0);
		SetColor(11);
		cout << "Menu";
		SetColor(7);
		if (k == 1)
			SetColor(13);
		gotoxy(15, 2);
		cout << "1. Arithmetic operations" << endl;
		SetColor(7);

		if (k == 2)
			SetColor(13);
		gotoxy(15, 3);
		cout << "2. Logical operations " << endl;
		SetColor(7);
		if (k == 3)
			SetColor(13);
		gotoxy(15, 4);
		cout << "3. Unary operations " << endl;
		SetColor(7);

	} while (en = _getch());

}