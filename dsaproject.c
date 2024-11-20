#include<stdio.h>
#include<stdlib.h>
#include <string.h>

struct student {
  char name[50];
  long id_num;
  float grade;
  struct student* next;
};

typedef struct student* T_Student;

T_Student createStudent() {

  T_Student newStudent = (T_Student)malloc(sizeof(struct student));

  if (newStudent == NULL) {
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

void displaylist(T_Student sentinel) {

  if(!sentinel->next){
        printf("No students in the list.\n");
        return;
  }

  printf("List of students: \n");
  printf("--------------------------------------------------\n");
  printf("| %-30s | %-10s | %-5s |\n", "Name", "ID", "Grade");
  printf("--------------------------------------------------\n");

  T_Student current = sentinel->next;
  while(current) {
    printf("| %-30s | %-10ld | %-5.3f |\n", current->name, current->id_num, current->grade);
    current = current->next;
  }

}

T_Student addStudent(T_Student sentinel, char name[], long id, float grade) {
    T_Student newStudent = (T_Student)malloc(sizeof(struct student));

    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    strcpy(newStudent->name, name);
    newStudent->id_num = id;
    newStudent->grade = grade;

    newStudent->next = sentinel->next;
    sentinel->next = newStudent;

    return sentinel;
}

int studentCount(T_Student sentinel) {
  int count = 0;

  T_Student current = sentinel->next;

  while(current!=NULL) {
    count++;
    current = current->next;
  }

  return count;
}

void findStudent(T_Student sentinel, long id) {
    T_Student current = sentinel->next;
    while (current) {
        if (current->id_num == id) {
            printf("Student: \n");
            printf("--------------------------------------------------\n");
            printf("| %-30s | %-10s | %-5s |\n", "Name", "ID", "Grade");
            printf("--------------------------------------------------\n");
            printf("| %-30s | %-10ld | %-5.3f |\n", current->name, current->id_num, current->grade);
            return;
        }
        current = current->next;
    }
    printf("No Student with ID %ld is found!\n", id);
}

void deleteLastStudent(T_Student sentinel) {
    if (!sentinel->next) {
        printf("No students to delete.\n");
        return;
    }

    T_Student current = sentinel->next;
    if (!current->next) {
        free(current);
        sentinel->next = NULL;
        return;
    }

    while (current->next && current->next->next) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
}

void sortList(T_Student sentinel) {
  T_Student sorted = NULL;

  T_Student current = sentinel->next;
  while(current) {
    T_Student next = current->next;
    if (sorted == NULL || sorted->grade >= current->grade) {
      current->next = sorted;
      sorted = current;
    } else {
      T_Student temp = sorted;
      while (temp->next != NULL && temp->next->grade < current->grade) {
        temp = temp->next;
      }

    current->next = temp->next;
    temp->next = current;
    }
    
    current = next;
  } 
  sentinel->next = sorted;
}

float averageExam(T_Student sentinel) {
    T_Student current = sentinel->next;

    float sum = 0;
    int count = 0;

    while (current) {
        sum += current->grade;
        count++;
        current = current->next;
    }

    if (count == 0) {
        printf("No students in the list.\n");
        return 0;
    }

    float average = sum / count;

    if (average > 65) {
        printf("Greater than 65.\n");
    } else if (average > 50 && average <= 65) {
        printf("Between 50 and 65.\n");
    } else {
        printf("Less than 50.\n");
    }

    return average;
}

void freeList(T_Student sentinel) {
  T_Student current = sentinel->next;

  while(current) {
    T_Student prev = current;
    current = current->next;
    free(prev);
  }
  free(sentinel);
}

void splitList(T_Student sentinel,  T_Student* highLevel, T_Student* lowLevel){
  *highLevel = (T_Student)malloc(sizeof(struct student));
  *lowLevel = (T_Student)malloc(sizeof(struct student));

  if (!*highLevel || !*lowLevel) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  (*highLevel)->next = NULL;
  (*lowLevel)->next = NULL;

  T_Student current = sentinel->next;

  while(current) {
    T_Student newStudent = (T_Student)malloc(sizeof(struct student));

    if (!newStudent) {
      printf("Memory allocation failed.\n");
      exit(1);
    }

    strcpy(newStudent->name, current->name);
    newStudent->id_num = current->id_num;
    newStudent->grade = current->grade;
    newStudent->next = NULL;

    if (current->grade >= 65) {
      newStudent->next = (*highLevel)->next;
      (*highLevel)->next = newStudent;
    } else {
        newStudent->next = (*lowLevel)->next;
        (*lowLevel)->next = newStudent;
    }

    current = current->next;
  }
}

T_Student mergeLists(T_Student firstSentinel, T_Student secondSentinel) {
    if (!firstSentinel || !secondSentinel) {
        printf("Error: One or both sentinels are NULL.\n");
        return NULL;
    }

    if (!firstSentinel->next) {
        free(firstSentinel);
        return secondSentinel;
    }

    if (!secondSentinel->next) {
      free(secondSentinel);
      return firstSentinel;
    }

    T_Student current = firstSentinel;
    while (current->next) {
        current = current->next;
    }

    current->next = secondSentinel->next;
    free(secondSentinel);

    return firstSentinel;
}