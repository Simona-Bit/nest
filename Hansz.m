function [minx, minz] = Hansz(c,A,b,x0)
%目标函数系数向量，c
%不等式约束矩阵，A
%不等式约束右边右端向量，b
%初始整数可行解，x0
%目标函数取最小值时的自变量值，intx
%目标函数的最小值，intz
sz=size(A);
if sz(2)<3
    [minx, minz]=All(c,A,b);
else
    [minx, minz]=Implicitprog(c,A,b,x0);
end

