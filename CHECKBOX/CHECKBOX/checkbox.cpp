#include "checkbox.h"
#include <iostream>

checkbox::checkbox(COORD p, short l, string s) {
	this->l = l;
	this->pos = p;
	this->txt = s;

	draw();
	
}


COORD checkbox::getPosition() { return this->pos; };

void checkbox::draw() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(out, &info);
	SetConsoleCursorPosition(out, { this->pos.X - 2 ,this->pos.Y - 1 });
		cout << '\xDA'; // leftv top corner
	for (int i = 0; i < 3; i++)
		cout << '\xC4'; // ver line
	cout << '\xBF'; //right top corner
	SetConsoleCursorPosition(out, { this->pos.X - 2,this->pos.Y  });
	cout << '\xB3'; // hor line
	for (int i = 0; i < 3; i++)
		cout << ' ';
	cout << '\xB3'; // hor line
	cout << this->txt;
	SetConsoleCursorPosition(out, { this->pos.X - 2,this->pos.Y + 1 });
	cout << '\xC0'; // left bot corner
	for (int i = 0; i < 3; i++)
		cout << '\xC4'; // ver line
	cout << '\xD9'; // right bot corner

	SetConsoleTextAttribute(out, info.wAttributes);

	SetConsoleCursorPosition(out, info.dwCursorPosition);
}
/*
void checkbox::listen() {   // <<-- this was a test to make a listener for each inside a object but looks like we need threads and we have no time
	while (1) {
		ReadConsoleInput(in, &ir, 1, &count);
		switch (ir.EventType) {
		case KEY_EVENT:
			break;
		case MOUSE_EVENT:
			if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				if ((ir.Event.MouseEvent.dwMousePosition.X >= getPosition().X && ir.Event.MouseEvent.dwMousePosition.X < getPosition().X + getl()) &&
					(ir.Event.MouseEvent.dwMousePosition.Y == getPosition().Y))
				{
					SetConsoleCursorPosition(out, { ir.Event.MouseEvent.dwMousePosition.X,ir.Event.MouseEvent.dwMousePosition.Y });
					ReadConsoleOutputCharacter(out, buf2, 2, ir.Event.MouseEvent.dwMousePosition, &charnum2);
					if (buf2[0] != '\xCE') {
						cout << '\xCE';
						checked = true;
					}
					else if (buf2[0] == '\xCE') {
						cout << "  ";
						checked = false;
					}

					SetConsoleCursorPosition(out, { ir.Event.MouseEvent.dwMousePosition.X,ir.Event.MouseEvent.dwMousePosition.Y });
					SetConsoleCursorPosition(out, { getPosition().X , getPosition().Y });
				}
				else {
					SetConsoleCursorPosition(out, COORD());
				}
		}
	}
}*/ 