#include <iostream>
#include <fstream>
#include <regex>
#include <string>
#include <vector>
#include <algorithm>

void grep(const std::string& template_str, const std::vector<std::string>& filenames, bool ignore_case, bool invert_match, bool count, bool print_file_names, bool line_number, bool suppress_errors, bool only_matching) {
    std::regex::flag_type flags = std::regex::ECMAScript;
    if (ignore_case) {
        flags |= std::regex::icase;
    }

    std::regex pattern(template_str, flags);

    for (const auto& filename : filenames) {
        std::ifstream file(filename);
        if (!file) {
            if (!suppress_errors) {
                std::cerr << "grep: " << filename << ": No such file or directory" << std::endl;
            }
            continue;
        }

        std::string line;
        int line_number_count = 0;
        int match_count = 0;

        while (std::getline(file, line)) {
            line_number_count++;
            bool match = std::regex_search(line, pattern);

            if (invert_match) {
                match = !match;
            }

            if (match) {
                match_count++;
                if (count) {
                    continue;
                }
                if (print_file_names) {
                    std::cout << filename << ":";
                }
                if (line_number) {
                    std::cout << line_number_count << ":";
                }
                if (only_matching) {
                    std::smatch matches;
                    if (std::regex_search(line, matches, pattern)) {
                        std::cout << matches.str() << std::endl;
                    }
                } else {
                    std::cout << line << std::endl;
                }
            }
        }

        if (count && match_count > 0) {
            std::cout << filename << ": " << match_count << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    bool ignore_case = false;
    bool invert_match = false;
    bool count = false;
    bool print_file_names = true;
    bool line_number = false;
    bool suppress_errors = false;
    bool only_matching = false;

    std::string template_str;
    std::vector<std::string> filenames;

    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        if (arg == "-e" && i + 1 < argc) {
            template_str = argv[++i];
        }
        else if (arg == "-i") {
            ignore_case = true;
        }
        else if (arg == "-v") {
            invert_match = true;
        }
        else if (arg == "-c") {
            count = true;
        }
        else if (arg == "-l") {
            print_file_names = true;
            count = true;
        }
        else if (arg == "-n") {
            line_number = true;
        }
        else if (arg == "-h") {
            print_file_names = false;
        }
        else if (arg == "-s") {
            suppress_errors = true;
        }
        else if (arg == "-o") {
            only_matching = true;
        }
        else {
            if (template_str.empty()) {
                template_str = arg; // Первый аргумент без опций считается шаблоном
            } else {
                filenames.push_back(arg); // Остальные аргументы считаются именами файлов
            }
        }
    }

    if (filenames.empty()) {
        filenames.push_back("-"); // Если файлы не указаны, использовать стандартный ввод
    }

    grep(template_str, filenames, ignore_case, invert_match, count, print_file_names, line_number, suppress_errors, only_matching);

    return 0;
}