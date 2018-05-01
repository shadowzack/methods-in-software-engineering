#pragma once

#include <windows.h>
#include <string>

using namespace std;

class checkbox {
private :
	COORD pos;  // Defines the coordinates of a character cell in a console screen buffer.The origin of the coordinate system(0, 0) is at the top, left cell of the buffer.
	short l; //length
	string txt; // text fallows the checkbox
	HANDLE in;
	HANDLE out;
	INPUT_RECORD ir;
	DWORD count;
	CONSOLE_SCREEN_BUFFER_INFO info;
	DWORD charnum2;
	bool checked ;
	CHAR* buf2;
public : 
	checkbox(COORD p, short l, string s);
	// constructor wich p=where the checkbox is located , l is the length

	void draw();

	inline short getl() { return this->l; };
	void listen();

	COORD getPosition();
};