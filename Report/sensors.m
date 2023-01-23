clear
clc
num = 1;
%uncomment required section and run


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%PLOTTING RESPONSES FOR UNPRESSED BUTTON
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% dom = [1*(10^-3) 1];
% sys = tf(num,dom);
% disp("Bandwidth of sensor is: " + num2str(bandwidth(sys)) + " rad/s");
% subplot(1,2,1)
% bode(sys)
% subplot(1,2,2)
% step(sys)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%PLOTTING RESPONSES FOR PRESSED BUTTON
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% dom = [174*(10^-3) 1];
% sys = tf(num,dom);
% disp("Bandwidth of sensor is: " + num2str(bandwidth(sys)) + " rad/s");
% subplot(1,2,1)
% bode(sys)
% subplot(1,2,2)
% step(sys)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%PLOTTING DIFFERENT RESPONSES FOR DIFFERENT TIME CONSTANTS
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% hold on
% dom = [1*(10^-3) 1];
% sys = tf(num,dom);
% step(sys)
% for t = 50:50:200
%     dom = [(t-1)*(10^-3) 1];
%     sys = tf(num,dom);
%     step(sys)
% end
% tc = ["T=0.001" "T=0.05" "T=0.1" "T=0.15" "T=0.2"];
% legend(tc);