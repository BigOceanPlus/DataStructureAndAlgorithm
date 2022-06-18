#include <stdio.h>
#define ERROR -1

int array[1200];  // 存放数据的数组

int Find(int array[],int n);  // 二分查找

/*
Input:
2
4
-1 1 3 4
5
1 2 3 4 5
Output:
1
-1
*/

int main(){
	
	int i,j,n,m;
	scanf("%d",&n);
	
	for(i = 0; i < n; i ++){  // 处理n组数据

		scanf("%d",&m);  // 读取数据
		for(j = 0; j < m; j ++)
			scanf("%d",array + j);
		
		printf("%d\n",Find(array,m));
	}

	return 0;
} 

int Find(int array[],int n){  // 运用二分查找，找出满足mid = array[mid]的元素
	int left = 0, right = n - 1;  // 初始化
	int mid;
	
	while(left <= right){
		mid = (left + right) / 2;
		if(mid < array[mid])  // 左半边查找
			right = mid - 1;
		else if(mid > array[mid])  // 右半边查找
			left = mid + 1;
		else  // 查找成功
			return mid;
	}
	
	return ERROR;  // 查找失败
}
