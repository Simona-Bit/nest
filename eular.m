function [t,x,y]=eular(v1,v2,T,h,x0,y0)
%v1Ϊ�������ٶ�
%v2Ϊ�н����ٶ�
%TΪ��ȡ����
%hΪ���ֵн��Ǿർ�����صľ���
%x0,y0Ϊ��ֵ����
t(1)=0;
x(1)=x0;
y(1)=y0;
i=1;
while (y(i)<h)
    i=i+1;
    t(i)=t(i-1)+T
    x(i)=x(i-1)+((v1*T)/sqrt(1+((h-y(i-1))/(v2*t(i-1)-x(i-1)))^2)))
    y(i)=y(i-1)+((v1*T)/sqrt(1+((v2*t(i-1)-x(i-1))/(h-y(i-1)))^2)))
end
t=t(i);
x=x(i);
y=y(i);