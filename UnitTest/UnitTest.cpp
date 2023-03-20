#include "CppUnitTest.h"
#include "../Lab_1/algorithm.h"
#include <iostream>
#include "../Lab_1/file_worker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(TestMethod_1)
		{
			std::string source = "Привет! Как дела?";
			std::string result = "\n\n   Привет!\n\n   Как дела?";
			Algorithm::GetSentences(source);
			Assert::AreEqual(result, Algorithm::GetResult());
		}
		TEST_METHOD(TestMethod_2)
		{
			std::string source = "Hello! How are you?";
			std::string result = "\n\n   Hello!\n\n   How are you?";
			Algorithm::GetSentences(source);
			Assert::AreEqual(result, Algorithm::GetResult());
		}
		TEST_METHOD(TestMethod_3) {
			std::string source;
			std::string result = source = "test";
			FileWorker::SetFileContent(source);
			Assert::AreEqual(FileWorker::GetFileContent(),result);
		}
		TEST_METHOD(TestMethod_4)
		{
			std::string source = "Hello.";
			std::string result = "\n\n   Hello";
			Algorithm::GetSentences(source);
			Assert::AreNotEqual(result, Algorithm::GetResult());
		}
	};
}
