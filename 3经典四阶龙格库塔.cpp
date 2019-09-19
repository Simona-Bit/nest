#include<iostream>
#include<iomanip>
using namespace std;
double a[2][3];
int main()
{
	cout << "������һ��΢�ַ������ϵ������\n" << "       dy=ax+by+cz\n       dz=dx+ey+fz\n";
	int n, i, j;
	double x[100] = { 0 }, y[100] = { 0 }, z[100] = { 0 }, xspan[2], h;
	//x���ؽڵ㣬y��z�ֱ�Ϊ�����麯����xspanΪ������䣬hΪ����
	int runge4s(double xspan[], double h, double x[], double y[], double z[]);//���ص�ֵΪ�ڵ����
	for (i = 0; i < 2; i++)

	for (j = 0; j < 3; j++)
		cin >> a[i][j];
	cout << "��������������˺����ĳ�ֵ\n    y(0)= ";
	cin >> y[0];
	cout << "    z(0)= ";
	cin >> z[0];
	cout << "\n�����벽�� h= ";
	cin >> h;
	cout << "\n������������� ��    ";
	cin >> xspan[0] >> xspan[1];
	n = runge4s(xspan, h, x, y, z);
	cout << setw(20) << "�ڵ�" << setw(20) << "����y" << setw(20) << "����z" << endl;
	for (i = 0; i < n; i++)
		cout << setw(20) << x[i] << setw(20) << y[i] << setw(20) << z[i] << endl;
	system("pause");
	return 0;
}
int runge4s(double xspan[], double h, double x[], double y[], double z[])
{
	double k[4], l[4];
	double fun_y(double x, double y, double z);
	double fun_z(double x, double y, double z);
	int i, j, n;
	n = (xspan[1] - xspan[0]) / h;//�����������������ǿ��ת����ֻȡ��������
	x[0] = xspan[0];
	for (i = 1; i <= n; i++)
		x[i] = x[i - 1] + h;
	for (i = 0; i < n; i++) {
		k[0] = fun_y(x[i], y[i], z[i]);
		l[0] = fun_z(x[i], y[i], z[i]);
		for (j = 1; j < 3; j++) {
			k[j] = fun_y(x[i] + h / 2, y[i] + h*k[j - 1] / 2, z[i] + h*l[j - 1] / 2);
			l[j] = fun_z(x[i] + h / 2, y[i] + h*k[j - 1] / 2, z[i] + h*l[j - 1] / 2);
		}
		k[3] = fun_y(x[i] + h, y[i] + h*k[2], z[i] + h*l[2]);
		l[3] = fun_z(x[i] + h, y[i] + h*k[2], z[i] + h*l[2]);
		y[i + 1] = y[i] + h*(k[0] + 2 * k[1] + 2 * k[2] + k[3]) / 6;
		z[i + 1] = z[i] + h*(l[0] + 2 * l[1] + 2 * l[2] + l[3]) / 6;
	}
	return n + 1;
}
double fun_y(double x, double y, double z)
{
	double fy;
	fy = a[0][0] * x + a[0][1] * y + a[0][2] * z;
	return fy;
}
double fun_z(double x, double y, double z)
{
	double fz;
	fz = a[1][0] * x + a[1][1] * y + a[1][2] * z;
	return fz;
}
