#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//int main()
//{
//	char* p = "hehe";//������ĸ��ַ����p
//	printf("hehe\n");//�����ַ����������ַ��ĵ�ַ����printf
//	printf(p);//�൱�ڽ�����ĸ��ַ����ȥ
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
//	 printf("hehhe");//����ջ�ռ��ַ����
//	 printf("%d", *p);
//	return 0;
//}
//void Getmemory(char* p)//��p������str�����ݣ�p���βΣ��β���ʵ�ε�һ����ʱ����
//{
//	p = (char*)malloc(100);//��p����һ��100�ֽڵĿռ䡣
//	//�������￪���˿ռ�󣬲�û���ͷţ�����ڴ�й©��
//}
//void test(void)
//{
//	char* str = NULL;
//	Getmemory(str);//��str���ָ�봫��ȥ���൱�ڴ�ֵ��ȥ�������Ǵ�ַ���룬���βεĸı䲢����Ӱ��ʵ�Ρ�
//	strcpy(str, "hello world");//�����str���ǿ�ָ�룬��û�пռ�����������γ�NULL�Ƿ����ʣ�����ͳ����ˡ�
//	printf(str);
//}
//int main()
//{
//	test();
//	return 0;
//}
#include <string.h>
#include <stdlib.h>
//void Getmemory(char** p)//str��һ��ָ�룬&str���Ƕ���ָ��
//{
//	*p = (char*)malloc(100);//*p���൱��str�����Ǹ�str����һ��100�ֽڵĿռ�
//}
//void test(void)
//{
//	char* str = NULL;
//	Getmemory(&str);//������д�ַ���룬�����β��޸�ʵ��
//	strcpy(str, "hello world");//�����str��ӵ����100�ֽڵĿռ���
//	printf(str);
//	free(str);//�ͷſռ�
//	str = NULL;//�ֶ���NULL
//}
//int main()
//{
//	test();
//	return 0;
//}
//char* Getmemory(void)
//{
//	char p[] = "hello world";//����һ������p�����������ַ���
//	return p;//������������Ҳ���Ƿ�����������Ԫ�صĵ�ַ
//}
//void test(void)
//{
//	char* str = NULL;
//	str = Getmemory();//Getmemory�����ķ���ֵ��str������
//	//����p����Ԫ�ص�ַ��str������
//	//��Ҫע����ǣ�p��������Getmemory�ڲ�������������ջ�������˺���������ռ��Ҫ���ظ�����ϵͳ��������ָ��p�ٿء�
//	//����str��Ȼ�õ����������Ԫ�ص�ַ������Ƭ�ռ��Ѿ�������������ռ��ˣ������γ��˷Ƿ�����
//	printf(str);//��ӡstrָ����ַ�
//}
//void Getmemory(char** p, int num)
//{
//	*p = (char*)malloc(num);//����100���ֽڿռ��*p  *p����str
//	//���Ը�str������100�ֽڵĿռ�
//}
//
//void test(void)
//{
//	char* str = NULL;
//	Getmemory(&str, 100);//��ַ���룬����ͨ�����β��޸Ķ��޸�ʵ��
//	strcpy(str, "xiao tao");//��strָ��Ŀռ���п���
//	printf(str);//��ӡ������Ŀռ�����
//	//������Ҫ��һ���ǣ��ռ�������ͷ��أ�����û���ͷ�������������ڴ�й©
//	free(str);//�ͷ��ڴ�
//	str = NULL;
//}
//void test(void)
//{
//	char* str = (char*)malloc(100);//����100���ֽڵĿռ�
//	strcpy(str, "xiao tao");//��ָ��srt�Ŀռ���п���
//	free(str);//�ͷſռ�
	//str = NULL;//�ͷſռ���ֶ���ΪNULL��������Ĳ����޷�����
	//free�Ĺ����ǽ�ԭ��ָ�����ռ��ָ�������ռ�֮�����ϵ�Ͽ������ռ䲻�������ָ����أ��ع鵽����ϵͳ��������Ҫ��ʹ��
	//��free�ͷſռ�󲢲��Ὣԭ��ָ�����ռ��ָ����Ϊ��ָ�룬����ָ��ԭ�ȵĵط�����������Ĳ����ͽ�����ȥ��
	//�������ָ����ȥ�����ǿ�ռ����䱻���ǳ�666�������ɷǷ�������
//	if (str != NULL)//���str��Ϊ��ָ������������
//	{
//		strcpy(str, "666");
//		printf(str);//��ӡָ��str�ǿ�ռ������
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
//	char arr[];//�����ô�С--�������飬�ṹ�������һ����ǰ������Ҫ��һ����Ա
//	//����ṹ���С�ǳ�������������ĳ�Ա����õ���С
//	//��������Ŀռ�ʹ����Ҫmalloc����
//};
//int main()
//{//ʹ��malloc�������ṹ����������ڴ棬sizeof(struct S)��Ϊ�ṹ���г������������Ա����ռ䣬�����������Ϊ�������鿪�ٿռ�
//	//��󶼰ѿ��ٵĿռ�ת��Ϊ�ṹ�����ͣ��ýṹ��ָ��������
//	struct S*p=(struct S*)malloc(sizeof(struct S) + 10 * sizeof(char));
//	if (p == NULL)//�ж�һ��
//	{
//		perror("malloc");
//		return 1;
//	}
//	p->a = 100;//���ʱ���
//	int i = 0;
//	for (i = 0; i < 10; i++)//�����������10�����εĿռ�
//	{
//		p->arr[i] = '6';//ʹ�����ռ�
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%c ", p->arr[i]);//��ӡ����
//	}
//	//��Ҫ�������������� -----pָ�����ԭ�ȵĿռ��С��ָ�룬Ҫ�뿪�ٸ���Ŀռ䣬��ԭ�����ϼӾͿ�����
//	struct S*ptr=(struct S*)realloc(p,sizeof(struct S) + 20 * sizeof(char));
//	if (ptr != NULL)//����Ҫ�ж�һ��
//	{
//		p = ptr;
//	}
//	else
//	{
//		perror("realloc");
//		return 1;
//	}
//	//�ͷ�
//	free(p);
//	p = NULL;
//	return 0;
//}//
//Ƶ����malloc��ʹ�ڴ���Ƭ���࣬Ӱ������ٶ�
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
	int* arr;//��Ա��ָ�벻����������
	//��mallocʹ���ָ��ָ��һ���С�������Լ��ı��
};
int main()
{
	struct S *p = (struct S*)malloc(sizeof(struct S));//���ṹ���������һ��ռ䣬�ýṹ��ָ�����
	p->a = 100;//���ʽṹ���Ա
	p->arr = (int*)malloc(10 * sizeof(int));//��ָ��arrָ��ĵط�����10�����οռ�
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		p->arr[i] = '6';//ʹ��mallocΪarr���ٵĿռ�
	}
	for (i = 0; i < 10; i++)
	{
		printf("%c ", p->arr[i]);
	}
	//����
	int *ptr=(int*)realloc(p->arr, 20 * sizeof(int));
	if (ptr == NULL)//�ж�һ��
	{
		perror("realloc");
		return 1;
	}
	free(p->arr);//�������ͷ�arr���ٵĿռ����ͷ�p���ٵĿռ䣬���ﵽ���ͷ�
	p->arr = NULL;
	free(p);
	p = NULL;
	return 0;
}