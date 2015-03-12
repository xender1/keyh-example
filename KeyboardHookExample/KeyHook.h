#pragma once

#include "Main.h"

LRESULT CALLBACK LowLevelKeyboardProc1(int nCode, WPARAM wParam, LPARAM lParam);

class KeyHook
{
public:
	KeyHook();
	~KeyHook();

	void		Init();
	void		DoIt();
};

