function [t,x,y]=eular(v1,v2,T,h,x0,y0)
%v1为导弹的速度
%v2为敌舰的速度
%T为所取步长
%h为发现敌舰是距导弹基地的距离
%x0,y0为初值条件
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