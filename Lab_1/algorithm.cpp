#include "messages.h"
#include "file_worker.h"
#include "algorithm.h"
#include <Windows.h>
#include <atlstr.h>

using namespace std;

string Algorithm::result = "";

string Algorithm::GetResult() { return result; }

void Algorithm::GetSentences(string &text) {
	result = "";
	int count;
	const string MULTI_POINT = "...";
	const string NEED_TO_SEARCH = ".!?";
	const size_t POS_WITH_SPACE = 2;
	const size_t POS_WITH_POINTS = 3;
	bool isFormatCorrect = false;
	size_t pos = text.find_first_of(NEED_TO_SEARCH);
	while (pos != string::npos) {
		if (text.substr(0, pos).empty()) {
			isFormatCorrect = false;
			break;
		}
		else {
			count = 0;
			for(int i = 0; i < text.substr(0, pos).size(); i++) {
				if(text[i] != ' ') {
					count++;
					break;
				}
			}
		}
			if (count != 0 && text.substr(0, pos + POS_WITH_POINTS).find(MULTI_POINT) != string::npos)
			{
				result += "\n\n   " + text.substr(0, pos + POS_WITH_POINTS);
				text.erase(0, pos + POS_WITH_POINTS + 1);
				pos = text.find_first_of(NEED_TO_SEARCH);
			}
			result += "\n\n   " + text.substr(0, pos + 1);
			text.erase(0, pos+POS_WITH_SPACE);
			pos = text.find_first_of(NEED_TO_SEARCH);
			isFormatCorrect = true;
	}
	if (!isFormatCorrect) {
		cout << "Исходный текст не был преобразован!" << endl;
		Messages::MainMenu();
	}
	else {
		cout << "\n\nРезультат:\n   " + result;
		FileWorker::SetFileContent(result);
		Messages::NeedToSaveText("полученный");
		Messages::MainMenu();
	}
}
