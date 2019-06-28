
function myplot()
x=0:30:90;
y=x;
plot(x,y,'r:*','Linewidth',2);
hold on;
y=[0.103 33.432 56.567 89.90];
plot(x,y,'b.-','Linewidth',2);
xlabel('计算方位');
ylabel('仿真理论方位');
title('单目标信号仿真分析图');
legend('理想信号','仿真信号');

