#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    char name[50];
    long id_num;
    float grade;
    struct student *next;
};

typedef struct student *T_Student;

T_Student createStudent()
{

    T_Student newStudent = (T_Student)malloc(sizeof(T_Student));

    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    printf("Enter the name of the student: ");
    scanf("%s", newStudent->name);

    printf("Enter the student's ID: ");
    scanf("%ld", &newStudent->id_num);

    printf("Enter the student's grade: ");
    scanf("%f", &newStudent->grade);

    newStudent->next = NULL;

    return newStudent;
}

void displaylist(T_Student sentinel)
{

    if (!sentinel->next)
    {
        printf("No students in the list.\n");
        return;
    }

    printf("List of students: \n");
    printf("--------------------------------------------------\n");
    printf("| %-30s | %-10s | %-5s |\n", "Name", "ID", "Grade");
    printf("--------------------------------------------------\n");

    T_Student current = sentinel->next;
    while (current)
    {
        printf("| %-30s | %-10ld | %-5.3f |\n", current->name, current->id_num, current->grade);
        current = current->next;
    }
}

T_Student addStudent(T_Student sentinel, char name[], long id, float grade)
{
    T_Student newStudent = (T_Student)malloc(sizeof(struct student));

    if (newStudent == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newStudent->name, name);
    newStudent->id_num = id;
    newStudent->grade = grade;

    newStudent->next = sentinel->next;
    sentinel->next = newStudent;
}

int studentCount(T_Student sentinel)
{
    int count = 0;

    T_Student current = sentinel->next;

    while (current != NULL)
    {
        count++;
        current = current->next;
    }

    return count;
}

void findStudent(T_Student sentinel, long id)
{
    T_Student current = sentinel->next;

    while (current)
    {
        if (current->id_num == id)
        {
            printf("Student: \n");
            printf("--------------------------------------------------\n");
            printf("| %-30s | %-10s | %-5s |\n", "Name", "ID", "Grade");
            printf("--------------------------------------------------\n");
            printf("| %-30s | %-10ld | %-5.3f |\n", current->name, current->id_num, current->grade);
        }
        else
            printf("No Student with %d is found!", id);
    }
}