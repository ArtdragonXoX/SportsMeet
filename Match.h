#pragma once

#include "Vector.h"

typedef struct
{
    char* name;
    char* unit; //单位名称
    int sex; //性别限制，0为无限制，1为男，2为女
    int site;  //场地序号
    int order;  //1为成绩最高第一，2为成绩最低第一
}Match;

void InitMatchVector();

int InsertNextMatch(char* name,char* unit,int sex,int site,int order);

int InsertNextMatchNode(Match* match);

Match* GetMatch(int serial);

char* GetMatchName(int serial);

int GetMatchSex(int serial);

int GetMatchSite(int serial);

int GetMatchOrder(int serial);

int DeleteMatch(int serial);

int NumberOfMatch();