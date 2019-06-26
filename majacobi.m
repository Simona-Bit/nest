%majacobi.m
function x=majacobi(A,b,x0,eps,N)
%��;����jacobi�����������Է�����Ax=b
%��ʽ��x=majacobi(A,b,x0,eps,N)
%AΪϵ������bΪ�Ҷ�������x0Ϊ��ʼ������epΪ���ȣ�NΪ������������x���ؽ��ƽ�����
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
if k==N,Warning('�Ѵﵽ������������');end
disp(['k=',num2str(k)])