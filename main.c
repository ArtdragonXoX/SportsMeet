#include "Organization.h"

void test();

int main()
{
    test();
    return 0;
}

void test()
{
        InitOrganizationList();
    char tem1[]="数计学院";
    char tem2[]="工学院";
    char tem3[]="文学院";
    InsertNextOrganization(tem1);
    InsertNextOrganization(tem2);
    InsertNextOrganization(tem3);
    PrintAllOrganization();

    DeleteOrganization(2);
    PrintAllOrganization();
}