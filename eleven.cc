#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main() {
    vector<vector<int>> grid(20, vector<int>(20));
    ifstream file("eleven.txt");
    string line;
    for (int i = 0; i < 20; ++i) {
        getline(file, line);
        stringstream ss(line);
        for (int j = 0; j < 20; ++j) {
            ss >> grid[i][j];
        }
    }
    file.close();

    long long max_product = 0;

    // Check horizontal
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j <= 16; ++j) {
            long long product = (long long)grid[i][j] * grid[i][j + 1] * grid[i][j + 2] * grid[i][j + 3];
            if (product > max_product) {
                max_product = product;
            }
        }
    }

    // Check vertical
    for (int j = 0; j < 20; ++j) {
        for (int i = 0; i <= 16; ++i) {
            long long product = (long long)grid[i][j] * grid[i + 1][j] * grid[i + 2][j] * grid[i + 3][j];
            if (product > max_product) {
                max_product = product;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i <= 16; ++i) {
        for (int j = 0; j <= 16; ++j) {
            long long product = (long long)grid[i][j] * grid[i + 1][j + 1] * grid[i + 2][j + 2] * grid[i + 3][j + 3];
            if (product > max_product) {
                max_product = product;
            }
        }
    }

    // Check diagonal (top-right to bottom-left)
    for (int i = 0; i <= 16; ++i) {
        for (int j = 3; j < 20; ++j) {
            long long product = (long long)grid[i][j] * grid[i + 1][j - 1] * grid[i + 2][j - 2] * grid[i + 3][j - 3];
            if (product > max_product) {
                max_product = product;
            }
        }
    }

    cout << "The greatest product of four adjacent numbers is: " << max_product << endl;

    return 0;
}
