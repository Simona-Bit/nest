d=[0 2 7 inf inf inf;
   2 0 4 6 8 inf;
   7 4 0 1 3 inf;
   inf 6 1 0 1 6;
   inf 8 3 1 0 3;
   inf inf inf 6 3 0];
n=length(d);
U=d;
S=zeros(n,n);
for i=1:n
    for j=1:n
        S(i,j)=j;
    end
end
for i=1:n
    for j=1:n
        for m=1:n
            if U(i,j)>U(i,m)+U(m,j)
               U(i,j)=U(i,m)+U(m,j);
               S(i,j)=S(i,m);
            end
        end
    end
end
renshu=[50 40 60 20 70 90];
juli=[inf inf inf inf inf inf];
for i=1:n 
    juli(i)=U(i,:)*renshu';
end
S
U
renshu
juli
[minjuli,cunzi]=min(juli)
start=input('Enter the start-node:start=')
endnode=input('Enter the end-node:endnode=')
minroad=road2(U,S,start,endnode)