
一、指针说明：
指针是包含另一变量的地址变量。
（1）int * p
p为指针，指向一个int类型的数。
（2）int *p()
p为一个函数，该函数返回一个int 类型的指针
（3）int (*p)()
p为一个指针，该指针指向一个函数，该函数返回一个int类型的数。
（4）int *p[]
p为一个数组,该数组的每一个元素都是一个指向int的指针。
（5）int （*）p[]
p为一个指针，该指针指向一个数组，该数组的每个元素一个int类型的数。
（6）int *(*p)()
p为一个指针，该指针指向函数，该函数返回一个int类型的指针。

二、指针的初始化（赋地址）
（1）通过符号&取变量（包括结构变量，数组的第一个元素）的地址赋值给指针
（2）把数组名赋值给指针
（3）把函数名赋值给指向函数的指针
（4）动态分配内存

例：
struct a
{
  int a,b;
};
struct a *p;
p=(struct a*)malloc(sizeof(struct a));

三、指针与数组之间的关系
1.对于一维数组int a[i]或指针int *a
a+i指向a[i]
2.对于字符串char s[i]或指针char *s
s+i指向第i个字符s[i]
3.对于二维数组a[i][j]
*a+j指向a[0][j]
*(a+i)指向a[i][0]
*(a+i)+j指向a[i][j]

例：
a[2][3]={1,2,3,4,5,6};有*(*(a+1)+1)=5

四、对于字符串数组char p[i][j]或字符型指针数组 char *p[i]
*p+j指向第0个字符串的第j个字符
*（p+i）指向第i个字符串的第0个字符
*（p+i）+j指向第i个字符串的第j个字符

例：char p[][3]={"ABC","DEF"};有*(（*p+i）+j)='E'
*p[]={"ABC","DEF"};有*(（*p+i）+j)='E'


五、对于指针数组int *a[i]
a[i]指向变量i,即 *a[i]=变量i,a[i]=&变量i


六、对于结构体
struct XY
{
  int x;
  int *y;
}*p;
p是指向结构体的指针，则
（*p）.x或p->x是表示x的内容
（*p）.y或p->y是表示指针y的值（地址）
*（*p）.y或*p->y是表示y所指的内容
&(*p）.x或&p->x是表示x的地址

七、指针的分类

https://github.com/SimonLien/CodeStudyForDataStructure/blob/master/0-other/FinateStateMachine/FinateStateMachine/FinateStateMachine/1.jpg
