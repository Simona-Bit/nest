//1.
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
//

//#include<stdio.h>
//#include<stdlib.h>
//
//int count_one_bits(unsigned int value)
//{
//	int i, count = 0;
//	for (i = value; i; i /= 2)
//	{
//		count += i % 2;
//	}
//	return count;
//}
//
//int main()
//{
//	printf("%d\n", count_one_bits(15));
//	system("pause");
//	return 0;
//}

//2.获取一个数二进制序列中所有的偶数位和奇数位，
//分别输出二进制序列。
//
//#include<stdio.h>
//#include<stdlib.h>
//
//int main()
//{
//	int n = 123456;
//	int i;
//	char num[33] = { 0 };
//
//	for (i = 0; i < 32; i++, n /=  2)
//	{
//		num[i] = n % 2 + '0';
//	}
//	puts(num);
//	system("pause");
//	return 0;
//}
//3. 输出一个整数的每一位。
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//#include<windows.h>
//
//int main()
//{
//	int num = 0;
//	printf("输入一个数：");
//	scanf("%d", &num);
//	while (num)
//	{
//		printf("%d ", num % 10);
//		num /= 10;
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//int count_diffrent_bits(int x, int y)
//{
//	int i = 0;
//	int tmp = x ^ y;
//	int count = 0;
//	while (tmp)
//	{
//		tmp = tmp & (tmp - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int m = 0;
//	int n = 0;
//	printf("请输入两个整数m,n：\n");
//	scanf("%d\n%d", &m, &n);
//	int ret = count_diffrent_bits(m, n);
//	printf("两个整数%d,%d有%d位不同\n", m, n, ret);
//	system("pause");
//	return 0;
//}
//5.写博客总结C语言操作符，博客链接发给我，并分享到群里。
在C语言中，操作符有以下几种，下面为大家详细介绍下其分类和用法。
算术操作符： + -*/ %
移位操作符： << >>
位操作符：& | ^
赋值操作符： = （复合赋值符： += -= *= /= %= >>= <<= &= |= ^= ）
单目操作符：!- +&sizeof ~–++ * (类型)
关系操作符：> >= < <= != ==
逻辑操作符：&& ||
条件操作符：exp1 ? exp2 : exp3
逗号表达式：esp1, exp2, exp3, … expn
下标引用、函数调用和结构成员：[]() . ->
以下是详细介绍及其应用：

算术操作符
+ -*/ &
1
除了 % 操作符之外，其他的几个操作符都可以作用于整数和浮点数；
对于 / 操作符如果两个操作数都为整数，执行整数除法。而只要有浮点数执行的就是浮点数除法。
% 操作符的两个操作数必须为整数。返回的是整除之后的余数。
移位操作符
<<  //左移操作符
>>  //右移操作符
1
2
左移操作符移位规则：
左边抛弃、右边补0
右移操作符移位规则：
首先右移运算分为两种：
1. 逻辑移位 左边用0填充，右边丢弃；
2. 算术移位 左边用原该值的符号位填充，右边丢弃。
警告：对于移位运算符，不要移动负数位，这个是标准未定义的。

位操作符
&  //按位与
|  //按位或
^  //按位异或
1
2
3
注：他们的操作数必须为整数。

例如：不能创建临时变量（第三个变量），实现两个数的交换。

#include <stdio.h>
int main(){
	int a = 10;
	int b = 20;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a = %d    b = %d\n", a, b);
	return 0;
}
1
2
3
4
5
6
7
8
9
10
赋值操作符
=


int a = 10;   //把10赋给整形变量 a
int x = 0;
int y = 0;
a = x = y + 1;  //连续赋值
1
2
3
4
5
6
7
复合赋值符
+=  //等价于 a = a + 10
-=  //等价于 a = a - 10
*=  //等价于 a = a * 10
/=  //等价于 a = a / 10
%=  //等价于 a = a % 10
>>=  //等价于 a = a >> 10
<<=  //等价于 a = a << 10
&=  //等价于 a = a & 10
|=  //等价于 a = a | 10
^=  //等价于 a = a ^ 10
1
2
3
4
5
6
7
8
9
10
单目操作符
!    //逻辑反操作
-    //负值
+    //正值
&    //取地址
sizeof    //操作数的类型长度（以字节为单位）
~    //对一个数的二进制按位取反
--    //前置、后置--
++    //前置、后置++
*    //间接访问操作符（解引用操作符）
(类型)    //强制类型转换
1
2
3
4
5
6
7
8
9
10
注：

前置++类似于以下代码：

num += 1;
return num;
1
2
2.后置++类似于以下代码：

int temp = num;
num += 1;
return temp;
1
2
3
关系操作符
>
>=
<
<=
!=    //用于测试“不相等”
==    //用于测试“相等”
1
2
3
4
5
6
特别注意：在一些 if () / while () 语句中，极其容易将 == 写为 = ，导致错误。

逻辑操作符
&&    //逻辑或
||    //逻辑与
1
2
区分逻辑与和按位与 区分逻辑或和按位或

1 & 2 ----> 0;
1 && 2 ----> 1;

1 | 2 ----> 3;
1 || 2 ----> 1;
1
2
3
4
5
条件操作符
exp1 ? exp2 : exp3
1
例：找两个数中的较大值。

if (a > b){
	int max = a;
}
else{
	int max = b;
}
1
2
3
4
5
等价于：

int max = (a > b ? a : b);
1
逗号表达式
exp1, exp2, exp3, ... expn
1
逗号表达式，就是用逗号隔开的多个表达式。逗号表达式，从左到右依次执行。整个表达式的结果是最后一个表达式的结果。

下标引用、函数调用和结构成员
[] 下标引用操作符
操作数：一个数组名 + 一个索引值
() 函数调用操作符
接受一个或者多个操作数：第一个操作数是函数名，剩余的操作数就是传递给函数的参数。
访问一个结构成员
.结构体.成员名
->结构体指针->成员名
表达式求值
表达式求值的顺序一部分是由操作符的优先级和结合性决定。
同样，有些表达式的操作数在求值的过程中可能需要转换为其他类型。

隐式类型转换
C的整形算术运算总是至少以缺省整形类型的精度来进行的。
为了获得这个精度，表达式中的字符和短整形操作数在使用之前被转换为普通整形，这种转换称为“整形提升”。
整形提升的意义：
表达式的整形运算要在CPU的相应运算器件内执行，CPU内整形运算器（ALU）的操作数的字节长度一般就是int的字节长度，同时也是CPU的通用寄存器的长度。因此，即使两个char类型的相加，在CPU执行时实际上也要先转换为CPU内整形操作数的标准长度。
通用CPU（general - purpose CPU）是难以实现两个8比特字节直接相加运算（虽然机器指令中可能有这种字节相加指令）。所以，表达式中各种长度可能小于int长度的整形值，都必须先转换为int或unsigned int，然后才能送入CPU去运算。

操作符的属性
复杂表达式的求值有三个影响的因素：

操作符的优先级；
操作符的结合性；
是否控制求值顺序。
两个相邻的操作符先执行哪个，取决于他们的优先级。如果两者的优先级相同，取决于他们的结合性。操作符的优先级大家可以上网搜索查询，此处不再赘述。

好了，以上就是我所认知的C语言的操作符的总结，希望可以帮助到大家。如有不足或者错误的地方，欢迎大家指出。
