#include <iostream>3
#include <cmath>
using namespace std;
#define m 10
double A[m][m], b[m], Aug[m][m + 1];//ȫ������
void equ(double A[m][m], double b[m], double x[m], int n)
{
	int i, i1, j, k;
	double Aug[m][m + 1], maxele, Temp, l;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j<n; j++)//����Aug���������
			Aug[i][j] = A[i][j];
		Aug[i][n] = b[i];
	}
	for (i1 = 0; i1<n - 1; i1++)
	{
		maxele = fabs(Aug[i1][i1]);
		k = i1;
		for (i = i1; i<n; i++)
		if (maxele < fabs(Aug[i1][i]))//�Ƚ�i1��
			k = i1;
		//����
		for (j = 0; j<n + 1; j++)
		{
			Temp = Aug[i1][j];
			Aug[i1][j] = Aug[k][j];
			Aug[k][j] = Temp;
		}
		//��Ԫ���Ե�i1��Ϊ�����д���һ���е�Ԫ��
		for (k = i1 + 1; k<n; k++)
		{
			l = -Aug[k][i1] / Aug[i1][i1];
			for (j = i1; j<n + 1; j++)
				Aug[k][j] = Aug[k][j] + l*Aug[i1][j];
		}
	}
	//�ش����
	double s;
	x[n - 1] = Aug[n - 1][n] / Aug[n - 1][n - 1];
	for (i = n - 2; i >= 0; i--)
	{
		s = 0;
		for (j = i + 1; j<n; j++)
			s = s + Aug[i][j] * x[j];
		x[i] = (Aug[i][n] - s) / Aug[i][i];
	}

}
//����Ϊ������
int main()
{
	int i, j, n; double A[m][m], b[m], x[m];//x[m]Ϊδ֪���ĸ���
	cout << "������δ֪���ĸ���" << endl;
	cin >> n;

	if (n>m)
	{
		cout << "�����ģ̫�����޸�Դ�����з��ų���m" << endl;
		return 0;
	}
	for (i = 0; i<n; i++)
	{
		cout << "������A�ĵ�" << i + 1 << "��";
		for (j = 0; j<n; j++)
			cin >> A[i][j];//ϵ������
		cin >> b[i];
	}
	equ(A, b, x, n);//����equ����
	for (i = 0; i<n; i++)//���x��ֵ
	{
		cout << x[i] << endl;
	}
	system ("pause");
	return 0;
}
