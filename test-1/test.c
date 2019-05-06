#include<stdio.h>
#include<math.h>
int main()
{
	int i, n;
	n = 100;
	while (n < 201)
	{
		i = 2;
		while (i <= sqrt(n))
		{
			if (n%i == 0)
				break;
			i++;
		}
		if (i>sqrt(n))
			printf("%d\n", n);
		n++;
	}
	system("pause");
}