#pragma once
#include <string.h>
#include "List.h"
#include "Iterator.h"

typedef struct 
{
    int serial;
    char* name;
}Organization;

void InitOrganizationList();

int InsertNextOrganization(char* name);

int InsertNextOrganizationNode(Organization* organization);

const char* GetOrganizationName(int serial);

int DeleteOrganization(int serial);

int NumberOfOrganization();

int SearchOrganization(int serial);

//定义寻找函数
int SearchOrganization_Fun_t(void* data,void *searchData);

//定义删除函数
void DeleteOrganization_Fun_t(void* data);

void PrintAllOrganization();