clc;
clear all;
close all;

nOmega = 100;
nTheta = 50;
dOmega = 2*pi/(nOmega-1);
dTheta = pi/(nTheta-1);
omega = linspace(0.0001, 2*pi, nOmega);
theta = linspace(0, 2*pi, nTheta);
Hs = 5;
T = 6;
[X, Y] = meshgrid(1:100,1:100);
tend = 30;
nt = 300;
t = linspace(0,tend,nt);
g = 9.81;

%%  Jonswap by somebody else
[ Somega, Amp, Phase ] = JONSWAP(omega, Hs, T, nTheta);
% f = 1/(2*pi)*cos(theta).^2;   % Faltinsen directional distribution
x = 0.8;
f = 1/(2*pi)*(1-x^2)./(1 - 2*x*cos(theta) + x^2);   % Poisson directional distribution
S = (ones(nTheta,1)*Somega).*(f'*ones(1,nOmega));

%%  Compute zeta
omegaAll = ones(nTheta,1)*omega;
thetaAll = f'*ones(1,nOmega);
zeta = zeros(100,100,nt);
figure
for k = 1:nt
    for i = 1:100
        for j = 1:100
            zOmega = sqrt(2*S*dOmega*dTheta)...
                .*sin(omegaAll*t(k) ...
                - X(i,j)*omegaAll.^2/g.*cos(thetaAll) ...
                - Y(i,j)*omegaAll.^2/g.*sin(thetaAll) ...
                +Phase);
            zeta(i, j, k) = sum(sum(zOmega));
        end
        
    end
    surf(X,Y,zeta(:,:,k))
    shading interp
    axis equal
    title(['t = ', num2str(t(k))])
    colorbar
    drawnow
end

%%  Other directional spectrum
% x = 0.2;
% p = 1/(2*pi)*(1-x^2)./(1 - 2*x*cos(theta) + x^2);

%%
figure('position',[500, 500, 800, 600])
loops = nt;
F(loops) = struct('cdata',[],'colormap',[]);

for j = 1:loops
    surf(X,Y,zeta(:,:,j))
    shading interp
    axis equal
    title(['t = ', num2str(t(j))])
    colorbar
    xlabel('x')
    ylabel('y')
    zlabel('\zeta')
    xlim([0, max(max(X))])
    ylim([0, max(max(Y))])
    zlim([-Hs/2, Hs/2]*1.3)
    caxis([-Hs/2, Hs/2]*1.3)
    annotation('textbox',...
    [0.083716049382716 0.642168674698799 0.33 0.07],...
    'String',{['Significant wave height: $H = $ ', num2str(Hs), 'm Mean period: $T_1 = $ ', num2str(T), 's']},...
    'LineStyle','none',...
    'Interpreter','latex',...
    'FontSize',12,...
    'FitBoxToText','off');
    drawnow
    F(j) = getframe;
end



