#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

char Lower(char ch) {
    if (ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    return ch;
}
string LowerCase(const string& str) {
    string lower;
    for (char ch : str) {
        lower += Lower(ch);
    }
    return lower;
}
    class Grep {
public:
    void searchInFiles(const vector<string>& filenames, const vector<string>& patterns, bool ignoreCase, bool invertMatch, bool countMatches, bool listFiles, bool lineNumber, bool noFileName, bool suppressErrors, bool onlyMatching) {
        vector<string> matchedFiles;
        int totalMatches = 0;
        vector<string> lowerPatterns;
        if (ignoreCase) {
            for (const auto& pattern : patterns) {
                lowerPatterns.push_back(LowerCase(pattern));
            }
        } else {
            lowerPatterns = patterns;
        }
        for (const auto& filename : filenames) {
            ifstream file(filename);
            if (!file.is_open()) {
                if (!suppressErrors) {
                    cerr <<" Не удается открыть файл " << filename << endl;
                }
                continue;
            }
            string line;
            int lineCount = 0;
            int matchCount = 0;
            while (getline(file, line)) {
                ++lineCount;
                string originalLine = line;
                if (ignoreCase) {
                    line = LowerCase(line);
                }
                bool matched = false;
                for (const auto& pattern : lowerPatterns) {
                    size_t pos = line.find(pattern);
                    while (pos != string::npos) {
                        matched = true;
                        if (onlyMatching && !invertMatch) {
                            string matchStr = originalLine.substr(pos, pattern.size());
                            if (lineNumber && !noFileName) {
                                cout << filename << ":" << lineCount << ":" << matchStr << endl;
                            } else if (noFileName) {
                                cout << matchStr << endl;
                            } else {
                                cout << filename << ":" << matchStr << endl;
                            }
                        }
                        pos = line.find(pattern, pos + 1);
                        ++matchCount;
                    }
                }
                if (invertMatch && !matched) {
                    cout << originalLine << endl;
                }
            }
            if (countMatches) {
                cout << filename << ": " << matchCount << " совпадений" << endl;
            }
            if (matchCount > 0 && listFiles && !invertMatch) {
                matchedFiles.push_back(filename);
            }
        }
        if (listFiles && !invertMatch) {
            for (const auto& file : matchedFiles) {
                cout << file << endl;
            }
        }
        if (countMatches) {
            cout << "Общее количество совпадений: " << totalMatches << endl;
        }
    }
};
vector<string> readPatternsFromFile(const string& filename) {
    vector<string> patterns;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Не удается открыть файл шаблона " << filename << endl;
        return patterns;
    }
    string pattern;
    while (getline(file, pattern)) {
        if (!pattern.empty()) {
            patterns.push_back(pattern);
        }
    }
    return patterns;
}
int main() {
    Grep grep;
    vector<string> filenames = {"Files1.txt", "Files2.txt"};
    vector<string> patterns = readPatternsFromFile("Obr.txt"); 
    bool ignoreCase = true; // -i опция
    bool invertMatch = true; // -v опция
    bool countMatches = true; // -c опция
    bool listFiles = true; // -l опция
    bool lineNumber = true; // -n опция
    bool noFileName = true; // -h опция
    bool suppressErrors = true; // -s опция
    bool onlyMatching = true; // -o опция
    grep.searchInFiles(filenames, patterns, ignoreCase, invertMatch, countMatches, listFiles, lineNumber, noFileName, suppressErrors, onlyMatching);
    return 0;
}
