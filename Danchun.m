function x =Danchun(x)
a=[1 2 1 0 0;4 0 0 1 0;0 4 0 0 1];
b=[8;16;12];
c=[2 3 0 0 0];
x=[1 2 3 4 5;1 1 1 1 1];
[m,n]=size(a);
e=eye(3);
B=e;
xb=zeros(m,1);
xn=[];
cn=[];
cb=zeros(1,m);
xin=0;xout=0;
for j=1:m
    for i=1:n
        if a(:,j)=e(:,j)
            xb(j)=i;
            x(2.i)=0;
            cb(j)=c(i);
        end
    end
end

