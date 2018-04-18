fileID = fopen('buffer_decode.txt','r');
stream = fgetl(fileID);
fileID1 = fopen('buffer_encode.txt','r');
stream_encode = fgetl(fileID1);
disp(stream);
disp(stream_encode);
n = length(stream);
n1 = length(stream_encode);
x_line = zeros(1, n*100);
x_line1 = zeros(1, n*100);
stream_encode1=str2num(stream_encode);
stream1=str2num(stream);
stream2=stream1;
stream_encode2=stream_encode1;
stream2(n+2)=0;
stream2(n+1)=0;
stream_encode2(n1+2)=0;
stream_encode2(n1+1)=0;
%disp(stream2);
for i=0:((n+1)*100)
    x_line(i+1)=i/100;
end
for i=0:((n1+1)*100)
    x_line1(i+1)=i/100;
end
for i=0:(n+1)*100
    if stream2(floor(i/100)+1)==0
        stream1(i+1)=0;
    else
        stream1(i+1)=1;
    end
end
for i=0:(n1+1)*100
    if stream_encode2(floor(i/100)+1)==0
        stream_encode1(i+1)=0;
    else
        stream_encode1(i+1)=1;
    end
end

figure(1)
subplot(2,1,1),plot(x_line, stream1, '-.');
axis([0,40,-0.5,1.5])
grid minor;
% for i = 0:(n-1)
% 	h=text(i+0.5, -0.2, num2str(stream1(i+1)))
%     h.FontSize = 5;
% end

subplot(2,1,2),plot(x_line1,stream_encode1,'--');
axis([0,40,-0.5,1.5])
grid minor;
fclose(fileID1);
fclose(fileID);