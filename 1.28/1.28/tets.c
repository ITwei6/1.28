#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	char* p = "hehe";//将首字母地址传给p
//	printf("hehe\n");//常量字符串，将首字符的地址传给printf
//	printf(p);//相当于将首字母地址传过去
//	return 0;
//}
//int* test()
//{
//	int a = 10;
//	return &a;
//}
//int main()
//{
//	 int *p=test();
//	 printf("hehhe");//返回栈空间地址问题
//	 printf("%d", *p);
//	return 0;
//}
//void Getmemory(char* p)//用p来接收str的数据，p是形参，形参是实参的一份临时拷贝
//{
//	p = (char*)malloc(100);//给p开辟一个100字节的空间。
//	//还有这里开辟了空间后，并没有释放，造成内存泄漏。
//}
//void test(void)
//{
//	char* str = NULL;
//	Getmemory(str);//将str这个指针传过去，相当于传值过去，并不是传址输入，对形参的改变并不会影响实参。
//	strcpy(str, "hello world");//这里的str还是空指针，并没有空间给它拷贝，形成NULL非法访问，这里就出错了。
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
#include <string.h>
#include <stdlib.h>
//void Getmemory(char** p)//str是一级指针，&str就是二级指针
//{
//	*p = (char*)malloc(100);//*p就相当于str，就是给str开辟一个100字节的空间
//}
//void test(void)
//{
//	char* str = NULL;
//	Getmemory(&str);//这里进行传址输入，利用形参修改实参
//	strcpy(str, "hello world");//这里的str就拥有了100字节的空间了
//	printf(str);
//	free(str);//释放空间
//	str = NULL;//手动置NULL
//}
//int main()
//{
//	test();
//	return 0;
//}
//char* Getmemory(void)
//{
//	char p[] = "hello world";//创建一个数组p，里面存放着字符串
//	return p;//返回数组名，也就是返回了数组首元素的地址
//}
//void test(void)
//{
//	char* str = NULL;
//	str = Getmemory();//Getmemory函数的返回值用str来接收
//	//数组p的首元素地址用str来接收
//	//但要注意的是，p数组是在Getmemory内部创建，创建在栈区，出了函数，这个空间就要返回给操作系统，不再受指针p操控。
//	//所以str虽然得到了数组的首元素地址，但这片空间已经不再属于数组空间了，所以形成了非法访问
//	printf(str);//打印str指向的字符
//}
//void Getmemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//开辟100个字节空间给*p  *p就是str
//	//所以给str开辟了100字节的空间
//}
//
//void test(void)
//{
//	char* str = NULL;
//	Getmemory(&str, 100);//传址输入，可以通过对形参修改而修改实参
//	strcpy(str, "xiao tao");//对str指向的空间进行拷贝
//	printf(str);//打印拷贝后的空间内容
//	//最最重要的一点是，空间申请后，释放呢？这里没有释放所以最后会造成内存泄漏
//	free(str);//释放内存
//	str = NULL;
//}
//void test(void)
//{
//	char* str = (char*)malloc(100);//开辟100个字节的空间
//	strcpy(str, "xiao tao");//给指向srt的空间进行拷贝
//	free(str);//释放空间
	//str = NULL;//释放空间后手动置为NULL，让下面的操作无法进行
	//free的功能是将原先指向这块空间的指针与这块空间之间的联系断开，这块空间不再首这个指针调控，回归到操作系统，供有需要的使用
	//而free释放空间后并不会将原先指向这块空间的指针置为空指针，还是指向原先的地方，所以下面的操作就进行下去了
	//所以这个指针又去访问那块空间让其被覆盖成666，这就造成非法访问了
//	if (str != NULL)//如果str不为空指针进行下面操作
//	{
//		strcpy(str, "666");
//		printf(str);//打印指向str那块空间的内容
//	}
//}
//int main()
//{
//	test();
//	return 0;
//}
//struct S
//{
//	int a;
//	char arr[];//不设置大小--柔性数组，结构体中最后一个，前面至少要求一个成员
//	//这个结构体大小是除柔性数组以外的成员计算得到大小
//	//柔性数组的空间使用需要malloc开辟
//};
//int main()
//{//使用malloc函数给结构体变量开辟内存，sizeof(struct S)是为结构体中除柔性数组外成员分配空间，而后面的则是为柔性数组开辟空间
//	//最后都把开辟的空间转换为结构体类型，用结构体指针来接收
//	struct S*p=(struct S*)malloc(sizeof(struct S) + 10 * sizeof(char));
//	if (p == NULL)//判断一下
//	{
//		perror("malloc");
//		return 1;
//	}
//	p->a = 100;//访问变量
//	int i = 0;
//	for (i = 0; i < 10; i++)//给数组分配了10个整形的空间
//	{
//		p->arr[i] = '6';//使用这块空间
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", p->arr[i]);//打印出来
//	}
//	//想要给柔性数组增容 -----p指向的是原先的空间大小的指针，要想开辟更大的空间，在原基础上加就可以了
//	struct S*ptr=(struct S*)realloc(p,sizeof(struct S) + 20 * sizeof(char));
//	if (ptr != NULL)//还是要判断一下
//	{
//		p = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	//释放
//	free(p);
//	p = NULL;
//	return 0;
//}//
//频繁的malloc会使内存碎片增多，影响访问速度
//struct Stu
//{
//	int n;
//	int arr[];
//};
//int main()
//{
//	printf("%d", sizeof(struct Stu));
//	return 0;
//}
struct S
{
	int a;
	int* arr;//成员是指针不是柔性数组
	//用malloc使这个指针指向一块大小可以是自己改变的
};
int main()
{
	struct S *p = (struct S*)malloc(sizeof(struct S));//给结构体变量申请一块空间，用结构体指针接收
	p->a = 100;//访问结构体成员
	p->arr = (int*)malloc(10 * sizeof(int));//给指针arr指向的地方申请10个整形空间
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = '6';//使用malloc为arr开辟的空间
	}
	for (i = 0; i < 10; i++)
	{
		printf("%c ", p->arr[i]);
	}
	//增容
	int *ptr=(int*)realloc(p->arr, 20 * sizeof(int));
	if (ptr == NULL)//判断一下
	{
		perror("realloc");
		return 1;
	}
	free(p->arr);//必须先释放arr开辟的空间再释放p开辟的空间，从里到外释放
	p->arr = NULL;
	free(p);
	p = NULL;
	return 0;
}