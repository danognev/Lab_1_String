#include "messages.h"
#include "input_handler.h"
#include <iostream>

using namespace std;

void Messages::MainMenu() {
	cout << "\n��� �� ������ ������� �����?\n1. ������ ����� � ����������\n2. ��������� �� �����\n3. ����� �� ���������" << endl;
	InputHandler::MainMenu();
}