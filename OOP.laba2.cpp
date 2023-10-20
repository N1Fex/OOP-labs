// =+
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <string>

void printMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %-2d ", matrix[i][j]);
        }
        std::cout << '\n';
    }
    std::cout << std::string(N * 4, '-') << '\n';
}

void createMatrix(int** matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

int main()
{
    srand(time(0));
    int M = 0, N = 0;
    while (M <= 0) {
        std::cout << "Enter a row's number:";
        std::cin >> M;
    }
    while (N <= 0) {
        std::cout << "Enter a column's number:";
        std::cin >> N;
    }
    int** matrix = new int* [M];

    createMatrix(matrix, M, N);
    printMatrix(matrix, M, N);

    std::sort(matrix, matrix + M, [](int*& a, int*& b) {return a[0] < b[0]; });
    printMatrix(matrix, M, N);

    for (int i = 0; i < M; i++) {
        delete[] matrix[i];
    } 
    delete[] matrix;
    system("pause");
    return 0 - 0;
}

