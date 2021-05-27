#include<iostream>
#include <windows.h>
#include<time.h>

#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<stdlib.h>

#include<cstdlib>
#include<iomanip>
#include<process.h>
#include<fstream>
void gotoxy(int column, int line);
void delay(int seconds);
void set_color(short int a);
void frame();
//int wherex(); int wherey();
using namespace std;
#define up 72
#define down 80
#define left 75
#define right 77
struct timer
{
int h;
int m;
int s;
}tm;
struct coord{  int i,j, dup;  }c[50];

struct sudoku {int a[9][9]; //ifstream sudo("hardSol.txt");
}
s[3] = { { 9,7,4,2,5,6,8,3,1,1,5,3,4,7,8,6,9,2,2,6,8,9,1,3,4,5,7,3,8,6,7,2,1,9,4,5,5,2,9,6,3,4,1,7,8,7,4,1,5,8,9,3,2,6,6,9,7,8,4,2,5,1,3,4,1,2,3,6,5,7,8,9,8,3,5,1,9,7,2,6,4 },{ 7,1,9,3,8,2,6,4,5,5,3,8,7,6,4,2,9,1,4,6,2,1,9,5,7,8,3,1,9,6,8,3,7,5,2,4,3,2,4,9,5,6,1,7,8,8,7,5,4,2,1,3,6,9,9,5,1,2,7,8,4,3,6,6,8,7,5,4,3,9,1,2,2,4,3,6,1,9,8,5,7 },{ 8,3,4,7,2,9,6,1,5,5,6,1,4,3,8,9,7,2,2,7,9,5,1,6,4,8,3,6,9,3,2,4,1,8,5,7,4,2,7,6,8,5,1,3,9,1,5,8,9,7,3,2,4,6,9,8,2,1,5,7,3,6,4,7,1,6,3,9,4,5,2,8,3,4,5,8,6,2,7,9,1 } };
int k, i, t, j, x, y, con;
int menu()
{
	//system("COLOR GC");
	system("cls");
	char key; int i, x = 11;
	for (i = 1; i>0; i++)
	{
	r:
		cout << i << " " << x;
		system("cls");
		gotoxy(30, 10);
		cout << "SUDOKU"; gotoxy(31, 11);
		if (!(x<11 || x>13))
		{
			if (x == 11)
			{
				cout << "NEW GAME\n"; gotoxy(31, 12);
			}
			else
			{
				cout << "new game\n"; gotoxy(31, 12);
			}
			if (x == 12)
			{
				cout << "INSTRUCTIONS\n"; gotoxy(31, 13);
			}
			else
			{
				cout << "instructions\n"; gotoxy(31, 13);
			}
			if (x == 13)
			{
				cout << "ABOUT\n"; gotoxy(31, 14);
			}
			else
			{
				cout << "about\n"; gotoxy(31, 14);
			}
		}
		else
		{
			if (x<11)
			{
				x++; goto r;
			}
			if (x>13)
			{
				x--; goto r;
			}
		}
		gotoxy(3, 25); cout << "Esc-quit game\t\t" << char(30) << " " << char(31) << "-select option";
		if (i == 1)
		{
			gotoxy(30-1, x); cout << (char)62;
		}
		if (x<11 || x>13)
		{
			if (x<11)
			{
				x++; gotoxy(30-1, x); cout << (char)62;
			}
			if (x>13)
			{
				x--; gotoxy(30-1, x); cout << (char)62;
			}
		}
		else
		{
			gotoxy(30-1, x); cout << (char)62;
		}
		key = _getch(); 
		if (key == 13)
			return x - 10;
		if (key == 27)
			return -1;
	//	if (key == 0)
	//	{
	//		key = _getch();// cout << key << "\n";
			switch (key)
			{
			case up:
			case right:
				i++; x--; goto r;
			case down:
			case left:
				i++; x++; goto r;
			}
		
	}
	return 0;
}
void e1()
{
	for (i = 0; i<9; i++)
		for (j = 0; j<3; j++)
		{
			t = s[k].a[i][j];
			s[k].a[i][j] = s[k].a[i][j + 6];
			s[k].a[i][j + 6] = t;
		}
}
void e2()
{
	for (j = 0; j<9; j++)
		for (i = 0; i<3; i++)
		{
			t = s[k].a[i][j];
			s[k].a[i][j] = s[k].a[i + 6][j];
			s[k].a[i + 6][j] = t;
		}
}
void e3()
{
	for (j = 0; j<9; j++)
		for (i = 3; i<6; i++)
		{
			t = s[k].a[i][j];
			s[k].a[i][j] = s[k].a[i + 3][j];
			s[k].a[i + 3][j] = t;
		}
}
void e4()
{
	for (i = 0; i<9; i++)
		for (j = 3; j<6; j++)
		{
			t = s[k].a[i][j];
			s[k].a[i][j] = s[k].a[i][j + 3];
			s[k].a[i][j + 3] = t;
		}
}
void e5()
{
	for (i = 0; i<9; i++)
	{
		t = s[k].a[i][0]; s[k].a[i][0] = s[k].a[i][2]; s[k].a[i][2] = t;
	}
}
void e6()
{
	for (i = 0; i<9; i++)
	{
		t = s[k].a[i][3]; s[k].a[i][3] = s[k].a[i][5]; s[k].a[i][5] = t;
	}
}
void e7()
{
	for (i = 0; i<9; i++)
	{
		t = s[k].a[i][6]; s[k].a[i][6] = s[k].a[i][8]; s[k].a[i][8] = t;
	}
}
void e8()
{
	for (i = 0; i<9; i++)
	{
		t = s[k].a[i][1]; s[k].a[i][1] = s[k].a[i][2]; s[k].a[i][2] = t;
	}
}
void e9()
{
	for (i = 0; i<9; i++)
	{
		t = s[k].a[i][4]; s[k].a[i][4] = s[k].a[i][5]; s[k].a[i][5] = t;
	}
}
void e10()
{
	for (i = 0; i<9; i++)
	{
		t = s[k].a[i][6]; s[k].a[i][6] = s[k].a[i][7]; s[k].a[i][7] = t;
	}
}
void e11()
{
	for (j = 0; j<9; j++)
	{
		t = s[k].a[0][j]; s[k].a[0][j] = s[k].a[2][j]; s[k].a[2][j] = t;
	}
}
void e12()
{
	for (j = 0; j<9; j++)
	{
		t = s[k].a[3][j]; s[k].a[3][j] = s[k].a[5][j]; s[k].a[5][j] = t;
	}
}
void e13()
{
	for (j = 0; j<9; j++)
	{
		t = s[k].a[6][j]; s[k].a[6][j] = s[k].a[8][j]; s[k].a[8][j] = t;
	}
}
void e14()
{
	for (j = 0; j<9; j++)
	{
		t = s[k].a[0][j]; s[k].a[0][j] = s[k].a[1][j]; s[k].a[1][j] = t;
	}
}
void e15()
{
	for (j = 0; j<9; j++)
	{
		t = s[k].a[3][j]; s[k].a[3][j] = s[k].a[4][j]; s[k].a[4][j] = t;
	}
}
void e16()
{
	for (j = 0; j<9; j++)
	{
		t = s[k].a[7][j]; s[k].a[7][j] = s[k].a[8][j]; s[k].a[8][j] = t;
	}
}
void about()
{
	gotoxy(25, 11); cout << "Developed by  :AKHIL MOHAN";
	gotoxy(25, 10); cout << "Title         :SUDOKU";
	gotoxy(25, 12); cout << "Special Thanks:JUSTINE CYRIAC";
	gotoxy(40, 13); cout << "DEPT. OF COMP.SCIENCE,SAPS,ANAKKAL";
	_getch();
}
void secmn()
{
	set_color(7); system("cls");   int op;
	for (int h = 0; h<45; h++)
		c[h].dup = 0;
	void playgame(); int escape(); void instruction();
	void frame(); void printer(); void obtcord(); obtcord();
//	randomize();
//	k = random(3);
	k=rand() % 3;
	frame();
	switch (k)
	{
	case 0:
		e1(); e12(); e4(); e14(); break;
	case 2:
		e3(); e9(); e6(); e5(); e11(); e16(); break;
	case 1:
		e1(); e3(); e5(); e12(); e10(); e13(); break;
	}
	e2();
	do
	{
		set_color(7); system("cls");
		op = menu();
		system("cls");
		switch (op)
		{
		case 1:
			frame(); printer(); playgame();
			break;
		case 2:
			instruction();
			break;
		case -1:
			op = escape();
			if (op == -1)
				exit(0);
			break;
		case 3:
			about(); break;
		}
	} while (op != -1);
}
int escape()
{
	//_getch();
	set_color(4);
	system("cls");
	gotoxy(20, 12); cout << "ARE YOU SURE YOU WANT TO EXIT(Y/N):"; char ex = _getch();
	if (ex == 'Y' || ex == 'y')
	{
		cout << "Y"; system("cls"); gotoxy(20, 12); cout << "THANK YOU FOR PLAYING THE GAME";
		delay(3); return -1;
	}
	else
	{
		cout << "N"; return 1;
	}
	_getch();
}
void instruction()
{
	cout << "The objective of the game is to fill all the blank squares in a game with the \ncorrect numbers. There are three very simple constraints to follow. In a 9 by 9 square Sudoku game:\n";
	cout << char(249) << "Every row of 9 numbers must include all digits from 1 to 9 in any order\n";
	cout << char(249) << "Every column of 9 numbers must include all digits from 1 to 9 in any order\n";
	cout << char(249) << "Every 3 by 3 subsection of the 9 by 9 square must include all digits from \n1 to 9\n";
	cout << "Every Sudoku games begins with a number of squares already filled in, and the \ndifficulty of each game is largely a function of how many squares are filled in. The more squares that are known, the easier it is to figure out which numbers\ngo in the open squares. As you fill in squares correctly, options for the \nremaining squares are narrowed and it becomes easier to fill them in.\n";
	cout << "\n\nYou can navigate through the boxes in the game by using the arrow keys.To clear a field press '0'.Press 'S' while playing the game to solve the puzzle.To check whether the puzzle is correct press 'ENTER'.\n";
	cout << "\t\t\t" << char(30) << "\n\t\t       " << char(17) << " " << char(16) << "\n\t\t\t" << char(31);
	gotoxy(2, 25); cout << "Esc-RETURN"; _getch();
}
void designer()
{
	for (int f = 0; f<6; f++)
	{
		switch (f)
		{
		case 0:
			set_color(7); system("cls");  gotoxy(35, 12);
			cout << "S"; delay(1); break;
		case 1:
			set_color(4);; system("cls");    gotoxy(35, 12);
			cout << "SU"; delay(1); break;
		case 2:
			set_color(1); system("cls");  gotoxy(35, 12);
			cout << "SUD"; delay(1); break;
		case 3:
			set_color(2); system("cls"); gotoxy(35, 12);
			cout << "SUD" << char(153); delay(1); break;
		case 4:
			set_color(8); system("cls");  gotoxy(35, 12);
			cout << "SUD" << char(153) << "K"; delay(1); break;
		case 5:
			set_color(6); system("cls"); gotoxy(35, 12);
			cout << "SUD" << char(153) << "KU"; delay(1); break;
		}
	}
	for (int f = 0; f<12; f++)
	{
		switch (f)
		{
		case 0:
			set_color(6); system("cls"); break;
		case 1:
			set_color(8); system("cls"); break;
		case 2:
			set_color(7); system("cls"); break;
		case 3:
			set_color(2); system("cls"); break;
		case 4:
			set_color(1); system("cls"); break;
		case 5:
			set_color(4); system("cls"); break;
		case 6:
			set_color(6); system("cls"); break;
		case 7:
			set_color(8); system("cls"); break;
		case 8:
			set_color(7); system("cls"); break;
		case 9:
			set_color(2); system("cls"); break;
		case 10:
			set_color(1); system("cls"); break;
		case 11:
			set_color(4); system("cls"); break;
		}
		gotoxy(35, 12);
		cout << "SUD" << char(153) << "KU"; delay(1);
	}
	// gotoxy(30,12);
	// cout<<"DEVELOPED BY ";delay(750);
}

