#include <iostream>
#include <list>
#include <string>

void Operation(std::list<std::string> &text, std::string &task, std::list<std::string>::iterator &cursor,
               std::string &buffer, bool &shift, std::list<std::string>::iterator &select_start,
               std::list<std::string>::iterator &select_end) {
    if (task == "Down") {
        auto next = std::next(cursor);
        if (next != text.end()) {
            if (shift) {
                select_end = cursor;
            }
            ++cursor;
        }
    } else if (task == "Up") {
        if (cursor != text.begin()) {
            if (shift) {
                select_end = cursor;
            }
            --cursor;
        }
    } else if (task == "Shift") {
        shift = true;
        select_start = cursor;
        select_end = cursor;
    } else if (task == "Ctrl+X") {
        if (shift && select_start != select_end) {
            if (select_start == text.end() || std::distance(select_start, select_end) < 0) {
                std::swap(select_start, select_end);
            }
            buffer.clear();
            for (auto it = select_start; it != std::next(select_end); ++it) {
                if (!it->empty()) {
                    buffer += *it + '\n';
                }
            }
            cursor = text.erase(select_start, std::next(select_end));
        } else {
            if (!cursor->empty()) {
                buffer = *cursor;
                cursor = text.erase(cursor);
            }
        }
        shift = false;
    } else if (task == "Ctrl+V") {
        if (!buffer.empty()) {
            auto start = cursor;
            if (shift && select_start != select_end) {
                if (select_start == text.end() || std::distance(select_start, select_end) < 0) {
                    std::swap(select_start, select_end);
                }
                cursor = text.erase(select_start, std::next(select_end));
                start = cursor;
                auto buffer_lines = buffer;
                while (!buffer_lines.empty()) {
                    auto pos = buffer_lines.find('\n');
                    if (pos != std::string::npos) {
                        text.insert(cursor, buffer_lines.substr(0, pos));
                        buffer_lines.erase(0, pos + 1);
                    } else {
                        break;
                    }
                }
                cursor = start;
            } else {
                text.insert(cursor, buffer);
            }

        }
        shift = false;
    }
}

int main() {
    std::list<std::string> text;
    std::string line;

    while (std::getline(std::cin, line) && !line.empty()) {
        text.push_back(line);
    }
    text.push_back("");

    auto cursor = text.begin();
    std::string buffer;
    bool shift = false;
    auto select_start = cursor;
    auto select_end = cursor;

    std::string task;
    while (std::cin >> task) {
        Operation(text, task, cursor, buffer, shift, select_start, select_end);
    }

    for (const auto &str: text) {
        std::cout << str << std::endl;
    }

    return 0;
}
