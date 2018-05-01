#include <string>
#include <iostream>
#include "checkbox.h"
#include <Windows.h>
#include <stdio.h>

using namespace std;
int main(int argc, char** argv) {

	HANDLE in = GetStdHandle(STD_INPUT_HANDLE);
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	INPUT_RECORD ir;
	DWORD count = ENABLE_EXTENDED_FLAGS | ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT;
	CONSOLE_SCREEN_BUFFER_INFO info;
	DWORD charnum2;
	bool checked = false;
	CHAR* buf2 = new CHAR[0];
	checkbox ChkBox1({ 2,2 }, 1," option 1");
	checkbox ChkBox2({ 2,5 }, 1, " option 2 (failed to listen) ");
	
	//ChkBox1.draw();
	//ChkBox2.draw(); 
	if (!SetConsoleMode(in, count))
		return -1;
		

	while (1) {
		ReadConsoleInput(in, &ir, 1, &count);
		switch (ir.EventType) {
		case KEY_EVENT:
			break;
		case MOUSE_EVENT:
			if (ir.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED)
				if ((ir.Event.MouseEvent.dwMousePosition.X >= ChkBox1.getPosition().X && ir.Event.MouseEvent.dwMousePosition.X < ChkBox1.getPosition().X + ChkBox1.getl()) &&
					(ir.Event.MouseEvent.dwMousePosition.Y == ChkBox1.getPosition().Y))
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
					SetConsoleCursorPosition(out, { ChkBox1.getPosition().X , ChkBox1.getPosition().Y });
				}
				else {
					SetConsoleCursorPosition(out, COORD());
				}
		}
	}





}