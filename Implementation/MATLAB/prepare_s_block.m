function [y] = prepare_s_block(fifo)
    if(fifo == 0)
        y=0;
    else
        if(rd == rd_th)
            if(fifo>0)
                y = 1;
            else
                y= -1;
            end
        else
            if(fifo<0)
                y=1;
            else
                y=-1;
            end
        end
    end
end
            