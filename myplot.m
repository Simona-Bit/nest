
function myplot()
x=0:30:90;
y=x;
plot(x,y,'r:*','Linewidth',2);
hold on;
y=[0.103 33.432 56.567 89.90];
plot(x,y,'b.-','Linewidth',2);
xlabel('���㷽λ');
ylabel('�������۷�λ');
title('��Ŀ���źŷ������ͼ');
legend('�����ź�','�����ź�');

