global outside rd_th max_size input_stream pos
global ends inside
mode = outside;
sflag = 0;
while(true)
    if(pos == max_size+1)
        break;
    end
    x = input_stream(pos);
    
    if(mode==outside)
        apply_rl(x);
        update_rd();
        if(mod(rd) == rd_th)
            fifo = calc_rd_sblock();
            sflag = prepare_s_block(fifo);
            ends = pos + s;
            mode = inside;
        end
    end
end
