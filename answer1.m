function dy= answer1(x,y)
dy=zeros(3,1);
dy(1)=dy(2);
dy(2)=dy(3);
dy(3)=(3*exp(2*x)+2*y(2)+3*y(3))/x^3;
end
