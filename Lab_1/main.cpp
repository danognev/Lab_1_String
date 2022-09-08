#include <iostream>
#include "messages.h"

int main(int argc, char** argv) {
	setlocale(LC_ALL,"");
	std::cout << "Выполнил студент 494 группы Огнев Даниил. Вариант 13" << std::endl;
	std::cout << std::endl << "Задача: Задан текст. Для каждой строки вычислить среднее арифметическое" <<
	 "значений длин слов в строке." << std::endl;
	Messages::MainMenu();
	return 0;
}