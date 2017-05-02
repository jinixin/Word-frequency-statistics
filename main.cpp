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
    char p[50];
    int cs;
    double qfb;
    int bj;//该单词出现的篇数-是否高频,是否重点
}du[100000],zu[500000];
char shanchu[100000][20];
int gs,k,shanchugeshu,wzzs;
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
        else if(isupper(dc[i]))
        {
            return 1;//大写字母（大多是人名）
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
    if((fp=fopen("amain(system).in","r"))==NULL)
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
    if((fp=fopen("bzong(system).out","r"))==NULL)
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
int durupanduan(int n)
{
    FILE *fp;
    char q[50];
    int t;
    if((fp=fopen("calrea(system).in","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    fscanf(fp,"%s%d",q,&t);
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        exit(0);
    }
    qsort(du,gs,sizeof(struct stu),zdx);
    if((strcmp(du[gs-1].p,q)==0)&&(gs==t))
    {
        return 0;
    }
    if(n==1)
    {
        if((fp=fopen("calrea(system).in","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        fprintf(fp,"%s %d",du[gs-1].p,gs);
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
    }
    return 1;
}
void chajieguo(int fl)
{
    int i;
    char q[50];
    if(fl==1)
    {
         printf("\n  单词                 本文出现次数    千分比（占本篇文章）\n");
         for(i=0;i<gs;i++)
         {
             printf("  %-20s    %5d        %8.2lf\n",du[i].p,du[i].cs,du[i].qfb);
         }
         printf("\n******已输出所有符合条件的单词******\n");
    }
    else if(fl==2)
    {
        printf("\n  单词                 总共出现次数    千分比（占所有文章）\n");
        for(i=0;i<k;i++)
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
            printf("  %-20s    %5d        %8.2lf %15s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
        }
        printf("\n******已输出所有符合条件的单词******\n");
    }
}
void cundang(int fl)
{
    int i;
    char q[50];
    FILE *fp;
    if(fl==1)
    {
        if((fp=fopen("新文章单词数.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
        fprintf(fp,"\n  单词                 本文出现次数    千分比（占本篇文章）\n");
        for(i=0;i<gs;i++)
        {
            fprintf(fp,"  %-20s    %5d        %8.2lf\n",du[i].p,du[i].cs,du[i].qfb);
        }
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            exit(0);
        }
    }
    else if(fl==2)
    {
        if((fp=fopen("bzong(system).out","w"))==NULL)
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
        fprintf(fp,"\n  单词                 总共出现次数    千分比（占所有文章）\n");
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
                fprintf(fp,"  %-20s    %5d        %8.2lf %15s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
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
    FILE *fp;
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
    if((fp=fopen("amain(system).in","w"))==NULL)
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
    int i,j,zgs;
    char cy[10000],dc[5000];
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
    for(zgs=0,i=0;i<gs;i++)
    {
        zgs+=du[i].cs;
    }
    for(i=0;i<gs;i++)
    {
        du[i].qfb=du[i].cs*1000.0/zgs;
    }
}
void paixu(int fl)
{
    int xz1,xz2;
    while(1)
    {
        printf("\n1.按次数顺序\n2.按字母顺序\n0.返回上级\n\n请选择：");
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
                    cundang(1);
                    printf("\n对新文章单词的上升排序已完成\n您可至“查看结果”选项中查看\n");
                }
                else if(fl==2)
                {
                    qsort(zu,k,sizeof(struct stu),zgsx);
                    cundang(2);
                    printf("\n对所有文章单词的上升排序已完成\n您可至“查看结果”选项中查看\n");
                }
            }
            else if(xz2==2)
            {
                if(fl==1)
                {
                    qsort(du,gs,sizeof(struct stu),wzjx);
                    cundang(1);
                    printf("\n对新文章单词的下降排序已完成\n您可至“查看结果”选项中查看\n");
                }
                else if(fl==2)
                {
                    qsort(zu,k,sizeof(struct stu),zgjx);
                    cundang(2);
                    printf("\n对所有文章单词的下降排序已完成\n您可至“查看结果”选项中查看\n");
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
                cundang(1);
                printf("\n对新文章单词的字典序排序已完成\n您可至“查看结果”选项中查看\n");
            }
            else if(fl==2)
            {
                qsort(zu,k,sizeof(struct stu),zdx);
                cundang(2);
                printf("\n对所有文章单词的字典序排序已完成\n您可至“查看结果”选项中查看\n");
            }
        }
        else if(xz1==0)
        {
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
    int i;
    char dc[50],q[50];
    printf("\n请输入所要查询的单词：");
    scanf("%s",dc);
    if(fl==1)
    {
        for(i=0;i<gs;i++)
        {
            if(strcmp(du[i].p,dc)==0)
            {
                printf("\n已找到您要查找的%s单词\n",dc);
                printf("\n  单词                 本文出现次数    千分比（占本篇文章）\n");
                printf("  %-20s    %5d        %8.2lf\n",du[i].p,du[i].cs,du[i].qfb);
                break;
            }
        }
        if(i==gs)
        {
            printf("\n对不起，您要查找的%s单词在表中不存在\n",dc);
        }
    }
    else if(fl==2)
    {
        for(i=0;i<k;i++)
        {
            if(strcmp(zu[i].p,dc)==0)
            {
                printf("\n已找到您要查找的%s单词\n",dc);
                printf("\n  单词                 总共出现次数    千分比（占所有文章）\n");
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
                printf("  %-20s    %5d        %8.2lf %15s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
                break;
            }
        }
        if(i==k)
        {
            printf("\n对不起，您要查找的%s单词在表中不存在\n",dc);
        }
    }
}
int main()
{
    int xz1,xz2;
    printf("**********************************************\n\n\n\n\n\n\n          欢迎使用词数统计程序  V2.0\n\n\n\n\n\n\n**********************************************\n\n");
    shanchuzong();
    while(1)
    {
        printf("\n1.添加新的文章\n2.处理汇总数据\n3.联系我们\n4.退出程序\n\n请选择：");
        scanf("%d",&xz1);
        if(xz1==1)
        {
            while(1)
            {
                printf("\n1.开始添加\n2.查看结果\n3.排序单词\n4.搜索单词\n5.保存结果\n6.和原有数据合并\n0.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2!=1&&gs==0&&xz2!=0)
                {
                    printf("\n对不起，新文章数据表中还没有任何数据\n建议您先进行“开始添加”操作后再进行以上操作\n");
                    continue;
                }
                if(xz2==1)
                {
                    tianjia();
                    if(!durupanduan(0))
                    {
                        printf("\n对不起，您刚刚执行过了添加操作\n故本次操作已禁止\n");
                        continue;
                    }
                    printf("\n******添加新文章成功******\n");
                }
                else if(xz2==2)
                {
                    chajieguo(1);
                }
                else if(xz2==3)
                {
                    paixu(1);
                }
                else if(xz2==4)
                {
                    sousuo(1);
                }
                else if(xz2==5)
                {
                    cundang(1);
                    printf("\n******保存结果成功******\n");
                    //printf("\n对不起，您刚刚执行过了保存操作\n故本次操作已禁止\n");
                }
                else if(xz2==6)
                {
                    if(durupanduan(1))
                    {
                        hebin();
                        printf("\n******和原有数据合并成功******\n");
                    }
                    else
                    {
                        printf("\n对不起，您刚刚执行过了合并操作\n一篇文章只能与原有数据合并一次，故本次操作已禁止\n");
                    }
                }
                else if(xz2==0)
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
                printf("\n2.查看结果\n3.排序单词\n4.搜索单词\n0.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2!=0&&k==0)
                {
                    printf("\n对不起，汇总数据表中还没有任何数据\n建议您先对数据进行合并汇总后再进行以上操作\n\n在此自动为您返回上级\n");
                    break;
                }
                if(xz2==2)
                {
                    chajieguo(2);
                }
                else if(xz2==3)
                {
                    paixu(2);
                }
                else if(xz2==4)
                {
                    sousuo(2);
                }
                else if(xz2==0)
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
            printf("\n******************************************************************\n");
            printf("程序名称    ：单词个数统计程序\n");
            printf("程序版本    ：V2.0\n");
            printf("内核版本    ：V1.4（基于优化V1.0）\n");
            printf("迭代次数    ：11\n");
            printf("开发语言    ：C/C++\n");
            printf("开发所属    ：AEM 工程\n");
            printf("开发者      ：Bei feng\n");
            printf("系统当前时间：%s\n",time);
            printf("系统当前日期：%s/%s/%s\n",year,month,day);
            printf("初次开发日期：2014/07/30\n");
            printf("最后更新日期：2014/10/02\n");
            printf("**********************************\n");
            printf("\n如有任何改进意见，请联系我们：jinixinwork@sina.com\n");
            printf("\n******************************************************************\n");
        }
        else if(xz1==4)
        {
            printf("\n感谢您的使用，已经为您安全退出程序\n\n请您按任意键退出本对话框\n");
            break;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
    return 0;
}
