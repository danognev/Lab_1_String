#include <iostream>
#include "messages.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL,"");
	std::cout << "�������� ������� 494 ������ ����� ������. ������� 13" << std::endl;
	std::cout << std::endl << "������: ����� �����. ��� ������ ������ ��������� ������� ��������������" <<
	 "�������� ���� ���� � ������." << std::endl;
	Messages::MainMenu();
	return 0;
}