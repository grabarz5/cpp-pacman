#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

#define CLOCK 128

using namespace std;

//deklaracje funkcji
void consoleConfig();
void draw(int x, int y);
void moveUp();
void moveDown();
void moveLeft();
void moveRight();
int getDirection();

//deklaracje zmiennych globalnych
/**
 * # - 35
 * . - 46
 * * - 42
 */
char MAP[21][22] = {
	{32,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
	{32,35,46,46,46,46,46,46,46,46,35,46,46,46,46,46,46,46,46,35},
	{32,35,42,35,35,46,35,35,35,46,35,46,35,35,35,46,35,35,42,35},
	{32,35,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,35},
	{32,35,46,35,35,46,35,46,35,35,35,35,35,46,35,46,35,35,46,35},
	{32,35,46,46,46,46,35,46,46,46,35,46,46,46,35,46,46,46,46,35},
	{32,35,35,35,35,46,35,35,35,46,35,46,35,35,35,46,35,35,35,35},
	{32,32,32,32,35,46,35,46,46,46,46,46,46,46,35,46,35,32,32,32},
	{32,35,35,35,35,46,35,46,35,35,32,35,35,46,35,46,35,35,35,35},
	{32,46,46,46,46,46,46,46,35,32,32,32,35,46,46,46,46,46,46,46},
	{32,35,35,35,35,46,35,46,35,35,35,35,35,46,35,46,35,35,35,35},
	{32,32,32,32,35,46,35,46,46,46,46,46,46,46,35,46,35,32,32,32},
	{32,35,35,35,35,46,35,46,35,35,35,35,35,46,35,46,35,35,35,35},
	{32,35,46,46,46,46,46,46,46,46,35,46,46,46,46,46,46,46,46,35},
	{32,35,46,35,35,46,35,35,35,46,35,46,35,35,35,46,35,35,46,35},
	{32,35,46,46,35,46,46,46,46,46,46,46,46,46,46,46,35,46,46,35},
	{32,35,35,46,35,46,35,46,35,35,35,35,35,46,35,46,35,46,35,35},
	{32,35,46,46,46,46,35,46,46,46,35,46,46,46,35,46,46,46,46,35},
	{32,35,46,35,35,35,35,35,35,46,35,46,35,35,35,35,35,35,46,35},
	{32,35,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,46,35},
	{32,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35,35},
};
int PACMAN_X = 10;
int PACMAN_Y = 15;
int SCORE = 0;

int main(){
	consoleConfig();

	while (1) {
		cout << " SCORE: " << SCORE << endl << endl;
		/*switch (getDirection()) {
		case 1:
			if (MAP[PACMAN_X][PACMAN_Y - 1] != 35) {
				if (PACMAN_Y > 1) {
					PACMAN_Y -= 1;
					if (MAP[PACMAN_X][PACMAN_Y - 1] == 46) {
						MAP[PACMAN_X][PACMAN_Y - 1] = 32;
						SCORE += 10;
					}
				}
			}
			break;
		case 2:
			if (MAP[PACMAN_X + 1][PACMAN_Y] != 35) {
				if (PACMAN_X < 18) PACMAN_X += 1;
			}
			break;
		case 3:
			if (MAP[PACMAN_X][PACMAN_Y + 1] != 35) {
				if (PACMAN_Y < 19) PACMAN_Y += 1;
			}
			break;
		case 4:
			if (MAP[PACMAN_X - 1][PACMAN_Y] != 35) {
				if (PACMAN_X > 1) PACMAN_X -= 1;
			}
			break;
		}*/
		switch (getDirection()) {
		case 1:
			moveUp();
			break;
		case 2:
			moveRight();
			break;
		case 3:
			moveDown();
			break;
		case 4:
			moveLeft();
			break;
		}
		draw(PACMAN_X, PACMAN_Y);
		cout << endl << " X: " << PACMAN_X << "\tY: " << PACMAN_Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD {0,0});
		Sleep(CLOCK);
	}
}

void moveUp() {
	if (MAP[PACMAN_X][(PACMAN_Y - 1)] != 35) {
		--PACMAN_Y;
		if (MAP[PACMAN_X][(PACMAN_Y - 1)] == 46) {
			SCORE += 10;
			MAP[PACMAN_X][(PACMAN_Y - 1)] = 32;
		}
	}
}

void moveDown() {
	if (MAP[PACMAN_X][(PACMAN_Y + 1)] != 35) {
		++PACMAN_Y;
		if (MAP[PACMAN_X][(PACMAN_Y + 1)] == 46) {
			SCORE += 10;
			MAP[PACMAN_X][(PACMAN_Y + 1)] = 32;
		}
	}
}

void moveLeft() {
	if (MAP[(PACMAN_X-1)][PACMAN_Y] != 35) {
		--PACMAN_X;
		if (MAP[(PACMAN_X - 1)][PACMAN_Y] == 46) {
			SCORE += 10;
			MAP[(PACMAN_X - 1)][PACMAN_Y] = 32;
		}
	}
}

void moveRight() {
	if (MAP[(PACMAN_X + 1)][PACMAN_Y] != 35) {
		++PACMAN_X;
		if (MAP[(PACMAN_X + 1)][PACMAN_Y]== 46) {
			SCORE += 10;
			MAP[(PACMAN_X + 1)][PACMAN_Y] = 32;
		}
	}
}

int getDirection() {
	if (GetAsyncKeyState(VK_UP)) {
		return 1;
	}
	else if (GetAsyncKeyState(VK_RIGHT)) {
		return 2;
	}
	else if (GetAsyncKeyState(VK_DOWN)) {
		return 3;
	}
	else if (GetAsyncKeyState(VK_LEFT)) {
		return 4;
	}
	else {
		return 0;
	}
}

void draw(int x, int y) {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			if (j == x && i == y) {
				cout << "\u001b[33;1m@\u001b[0m";
			}
			else {
				switch (MAP[i][j]) {
				case 35:
					cout << "\u001b[44m \u001b[0m";
					break;
				case 46:
					cout << "\u001b[40m.\u001b[0m";
					break;
				case 42:
					cout << "\u001b[40m*\u001b[0m";
					break;
				case 64:
					cout << "\u001b[33;1m@\u001b[0m";
					break;
				case 32:
				default:
					cout << "\u001b[40m \u001b[0m";
					break;
				}
			}
			//cout << MAP[i][j];
		}
		cout << endl;
	}
}

void consoleConfig() {
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 32;                   // Width of each character in the font
	cfi.dwFontSize.Y = 32;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;

	wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);

	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);
	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 712, 900, TRUE);

	//Hide cursor
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}