int main()
{
	//designer();////
	secmn();
	
}
void printer()         //check printer obcord and found once more ..logical error
{
	int extraprint(int, int);
	for (i = 0, x = 7; i<9; i++, x += 2)
		for (j = 0, y = 21; j<9; j++, y += 3)
		{
			gotoxy(y, x);
			if (extraprint(i, j) == 1)
				cout << s[k].a[i][j];
			else
				continue;
		}
	for (int q = 1; q<26; q++)
	{
		gotoxy(65, q); cout << char(186);
	}
	gotoxy(66, 4); cout << "S-solve";
	gotoxy(66, 6); cout << "Esc-return";
	gotoxy(66, 8); cout << "Enter-check";
	gotoxy(66, 10); cout << "Starting time:"; //cout << CLOCKS_PER_SEC;
}
void frame()
{
	int x;
	system("cls"); gotoxy(20, 6);
	cout << char(201);
	for (int i = 0; i<2; i++)
		cout << char(205) << (char)205 << char(209);
	cout << char(205) << char(205) << char(203);
	for (i = 0; i<2; i++)
		cout << char(205) << (char)205 << char(209);
	cout << char(205) << char(205) << char(203);
	for (i = 0; i<2; i++)
		cout << char(205) << (char)205 << char(209);
	cout << char(205) << char(205) << char(187);
	gotoxy(20, 7);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	for (i = 0; i<2; i++)
		cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 8);
	cout << char(199) << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(182);
	gotoxy(20, 9);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 10);
	cout << char(199) << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(182);
	gotoxy(20, 11);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 12);
	cout << char(204) << char(205) << char(205) << char(216) << char(205) << char(205) << char(216) << char(205) << char(205) << char(206);
	cout << char(205) << char(205) << char(216) << char(205) << char(205) << char(216) << char(205) << char(205) << char(206);
	cout << char(205) << char(205) << char(216) << char(205) << char(205) << char(216) << char(205) << char(205) << char(185);
	gotoxy(20, 13);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 14);
	cout << char(199) << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(182);
	gotoxy(20, 15);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 16);
	cout << char(199) << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(182);
	gotoxy(20, 17);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 18);
	cout << char(204) << char(205) << char(205) << char(216) << char(205) << char(205) << char(216) << char(205) << char(205) << char(206);
	cout << char(205) << char(205) << char(216) << char(205) << char(205) << char(216) << char(205) << char(205) << char(206);
	cout << char(205) << char(205) << char(216) << char(205) << char(205) << char(216) << char(205) << char(205) << char(185);
	gotoxy(20, 19);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 20);
	cout << char(199) << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(182);
	gotoxy(20, 21);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 22);
	cout << char(199) << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(215);
	cout << char(196) << char(196) << char(197) << char(196) << char(196) << char(197) << char(196) << char(196) << char(182);
	gotoxy(20, 23);
	cout << char(186) << "  " << char(179) << "  " << char(179) << "  " << char(186);
	cout << "  " << char(179) << "  " << char(179) << "  " << char(186); cout << "  " << char(179) << "  " << char(179) << "  " << char(186);
	gotoxy(20, 24);
	cout << char(200) << char(205) << char(205) << char(207);
	cout << char(205) << char(205) << char(207) << char(205) << char(205) << char(202);
	cout << char(205) << char(205) << char(207);
	cout << char(205) << char(205) << char(207) << char(205) << char(205) << char(202);
	cout << char(205) << char(205) << char(207);
	cout << char(205) << char(205) << char(207) << char(205) << char(205) << char(188);
}
void obtcord()
{
	int fl = 0, g1, g2;// , g; ///////////////////////////////
	unsigned int seedval; time_t t;
	seedval = (unsigned)time(&t); srand(seedval);
	int found(int, int, int);
	for (i = 0; i<9; i++)
		for (j = 0; j<9; j++)
		{
			if (s[k].a[i][j] == 1 || s[k].a[i][j] == 2 || s[k].a[i][j] == 7)
			{
				c[fl].i = i; c[fl].j = j; fl++;
			}
		}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	g1 = rand(); g1 %= 9;
	g2 = rand(); g2 %= 9;
	if (found(g1, g2, fl) == 1)
	{
		c[fl].i = g1; c[fl].j = g2; fl++;
	}
	c[fl].i = -1; c[fl].j = -1;

}
int pass()
{
	int qc = 1;
	for (int me = 0; c[me].i != -1; me++)
	{
		if (c[me].dup == 0)
		{
			qc = 0; break;
		}
	}
	return qc;
}
int found(int a, int b, int co)
{
	for (int fl = 0; fl<co; fl++)
		if (c[fl].i == a&&c[fl].j == b)
			return 0;
	return 1;
}
int extraprint(int r, int co)
{
	int fl = 0;
	for (; fl<50; fl++)
	{
		if (c[fl].i == r&&c[fl].j == co)
		{
			if (c[fl].dup == 0)
				return 0;
			else
			{
				cout << c[fl].dup; return 0;
			}
		}
	}
	return 1;
}
void playgame()
{
	int cord(int, int); void check(); void solve(); void error();
	char key; int xp = 7, yp = 21, g;
	do
	{
		gotoxy(yp, xp);
		key = _getch();
		if (key == 27)
			secmn();
		else
			if (key==13)
				check();
			else
				if (key == '0')
				{
					g = cord(xp, yp);
					if (g == -1)
						error();
					else
					{
						c[g].dup = 0; system("cls"); frame(); printer();
					}
				}
				else
					if (key == '1')
					{
						g = cord(xp, yp);
						if (g == -1)
							error();
						else
						{
							c[g].dup = 1; system("cls"); frame(); printer();
						}
					}
					else
						if (key == '2')
						{
							g = cord(xp, yp);
							if (g == -1)
								error();
							else
							{
								c[g].dup = 2; system("cls"); frame(); printer();
							}
						}
						else
							if (key == '3')
							{
								g = cord(xp, yp);
								if (g == -1)
									error();
								else
								{
									c[g].dup = 3; system("cls"); frame(); printer();
								}
							}
							else
								if (key == '4')
								{
									g = cord(xp, yp);
									if (g == -1)
										error();
									else
									{
										c[g].dup = 4; system("cls"); frame(); printer();
									}
								}
								else
									if (key == '5')
									{
										g = cord(xp, yp);
										if (g == -1)
											error();
										else
										{
											c[g].dup = 5; system("cls"); frame(); printer();
										}
									}
									else
										if (key == '6')
										{
											g = cord(xp, yp);
											if (g == -1)
												error();
											else
											{
												c[g].dup = 6; system("cls"); frame(); printer();
											}
										}
										else
											if (key == '7')
											{
												g = cord(xp, yp);
												if (g == -1)
													error();
												else
												{
													c[g].dup = 7; system("cls"); frame(); printer();
												}
											}
											else
												if (key == '8')
												{
													g = cord(xp, yp);
													if (g == -1)
														error();
													else
													{
														c[g].dup = 8; system("cls"); frame(); printer();
													}
												}
												else
													if (key == '9')
													{
														g = cord(xp, yp);
														if (g == -1)
															error();
														else
														{
															c[g].dup = 9; system("cls"); frame(); printer();
														}
													}
													else
													///	if (key == 0)
													//	{
													//		key = _getch();
															switch (key)
															{
															case up:
																xp -= 2; break;
															case down:
																xp += 2; break;
															case left:
																yp -= 3; break;
															case right:
																yp += 3; break;
															}
															if ((xp<7 || xp>23) || (yp<21 || yp>45))
															{
																if (xp<7)
																	xp += 2;
																if (xp>23)
																	xp -= 2;
																if (yp<21)
																	yp += 3;
																if (yp>45)
																	yp -= 3;
															}
													//	}
														else
															if (key == 'S' || key == 's')
																solve();


	} while (key != 27);
}
void error()
{
	cout << "\a";// sound(1500);delay(500);nosound();
}
int cord(int r, int co)
{
	int i, j, k, l, g;
	for (i = 0, k = 7; i<9; i++, k += 2)
		for (j = 0, l = 21; j<9; j++, l += 3)
			if (k == r&&l == co)
			{
				for (g = 0; g<50; g++)
					if (c[g].i == i&&c[g].j == j)
						return g;
				return -1;
			}
	return 0;
}
void solve()
{
	//_getch();
	system("cls"); int x, y; frame();
	for (i = 0, x = 7; i<9; i++, x += 2)
		for (j = 0, y = 21; j<9; j++, y += 3)
		{
			gotoxy(y, x); cout << s[k].a[i][j];
		}
	_getch();
	secmn();
}
void check()
{
	int checker = 0;
	for (int h = 0; h<43; h++)
	{
		if (c[h].dup != 0)
		{
			if (s[k].a[c[h].i][c[h].j] == c[h].dup)
			{
				checker = 0; continue;
			}
			else
			{
				checker = -1; break;
			}
		}
		else
			checker = 1;
	}

	if (checker == -1)
	{
		set_color(4); system("cls"); frame(); printer(); gotoxy(2, 14); cout << "\aWrong"; delay(3);
		set_color(7); system("cls"); frame(); printer(); playgame();
	}
	if (pass() == 1 && checker == 1)       //not working properly
	{
		set_color(2); system("cls"); gotoxy(25, 10); cout << "CONGRATULATIONS"; gotoxy(25, 12);
		cout << "YOU HAVE WON THE SUDOKU GAME"; delay(3); set_color(7); system("cls"); secmn();
	}
	else
		if (checker == 1)
		{
			set_color(2); system("cls"); frame(); printer(); gotoxy(2, 14);
			cout << "Go on..You"; gotoxy(2, 15); cout << "are in the correct";
			gotoxy(2, 16); cout << "path"; delay(2); set_color(7); system("cls");
			frame(); printer(); playgame();
		}
}
/*void delay(int a )
{
	delay(a * 1000);
	
}
*/
void delay(int seconds)
{
	clock_t enddelay;
	enddelay = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < enddelay) {}
}

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

int wherex()
{
	//int *X = NULL;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
		return -1;
	return csbi.dwCursorPosition.X;
	//return result.X;
}

int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD  result;
	if (!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
		return -1;
	return csbi.dwCursorPosition.Y;
	//return result.Y;

}
void set_color(short int a)
{

	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, a);
}
/*Color Codes:
0 = Black
1 = Blue
2 = Green
3 = Aqua
4 = Red
5 = Purple
6 = Yellow
7 = White
8 = Gray
9 = Light Blue
A = Light Green
B = Light Aqua
C = Light Red
D = Light Purple
E = Light Yellow
F = Bright White*/