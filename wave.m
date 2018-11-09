clc;
clear all;
close all;

nOmega = 100;
nTheta = 50;
dOmega = 2*pi/(nOmega-1);
dTheta = pi/(nTheta-1);
omega = linspace(0.0001, 2*pi, nOmega);
theta = linspace(0, 2*pi, nTheta);
Hs = 8;
T = 5;
[X, Y] = meshgrid(1:100,1:100);
tend = 10;
nt = 100;
t = linspace(0,tend,nt);
g = 9.81;

%%  Jonswap by somebody else
[ Somega, Amp, Phase ] = JONSWAP(omega, Hs, T, nTheta);
% f = 1/(2*pi)*cos(theta).^2;   % Faltinsen directional distribution
x = 0.8;
f = 1/(2*pi)*(1-x^2)./(1 - 2*x*cos(theta) + x^2);   % Poisson distribution
S = (ones(nTheta,1)*Somega).*(f'*ones(1,nOmega));

%%  Compute zeta
omegaAll = ones(nTheta,1)*omega;
thetaAll = f'*ones(1,nOmega);
zeta = zeros(100,100,nt);
figure
for k = 1:nt
    for i = 1:100
        for j = 1:100
            zOmega = 2*S*dOmega*dTheta...
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
% figure
% loops = nt;
% F(loops) = struct('cdata',[],'colormap',[]);
% 
% for j = 1:loops
%     surf(X,Y,zeta(:,:,j))
%     shading interp
%     axis equal
%     drawnow
%     F(j) = getframe;
% end



