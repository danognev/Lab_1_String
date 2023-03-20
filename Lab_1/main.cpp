#include <iostream>
#include <Windows.h>
#include "messages.h"
#include "algorithm.h"

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "Выполнил студент 494 группы Огнев Даниил. Вариант 13" << std::endl;
	std::cout << std::endl << "Задача: Предложения текста идут подряд. Преобразовать текст так,\n" <<
	"чтобы каждое предложение составляло отдельный абзац, начинающийся с " <<
	"красной строки в три пробела." << std::endl;
	Messages::MainMenu();
	return 0;
}