#include <iostream>
#include <Windows.h>
#include "messages.h"
#include "algorithm.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "�������� ������� 494 ������ ����� ������. ������� 13" << std::endl;
	std::cout << std::endl << "������: ����������� ������ ���� ������. ������������� ����� ���,\n" <<
	"����� ������ ����������� ���������� ��������� �����, ������������ � " <<
	"������� ������ � ��� �������." << std::endl;
	Messages::MainMenu();
	return 0;
}