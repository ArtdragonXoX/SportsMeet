#include "Organization.h"

int serialOrganization=1;

ListNode* organizationList=NULL;

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
    organization->serial=serialOrganization++;
    return InsertNextOrganizationNode(organization);
}

int InsertNextOrganizationNode(Organization *organization)
{
    return InsertNextListData(organizationList,organization);
}

const char *GetOrganizationName(int _serial)
{
    int serial=SearchOrganization(_serial);
    if(serial==-1)
        return NULL;
    Organization* organization=GetListNodeData(organizationList,serial);
    return organization->name;
}

int DeleteOrganization(int _serial)
{
    int serial=SearchOrganization(_serial);
    DeleteListNode(organizationList,serial,DeleteOrganization_Fun_t);
    return 1;
}

int NumberOfOrganization()
{
    return NumberOfList(organizationList);
}

int SearchOrganization(int serial)
{
    return SearchData(organizationList,&serial,SearchOrganization_Fun_t);
}

int SearchOrganization_Fun_t(void *data,void *searchData)
{
    int serial=((Organization*)data)->serial;
    int searchSerial=*(int*)searchData;
    if(serial==searchSerial)
        return 1;
    return 0;
}

void DeleteOrganization_Fun_t(void *data)
{
    free((Organization*)data);
}

void PrintAllOrganization()
{
    Iterator* it = InitIterator(organizationList);
    printf("学校组织\n");
    printf("------------------------------------------\n");
    printf("%5s %10s","编号","名称\n");
    while(it->node!=NULL)
    {
        Organization* data=(Organization*)IteratorData(it);
        printf("%5d %10s\n",data->serial,data->name);
        IteratorNextNode(it);
    }
    printf("------------------------------------------\n");
    FreeIterator(it);
}
