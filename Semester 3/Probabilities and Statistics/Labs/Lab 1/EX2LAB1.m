x = 0:0.01:3
y1 = x.^5/10;
y2 = x.*sin(x);
y3 = cos(x);

hold on
title('Plot for x^5/10')
legend('x^5/10')
plot(x,y1)

title('Plot for x*sin(x)')
legend('x*sin(x)')
plot(x,y2)

title('Plot for cos(x)')
legend('')
plot(x,y3)

hold off

subplot(3,1,1)
subplot(3,1,2)
subplot(3,1,3)