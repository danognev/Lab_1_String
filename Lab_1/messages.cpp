#include "messages.h"
#include "input_handler.h"
#include <iostream>

using namespace std;

void Messages::MainMenu() {
	cout << "\nЧто вы хотите сделать далее?\n1. Ввести текст с клавиатуры\n2. Загрузить из файла\n3. Выйти из программы" << endl;
	InputHandler::MainMenu();
}