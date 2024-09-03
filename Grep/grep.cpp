#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <string>
#include <windows.h>
#include <locale>
#include <codecvt>


void searchInFile(const std::string& filename, const std::string& searchTerm, bool ignoreCase, bool invertMatch, bool countOnly, bool matchFilesOnly, bool printLineNumbers, bool printMatchingParts) {
	std::ifstream file(filename);

	if (!file.is_open()) {
		std::cerr << "Cannot open file: " << filename << std::endl;
		return;
	}

	std::string line;
	int lineNumber = 0;
	int matchCount = 0;
	std::regex::flag_type flags = std::regex_constants::ECMAScript;

	if (ignoreCase) {
		flags |= std::regex_constants::icase;
	}

	std::regex pattern(searchTerm, flags);
	std::vector<int> matchingLines;

	while (std::getline(file, line)) {
		lineNumber++;
		bool match = std::regex_search(line, pattern);  
		if (invertMatch) {
			match = !match;
		}

		if (match) {
			matchCount++;

				if (matchFilesOnly) {
				matchingLines.push_back(lineNumber);
				break;
			}

			if (!countOnly) {
				if (printLineNumbers) {
					std::cout << lineNumber << ": ";
				}

				if (printMatchingParts) {
					std::smatch matchResult;
					std::regex_search(line, matchResult, pattern);

					for (const auto& part : matchResult) {
						if (!part.str().empty()) {
							std::cout << part.str() << " ";
						}
					}
					std::cout << std::endl;
				}
				else {
					std::cout << line << std::endl;
				}
			}
		}
	}

	if (countOnly) {
		std::cout << matchCount << std::endl;
	}
	else if (matchFilesOnly && !matchingLines.empty()) {
		std::cout << filename << std::endl;
	}

	file.close(); 

int main(int argc, char* argv[]) {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	setlocale(LC_ALL, "rus");

	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <filename> <searchTerm> [options]" << std::endl;
		return 1;
	}

	std::string filename = argv[1];
	std::string searchTerm = argv[2];

	bool ignoreCase = false; // -i опция
	bool invertMatch = false;  // -v опция
	bool countMatches = false; // -c опция
	bool matchFilesOnly = false; // -l опция
	bool lineNumber = false; // -n опция
	bool matchingFile = false; // -o опция

	for (int i = 3; i < argc; i++) {
		std::string option = argv[i];
		if (option == "-i") {
			ignoreCase = true;
		}
		else if (option == "-v") {
			invertMatch = true;
		}
		else if (option == "-c") {
			countMatches = true;
		}
		else if (option == "-l") {
			matchFilesOnly = true;
		}
		else if (option == "-n") {
			lineNumber = true;
		}
		else if (option == "-o") {
			matchingFile = true;
		}
	}

	searchInFile(filename, searchTerm, ignoreCase, invertMatch, countMatches, matchFilesOnly, lineNumber, matchingFile);

	return 0;
}
