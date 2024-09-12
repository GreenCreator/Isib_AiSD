#include <string_view>
#include <iostream>

bool NextToken(std::string_view& sv, char delimiter, std::string_view& token) {
    if (sv.empty()) {
        return false;
    }

    size_t pos = sv.find(delimiter);
    if (pos == std::string_view::npos) {
        token = sv;
        sv.remove_prefix(sv.size());
    } else {
        token = sv.substr(0, pos);
        sv.remove_prefix(pos + 1);
    }

    return true;
}

int main() {
    std::string_view sv = "Hello world and good bye";

    const char delimiter = ' ';
    std::string_view token;

    while (NextToken(sv, delimiter, token)) {
        if(!token.empty())
        std::cout << token << "\n";
    }
}

