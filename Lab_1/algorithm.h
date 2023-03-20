#pragma once
#include <iostream>

class Algorithm {
private:
	static std::string result;
public:
	static void GetSentences(std::string &);
	static std::string GetResult();
};