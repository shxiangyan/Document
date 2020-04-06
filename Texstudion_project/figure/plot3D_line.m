subplot(1,2,1);
t=0:pi/50:10*pi;
plot3(sin(t),cos(t),t);
grid on;
axis square;

subplot(1,2,2);
turns=40*pi;
t=linspace(0,turns,4000);
x=cos(t).*(turns-t)./turns;
y=sin(t).*(turns-t)./turns;
z=t./turns;
plot3(x,y,z);
grid on;
