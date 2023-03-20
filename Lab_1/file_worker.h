#pragma once
#include <filesystem>
#include <iostream>
#include <fstream>
#include <Windows.h>

class FileWorker
{
private:
	static std::string fileName;
	static std::string content;
	static DWORD g_BytesTransferred;
	static VOID CALLBACK FileIOCompletionRoutine(__in  DWORD,__in  DWORD,__in  LPOVERLAPPED);
public:
	static void SetFileContent(std::string);
	static void ReadFile();
	static std::string GetFileName();
	static void SaveFile();
	static void SaveFile(std::string);
	static std::string GetFileContent();
};