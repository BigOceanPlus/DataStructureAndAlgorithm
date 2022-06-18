#include <stdio.h>
#include <stdlib.h>

typedef struct stu{  // 学生的结构体
    char name[20];  // 姓名
    char id[20];  // 学号

    int* mark;  // 学科成绩的数组

    int sum;  // 总分
}Student;

int n,m;  // n个学生 m个学科

/*
Input: 
3 2
Math Chinese
Kang 2021 88 77
Ming 1672 76 91
Yang 0456 99 84
*/

int com(const void* x,const void* y){  //  std排序
    Student* p1 = (Student*)x;
    Student* p2 = (Student*)y;
    return p2->sum - p1->sum;
}

int main(){
    scanf("%d %d",&n,&m);  
    Student array[n];

    char subject[m][20];
    for(int j = 0; j < m; j ++)  // 读取学科
        scanf("%s",subject[j]);

    for(int i = 0; i < n; i ++){  // n个学生
        scanf("%s %s",array[i].name,array[i].id);

        array[i].mark = (int*)malloc(sizeof(int) * m);
        for(int j = 0; j < m; j ++)  // 读取各科成绩
            scanf("%d",&array[i].mark[j]);

        // 计算总分
        array[i].sum = 0;
        for(int j = 0; j < m; j ++)
            array[i].sum += array[i].mark[j];
        
    }

    qsort(array,n,sizeof(Student),com);  // 排序

    // 打印表头
    printf("\n%s\t\t%s\t\t%s\t\t","排名","姓名","学号");
    for(int j = 0; j < m; j ++)
        printf("%s\t\t",subject[j]);
    printf("%s\n","总分");

    // 打印表的主体内容
    int count = 1;  // 排名
    for(int i = 0; i < n; i ++){
        printf("%d\t\t%s\t\t%s\t\t",count ++,array[i].name,array[i].id);
        for(int j = 0; j < m; j ++)
            printf("%d\t\t",array[i].mark[j]);

        printf("%d\n",array[i].sum);
    }
    return 0;
}