#include "messages.h"
#include "input_handler.h"
#include <iostream>

using namespace std;

void Messages::MainMenu() {
	cout << "\n��� �� ������ ������� �����?\n1. ������ ����� � ����������\n2. ��������� �� �����\n3. ����� �� ���������" << endl;
	InputHandler::MainMenu();
}
void Messages::NeedToSaveText(std::string text) {
	cout << "\n\n������ ��������� " << text << " ����� � ����?\n1. ��\n2. ���" << endl;
	InputHandler::NeedToSaveText(text);
}
void Messages::FileExists() {
	cout << "\n���� �� ������ ���� ��� ����������. ������ ������������?\n1. ��\n2. ���" << endl;
	InputHandler::FileExists();
}