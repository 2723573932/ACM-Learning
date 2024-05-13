#include <iostream>
#include <string>

std::string processKeyboardInput(const std::string& input) {
    std::string text;
    int cursorPosition = 0;
    bool insertMode = true;

    for (char key : input) {
        if (key == '[') {
            cursorPosition = 0;
        } else if (key == ']') {
            cursorPosition = text.length();
        } else if (key == '{') {
            if (cursorPosition > 0) {
                cursorPosition--;
            }
        } else if (key == '}') {
            if (cursorPosition < text.length()) {
                cursorPosition++;
            }
        } else if (key == '-') {
            insertMode = !insertMode;
        } else if (key == '=') {
            if (cursorPosition > 0) {
                text.erase(cursorPosition - 1, 1);
                cursorPosition--;
            }
        } else if (key == '#') {
            break;
        } else {
            if (insertMode) {
                text.insert(cursorPosition, 1, key);
                cursorPosition++;
            } else {
                if (cursorPosition < text.length()) {
                    text[cursorPosition] = key;
                    cursorPosition++;
                } else {
                    text += key;
                    cursorPosition++;
                }
            }
        }
    }

    return text;
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::string result = processKeyboardInput(input);
    std::cout << result;

    return 0;
}