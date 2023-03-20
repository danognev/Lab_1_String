#pragma once
#include <iostream>

class InputHandler {
private:
	static std::string text;
public:
	static void SetText(std::string);
	static std::string GetText();
	static void MainMenu();
	static void ManualInput();
	static void NeedToSaveText(std::string);
	static void FileExists();
};