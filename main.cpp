#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct stu
{
    char p[30];
    int wz;
    int zg;
}du[50000],zu[800000];
int gs=0,k=0;
int bpwz(const void *a,const void *b)
{
    return(*(struct stu*)a).wz>(*(struct stu*)b).wz?1:-1;
}
int zgwz(const void *a,const void *b)
{
    return(*(struct stu*)a).zg>(*(struct stu*)b).zg?1:-1;
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
void cundang()
{

}
void tianjia()
{
    int xz,i,j,flag,xx,sx;
    char xz1;
    char cy[200],dc[30];
    FILE *fp;
    printf("\n欢迎进入数据添加模块\n");
    while(1)
    {
        printf("\n1.开始添加\n2.查看结果\n3.和原有数据合并\n4.返回上级\n\n请选择：");
        scanf("%d",&xz);
        if(xz==1)
        {
            if((fp=fopen("wenzhang.txt","r"))==NULL)
            {
                printf("\n程序发生崩溃，已为您安全结束程序\n");
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
                printf("\n程序发生崩溃，已为您安全结束程序\n");
                exit(0);
            }
        }
        else if(xz==2)
        {
            printf("\n请输入本文次数的下限：");
            scanf("%d",&xx);
            printf("\n请输入本文次数的上限：");
            scanf("%d",&sx);
            printf("\n  单词     本文次数\n");
            for(i=0;i<gs;i++)
            {
                if(du[i].wz>=xx&&du[i].wz<=sx)
                {
                    printf("%s %d\n",du[i].p,du[i].wz);
                }
            }
            printf("\n已输出所有\n");
        }
        else if(xz==3)
        {
            if((fp=fopen("xinxi.txt","r"))==NULL)
            {
                printf("\n程序发生崩溃，已为您安全结束程序\n");
                exit(0);
            }
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
                printf("\n程序发生崩溃，已为您安全结束程序\n");
                exit(0);
            }
            printf("\n请输入总共次数的下限：");
            scanf("%d",&xx);
            printf("\n请输入总共次数的上限：");
            scanf("%d",&sx);
            printf("\n  单词     本文次数     总共次数\n");
            for(i=0;i<k;i++)
            {
                if(zu[i].zg>=xx&&zu[i].zg<=sx)
                {
                    printf("%s %d     %d\n",zu[i].p,zu[i].wz,zu[i].zg);
                }
            }
            printf("\n已输出所有,是否将以上信息存档，以便下次查看，y/n？：");
            scanf("%c",&xz1);
            if(xz1=='y')
            {
                cundang();
            }
            else if(xz1=='n')
            {
                printf("\n信息未存档\n");
            }
            else
            {
                printf("\n输入非法，信息未存档\n");
            }
        }
        else if(xz==4)
        {
            printf("\n已经为您退出数据添加模块\n");
            return ;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
}
void paixu()
{
    int xz,xz1;
    printf("\n欢迎进入数据排序模块\n");
    while(1)
    {
        printf("\n1.本篇文章\n2.所有文章\n3.返回上级\n\n请选择：");
        scanf("%d",&xz);
        if(xz==1)
        {
            while(1)
            {
                printf("\n1.按次数顺序\n3.按字母顺序\n3.返回上级\n\n请选择：");
                scanf("%d",&xz1);
                if(xz1==1)
                {
                    qsort(du,gs,sizeof(struct stu),bpwz);
                }
                else if(xz1==2)
                {
                    qsort(du,gs,sizeof(struct stu),zdx);
                }
                else if(xz1==3)
                {
                    break;
                }
                else
                {
                    printf("\n对不起，您的输入非法，请您重新输入\n");
                }
            }
        }
        else if(xz==2)
        {
            while(1)
            {
                printf("\n1.按次数顺序\n3.按字母顺序\n3.返回上级\n\n请选择：");
                scanf("%d",&xz1);
                if(xz1==1)
                {
                    qsort(du,gs,sizeof(struct stu),bpwz);
                }
                else if(xz1==2)
                {
                    qsort(zu,gs,sizeof(struct stu),zdx);
                }
                else if(xz1==3)
                {
                    break;
                }
                else
                {
                    printf("\n对不起，您的输入非法，请您重新输入\n");
                }
            }
        }
        else if(xz==3)
        {
            printf("\n已经为您退出数据排序模块\n");
            return ;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
}
void sousuo()
{
    int xz;
    printf("\n欢迎进入数据搜索模块\n");
    while(1)
    {
        printf("\n1.开始添加\n2.返回上级\n\n请选择：");
        scanf("%d",&xz);
        if(xz==2)
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
int main()
{
    int xz;
    printf("*****************************************\n\n\n\n\n       欢迎使用词数统计程序 V1.0\n\n\n\n\n*****************************************\n\n");
    while(1)
    {
        printf("\n1.数据添加\n2.数据排序\n3.数据搜索\n4.退出程序\n\n请选择：");
        scanf("%d",&xz);
        if(xz==1)
        {
            tianjia();
        }
        else if(xz==2)
        {
            paixu();
        }
        else if(xz==3)
        {
            sousuo();
        }
        else if(xz==4)
        {
            printf("\n已经为您安全退出程序\n");
            break;
        }
        else
        {
            printf("\n对不起，您的输入非法，请您重新输入\n");
        }
    }
    return 0;
}
