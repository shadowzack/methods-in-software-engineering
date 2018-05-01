
#include "TextBox.h"
#include <stdio.h>
#include <conio.h>
//draw the TextBox
void textbox::drawTextBox() {
	setPosition(20, 20);
	SetConsoleCursorPosition(output, this->position);
	cout << "\xDA";//|-
	for (int i = 0; i < MAX_SIZE ; i++)
		cout << "\xC4";//-

	cout << "\xBF";//-|

	setPosition(20, 21);
	SetConsoleCursorPosition(output, this->position);				
	cout << "\xB3";//|

	setPosition(20, 22);
	SetConsoleCursorPosition(output, this->position);				
	cout << "\xC0";//|_

	for (int i = 0; i < MAX_SIZE; i++)
		cout << "\xC4";//-

	cout << "\xD9";//_|

	setPosition(20 + MAX_SIZE+1, 21);
	SetConsoleCursorPosition(output, this->position);				
	cout << "\xB3";//|

	setPosition(21, 21);
	SetConsoleCursorPosition(output, this->position);						
}
//make sure the text wont cross boundries
void textbox::handleUserInput() 
{
	DWORD num;
	COORD lastpostion;
	for (;;)
	{
		ReadConsoleInput(input, &inputRecord, 1, &num);
		if (inputRecord.EventType != KEY_EVENT) 
			continue;				
		if (!inputRecord.Event.KeyEvent.bKeyDown) 
			continue;				

		GetConsoleScreenBufferInfo(output, &screenInfo);					
		if (screenInfo.dwCursorPosition.X <= (21 + this->MAX_SIZE) && screenInfo.dwCursorPosition.X > 20) {
		
			/*
			if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_LEFT)
			{
				//left arrowkey
				SetConsoleCursorPosition(output, { screenInfo.dwCursorPosition.X - 1, 21 });
			}
			else if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_RIGHT)
			{
				//right arrowkey
				SetConsoleCursorPosition(output, { screenInfo.dwCursorPosition.X +1, 21 });
			}*/
			 if (inputRecord.Event.KeyEvent.wVirtualKeyCode == VK_BACK)
			{		
				//backspace
				GetConsoleScreenBufferInfo(output, &screenInfo);			
				if (screenInfo.dwCursorPosition.X == 21)
					continue;
				if (screenInfo.dwCursorPosition.X != 20) {				
					SetConsoleCursorPosition(output, { screenInfo.dwCursorPosition.X, 21 });
					cout << '\x08' << '\x0';			
					SetConsoleCursorPosition(output, { screenInfo.dwCursorPosition.X - 1, 21 });	
				}
			}
			 else if (screenInfo.dwCursorPosition.X < (21 + this->MAX_SIZE))
			 {
				 
				 lastpostion =  { screenInfo.dwCursorPosition.X ,21};
				 cout << inputRecord.Event.KeyEvent.uChar.AsciiChar;
				 
			 }
		}
		else
		{
			SetConsoleCursorPosition(output, lastpostion);
		}
	}
	
}
//send postion of cursor
void textbox::setPosition(int x, int y)
{
	this->position.X = x;
	this->position.Y = y;
}

