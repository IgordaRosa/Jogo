//////////////////////////////////////////////////////////////////////////
#ifndef MENU
#define MENU

#include "Window.h"
#include "Engine.h"

//////////////////////////////////////////////////////////////////////////
class Menu
{
private:
	static Window* & window;

	bool cursor;
	bool apertouEnter;

public:
	Menu();
	~Menu();
	void KeyInteract();

};

//////////////////////////////////////////////////////////////////////////

#endif