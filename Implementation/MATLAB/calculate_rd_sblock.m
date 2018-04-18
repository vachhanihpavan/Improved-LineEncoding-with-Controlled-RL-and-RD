function [fifo] = calculate_rd_sblock()
global ends pos s input_stream
    fifo = 0;
    for i = pos:1:pos+s
        if(input_stream(i)==0)
            fifo = fifo - 1;
        else
            fifo = fifo + 1;
        end
    end
    ends = i;
end