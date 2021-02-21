#include <iostream>
#include <vector>

int rounds = 0;
std::vector<std::vector<std::vector<int>>> solved = {};
std::vector<std::vector<char>> clearBoard = {
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
};

bool testRow(std::vector<std::vector<int>> inCoords) {
    for (int i = 0; i < inCoords.size(); i++) {
        for (int j = i + 1; j < inCoords.size(); j++) {
            if (inCoords[i][0] == inCoords[j][0]) {
                return true;
            }
        }
    }
    return false;
}

// bool testColumn(std::vector<std::vector<int>> inCoords) {
//     for (int i = 0; i < inCoords.size(); i++) {
//         for (int j = i + 1; j < inCoords.size(); j++) {
//             if (inCoords[i][1] == inCoords[j][1]) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

bool testDiagonal(std::vector<std::vector<int>> inCoords) {
    // int ref1 = inCoord[0] - outCoord[0];
    // int ref2 = inCoord[1] - outCoord[1];
    // if (ref2 == ref1 || ref2 == (ref1 * -1) || ref1 == (ref2 * -1)) {
    //     return true; 
    // } else {
    //     return false;
    // }
    for (int i = 0; i < inCoords.size(); i++) {
        for (int j = i + 1; j < inCoords.size(); j++) {
            if (inCoords[i][0] - inCoords[j][0] == inCoords[i][1] - inCoords[j][1] || inCoords[i][0] - inCoords[j][0] == ((inCoords[i][1] - inCoords[j][1]) * -1) || inCoords[i][1] - inCoords[j][1] == ((inCoords[i][0] - inCoords[j][0]) * -1)) {
                return true;
            }
        }
    }
    return false;
}

bool testAll(std::vector<std::vector<int>> inCoords) {
    if (testRow(inCoords) || testDiagonal(inCoords)) {
        return true;
    }
    return false;
}

void printBoard(std::vector<std::vector<char>> board, std::vector<std::vector<int>> solution) {
    std::vector<std::vector<char>> tboard = board;
    for (int i = 0; i < solution.size(); i++) {
        int row = solution[i][0];
        int column = solution[i][1];
        tboard[row][column] = 'X';
    }
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[0][0] << "|" << tboard[0][1] << "|" << tboard[0][2] << "|" << tboard[0][3] << "|" << tboard[0][4] << "|" << tboard[0][5] << "|" << tboard[0][6] << "|" << tboard[0][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[1][0] << "|" << tboard[1][1] << "|" << tboard[1][2] << "|" << tboard[1][3] << "|" << tboard[1][4] << "|" << tboard[1][5] << "|" << tboard[1][6] << "|" << tboard[1][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[2][0] << "|" << tboard[2][1] << "|" << tboard[2][2] << "|" << tboard[2][3] << "|" << tboard[2][4] << "|" << tboard[2][5] << "|" << tboard[2][6] << "|" << tboard[2][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[3][0] << "|" << tboard[3][1] << "|" << tboard[3][2] << "|" << tboard[3][3] << "|" << tboard[3][4] << "|" << tboard[3][5] << "|" << tboard[3][6] << "|" << tboard[3][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[4][0] << "|" << tboard[4][1] << "|" << tboard[4][2] << "|" << tboard[4][3] << "|" << tboard[4][4] << "|" << tboard[4][5] << "|" << tboard[4][6] << "|" << tboard[4][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[5][0] << "|" << tboard[5][1] << "|" << tboard[5][2] << "|" << tboard[5][3] << "|" << tboard[5][4] << "|" << tboard[5][5] << "|" << tboard[5][6] << "|" << tboard[5][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[6][0] << "|" << tboard[6][1] << "|" << tboard[6][2] << "|" << tboard[6][3] << "|" << tboard[6][4] << "|" << tboard[6][5] << "|" << tboard[6][6] << "|" << tboard[6][7] << "|" << "\n";
    std::cout << "-----------------" << "\n";
    std::cout << "|" << tboard[7][0] << "|" << tboard[7][1] << "|" << tboard[7][2] << "|" << tboard[7][3] << "|" << tboard[7][4] << "|" << tboard[7][5] << "|" << tboard[7][6] << "|" << tboard[7][7] << "|" << "\n";
    std::cout << "-----------------" << "\n"; 
}


int main() {
    for (int a = 0; a < 8; a++) {
        std::cout << a << "\n";
        for (int b = 0; b < 8; b++) {
            for (int c = 0; c < 8; c++) {
                for (int d = 0; d < 8; d++) {
                    for (int e = 0; e < 8; e++) {
                        for (int f = 0; f < 8; f++) {
                            for (int g = 0; g < 8; g++) {
                                for (int h = 0; h < 8; h++) {
                                    if (!testAll({{a, 0}, {b, 1}, {c, 2}, {d, 3}, {e, 4}, {f, 5}, {g, 6}, {h, 7}})) {
                                        rounds++;
                                        std::cout << "Hello World " << rounds << "\n";
                                        solved.push_back({{a, 0}, {b, 1}, {c, 2}, {d, 3}, {e, 4}, {f, 5}, {g, 6}, {h, 7}});
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < solved.size(); i++) {
        std::cout << "\n";
        std::cout << "............................." << "\n";
        std::cout << "\n";
        printBoard(clearBoard, solved[i]);
    }
}