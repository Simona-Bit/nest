Y=0:12;
GDP=[3540 3783 3916 4239 4922 5560 6399 7842 9116 10879 13475 16737 18745];
P=[767 895 995 1117 1261 1437 1640 1957 2244 2489 2801 3096 3500];
figure,subplot(121),
plot(P,GDP,'bo')
hold on
a=polyfit(P,GDP,2)
GDP1=a(1,1)*P.^2+a(1,2)*P+a(1,3);
error1=sum(abs(GDP-GDP1))  %误差
plot(P,GDP1,'rs')
xlabel('房价（元）')
ylabel('GDP')
%模型二
a=polyfit(P,GDP,2)
P1=a(1,1)*GDP.^2+a(1,2)*GDP+a(1,3);
error2=sum(abs(P-P1))  %误差
subplot(122)
plot(GDP,P,'bo')
hold on
plot(GDP,P1,'rs')