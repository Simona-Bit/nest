function [minx, minz] = Implicitprog(c,A,b,x0)   
sz_A=size(A);
rw=sz_A(1);
col=sz_A(2);
minz=c*x0;
A=[A;-c];
b=[b;-minz];
for i=0:(2^(col)-1)
    x1=Tran(i,col);
    if A*x1>=b
        z_tmp=c*x1;
        if z_tmp<minz
            minz=z_tmp;
            b(rw+1,1)=-minz;
            minx=x1;
        else
            continue;
        end
    else
        continue;
    end
end

