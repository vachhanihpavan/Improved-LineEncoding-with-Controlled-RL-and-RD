function update_rl(x)
global rl prev
    if(rl == -1)
        rl = 1;
        prev = x;
    elseif(x == prev)
        rl = rl + 1;
    else
        rl = 1;
        prev = x;
    end
end