clear all;
clc;



p = input("Please enter the probability of success: ");
while p <= 0 || p >= 1
    p = input("Please enter the probability of success: ");
end

s = input("Enter the number of simulations: ");

U = rand(1,s);

X = U < p;

U_X = unique(X);
n_x = hist(X, length(U_X));
[U_X;n_x];
relfreq = n_x/s;
[U_X;relfreq]