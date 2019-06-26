%majacobi.m
function x=majacobi(A,b,x0,eps,N)
%用途：用jacobi迭代法解线性方程组Ax=b
%格式：x=majacobi(A,b,x0,eps,N)
%A为系数矩阵，b为右端向量，x0为初始向量，ep为精度，N为最大迭代次数，x返回近似解向量
n=length(b);
if nargin<5,N=500;end
if nargin<4,ep=1e-6;end
if nargin<3,x0=zeros(n,1);end
x=zeros(n,1);k=0;
while k<N
    for i=1:n
        x(i)=(b(i)-A(i,[1:i-1,i+1:n])*x0([1:i-1,i+1:n]))/A(i,i);
    end
    if norm(x-x0,inf)<ep,break;end
    x0=x;k=k+1;
end
if k==N,Warning('已达到迭代次数上限');end
disp(['k=',num2str(k)])