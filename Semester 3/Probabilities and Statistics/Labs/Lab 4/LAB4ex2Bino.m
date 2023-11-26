clear all;
clc;

p = input("Please enter the probability of success: ");
while p <= 0 || p >= 1
    p = input("Please enter the probability of success: ");
end

n = input("Enter the number of trials: ");

s = input("Enter the number of simulations: ");

U = rand(n,s);

M = U < p;
X = sum(M); 

U_X = unique(X);
n_x = hist(X, length(U_X));
[U_X;n_x];
relfreq = n_x/s;
[U_X;relfreq];

hold on
title("Binomial distribution graph");
plot(U_X,relfreq, "X");
plot(0:n, binopdf(0:n, n, p), "O");
legend("Frequency", "Binopdf");
hold off
%Ideea e sa vedem cat de aproape sunt aproximarile cu rand de
%realitate(care este cu binopdf)


