#include "file_worker.h"
#include "messages.h"
#include <atlstr.h>

using namespace std;
using namespace filesystem;

string FileWorker::fileName;
string FileWorker::content;

#define BUFFERSIZE 2048

DWORD FileWorker::g_BytesTransferred = 0;


VOID CALLBACK FileWorker::FileIOCompletionRoutine(	__in  DWORD dwErrorCode,
	__in  DWORD dwNumberOfBytesTransfered,
	__in  LPOVERLAPPED Overlapped)
{
	dwErrorCode = 0;
	Overlapped->Pointer = NULL;
	g_BytesTransferred = dwNumberOfBytesTransfered;
}

void FileWorker::ReadFile() {
	content = "";
	OPENFILENAME ofn;
	const int TIMEOUT = 5000;
	char szFileName[MAX_PATH] = "";
	DWORD dwBytesRead = 0;
	char ReadBuffer[BUFFERSIZE] = { 0 };
	OVERLAPPED ol = { 0 };

	ZeroMemory(&ofn, sizeof(ofn));

	HANDLE hFile;
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = L"Text Files (*.txt)\0*.txt";
	ofn.lpstrFile = (LPWSTR)szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = L"txt";

	GetOpenFileName(&ofn);
	fileName = CW2A(ofn.lpstrFile);
	hFile = CreateFile(ofn.lpstrFile,               // file to open
		GENERIC_READ,          // open for reading
		FILE_SHARE_READ,       // share for reading
		NULL,                  // default security
		OPEN_EXISTING,         // existing file only
		FILE_ATTRIBUTE_NORMAL | FILE_FLAG_OVERLAPPED, // normal file
		NULL);                 // no attr. template

	if (hFile == INVALID_HANDLE_VALUE)
	{
		cout << "Произошла ошибка при открытии файла. Попробуйте ещё раз!" << endl;
		ReadFile();
	}
	if (FALSE == ReadFileEx(hFile, ReadBuffer, BUFFERSIZE - 1, &ol,FileIOCompletionRoutine))
	{
		cout << "Произошла ошибка при чтении файла. Попробуйте ещё раз!" << endl;
		CloseHandle(hFile);
		ReadFile();
	}
	SleepEx(TIMEOUT, TRUE);
	dwBytesRead = g_BytesTransferred;

	if (dwBytesRead > 0 && dwBytesRead <= BUFFERSIZE - 1)
	{
		ReadBuffer[dwBytesRead] = '\0';
		content = ReadBuffer;
	}
	else if (dwBytesRead == 0)
	{
		cout << "В файле нет данных. Попробуйте другой файл!" << endl;
		ReadFile();
	}
	else
	{
		cout << "В процессе чтения произошла непредвиденная ошибка. Попробуйте еще раз!" << endl;
		ReadFile();
	}
}
string FileWorker::GetFileContent() {
	return content;
}
void FileWorker::SetFileContent(string Content) {
	FileWorker::content = Content;
}
void FileWorker::SaveFile() {
	OPENFILENAME ofn;

	char szFileName[MAX_PATH] = "";

	ZeroMemory(&ofn, sizeof(ofn));

	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFilter = (LPCWSTR)L"Text Files (*.txt)\0*.txt";
	ofn.lpstrFile = (LPWSTR)szFileName;
	ofn.nMaxFile = MAX_PATH;
	ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_HIDEREADONLY;
	ofn.lpstrDefExt = (LPCWSTR)L"txt";

	GetSaveFileName(&ofn);
	fileName = CW2A(ofn.lpstrFile);

	if (exists(fileName)) {
		Messages::FileExists();
	}
	else
		SaveFile(fileName);
}
string FileWorker::GetFileName() { return fileName; }

void FileWorker::SaveFile(string FileName) {
	ofstream out(FileName);
	if (out.is_open()) {
		out << content;
		out.close();
		cout << "Файл успешно сохранен по адресу: " << FileName << endl;
	}
	else {
		cout << "Произошла ошибка при записи файла!" << endl;
		SaveFile();
	}
}