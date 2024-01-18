%To reach maximum efficiency in performing an assembling operation in a
%manufacturing plant, new employees are required to take a 1-month training
%course. A new method was suggested, and the manager wants to compare the
%new method with the standard one, by looking at the lengths of time
%required for employees to assemble a certain device. They are given
%below (and assumed approximately normally distributed)

%a. at the 5% significance level, do the population variances seem to
%differ ?
%b. at the same significance level, does it seem that on average, that the
%new method is more efficient?
clear all;
clc;

S = [46, 37, 39, 48, 47, 44, 35, 31, 44, 37];
N = [35, 33, 31, 35 ,34, 30, 27, 32, 31, 31];

% The null hypothesis H0: sigma1^2 = sigma2^2
% The alt. hypothesis H1: sigma1^2 != sigma2^2
% two-tailed for comparing the variances

n1 = length(S);
n2 = length(N);

% alpha is the significance level 
alpha = 0.05;

tt1 = finv(alpha/2, n1-1, n2-1); % quantile of order alpha / 2 for F(n1 - 1,n2 - 1)
tt2 = finv(1-(alpha/2), n1-1, n2-1); % quantile of order 1 - alpha / 2 for F(n1 - 1,n2 - 1)

% vartest2 -> test for the ratio of two population variances

[h, p, ci, stats] = vartest2(S, N, alpha, 0);

% result of the test, h = 0, if H0 is NOT rejected,
% h = 1, if H0 IS rejected

fprintf("a)\n\n");

fprintf("h is %d\n", h);
if h == 1
    fprintf("So the hyphotesis is rejected. The populations differ.\n");
else
    fprintf("So the hyphotesis is NOT rejected. The populations do not differ.\n");
end

fprintf("The rejection region is (-Inf, %5.4f) U (%5.4f, Inf)\n", tt1, tt2);
% RR = (-inf, tt_{alpha/2}) U (tt_{1-alpha/2},inf) since it's a two-tailed test
fprintf("The Confidence Interval is (%f, %f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.fstat);
fprintf("P value is %5.4f\n\n", p);

fprintf("b)\n\n");

[h, p, ci, stats] = ttest2(S, N, alpha, "right", "unequal");

 s1 = var(S);
 s2 = var(N);

 c = (s1/n1) / ((s1/n1) + (s2/n2));
 n = ((c^2)/(n1-1) + ((1-c)^2)/(n2-1))^(-1);

rr = tinv(1-alpha, n);
fprintf("h is %d\n", h);

if h == 1
    fprintf("So the hyphotesis is rejected. The new method seems to be more efficient.\n");
else
    fprintf("So the hyphotesis is NOT rejected. The new method seems not to be more efficient.\n");
end
fprintf("The rejection region is (%5.4f, Inf)\n", rr);
fprintf("The Confidence Interval is (%f, %f)\n", ci(1), ci(2));
fprintf("The value of the test statistic is %5.4f\n", stats.tstat);
fprintf("P value is %5.10f\n", p);



