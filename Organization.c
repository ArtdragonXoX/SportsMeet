#include "Organization.h"
List* organizationList=NULL;

void InitOrganizationList()
{
    organizationList=InitList();
}

int InsertNextOrganization(char *name)
{
    Organization *organization = (Organization *)malloc(sizeof(Organization));
    char *name_ = (char *)malloc(sizeof(char) * strlen(name));
    strcpy(name_, name);
    organization->name = name_;
    return InsertNextOrganizationNode(organization);
}

int InsertNextOrganizationNode(Organization *organization)
{
    return InsertNextListData(organizationList,organization);
}

const char *GetOrganizationName(int serial)
{
    ListNode* node=GetListNode(organizationList,serial);
    if(node==NULL)
        return NULL;
    Organization* organization=node->data;
    return organization->name;
}

int DeleteOrganization(int serial)
{
    Organization* data=DeleteListNode(organizationList,serial);
    if(data==NULL)
        return 0;
    free(data->name);
    free(data);
    return 1;
}

int NumberOfOrganization()
{
    return NumberOfList(organizationList);
}
