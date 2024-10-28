#include <stdio.h>
#include <string.h>

typedef struct {
    char surname[50];
    int groupNumber;
    int grade1;
    int grade2;
    int grade3;
} Student;

void findStudentsWithDebts(Student* students, int n) {
    printf("Студенти із заборгованостями:\n");
    for (int i = 0; i < n; i++) {
        if (students[i].grade1 < 60 || students[i].grade2 < 60 || students[i].grade3 < 60) {
            printf("%s, група %d\n", students[i].surname, students[i].groupNumber);
        }
    }
}

void findStudentsWithAllGradesAbove(Student* students, int n, int threshold) {
    printf("Студенти, що склали всі іспити вище за %d:\n", threshold);
    for (int i = 0; i < n; i++) {
        if (students[i].grade1 > threshold && students[i].grade2 > threshold && students[i].grade3 > threshold) {
            printf("%s, група %d\n", students[i].surname, students[i].groupNumber);
        }
    }
}

int main() {
    int n, threshold;
    printf("Введіть кількість студентів: ");
    scanf("%d", &n);

    Student students[n];
    for (int i = 0; i < n; i++) {
        printf("Введіть прізвище, номер групи та три оцінки для студента %d: ", i + 1);
        scanf("%s %d %d %d %d", students[i].surname, &students[i].groupNumber, &students[i].grade1, &students[i].grade2, &students[i].grade3);
    }

    printf("Введіть порогову оцінку: ");
    scanf("%d", &threshold);

    findStudentsWithDebts(students, n);
    findStudentsWithAllGradesAbove(students, n, threshold);

    return 0;
}

