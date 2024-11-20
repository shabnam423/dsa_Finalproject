#ifndef STUDENT_H
#define STUDENT_H

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

T_Student createStudent();
void displaylist(T_Student sentinel);
T_Student addStudent(T_Student sentinel, char name[], long id, float grade);
int studentCount(T_Student sentinel);
void findStudent(T_Student sentinel, long id);
void deleteLastStudent(T_Student sentinel);
void sortList(T_Student sentinel);
float averageExam(T_Student sentinel);
void freeList(T_Student sentinel);
void splitList(T_Student sentinel, T_Student *highLevel, T_Student *lowLevel);
T_Student mergeLists(T_Student firstSentinel, T_Student secondSentinel);

#endif