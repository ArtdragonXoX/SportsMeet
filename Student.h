#pragma once

typedef struct
{
    char* name;
    int sex;
}Student;

void InitStudentVector();

int InsertNextStudent(char* name,int sex);

int InsertNextStudentNode(Student* student);

Student* GetStudent(int serial);

char* GetStudentName(int serial);

int GetStudentSex(int serial);

int DeleteStudent(int serial);

int NumberOfStudent();