#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 5 // Розмірність квадратної матриці (NxN)

/**
 * @brief Копіює матрицю та сортує її головну діагональ за спаданням методом бульбашки.
 * 
 * @param A Початкова матриця NxN (залишається без змін).
 * @param B Матриця-результат NxN, куди копіюється A, і де сортується діагональ.
 */
void sortdiag(int A[N][N], int B[N][N]);

/**
 * @brief Виводить матрицю у консоль із форматуванням.
 * 
 * @param matrix Матриця NxN, яку потрібно вивести.
 * @param name   Ім'я матриці для виведення в заголовку.
 */
void printMatrix(int matrix[N][N], const char* name);

int main() {
    SetConsoleOutputCP(CP_UTF8);
    
    // Ініціалізація генератора випадкових чисел 
    srand((unsigned int)time(NULL));
    
    int A[N][N];
    int B[N][N];
    
    // Формування діапазону згідно із завданням (a = від 10 до 15)
    int a = 10 + rand() % 6; 
    printf("a = %d (діапазон елементів: [0, %d])\n\n", a, a);
    
    // Заповнення матриці A випадковими числами від 0 до a (включно)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % (a + 1);
        }
    }
    
    // Виклик робочої функції де А не змінюється, а В сортується
    sortdiag(A, B);
    
    // Виведення початкової матриці А та відсортованої В
    printMatrix(A, "A");
    printMatrix(B, "B (відсортована діагональ)");
    
    return 0;
}

// Функція для переносу матриці та сортування її головної діагоналі бульбашкою
void sortdiag(int A[N][N], int B[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            B[i][j] = A[i][j];
        }
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (B[j][j] < B[j + 1][j + 1]) {
                int temp = B[j][j];
                B[j][j] = B[j + 1][j + 1];
                B[j + 1][j + 1] = temp;
            }
        }
    }
}

// Функція для виведення матриці у консоль
void printMatrix(int matrix[N][N], const char* name) {
    printf("Матриця %s:\n", name);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matrix[i][j]); 
        }
        printf("\n");
    }
    printf("\n");
}
