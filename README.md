# Calculation-assignment-KPI
Calculation assignment of student Red`ko Yehor of RB-61 group.
All the works were made by the 13-th variant included in the PDF file.

The task:
<img width="1053" height="277" alt="зображення" src="https://github.com/user-attachments/assets/14715e6d-673f-4676-a1d6-96cef361dade" />

[файл RR1.c](https://github.com/DeadLadyBug69/Calculation-assignment-KPI/blob/Part-1/RR1/RR1.c)

В цій частині коду ми оголошуємо змінні та просимо користувача ввести значення a (основу) та N (кількість ітерацій в циклі). Також тут реалізовано захист від некоректного вводу за допомогою циклу do-while, оскільки N не може бути від'ємним:
```c
  double a;
int N;

printf("Введіть значення a: ");
scanf("%lf", &a);

do {
    printf("Введіть значення N (N >= 0): ");
    scanf("%d", &N);
} while (N < 0);
```

В цій частині коду ми обчислюємо суму ряду. Щоб уникнути використання math.h та переповнення пам'яті через розрахунок величезних факторіалів, ми використовуємо метод рекурентних співвідношень — кожен наступний член ряду розраховується на основі попереднього:

```c
   double S = 0.0;
double current = 1.0; // Для n = 0, a^0 / 0! = 1

for (int n = 0; n <= N; n++) {
    if (n > 0) {
        // Формула: a^2n / (2n)! = (a^2n-2 / (2n-2)!) * (a^2) / ((2n-1)*2n)
        current = current * (-1) * (a * a) / ((2.0 * n - 1) * (2.0 * n));
    }
    
    S += current;
}
    }
```

В цій частині коду ми виводимо кінцевий результат (обчислену суму ряду) у консоль:
```c
// Виведення результату 
printf("Сума ряду S = %lf\n", S);
```

RESULT OF THE PROGRAM:
<img width="875" height="92" alt="зображення" src="https://github.com/user-attachments/assets/ad6eec2b-f66b-4875-bd7a-34e0a3f4a57b" />

