#pragma once
#ifndef _TEXTBOX_
#define _TEXTBOX_

#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>

using namespace std;
class textbox
{
public:
	textbox();
	~textbox();
	void drawTextBox();
	void handleUserInput();
	//setters
	void setPosition(int x, int y);
private:
	COORD position;
	DWORD backgorund, foreground;
	HANDLE output, input;
	CONSOLE_SCREEN_BUFFER_INFO screenInfo;
	INPUT_RECORD inputRecord;
	int MAX_SIZE;
};

inline textbox::textbox()
{
	this->position.X = 20;
	this->position.Y = 20;
	this->output = GetStdHandle(STD_OUTPUT_HANDLE);
	this->input = GetStdHandle(STD_INPUT_HANDLE);
	this->MAX_SIZE = 40;
	drawTextBox();
	handleUserInput();
}

inline textbox::~textbox()
{
}

#endif _TEXTBOX_