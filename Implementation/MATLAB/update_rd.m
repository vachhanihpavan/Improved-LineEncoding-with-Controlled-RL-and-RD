function update_rd()
    rd = 0;
    for i = 1:1:length(output_stream)
        if(output_stream(i) == 0)
            rd = rd - 1;
        else
            rd = rd + 1;
        end
    end
end