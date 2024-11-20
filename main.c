#include <stdio.h>
#include <stdlib.h>
#include "dsaproject.c" 

int main() {
    T_Student sentinel = (T_Student)malloc(sizeof(struct student));

    if (!sentinel) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    sentinel->next = NULL;

    int choice;
    char name[50];
    long id;
    float grade;
    T_Student highLevel = NULL, lowLevel = NULL;

    do {
        printf("\n*** Student Exam Management System ***\n");
        printf("1. Enter a new student\n");
        printf("2. Add new student (directly)\n");
        printf("3. Search for a student\n");
        printf("4. Display the list of students\n");
        printf("5. Sort the list of students by grade\n");
        printf("6. Split the list into high-level and low-level students\n");
        printf("   a. Sort sub-lists by grade\n");
        printf("   b. Merge the two sub-lists\n");
        printf("7. Calculate the exam average\n");
        printf("8. Free all student data\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                T_Student newStudent = createStudent();
                sentinel = addStudent(sentinel, newStudent->name, newStudent->id_num, newStudent->grade);
                break;
            case 2:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter ID: ");
                scanf("%ld", &id);
                printf("Enter grade: ");
                scanf("%f", &grade);
                sentinel = addStudent(sentinel, name, id, grade);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%ld", &id);
                findStudent(sentinel, id);
                break;
            case 4:
                displaylist(sentinel);
                break;
            case 5:
                sortList(sentinel);
                printf("The list has been sorted by grades.\n");
                break;
            case 6:
                splitList(sentinel, &highLevel, &lowLevel);
                printf("The list has been split into high-level and low-level students.\n");
                printf("\nHigh-level Students:\n");
                displaylist(highLevel);
                printf("\nLow-level Students:\n");
                displaylist(lowLevel);

                printf("\nSorting both sub-lists by grades...\n");
                sortList(highLevel);
                sortList(lowLevel);

                printf("\nSorted High-level Students:\n");
                displaylist(highLevel);
                printf("\nSorted Low-level Students:\n");
                displaylist(lowLevel);

                printf("\nMerging both sub-lists back into one sorted list...\n");
                sentinel = mergeLists(highLevel, lowLevel);
                displaylist(sentinel);
                break;
            case 7:
                printf("The exam average is: %.2f\n", averageExam(sentinel));
                break;
            case 8:
                freeList(sentinel);
                sentinel = (T_Student)malloc(sizeof(struct student));
                if (!sentinel) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
                sentinel->next = NULL;
                printf("All data has been freed.\n");
                break;
            case 9:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 9);

    freeList(sentinel);
    return 0;
}
