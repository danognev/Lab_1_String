#include "input_handler.h"
#include "file_worker.h"
#include "algorithm.h"
#include "messages.h"
#include <iostream>
#include <conio.h>

using namespace std;
using IH = InputHandler;
using FW = FileWorker;
using MSSG = Messages;

enum KEYS { Manual = '1', File, Exit };
enum SAVE { Yes = '1', No };

string IH::text;

void IH::MainMenu() {
	char key = static_cast<char>(_getch());
	switch (key) {
		case Manual: {
			ManualInput();
			break;
		}
		case File: {
			FW::ReadFile();
			text = FW::GetFileContent();
			cout << "\n����������� �����:" << endl << text << endl;
			Algorithm::GetSentences(text);
			//Messages::NeedToSaveText("����������");
			//Messages::MainMenu();
			break;
		}
		case Exit: {
			break;
		}
		default: {
			cout << "������������ ����! ���������� ��� ���." << endl;
			MainMenu();
			break;
		}
	}
}
void IH::SetText(string Text) {
	IH::text = Text;
}
string IH::GetText() {
	return text;
}
void IH::ManualInput() {
	cout << "������� �����: ";
	getline(cin,text);
	if (text.empty()) {
		cout << "���������� ������ �����! ���������� ��� ���." << endl;
		ManualInput();
	}
	else {
		FW::SetFileContent(text);
		MSSG::NeedToSaveText("��������");
		Algorithm::GetSentences(text);
	}
}
void IH::NeedToSaveText(string source) {
	switch (_getch()) {
		case Yes: {
			FW::SaveFile();
			break;
		}
		case No: {
			break;
		}
		default: {
			cout << "������������ ����! ���������� ��� ���." << endl;
			NeedToSaveText(source);
			break;
		}
	}
}
void IH::FileExists() {
	switch(_getch()) {
		case Yes: {
			FW::SaveFile(FW::GetFileName());
			break;
		}
		case No: {
			break;
		}
		default: {
			cout << "������������ ����! ���������� ��� ���." << endl;
			FileExists();
		}
	}
}