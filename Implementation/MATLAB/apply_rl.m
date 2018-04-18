function apply_rl(x)
global max_rl rl prev 
global output_stream
    output_stream(end+1) = x;
    update_rl(x);
    if(rl == max_rl)
        if(x == 0)
            output_stream(end+1) = 1;
            rl = 1;
            prev = 1;
        else
            output_stream(end+1) = 0;
            rl = 1;
            prev = 0;
        end
    end
end