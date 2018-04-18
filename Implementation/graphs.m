fileID = fopen('raw_data.txt','r');
stream = fgetl(fileID);


n = 37;
x_line = zeros(1, 37*100);
stream1=str2num(stream);
stream2=stream1;
stream2(n+2)=0;
stream2(n+1)=0;


for i=0:(38*100)
    x_line(i+1)=i/100;
end
for i=0:38*100
    if stream2(floor(i/100)+1)==0
        stream1(i+1)=0;
    else
        stream1(i+1)=1;
    end
end
%disp(stream1);
%disp(length(x_line));
%disp(length(stream1));
plot(x_line, stream1);
axis([0,40,-0.5,1.5])
grid on;
%disp(stream1);
fclose(fileID);