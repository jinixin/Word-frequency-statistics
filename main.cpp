#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
struct stu
{
    char p[30];
    int cs;
    double qfb;
    int bj;//该单词出现的篇数-是否高频,是否重点
}du[50000],zu[900000];
char shanchu[20000][20];
int gs,k,shanchugeshu,wzzs,flag1=0,flag2=0,flag3=0;
int wzsx(const void *a,const void *b)
{
    return(*(struct stu*)a).cs>(*(struct stu*)b).cs?1:-1;
}
int wzjx(const void *a,const void *b)
{
    return(*(struct stu*)a).cs<(*(struct stu*)b).cs?1:-1;
}
int zgsx(const void *a,const void *b)
{
    return(*(struct stu*)a).cs>(*(struct stu*)b).cs?1:-1;
}
int zgjx(const void *a,const void *b)
{
    return(*(struct stu*)a).cs<(*(struct stu*)b).cs?1:-1;
}
int zdx(const void *a,const void *b)
{
    if(strcmp((*(struct stu*)a).p,(*(struct stu*)b).p)>=0)
       return 1;
    else
       return -1;
    return 0;
}
void shanchuzong()
{
    int i=0;
    FILE *fp;
    if((fp=fopen("这些单词不统计.txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    while(!feof(fp))
    {
        fscanf(fp,"%s",shanchu[i]);
        i++;
    }
    shanchugeshu=i;
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
}
int shanchufeng(char *dc)
{
    int i;
    for(i=0;i<shanchugeshu;i++)
    {
        if(strcmp(dc,shanchu[i])==0)
        {
            return 1;
        }
    }
    if(dc[0]=='\0')
    {
        return 1;
    }
    if(strstr(dc,"　")!=NULL)//大空格
    {
        return 1;
    }
    for(i=0;dc[i]!='\0';i++)
    {
        if(dc[i]==' ')
        {
            return 1;
        }
        else if(dc[i]>='0'&&dc[i]<='9')
        {
            return 1;
        }
        else if(dc[i]<0)//剔除汉字
        {
            return 1;
        }
    }
    return 0;
}
void panduan(char *dc)
{
    int i;
    if(shanchufeng(dc))
    {
        return ;
    }
    for(i=0;i<gs;i++)
    {
        if(strcmp(du[i].p,dc)==0)
        {
            du[i].cs++;
            return ;
        }
    }
    strcpy(du[gs].p,dc);
    du[gs].cs=1;
    gs++;
}
void duruzongshu()
{
    FILE *fp;
    if((fp=fopen("system.txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    fscanf(fp,"%d",&wzzs);
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    if((fp=fopen("zongshu(system).txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    k=0;
    while(!feof(fp))
    {
        fscanf(fp,"%s%d%lf%d",zu[k].p,&zu[k].cs,&zu[k].qfb,&zu[k].bj);
        if(!shanchufeng(zu[k].p))
        {
            k++;
        }
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
}
void chajieguo(int fl)
{
    int i,zgs;
    char q[20];
    if(fl==1)
    {
         for(zgs=0,i=0;i<gs;i++)
         {
             zgs+=du[i].cs;
         }
         printf("\n  单词                   本文次数    千分比（占本篇文章）\n");
         for(i=0;i<gs;i++)
         {
             du[i].qfb=du[i].cs*1000.0/zgs;
             printf("  %-20s    %5d        %.2lf\n",du[i].p,du[i].cs,du[i].qfb);
         }
         printf("\n已输出所有符合条件的单词\n");
    }
    else if(fl==2)
    {
        for(zgs=0,i=0;i<k;i++)
        {
            zgs+=zu[i].cs;
        }
        printf("\n  单词                   总共次数    千分比（占总共次数）\n");
        for(i=0;i<k;i++)
        {
            zu[i].qfb=zu[i].cs*1000.0/zgs;
            if(zu[i].bj*2>wzzs)
            {
                strcpy(q,"超高频");
            }
            else if(zu[i].bj*3>wzzs)
            {
                strcpy(q,"高频");
            }
            else
            {
                strcpy(q,"");
            }
            printf("  %-20s    %5d        %8.2lf %-10s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
        }
        printf("\n已输出所有符合条件的单词\n");
    }
}
void cundang(int fl)
{
    int i;
    char q[20];
    FILE *fp;
    if(fl==1)
    {
        if((fp=fopen("新文章单词数.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        for(i=0;i<gs;i++)
        {
            fprintf(fp,"  %-20s    %5d        %.2lf\n",du[i].p,du[i].cs,du[i].qfb);
        }
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
    }
    else if(fl==2)
    {
        if((fp=fopen("system.txt","r"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        fscanf(fp,"%d",&wzzs);
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        if((fp=fopen("system.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        fprintf(fp,"%d",wzzs+1);
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        if((fp=fopen("zongshu(system).txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        for(i=0;i<k;i++)
        {
            if(!shanchufeng(zu[i].p))
            {
                fprintf(fp,"%s %d %.2lf %d\n",zu[i].p,zu[i].cs,zu[i].qfb,zu[i].bj);
            }
        }
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        if((fp=fopen("所有文章单词数.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        for(i=0;i<k;i++)
        {
            if(!shanchufeng(zu[i].p))
            {
                if(zu[i].bj*2>wzzs)
                {
                    strcpy(q,"超高频");
                }
                else if(zu[i].bj*3>wzzs)
                {
                    strcpy(q,"高频");
                }
                else
                {
                    strcpy(q,"");
                }
                fprintf(fp,"  %-20s    %5d        %8.2lf %-10s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
            }
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
    int i,j,flag,zgs;
    duruzongshu();
    for(i=0;i<gs;i++)
    {
        for(flag=0,j=0;j<k;j++)
        {
            if(strcmp(du[i].p,zu[j].p)==0)
            {
                zu[j].cs+=du[i].cs;
                zu[j].bj++;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            strcpy(zu[k].p,du[i].p);
            zu[k].cs=du[i].cs;
            zu[k].bj=1;
            k++;
        }
    }
    for(zgs=0,i=0;i<k;i++)
    {
        zgs+=zu[i].cs;
    }
    for(i=0;i<k;i++)
    {
        zu[i].qfb=zu[i].cs*1000.0/zgs;
    }
    cundang(2);
}
void tianjia()
{
    int i,j;
    char cy[500],dc[30];
    char xz1;
    FILE *fp;
    gs=0;
    if((fp=fopen("新文章.txt","r"))==NULL)
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
                         printf("%s %d\n",du[i].p,du[i].cs);
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
                         printf("%s %d\n",zu[i].p,zu[i].cs);
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
            if(flag2==0)
            {
                cundang(1);
                flag2=1;
            }
            else
            {
                printf("\n对不起，您刚刚执行过了存档操作\n故本次操作已禁止\n");
            }
        }
        else if(xz1==3)
        {
            if(flag1==0)
            {
                hebin();
                flag1=1;
            }
            else
            {
                printf("\n对不起，您刚刚执行过了合并操作\n一篇文章只能与原有数据合并一次，故本次操作已禁止\n");
            }
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
    printf("*****************************************\n\n\n\n\n\n\n       欢迎使用词数统计程序  V1.7\n\n\n\n\n\n\n*****************************************\n\n");
    shanchuzong();
    while(1)
    {
        printf("\n1.添加新文章\n2.查看汇总数据\n3.联系我们\n4.退出程序\n\n请选择：");
        scanf("%d",&xz1);
        if(xz1==1)
        {
            while(1)
            {
                printf("\n1.开始添加\n2.排序单词\n3.搜索单词\n4.辅助功能\n5.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2==1)
                {
                    if(flag3==0)
                    {
                        tianjia();
                        flag3=1;
                    }
                    else
                    {
                        printf("\n对不起，您刚刚执行过了添加操作\n故本次操作已禁止\n");
                    }
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
            char time[20],day[10],month[10],year[10];
            _strdate(time);
            day[0]=time[3];day[1]=time[4];day[2]='\0';
            month[0]=time[0];month[1]=time[1];month[2]='\0';
            year[0]='2';year[1]='0';year[2]=time[6];year[3]=time[7];year[4]='\0';
            _strtime(time);
            printf("\n程序名称：单词个数统计程序\n");
            printf("程序版本：V1.7\n");
            printf("内核版本：V1.4（基于优化V1.0）\n");
            printf("迭代次数：8\n");
            printf("初次开发日期：2014/07/30\n");
            printf("最后更新日期：2014/10/01\n");
            printf("系统当前日期：%s/%s/%s\n",year,month,day);
            printf("系统当前时间：%s\n",time);
            printf("开发语言：C/C++\n");
            printf("开发所属：AEM工程\n");
            printf("开发者  ：Beifeng\n");
            printf("\n如有任何改进意见，请联系我们：jinixinwork@sina.com\n");
        }
        else if(xz1==4)
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
