%Global Variable Declarations
global max_rl rl prev rd rd_th max_rd s pos ends input_stream output_stream
global outside inside
global max_size

%Initialize Variables
outside = 0;
inside = 1;
rl = -1;
prev = -1;
pos = 1;
ends = 0;
rd = 0;
%Taking Control Parameters as the input
max_rl = input('Enter the value of Maximum RL allowed in the stream: ');
max_rd = input('Enter the value of Maximum RD allowed in the stream: ');
s = input('Enter the size of S-block: ');
if mod(s,2)==1          %Checking S values for errors
    fprintf('Value of S cannot be odd\n');
    fprintf('Exiting.......\n');
    return;
end

%Calculating RD_Threshold value from Max_RD and S
rd_th = max_rd - ( s/2);

%Taking stream as input
input_stream = input('Enter the bit stream: ');
max_size = length(input_stream);

%Print Input Data
print();

combined_rl_rd();

fprintf('Output Stream: %s',output_stream);


