fileID = fopen('buffer_decode.txt','r');                        %Opening input file in read mode
stream = fgetl(fileID);                                         %Reading the file
fileID1 = fopen('buffer_encode.txt','r');                       %Opening input file in read mode
stream_encode = fgetl(fileID1);                                 %Reading the file
disp(stream);                                                   %Confirm read data in console
disp(stream_encode);
n = length(stream);                                             %Get length of streams
n1 = length(stream_encode);
x_line = zeros(1, n*100);                                       %Initializing X-axis with 0s 
x_line1 = zeros(1, n*100);
stream_encode1=str2num(stream_encode);                          %Converting string to integer easy processing
stream1=str2num(stream);
stream2=stream1;                                                %Final streams to plot graphs
stream_encode2=stream_encode1;
stream2(n+2)=0;
stream2(n+1)=0;
stream_encode2(n1+2)=0;
stream_encode2(n1+1)=0;
%disp(stream2);

for i=0:((n+1)*100)                                             %Assign X-axis values 
    x_line(i+1)=i/100;
end
for i=0:((n1+1)*100)
    x_line1(i+1)=i/100;
end

for i=0:(n+1)*100                                           %Assigning Y-axis values to plot
    if stream2(floor(i/100)+1)==0                           %Checks values 100 times per bit
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

plot(x_line, stream1,'-.',x_line1,stream_encode1);          %Final plot function
axis([0,40,-2,2])
grid on;
fclose(fileID1);                                            %Closing files
fclose(fileID);