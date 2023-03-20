#include "messages.h"
#include "input_handler.h"
#include <iostream>

using namespace std;

void Messages::MainMenu() {
	cout << "\nЧто вы хотите сделать далее?\n1. Ввести текст с клавиатуры\n2. Загрузить из файла\n3. Выйти из программы" << endl;
	InputHandler::MainMenu();
}
void Messages::NeedToSaveText(std::string text) {
	cout << "\n\nХотите сохранить " << text << " текст в файл?\n1. Да\n2. Нет" << endl;
	InputHandler::NeedToSaveText(text);
}
void Messages::FileExists() {
	cout << "\nФайл по такому пути уже существует. Хотите перезаписать?\n1. Да\n2. Нет" << endl;
	InputHandler::FileExists();
}