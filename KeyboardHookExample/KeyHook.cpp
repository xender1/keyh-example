#include "KeyHook.h"

HHOOK m_keyHook;

KeyHook::KeyHook()
{
	m_keyHook = NULL;
}


KeyHook::~KeyHook()
{
	UnhookWindowsHookEx(m_keyHook);
	m_keyHook = NULL;
}

void KeyHook::Init() {
	m_keyHook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc1, NULL, NULL);
}

void KeyHook::DoIt() {
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK LowLevelKeyboardProc1(int nCode, WPARAM wParam, LPARAM lParam) {

	PKBDLLHOOKSTRUCT keyp = (PKBDLLHOOKSTRUCT)lParam;
	switch (wParam) {
	case WM_KEYUP:
		switch (keyp->vkCode) {
		case 0x70: //f1
			cout << "f1" << endl;
			break;
		case 0x71: //f2
			cout << "f2" << endl;
			break;
		default:
			cout << "other" << endl;
		}
		break;
	case WM_KEYDOWN:
		cout << "down" << endl;
		break;

	default:
		break;
	}
	return CallNextHookEx(m_keyHook, nCode, wParam, lParam); //This is very Important since we tell the Windows
	//that send me the next Message so that we do not cause Error  
}