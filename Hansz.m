function [minx, minz] = Hansz(c,A,b,x0)
%Ŀ�꺯��ϵ��������c
%����ʽԼ������A
%����ʽԼ���ұ��Ҷ�������b
%��ʼ�������н⣬x0
%Ŀ�꺯��ȡ��Сֵʱ���Ա���ֵ��intx
%Ŀ�꺯������Сֵ��intz
sz=size(A);
if sz(2)<3
    [minx, minz]=All(c,A,b);
else
    [minx, minz]=Implicitprog(c,A,b,x0);
end

