W=[0 13 51 77 68 50;
   13 0 60 70 67 59;
   51 60 0 57 36 2;
   77 70 57 0 20 34;
   68 67 36 20 0 34;
   50 59 2 55 34 0]
n=length(W);    
T=zeros(n);       %��С����Ȩ���󣬳�ֵΪzeros(n)
WW=W;             %WW����Ϊ���ҳ�ʵ�ʵı���m
m=((nnz(WW))/2);    %ʵ�ʵı���m
j=0;                %��ǰ��С�������ı���
for i=1:m
    if j<(n-1)
        minw=inf;
        a=0;
        b=0;
        for k=1:n
            for s=(k+1):n
                if W(k,s)<=minw
                    minw=W(k,s);
                    a=k;
                    b=s;
                end
            end
        end
        T(a,b)=W(a,b);
        T(b,a)=W(a,b);
        f=0;
        P=zeros(2,m);y=0;
        for i=1:n
            for v=(i+1):n
                if T(i,v)~=0 
                    y=y+1;
                    P(1,y)=i;P(2,y)=v;
                end
            end
        end
        for y=1:m
            if P(1,y)<P(2,y)
                for s=(y+1):m
                    if P(1,s)==P(2,y)
                        P(1,s)=P(1,y);
                    elseif P(2,s)==P(2,y)
                           P(2,s)=P(1,y);
                        end
                    end
                    P(2,y)=P(1,y);
                elseif P(2,y)<P(1,y)
                    for s=(y+1):m
                        if P(1,s)==P(1,y) P(1,s)=P(2,y);
                        elseif P(2,s)==P(1,y) P(2,s)=P(2,y);
                            end
                        end
                    P(1,y)=P(2,y);
                elseif (P(1,y)+P(2,y))~=0
                    f=1;
                    break
                    end
            end
                            if f==1  T(a,b)=0;T(b,a)=0;
                              else j=j+1;
                            end
                            W(a,b)=inf;
                        else
                            MST=T;
                            dianshu=n
                            node=input('Enter the node coordinate:node=')
                            input('The weigeht adjacent matrix of the Minimum Spanning Tree of the graph is:')
                            for i=1:n
                                for j=1:n
                                    if MST(i,j)==inf 
                                       MST(i,j)=0;
                                    end
                                end
                            end
                            MST
                            gplot(MST,node,'r-d')
                            weight=sum(sum(MST))/2
                            break
                       end
end                
                if j<(n-1)
                    input('The graph doesn"t include a Minimum Spanning Tree.')
                end