// advent-of-code-2024-09.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "failed to open" << std::endl;
        return 1;
    }
    std::string line;
    std::string res;
    getline(file, line);
    int i = 0;
    int stringLength = line.size();
    bool target = true;
    int count = 0;
    while (i < stringLength) {
        if (target)
        {
            for (size_t j = 0; j < (line[i]-'0'); j++)
            {
                res += std::to_string(count);
            }
            count++;
        }
        else {
            for (size_t j = 0; j < (line[i]-'0'); j++)
            {
                res += '.';
            }
        }
        target = !target;
        i++;
    }

    int j = res.size()-1;
    i = 0;
    count = 0;
    long long int s = 0;
    while (j >= i) {
        if (res[i] != '.') {
            s += count*(res[i] - '0');
        }
        else
        {
            while (res[j] == '.') {
                j--;
            }
            s += count * (res[j] - '0');
            j--;
        }
        i++;
        count++;
    }
    std::cout << s;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
