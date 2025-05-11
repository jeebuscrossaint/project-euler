#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
        std::ifstream file("100/22.txt");
        if (!file.is_open())
        {
                std::cerr << "Error opening file." << std::endl;
                return 1;
        }

        std::string content;
        std::vector<std::string> names;

        std::getline(file, content);

        size_t start = 0;
        size_t end = 0;

        while ((start = content.find('"', start)) != std::string::npos)
        {
                start++;
                end = content.find('"', start);
                if (end == std::string::npos) break;

                std::string name = content.substr(start, end - start);
                names.push_back(name);

                start = end + 1;
        }

        std::sort(names.begin(), names.end());
        int totalScore = 0;

        for (size_t i = 0; i < names.size(); i++)
        {
                int nameValue = 0;

                for (char c: names[i])
                {
                        nameValue += c - 'A' + 1; // Calculate the alphabetical value
                }

                long long score = nameValue * (i + 1); // Multiply by the position (1-indexed)
                totalScore += score; // Add to the total score
        }

        std::cout << "Total score: " << totalScore << std::endl;

        file.close();

        return 0;
}