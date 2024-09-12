#include <iostream>
#include <list>

void Operation(std::list<std::string> &text, std::string &task, std::list<std::string>::iterator &cursor, std::string &buffer) {
    if (task == "Down") {
        auto next = std::next(cursor);
        if (next != text.end()) {
            ++cursor;
        }
    } else if (task == "Up") {
        if (cursor != text.begin()) {
            --cursor;
        }
    } else if (task == "Ctrl+X") {
        if (!cursor->empty()) {
            buffer = *cursor;
            cursor = text.erase(cursor);
            if (cursor == text.end() && cursor != text.begin()) {
                --cursor;
            }
        }
    } else if (task == "Ctrl+V") {
        if (!buffer.empty()) {
            text.insert(cursor, buffer);
        }
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

    std::string task;
    while (std::cin >> task) {
        Operation(text, task, cursor, buffer);
    }

    for (const auto &str : text) {
        std::cout << str << std::endl;
    }

    return 0;
}
