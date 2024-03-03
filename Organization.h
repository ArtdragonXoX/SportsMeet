#pragma once
#include <string.h>
#include "List.h"

typedef struct 
{
    char* name;
}Organization;

void InitOrganizationList();

int InsertNextOrganization(char* name);

int InsertNextOrganizationNode(Organization* organization);

const char* GetOrganizationName(int serial);

int DeleteOrganization(int serial);

int NumberOfOrganization();
