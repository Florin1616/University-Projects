clear all;
clc;
clf;


p = input("Please enter the probability of success: ");
while p <= 0 || p >= 1
    p = input("Please enter the probability of success: ");
end

s = input("Enter the number of simulations: ");

X = zeros(1,s);
for i=1:s

    counter = 0;
    a = 4;
    while a >=p
        a = rand(); %to generate a single rand number
        if a>=p
            counter = counter + 1;
        end
    end
    X(i) = counter;

end


U_X = unique(X);
n_x = hist(X, length(U_X));
[U_X;n_x];
relfreq = n_x/s;
[U_X;relfreq];

hold on
title("Binomial distribution graph");
plot(U_X, relfreq, "X");
plot(0:max(U_X), geopdf(0:max(U_X),p), "O");
legend("Frequency", "Geopdf");
hold off
%Ideea e sa vedem cat de aproape sunt aproximarile cu rand de
%realitate(care este cu geopdf)


