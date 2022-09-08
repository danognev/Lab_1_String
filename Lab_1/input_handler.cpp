#include "input_handler.h"
#include <iostream>

using namespace std;

enum KEYS { Manual = '1', File, Exit };

void InputHandler::MainMenu() {
	char key = cin.get();
	switch (key) {
		case Manual: {
				break;
		}
		case File: {
			break;
		}
		case Exit: {
			break;
		}
		default: {
			cout << "Некорректный ввод! Попробуйте ещё раз." << endl;
			cin.ignore();
			cin.clear();
			MainMenu();
			break;
		}
	}
}