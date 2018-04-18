function insert_indication_bit(sflag)
    if(sflag == 0)
        return;
    elseif(sflag == -1)
        apply_rl(0);
        return;
    else
        apply_rl(1);
        return;
    end
end