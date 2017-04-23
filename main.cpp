#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct stu
{
    char p[50];
    int wz;
    int zg;
}du[50000],zu[800000];
int gs,k;
int wzsx(const void *a,const void *b)
{
    return(*(struct stu*)a).wz>(*(struct stu*)b).wz?1:-1;
}
int wzjx(const void *a,const void *b)
{
    return(*(struct stu*)a).wz<(*(struct stu*)b).wz?1:-1;
}
int zgsx(const void *a,const void *b)
{
    return(*(struct stu*)a).zg>(*(struct stu*)b).zg?1:-1;
}
int zgjx(const void *a,const void *b)
{
    return(*(struct stu*)a).zg<(*(struct stu*)b).zg?1:-1;
}
int zdx(const void *a,const void *b)
{
    if(strcmp((*(struct stu*)a).p,(*(struct stu*)b).p)>=0)
       return 1;
    else
       return -1;
    return 0;
}
void panduan(char *dc)
{
    int i;
    for(i=0;i<gs;i++)
    {
        if(strcmp(du[i].p,dc)==0)
        {
            du[i].wz++;
            return ;
        }
    }
    strcpy(du[gs].p,dc);
    du[gs].wz=0;du[gs++].zg=0;
}
void duruzongshu()
{
    FILE *fp;
    if((fp=fopen("zongshu.txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    k=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s%d",zu[k].p,&zu[k].zg);
        zu[k].wz=0;
        k++;
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
}
void chajieguo(int fl)
{
    int xx,sx,i;
    if(fl==1)
    {
         printf("\n请输入单词在本文出现次数的下限：");
         scanf("%d",&xx);
         printf("\n请输入单词在本文出现次数的上限：");
         scanf("%d",&sx);
         printf("\n    单词     本文次数\n");
         for(i=0;i<gs;i++)
         {
             if(du[i].wz>=xx&&du[i].wz<=sx)
             {
                  printf("%s   %d\n",du[i].p,du[i].wz);
             }
         }
         printf("\n已输出所有符合条件的单词\n");
    }
    else if(fl==2)
    {
        printf("\n请输入单词出现总共次数的下限：");
        scanf("%d",&xx);
        printf("\n请输入单词出现总共次数的上限：");
        scanf("%d",&sx);
        printf("\n    单词     本文次数     总共次数\n");
        for(i=0;i<k;i++)
        {
            if(zu[i].zg>=xx&&zu[i].zg<=sx)
            {
                printf("%s %d     %d\n",zu[i].p,zu[i].wz,zu[i].zg);
            }
        }
        printf("\n已输出所有符合条件的单词\n");
    }
}
void cundang(int fl)
{
    int i;
    FILE *fp;
    if(fl==1)
    {
        if((fp=fopen("geshu.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        for(i=0;i<gs;i++)
        {
            fprintf(fp,"%s %d\n",du[i].p,du[i].wz);
        }
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
    }
    else if(fl==2)
    {
        if((fp=fopen("zongshu.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        for(i=0;i<k;i++)
        {
            fprintf(fp,"%s %d\n",zu[i].p,zu[i].zg);
        }
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
    }
}
void hebin()
{
    int i,j,flag;
    FILE *fp;
    if((fp=fopen("zongshu.txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    k=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s%d",zu[k].p,&zu[k].zg);
        zu[k].wz=0;
        k++;
    }
    for(i=0;i<gs;i++)
    {
        for(flag=0,j=0;j<k;j++)
        {
            if(strcmp(du[i].p,zu[j].p)==0)
            {
                zu[j].zg=zu[j].zg+du[i].wz;
                zu[j].wz=zu[j].wz+du[i].wz;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            strcpy(zu[k].p,du[i].p);
            zu[k].wz=du[i].wz;
            zu[k++].zg=du[i].wz;
        }
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    cundang(2);
}
void tianjia()
{
    int i,j;
    char cy[300],dc[50];
    char xz1;
    FILE *fp;
    gs=0;
    if((fp=fopen("wenzhang.txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",cy);
        for(j=0,i=0;;i++)
        {
            if(ispunct(cy[i]))
            {
                if(j!=0)
                {
                    dc[j]='\0';
                    panduan(dc);
                    j=0;
                }
            }
            else if(isupper(cy[i]))
            {
                dc[j]=cy[i]+32;
                j++;
            }
            else if(cy[i]=='\0')
            {
                dc[j]='\0';
                panduan(dc);
                break;
            }
            else
            {
                dc[j]=cy[i];
                j++;
            }
        }
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    loop1:printf("\n文章已添加完成\n\n是否现在显示单词分类结果，请选择y/n：");
    getchar();
    scanf("%c",&xz1);
    if(xz1=='y')
    {
         chajieguo(1);
    }
    else if(xz1=='n')
    {
        printf("\n您可“返回上级”至“辅助功能”里查看本结果\n");
        return ;
    }
    else
    {
        printf("\n对不起，您的输入非法，请您重新输入\n");
        goto loop1;
    }
}
void paixu(int fl)
{
    int xz1,xz2;
    printf("\n欢迎进入排序模块\n");
    while(1)
    {
        printf("\n1.按次数顺序\n2.按字母顺序\n3.返回上级\n\n请选择：");
        scanf("%d",&xz1);
        if(xz1==1)
        {
            loop2:printf("\n1.升序\n2.降序\n\n请选择：");
            scanf("%d",&xz2);
            if(xz2==1)
            {
                if(fl==1)
                {
                    qsort(du,gs,sizeof(struct stu),wzsx);
                }
                else if(fl==2)
                {
                    qsort(zu,k,sizeof(struct stu),zgsx);
                }
            }
            else if(xz2==2)
            {
                if(fl==1)
                {
                    qsort(du,gs,sizeof(struct stu),wzjx);
                }
                else if(fl==2)
                {
                    qsort(zu,k,sizeof(struct stu),zgjx);
                }
            }
            else
            {
                printf("\n对不起，您的输入非法，请您重新输入\n");
                goto loop2;
            }
        }
        else if(xz1==2)
        {
            if(fl==1)
            {
                qsort(du,gs,sizeof(struct stu),zdx);
            }
            else if(fl==2)
            {
                qsort(zu,k,sizeof(struct stu),zdx);
            }
        }
        else if(xz1==3)
        {
            printf("\n已经为您退出排序模块\n");
            return ;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
}
void sousuo(int fl)
{
    int xz1,i;
    char dc[50];
    printf("\n欢迎进入数据搜索模块\n");
    while(1)
    {
         printf("\n1.搜索单词\n2.返回上级\n\n请选择：");
         scanf("%d",&xz1);
         if(xz1==1)
         {
             printf("\n请输入所要查询的单词：");
             scanf("%s",dc);
             if(fl==1)
             {
                 printf("\n  单词     本文中出现次数\n");
                 for(i=0;i<gs;i++)
                 {
                     if(strcmp(du[i].p,dc)==0)
                     {
                         printf("%s %d\n",du[i].p,du[i].wz);
                         break;
                     }
                 }
             }
             else if(fl==2)
             {
                 printf("\n  单词     总共出现次数\n");
                 for(i=0;i<k;i++)
                 {
                     if(strcmp(zu[i].p,dc)==0)
                     {
                         printf("%s %d\n",zu[i].p,zu[i].zg);
                         break;
                     }
                 }
             }
         }
         else if(xz1==2)
         {
             printf("\n已经为您退出数据搜索模块\n");
             return ;
         }
         else
         {
             printf("\n对不起，您的输入非法，请您重新输入\n");
         }
    }
}
void fuzhu()
{
    int xz1;
    printf("\n欢迎进入辅助功能模块\n");
    while(1)
    {
        printf("\n1.查看结果\n2.将数据存档\n3.和原有数据合并\n4.返回上级\n\n请选择：");
        scanf("%d",&xz1);
        if(xz1==1)
        {
            chajieguo(1);
        }
        else if(xz1==2)
        {
            cundang(1);
        }
        else if(xz1==3)
        {
            hebin();
        }
        else if(xz1==4)
        {
            printf("\n已经为您退出辅助功能模块\n");
            return ;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
}
int main()
{
    int xz1,xz2;
    printf("*****************************************\n\n\n\n\n\n       欢迎使用词数统计程序 V1.2\n\n\n\n\n\n*****************************************\n\n");
    while(1)
    {
        printf("\n1.添加新文章\n2.查看汇总数据\n3.退出程序\n\n请选择：");
        scanf("%d",&xz1);
        if(xz1==1)
        {
            while(1)
            {
                printf("\n1.开始添加\n2.排序单词\n3.搜索单词\n4.辅助功能\n5.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2==1)
                {
                    tianjia();
                }
                else if(xz2==2)
                {
                    paixu(1);
                }
                else if(xz2==3)
                {
                    sousuo(1);
                }
                else if(xz2==4)
                {
                    fuzhu();
                }
                else if(xz2==5)
                {
                    break;
                }
                else
                {
                    printf("\n对不起，您的输入非法，请您重新输入\n");
                }
            }
        }
        else if(xz1==2)
        {
            duruzongshu();
            while(1)
            {
                printf("\n1.查看结果\n2.排序单词\n3.搜索单词\n4.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2==1)
                {
                    chajieguo(2);
                }
                else if(xz2==2)
                {
                    paixu(2);
                }
                else if(xz2==3)
                {
                    sousuo(2);
                }
                else if(xz2==4)
                {
                    break;
                }
                else
                {
                    printf("\n对不起，您的输入非法，请您重新输入\n");
                }
            }
        }
        else if(xz1==3)
        {
            printf("\n已经为您安全退出程序\n\n请您按任意键退出本对话框\n");
            break;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
    return 0;
}
