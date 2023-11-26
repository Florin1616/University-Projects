clear all;
clc;

option = input("Select one of the following models: Normal/Student/Chi/Fisher/Poisson\n",'s');
alfa = input("Enter the alfa: ");
beta = input("Enter the beta: ");
switch option
    
    case "Normal"
       fprintf('Normal distribution model\n')
       miu = input("Miu = ");
       sigma = input("Sigma = ");

       a1 = normcdf(0,miu,sigma);
       a2 = 1-a1;
       fprintf("P(x<=0) = %9.5f\n", a1) 
       fprintf("P(x>=0) = %9.5f\n", a2) 

       b1 = normcdf(1,miu,sigma) - normcdf(-1,miu,sigma);
       b2 = 1-b1;

       fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b1)
       fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b2)
    
       c1 = norminv(alfa, miu, sigma);
       fprintf("P(x <= alfa)  =  %9.5f\n",c1)
        
       d1 = norminv(1-beta, miu, sigma);
       fprintf("P(x >= beta)  =  %9.5f\n",c1)


    case "Student"
       fprintf('Student distribution model\n')
       n = input("n = ");

       a1 = tcdf(0,n);
       a2 = 1-a1;
       fprintf("P(x<=0) = %9.5f\n", a1) 
       fprintf("P(x>=0) = %9.5f\n", a2) 


       b1 = tcdf(1,n) - tcdf(-1,n);
       b2 = 1-b1;

       fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b1)
       fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b2)

       c1 = tinv(alfa, n);
       fprintf("P(x <= alfa)  =  %9.5f\n",c1)

       d1 = tinv(1-beta, miu, sigma);
       fprintf("P(x >= beta)  =  %9.5f\n",d1)

    case "Chi"
        fprintf('Chi distribution model\n')
        n = input("n = ");
        
        a1 = chi2cdf(0,n);
        a2 = 1-a1;
        fprintf("P(x<=0) = %9.5f\n", a1) 
        fprintf("P(x>=0) = %9.5f\n", a2) 
        

        b1 = chi2cdf(1,n) - chi2cdf(-1,n);
        b2 = 1-b1;

        fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b1)
        fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b2)

        c1 = chi2inv(alfa, n);
        fprintf("P(x <= alfa)  =  %9.5f\n",c1)

         d1 = chi2inv(1-beta, miu, sigma);
         fprintf("P(x >= beta)  =  %9.5f\n",d1)

    case "Fisher"
        fprintf('Fisher distribution model\n')
        miu = input("Miu = ");
        sigma = input("Sigma = ");

        a1 = fcdf(0,miu,sigma);
        a2 = 1-a1;
        fprintf("P(x<=0) = %9.5f\n", a1) 
        fprintf("P(x>=0) = %9.5f\n", a2) 

        b1 = fcdf(1,n) - fcdf(-1,n);
        b2 = 1-b1;

        fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b1)
        fprintf("P(-1 <= X <= 1)  =  %9.5f\n",b2)

        c1 = finv(alfa, n);
        fprintf("P(x <= alfa)  =  %9.5f\n",c1)

        d1 = finv(1-beta, miu, sigma);
        fprintf("P(x >= beta)  =  %9.5f\n",d1)

    case "Poisson"
        fprintf('Poisson distribution model')
    otherwise
        fprintf('No distribution model chosen')

end