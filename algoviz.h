#ifndef ALGOVIZ_H
#define ALGOVIZ_H

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include <string>
#include <iomanip>

namespace AlgoViz {

class ArrayTracer {
private:
    std::vector<int> array;
    int highlightIndex;

public:
    ArrayTracer(const std::vector<int>& data) : array(data), highlightIndex(-1) {}

    void set(const std::vector<int>& data) {
        array = data;
    }

    void select(int index) {
        highlightIndex = index;
        render();
    }

    void deselect(int index) {
        if (highlightIndex == index) highlightIndex = -1;
        render();
    }

    void render() {
        std::cout << "Array: [";
        for (size_t i = 0; i < array.size(); ++i) {
            if ((int)i == highlightIndex) {
                std::cout << "\033[1;31m" << array[i] << "\033[0m"; // Highlight in red
            } else {
                std::cout << array[i];
            }
            if (i < array.size() - 1) std::cout << ", ";
        }
        std::cout << "]" << std::endl;
    }
};

class LogTracer {
public:
    void log(const std::string& message) {
        std::cout << "[LOG] " << message << std::endl;
    }
};

void delay(int milliseconds) {
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

} // namespace AlgoViz

#endif // ALGOVIZ_H
