#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cctype>
#include<ctime>
#include<windows.h>//屏幕缓冲区大小
using namespace std;
struct stu
{
    char p[50];
    int cs;
    double qfb;
    int bj;//该单词出现的篇数-是否高频,是否重点
}du[100000],zu[500000];
char shanchu[100000][20];
int gs,k,shanchugeshu,wzzs,xz;
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
int tbsx(const void *a,const void *b)
{
    return(*(struct stu*)a).bj<(*(struct stu*)b).bj?1:-1;
}
void shanchuzong()
{
    int i=0;
    FILE *fp;
    if((fp=fopen("这些单词不统计.txt","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
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
        getchar();
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
        getchar();
        getchar();
        exit(0);
    }
    fscanf(fp,"%d",&wzzs);
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("bzong(system).out","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
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
        getchar();
        getchar();
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
        getchar();
        getchar();
        exit(0);
    }
    fscanf(fp,"%s%d",q,&t);
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
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
            getchar();
            getchar();
            exit(0);
        }
        fprintf(fp,"%s %d",du[gs-1].p,gs);
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            getchar();
            getchar();
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
        printf("\n  ********************************************************\n");
        printf("\n  单词                 本文出现次数    千分比（占本篇文章）\n");
        for(i=0;i<gs;i++)
        {
            printf("  %-20s    %5d        %8.2lf\n",du[i].p,du[i].cs,du[i].qfb);
        }
        printf("\n  ******已输出所有符合条件的单词******\n");
        printf("\n  本篇文章共有%d个有效单词\n",gs);
    }
    else if(fl==2)
    {
        printf("\n  *********************************************************\n");
        printf("\n  单词                 总共出现次数    千分比（占所有文章）\n");
        for(i=0;i<k;i++)
        {
            if(wzzs>3)
            {
                if(zu[i].bj*3>wzzs)
                {
                    strcpy(q,"超高频");
                }
                else if(zu[i].bj*4>wzzs)
                {
                    strcpy(q,"高频");
                }
                else
                {
                    strcpy(q,"");
                }
            }
            else
            {
                strcpy(q,"");
            }
            printf("  %-20s    %5d        %8.2lf %15s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
        }
        printf("\n  ******已输出所有符合条件的单词******\n");
        printf("\n  所有文章共有%d个有效单词\n",k);
    }
}
void beifensj()
{
    FILE *fp1,*fp2;
    char c;
    if((fp1=fopen("ehgsj(system).in","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp2=fopen("bzong(system).out","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    while(!feof(fp2))
    {
        c=fgetc(fp2);
        if(c!=EOF)
        {
            fputc(c,fp1);
        }
    }
    if(fclose(fp2))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(fclose(fp1))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
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
            getchar();
            getchar();
            exit(0);
        }
        fprintf(fp,"\n  ********************************************************\n");
        fprintf(fp,"\n  单词                 本文出现次数    千分比（占本篇文章）\n");
        for(i=0;i<gs;i++)
        {
            fprintf(fp,"  %-20s    %5d        %8.2lf\n",du[i].p,du[i].cs,du[i].qfb);
        }
        fprintf(fp,"\n  ******已输出所有符合条件的单词******\n");
        fprintf(fp,"\n  本篇文章共有%d个有效单词\n",gs);
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            getchar();
            getchar();
            exit(0);
        }
    }
    else if(fl==2)
    {
        //beifensj();
        if((fp=fopen("bzong(system).out","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            getchar();
            getchar();
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
            getchar();
            getchar();
            exit(0);
        }
        if((fp=fopen("所有文章单词数.txt","w"))==NULL)
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            getchar();
            getchar();
            exit(0);
        }
        fprintf(fp,"\n  ********************************************************\n");
        fprintf(fp,"\n  单词                 总共出现次数    千分比（占所有文章）\n");
        for(i=0;i<k;i++)
        {
            if(!shanchufeng(zu[i].p))
            {
                if(wzzs>3)
                {
                    if(zu[i].bj*3>wzzs)
                    {
                        strcpy(q,"超高频");
                    }
                    else if(zu[i].bj*4>wzzs)
                    {
                        strcpy(q,"高频");
                    }
                    else
                    {
                        strcpy(q,"");
                    }
                }
                else
                {
                    strcpy(q,"");
                }
                fprintf(fp,"  %-20s    %5d        %8.2lf %15s\n",zu[i].p,zu[i].cs,zu[i].qfb,q);
            }
        }
        fprintf(fp,"\n  ******已输出所有符合条件的单词******\n");
        fprintf(fp,"\n  所有文章共有%d个有效单词\n",k);
        if(fclose(fp))
        {
            printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
            getchar();
            getchar();
            exit(0);
        }
    }
}
void hebin()
{
    int i,j,flag,zgs;
    FILE *fp;
    duruzongshu();
    for(xz=0,i=0;i<gs;i++)
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
            xz++;
        }
    }
    if((fp=fopen("amain(system).in","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    fprintf(fp,"%d",wzzs+1);
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
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
        getchar();
        getchar();
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
        getchar();
        getchar();
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
                    printf("\n******对新文章单词的上升排序已完成******\n您可至“查看结果”选项中查看\n");
                }
                else if(fl==2)
                {
                    qsort(zu,k,sizeof(struct stu),zgsx);
                    cundang(2);
                    printf("\n******对所有文章单词的上升排序已完成******\n您可至“查看结果”选项中查看\n");
                }
            }
            else if(xz2==2)
            {
                if(fl==1)
                {
                    qsort(du,gs,sizeof(struct stu),wzjx);
                    cundang(1);
                    printf("\n******对新文章单词的下降排序已完成******\n您可至“查看结果”选项中查看\n");
                }
                else if(fl==2)
                {
                    qsort(zu,k,sizeof(struct stu),zgjx);
                    cundang(2);
                    printf("\n******对所有文章单词的下降排序已完成******\n您可至“查看结果”选项中查看\n");
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
                printf("\n******对新文章单词的字典序排序已完成******\n您可至“查看结果”选项中查看\n");
            }
            else if(fl==2)
            {
                qsort(zu,k,sizeof(struct stu),zdx);
                cundang(2);
                printf("\n******对所有文章单词的字典序排序已完成******\n您可至“查看结果”选项中查看\n");
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
                printf("\n  ******已找到您要查找的%s单词******\n",dc);
                printf("\n  单词                 本文出现次数    千分比（占本篇文章）\n");
                printf("  %-20s    %5d        %8.2lf\n",du[i].p,du[i].cs,du[i].qfb);
                break;
            }
        }
        if(i==gs)
        {
            printf("\n******对不起，您要查找的%s单词在表中不存在******\n",dc);
        }
    }
    else if(fl==2)
    {
        for(i=0;i<k;i++)
        {
            if(strcmp(zu[i].p,dc)==0)
            {
                printf("\n  ******已找到您要查找的%s单词******\n",dc);
                printf("\n  单词                 总共出现次数    千分比（占所有文章）\n");
                if(wzzs>3)
                {
                    if(zu[i].bj*3>wzzs)
                    {
                        strcpy(q,"超高频");
                    }
                    else if(zu[i].bj*4>wzzs)
                    {
                        strcpy(q,"高频");
                    }
                    else
                    {
                        strcpy(q,"");
                    }
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
            printf("\n******对不起，您要查找的%s单词在表中不存在******\n",dc);
        }
    }
}
void chushihua()
{
    FILE *fp;
    if((fp=fopen("amain(system).in","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    fprintf(fp,"0");
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("bzong(system).out","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("calrea(system).in","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    fprintf(fp,"a 0");
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("所有文章单词数.txt","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("新文章.txt","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("新文章单词数.txt","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    k=gs=0;
    printf("\n******初始化软件（删除所有数据）成功******\n");
    printf("\n******在此自动为您返回上级******\n");
}
void zwxf()
{
    FILE *fp;
    if((fp=fopen("amain(system).in","r"))==NULL)
    {
        fp=fopen("amain(system).in","w");
    }
    fprintf(fp,"0");
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("bzong(system).out","r"))==NULL)
    {
        fp=fopen("bzong(system).out","w");
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("calrea(system).in","r"))==NULL)
    {
        fp=fopen("calrea(system).in","w");
    }
    fprintf(fp,"a 0");
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("djhrq(system).out","r"))==NULL)
    {
        fp=fopen("djhrq(system).out","w");
    }
    fprintf(fp,"1 1 1");
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("ehgsj(system).in","r"))==NULL)
    {
        fp=fopen("ehgsj(system).in","w");
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("所有文章单词数.txt","r"))==NULL)
    {
        fp=fopen("所有文章单词数.txt","w");
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("新文章.txt","r"))==NULL)
    {
        fp=fopen("新文章.txt","w");
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("新文章单词数.txt","r"))==NULL)
    {
        fp=fopen("新文章单词数.txt","w");
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp=fopen("这些单词不统计.txt","r"))==NULL)
    {
        fp=fopen("这些单词不统计.txt","w");
    }
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    printf("\n******自我修复（异常处理-修复丢失的文件）成功******\n");
}
int jihuoriqi()
{
    FILE *fp;
    int y,m,d,fh,xz;
    char time[20],day[20],month[20],year[20],jihuo[20];
    if((fp=fopen("djhrq(system).out","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃\n崩溃原因（可能）：程序共有10个文件（.exe文件不可以脱离其余9个文件单独存在）\n\n在此为您提供两种解决方案：\n\n1.自我修复（异常处理-自动修复丢失的文件）\n2.安全退出程序（您自行寻回丢失的文件）\n\n请选择：");
        scanf("%d",&xz);
        if(xz==1)
        {
            zwxf();
            fp=fopen("djhrq(system).out","r");
        }
        else if(xz==2)
        {
            printf("\n现已为您安全结束程序，请您按任意键退出本对话框\n");
            getchar();getchar();
            exit(0);
        }
        else
        {
            printf("\n对不起，您的输入非法\n现已为您安全结束程序，请您按任意键退出本对话框\n");
            getchar();getchar();
            exit(0);
        }
    }
    fscanf(fp,"%d %d %d",&y,&m,&d);
    if(fclose(fp))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(y==1&&m==1&&d==1)
    {
        fh=1;
    }
    else if(y==0&&m==0&&d==0)
    {
        printf("\n  感谢您首次使用\"词数统计程序\"，使用前请阅读\"使用说明\"以获得激活码和操作方式\n");
        printf("\n  您好，我们检测到您的程序尚未激活\n  请您在此输入永久激活码或试用码：");
        scanf("%s",jihuo);
        if(strstr(jihuo,"ASDFGQ")!=NULL)
        {
            printf("\n******已为您永久激活程序，感谢您的使用******\n");
            if((fp=fopen("djhrq(system).out","w"))==NULL)
            {
                printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
                getchar();
                getchar();
                exit(0);
            }
            fprintf(fp,"1 1 1\n");
            if(fclose(fp))
            {
                printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
                getchar();
                getchar();
                exit(0);
            }
            fh=1;
        }
        else if(strstr(jihuo,"ZXCVBP")!=NULL)
        {
            printf("\n******您输入的是30天试用码，感谢您的使用******\n");
            _strdate(time);
            day[0]=time[3];day[1]=time[4];day[2]='\0';
            month[0]=time[0];month[1]=time[1];month[2]='\0';
            year[0]='2';year[1]='0';year[2]=time[6];year[3]=time[7];year[4]='\0';
            if(strcmp(month,"12")==0)
            {
                strcpy(month,"01");
                if(year[3]=='9')
                {
                    year[2]++;
                    year[3]='0';
                }
                else
                {
                    year[3]++;
                }
            }
            else if(strcmp(month,"09")==0)
            {
                strcpy(month,"10");
            }
            else
            {
                month[1]++;
            }
            if((fp=fopen("djhrq(system).out","w"))==NULL)
            {
                printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
                getchar();
                getchar();
                exit(0);
            }
            fprintf(fp,"%s %s %s\n",year,month,day);
            if(fclose(fp))
            {
                printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
                getchar();
                getchar();
                exit(0);
            }
            fh=2;
        }
        else
        {
            printf("\n对不起，您输入的激活码或试用码有误\n我们建议您联系：jixinwork@qq.com\n");
            fh=0;
        }
    }
    else
    {
        _strdate(time);
        day[0]=time[3];day[1]=time[4];day[2]='\0';
        month[0]=time[0];month[1]=time[1];month[2]='\0';
        year[0]='2';year[1]='0';year[2]=time[6];year[3]=time[7];year[4]='\0';
        strcat(year,month);
        strcat(year,day);
        //puts(year);
        sprintf(month,"%d",y);
        sprintf(day,"%d",m);
        if(strlen(day)==1)
        {
            day[1]=day[0];
            day[0]='0';
            day[2]='\0';
        }
        strcat(month,day);
        sprintf(day,"%d",d);
        if(strlen(day)==1)
        {
            day[1]=day[0];
            day[0]='0';
            day[2]='\0';
        }
        strcat(month,day);
        //puts(month);
        if(strcmp(month,year)<0)
        {
            printf("\n******对不起，您的试用期已过******\n如您想继续使用，我们建议您输入永久激活码：");
            scanf("%s",jihuo);
            if(strstr(jihuo,"ASDFGQ")!=NULL)
            {
                printf("\n******已为您永久激活程序，感谢您的使用******\n");
                if((fp=fopen("djhrq(system).out","w"))==NULL)
                {
                    printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
                    getchar();
                    getchar();
                    exit(0);
                }
                fprintf(fp,"1 1 1\n");
                if(fclose(fp))
                {
                    printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
                    getchar();
                    getchar();
                    exit(0);
                }
                fh=1;
            }
            else
            {
                printf("\n对不起，您输入的激活码有误\n我们建议您联系：jixinwork@qq.com\n");
                fh=0;
            }
        }
        else
        {
            fh=2;
        }
    }
    return fh;
}
void lianxiwm(int pd)
{
    char time[20],day[10],month[10],year[10];
    _strdate(time);
    day[0]=time[3];day[1]=time[4];day[2]='\0';
    month[0]=time[0];month[1]=time[1];month[2]='\0';
    year[0]='2';year[1]='0';year[2]=time[6];year[3]=time[7];year[4]='\0';
    _strtime(time);
    printf("\n*********************************************************\n");
    printf("程 序 名 称 ：英文单词频数统计软件\n");
    printf("程 序 版 本 ：V2.6");
    if(pd==1)
    {
        printf("（ 已激活 ）\n");
    }
    else if(pd==2)
    {
        printf("（ 试 用 ）\n");;
    }
    printf("内 核 版 本 ：V1.4（ 基于优化V1.0 ）\n");
    printf("迭 代 次 数 ：17\n");
    printf("开 发 语 言 ：C/C++\n");
    printf("开 发 所 属 ：AEM 工程\n");
    printf("开 发 者    ：ji xin\n");
    printf("系统当前时间：%s\n",time);
    printf("系统当前日期：%s/%s/%s\n",year,month,day);
    printf("程序开发周期：2014/07/30  至  2014/10/07\n");
    printf("最后更新说明：V2.6/功能优化   2015/01/22\n");
    printf("******************************************\n");
    printf("\n程序仅作交流学习之用，严禁商业用途。如有发现，追其失责\n若有改进意见，请联系我们：jixinwork@qq.com\n");
    printf("\n*********************************************************\n");
}
void huigunsj()
{
    FILE *fp1,*fp2;
    char c;
    if((fp1=fopen("bzong(system).out","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp2=fopen("ehgsj(system).in","r"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    while(!feof(fp2))
    {
        c=fgetc(fp2);
        if(c!=EOF)
        {
            fputc(c,fp1);
        }
    }
    if(fclose(fp2))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(fclose(fp1))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if((fp1=fopen("calrea(system).in","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    fprintf(fp1,"a 0");
    if(fclose(fp1))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    duruzongshu();
    if((fp1=fopen("amain(system).in","w"))==NULL)
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    if(wzzs>1)
    {
        wzzs--;
    }
    fprintf(fp1,"%d",wzzs);
    if(fclose(fp1))
    {
        printf("\n对不起，程序发生崩溃，现已为您安全结束程序\n\n请您按任意键退出本对话框\n");
        getchar();
        getchar();
        exit(0);
    }
    cundang(2);
    printf("\n******回滚数据（还原到上次未合并前）成功******\n");
    printf("\n******在此自动为您返回上级******\n");
}
void tbfx()
{
    int flag[100];
    int rd,i,r;
    memset(flag,0,sizeof(flag));
    qsort(zu,k,sizeof(struct stu),tbsx);
    printf("\n图表分析如下（重要词汇及其出现的篇章频数）：\n");
    for(i=0;i<27;)
    {
        rd=rand()/300;
        if((rd>=0&&rd<90)&&(!flag[rd]))
        {
            flag[rd]=1;
            i++;
            printf("%-12s ",zu[rd].p);
            r=zu[rd].bj*2;
            while(r--)
            {
                printf("�{");
            }
            printf("\n");
        }
    }
    printf("\n******图表分析成功******\n");
    printf("\n******在此自动为您返回上级******\n");
}
int main()
{
    system("color f0");//字体色和背景色
    system("mode con cols=80 lines=40");//屏幕大小
    HANDLE con=GetStdHandle(STD_OUTPUT_HANDLE);//屏幕缓冲区大小
    COORD buf={100,5000};//屏幕缓冲区大小（宽*长）
    SetConsoleScreenBufferSize(con,buf);//屏幕缓冲区大小
    int xz1,xz2,flag1,pd;
    pd=jihuoriqi();
    if(!pd)
    {
        printf("\n如有不便，请您谅解\n在此自动为您退出程序");
        goto loop2;
    }
    printf("*************************************************************\n\n\n\n\n\n\n\n\n\n                欢迎使用英文单词频数统计软件\n\n\n\n\n\n\n\n                                                     V2.6\n\n*************************************************************\n\n");
    shanchuzong();
    while(1)
    {
        printf("\n1.添加新的文章\n2.处理汇总数据\n3.一键添加\n4.系统工具\n0.退出程序\n\n请选择：");
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
                        printf("\n对不起，您刚刚执行过了添加操作（本篇文章已添加，不可重复添加）\n");
                        printf("******故本次操作已禁止******\n");
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
                        beifensj();
                        printf("\n******和原有数据合并成功******\n");
                        printf("\n合并本篇文章后所有数据在原有数据基础上新增了%d个有效单词\n",xz);
                    }
                    else
                    {
                        printf("\n对不起，您刚刚执行过了合并操作（本篇文章已合并，不可重复合并）\n一篇文章只能与原有数据合并一次\n");
                        printf("******故本次操作已禁止******\n");
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
                printf("\n2.查看结果\n3.排序单词\n4.搜索单词\n5.图表分析\n0.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2!=0&&k==0)
                {
                    printf("\n对不起，汇总数据表中还没有任何数据\n建议您先对数据进行合并汇总后再进行以上操作\n");
                    printf("\n******在此自动为您返回上级******\n");
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
                else if(xz2==5)
                {
                    tbfx();
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
            printf("\n************************\n一键添加将为您完成“添加新文章”，“保存结果”，“打印结果”操作\n此外您还可以选择是否进行“和原有数据合并”的操作\n\t\t\t\t\t************************\n");
            loop1:printf("\n1.和原有数据合并\n2.不和原有数据合并\n0.返回上级\n\n请选择：");
            scanf("%d",&xz2);
            flag1=0;
            if(xz2==1||xz2==2)
            {
                tianjia();
                if(!durupanduan(0))
                {
                    printf("\n对不起，您刚刚执行过了添加操作（本篇文章已添加，不可重复添加）\n");
                    printf("******故本次操作已禁止******\n");
                    printf("\n******在此自动为您返回上级******\n");
                    continue;
                }
                printf("\n******添加新文章成功******\n");
                cundang(1);
                printf("\n******保存结果成功******\n");
                if(xz2==1)
                {
                    if(durupanduan(1))
                    {
                        hebin();
                        beifensj();
                        printf("\n******和原有数据合并成功******\n");
                        flag1=1;
                    }
                    else
                    {
                        printf("\n对不起，您刚刚执行过了合并操作（本篇文章已合并，不可重复合并）\n一篇文章只能与原有数据合并一次\n");
                        printf("******故本次操作已禁止******\n");
                        printf("\n******在此自动为您返回上级******\n");
                        continue;
                    }
                }
                chajieguo(1);
                if(flag1==1)
                {
                    printf("\n  合并本篇文章后所有数据在原有数据基础上新增了%d个有效单词\n",xz);
                }
                printf("\n******一键添加成功******\n");
                printf("\n******在此自动为您返回上级******\n");
            }
            else if(xz2==0)
            {
                ;
            }
            else
            {
                printf("\n对不起，您的输入非法，请您重新输入\n");
                goto loop1;
            }
        }
        else if(xz1==4)
        {
            int chushiflag=0,huigunflag=0;
            while(1)
            {
                printf("\n1.初始化软件（删除所有数据-慎选）\n2.回滚数据 （还原到上次未合并前）\n3.自我修复（异常处理-修复丢失的文件）\n4.联系我们\n0.返回上级\n\n请选择：");
                scanf("%d",&xz2);
                if(xz2==0)
                {
                    break;
                }
                else if(xz2==1)
                {
                    if(chushiflag==1)
                    {
                        printf("\n对不起，您刚刚执行过了初始化操作（不可重复初始化）\n");
                        printf("******故本次操作已禁止******\n");
                    }
                    else
                    {
                        chushihua();
                        chushiflag=1;
                    }
                }
                else if(xz2==2)
                {
                    if(huigunflag==1)
                    {
                        printf("\n对不起，您刚刚执行过了回滚数据操作（不可重复回滚）\n");
                        printf("******故本次操作已禁止******\n");
                    }
                    else
                    {
                        huigunsj();
                        huigunflag=1;
                    }
                }
                else if(xz2==3)
                {
                    zwxf();
                    printf("\n******在此自动为您返回上级******\n");
                }
                else if(xz2==4)
                {
                    lianxiwm(pd);
                }
                else
                {
                    printf("\n对不起，您的输入非法，请您重新输入\n");
                }
            }
        }
        else if(xz1==0)
        {
            loop2:printf("\n感谢您的使用，已经为您安全退出程序\n\n******请您按任意键退出本对话框******\n");
            getchar();
            getchar();
            break;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
    return 0;
}
