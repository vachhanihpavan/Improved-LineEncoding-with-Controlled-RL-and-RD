function rd_adjust()
global rd rd_th
    while(abs(rd) > rd_th)
        if(rd>0)
            apply_rl(0);
        else
            apply_rl(1);
        end
        update_rd();
    end
end
