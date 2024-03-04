//场地信息
#pragma once

#include "List.h"

typedef struct
{
    char* name;
}Site;

void InitSiteList();

int InsertNextSite(char* name);

int InsertNextSiteNode(Site* site);

Site* GetSite(int serial);

char* GetSiteName(int serial);

int DeleteSite(int serial);

int NumberOfSite();