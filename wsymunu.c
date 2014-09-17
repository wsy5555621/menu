/**************************************************************************************************/
/* Copyright (C)  2014-2015                                                                       */
/*                                                                                                */
/*  FILE NAME             :  wsymenu.c                                                            */
/*  PRINCIPAL AUTHOR      :  Wangshenyu                                                           */
/*  SUBSYSTEM NAME        :  menu                                                                 */
/*  MODULE NAME           :  menu                                                                 */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/11                                                           */
/*  DESCRIPTION           :  This is a menu program!                                              */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by wsy,2014/9/11.
 *
 */
 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
#define DESC_LEN    1024
#define CMD_NUM     10
#define CMD_LEN     10
 
typedef struct DataNode
{
    char   cmd[10];
    char   desc[DESC_LEN];
    struct DataNode *next;	 
}tDataNode;
 
void Init();
void Iscmdexist(char cmd[CMD_LEN]);
void Showallcmd();
 
char *a[CMD_NUM]={"open","shutdown","delete","end","pgup","pgdown","ctrl","shift","tab",
"help"};
	
tDataNode *head=NULL;
tDataNode *p=NULL;

main()
{
    Init();     
    /* cmd line begins */
    while(1)
    {
        char cmd[CMD_LEN];
        printf("Input a cmd  > ");
   	scanf("%s",&cmd);
   	if(strcmp("help",cmd)==0)
   	{
            Showallcmd(); 
        }
    	else    
        {    
            Iscmdexist(cmd);
        }
    } 	
}
 
/* Init cmd list */
void Init()
{
    int i;
    for(i=0;i<CMD_NUM;i++)
    {
        p=(tDataNode*)malloc(sizeof(tDataNode));
        snprintf(p->cmd, 10, "%s", a[i]);
        snprintf(p->desc,DESC_LEN,"This is the no.%d cmd!",i);
        p->next=head;
        head=p;
    }
}
  
void Iscmdexist(char cmd[CMD_LEN])
{
    p=head;
    while(p!=NULL)
    {
        if(strcmp(p->cmd,cmd)==0)
  	{
  	    printf("%s - %s\n",p->cmd,p->desc);
	    break;
   	}
        p=p->next;
   	if(!p)
   	{
    	    printf("This is a wrong cmd!\n");  	
 	}
    }
}

void Showallcmd()
{
    printf("Menu List:\n");
    p=head;
    while(p!=NULL)
    {
        printf("%s - %s\n",p->cmd,p->desc);
        p=p->next;
    }
}

