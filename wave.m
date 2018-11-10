clc;
clear all;
close all;

nOmega = 100;
nTheta = 50;
dOmega = 2*pi/(nOmega-1);
dTheta = pi/(nTheta-1);
omega = linspace(0.0001, 2*pi, nOmega);
theta = linspace(-pi/2, pi/2, nTheta);
Hs = 5.6;
T = 7.1;
[X, Y] = meshgrid(-49:50,-49:50);
tend = 30;
nt = 300;
t = linspace(0,tend,nt);
g = 9.81;
makeMovie = 0;

%%  Jonswap by somebody else
[ Somega, Amp, Phase ] = JONSWAP(omega, Hs, T, nTheta);
f = 2/(pi)*cos(theta).^2;   % Faltinsen directional distribution
% x = 0.3;
% f = 1/(2*pi)*(1-x^2)./(1 - 2*x*cos(theta) + x^2);   % Poisson directional distribution
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


%%
% figure('position',[500, 500, 800, 600])
if (makeMovie)
    figure
    %F(loops) = struct('cdata',[],'colormap',[]);
    VidName = ['Hs', num2str(Hs), 'T', num2str(T), '.avi'];
    v = VideoWriter(VidName);
    open(v);
    for j = 1:nt
        surf(X,Y,zeta(:,:,j))
        shading interp
        colormap winter
        axis equal
        axis tight
        title(['t = ', num2str(t(j),3)])
        colorbar
        xlabel('x')
        ylabel('y')
        zlabel('\zeta')
        xlim([0, max(max(X))])
        ylim([0, max(max(Y))])
        zlim([-Hs/2, Hs/2]*1.4)
        caxis([-Hs/2, Hs/2]*1.4)
        drawnow
        frame = getframe(gcf);
        writeVideo(v, frame);
    end
    
    close(v);
end

