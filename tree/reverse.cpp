#include <iostream>
#include <string>
#include <algorithm> // for std::reverse

class Solution {
public:
    std::string reverseParts(std::string s) {
        auto commapos=std::find(s.begin(),s.end(),',');
        std::reverse(s.begin(), commapos);
        std::reverse(commapos + 1, s.end());
        return s;
    }
};

int main() {
    Solution solution;
    std::string s1 = "hello world,how are you";
    std::string result1 = solution.reverseParts(s1);
    std::cout << "Test Case 1: " << result1 << std::endl;

    std::string s2 = "example,case";
    std::string result2 = solution.reverseParts(s2);
    std::cout << "Test Case 2: " << result2 << std::endl;
    return 0;
}
