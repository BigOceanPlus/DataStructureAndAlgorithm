#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 100

char hashTable[MAX][15];
bool flag[MAX] = {0};
char names[30][15] = {"liqiyang","jinhaoran","lichunyang","wangshenghang","wangzhaoyu","pendong","huangzixing","longminyao","lixianzhen",
"yanglisi","wangwangyong","lijingmin","wangtongxuan","yangxinyin","liyuman","liyanghai","longyuan","fanxiappeng","siyachang","yangyisheng",
"gaoyuhu","sidaidi","wangyilong","yangzida","xurui","yezinan","yaohan","jixiaozhuo","wujiru","mahanten"};

int EasyHash(char* name);  // 哈希函数
int Find(char* name);  // 哈希表查找
void Insert(char* name);  // 哈希表插入

int main(){
    
    for(int i = 0; i < 30; i ++)  // 用30个姓名建表
        Insert(names[i]);  // 哈希表插入

    for(int i = 0; i < 30; i ++){  // 用30个姓名查表
        int length = Find(names[i]);
        if(length)
            printf("Search success, the find length is %d\n",length);
        else
            printf("Search faliure, the find length is %d\n",length);
    }

    return 0;
}

int EasyHash(char* name){
    char* scan = name;
    int value = 0;

    while(*scan){  // 将字符串的各个字母(大写字母转为小写字母)的ASCII码值相加再取余
        value += tolower(*scan);
        scan ++;
    }
    value %= MAX;

    return value;
}

void Insert(char* name){
    int value = EasyHash(name);  // 获取哈希值
    
    while(flag[value])  // 查找哈希表空位
        value = (value + 1) % MAX;  // 再散列

    strcpy(hashTable[value],name);  // 插入字符串
    flag[value] = 1;
        
}

int Find(char* name){  
    int value = EasyHash(name);  // 获取哈希值
    int length = 1;  // 查找长度

    while(flag[value]){  // 查找目标字符串
        if(strcmp(name,hashTable[value]) == 0)  // 查找成功
            return length;
        value = (value + 1) % MAX;  // 再散列
        length ++;
    }

    return 0;  // 若找到哈希表空位,说明查找失败
}
