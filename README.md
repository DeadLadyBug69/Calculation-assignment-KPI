# Calculation-assignment-KPI
Calculation assignment of student Red`ko Yehor of RB-61 group.
All the works were made by the 13-th variant included in the PDF file.

The task:
<img width="1053" height="408" alt="зображення" src="https://github.com/user-attachments/assets/d40a8300-8c06-45e5-aca1-e6924b64aeae" />

[файл RR2.c](https://github.com/DeadLadyBug69/Calculation-assignment-KPI/blob/Part-2/RR2/RR2.c)

В цій частині коду ми генеруємо граничне значення a (випадкове число від 10 до 15) та заповнюємо початкову матрицю A числами в діапазоні від 0 до a включно:

```c
// Формування діапазону згідно із завданням (a = від 10 до 15)
// rand() % 6 видає від 0 до 5, додається 10 щоб вийшло від 10 о 15
int a = 10 + rand() % 6; 
printf("Рандомне a: %d\n\n", a);

// Заповнення матрицю A випадковими числами від 0 до a (включно)
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        A[i][j] = rand() % (a + 1);
    }
}
```

В цій частині коду (у функції sortdiag) ми спочатку переносимо весь вміст матриці A в матрицю B, щоб зберегти оригінал незмінним, а потім сортуємо головну діагональ безпосередньо в матриці B за спаданням, використовуючи метод бульбашки:

```c
// Перенос вмісту матриці A в матрицю B
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        B[i][j] = A[i][j];
    }
}

// Сорт елементів головної діагоналі безпосередньо в матриці B бульбашкою
for (int i = 0; i < N - 1; i++) {
    for (int j = 0; j < N - i - 1; j++) {
        // Якщо поточний елемент менший за наступний, міняємо їх місцями 
        // Щоб було за спаданням
        if (B[j][j] < B[j + 1][j + 1]) {
            int temp = B[j][j];
            B[j][j] = B[j + 1][j + 1];
            B[j + 1][j + 1] = temp;
        }
    }
}
```

В цій частині коду (у функції printMatrix) ми виводимо матрицю у консоль. Використання форматування %4d дозволяє вирівняти стовпчики матриці для акуратного та читабельного відображення:

```c
for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
        // %4d виділяє 4 позиції для числа, щоб стовпчики були рівними
        printf("%4d", matrix[i][j]); 
    }
    printf("\n"); // Перехід на новий рядок
}
```

RESULT OF THE PROGRAM:
<img width="1222" height="488" alt="зображення" src="https://github.com/user-attachments/assets/416e47bd-753c-4e66-98b4-bc0819a9b6c0" />


