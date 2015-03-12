// KeyboardHookExample.cpp : Defines the entry point for the console application.
//

#include "Main.h"
#include "KeyHook.h"

void CommandLineInputThread();
void KeyLoggerThread();

int main() 
{
	cout << "hello keyboard" << endl;
	thread blah(CommandLineInputThread);
	thread blah2(KeyLoggerThread);
	cout << "after" << endl;

	//UnhookWindowsHookEx(keyHook);
	getchar(); //stopper
	return 0;
}

void KeyLoggerThread() {
	KeyHook mykey;
	mykey.Init();
	mykey.DoIt();
}

void CommandLineInputThread() {
	while (true) {
	//	cout << "question: ";
	//	string s;
	//	cin >> s;
	//	cout << "hi";
	}
}