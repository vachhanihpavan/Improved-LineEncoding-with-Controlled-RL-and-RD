# Theoretical Aspect
## Introduction
Now a days serial communication is widely used compared to parallel communication due to higher speeds and performance. In serial communication, parallel data is first serialised, then line encoding is applied  and then data is sent through links. 
In this communication, reliable clock and data recovery is achieved by transitions from '0' to '1' or vice versa. But when long sequences of same bits are transmitted, circuit cannot synchronise which results in data loss or errors.

## Definitions

**Running Length**

The number of same bit is called run length (RL). RL increases when the current bit has the same value with the previous one, and it is reset to 1 when a different bit appears. RL is always greater than 0. 


**Running Disparity**

In AC coupled data-links, if the numbers of '0' and '1' that appear in the links are unbalanced, then charges start accumulating on the capacitors of the circuit, thus damaging the circuit. The difference of numbers of “0” and “1” is called running disparity (RD). RD initially takes 0, and is incremented (or decremented) when “1” (or “0”) appears in data. RD can be negative, 0, or positive.

But line encoding adds some extra bit overhead (extra bits) to the raw data. It also limits the RL and RD limits.

## Algorithms

**Controlling RL and RD**

A standard technique to manage the RL bounds is bit stuffing. In this technique, when a new bit x is given, the RL up to x is updated such that it is is incremented if x is equal to the previous bit, and otherwise, it is reset to 1. If it reaches Max RL, then x is inserted after x, and RL is reset to 1.

For controlling RD, the absolute value of the RD should be decreased when necessary. We are using S-bit inversion technique to produce low overhead. In this technique S-bit long FIFO  is available. An input bit stream comes through the FIFO. Suppose that a bit x is obtained from the output of the FIFO, and the FIFO is shifted with a  new bit in the input of the FIFO. RD handling is done when absolute value of RD reaches threshold value.

**Calculating Bit Overhead**

Average bit overhead is calculated with the formula below.
Average bit-overhead = Average number of inserted bits/Average raw data length

## Previous Results

**General Line Encoding Methods**

Three typical line codings, 8b/10b, 16b/18b, and 64b/67b, can be used for comparison, because the RD bounds are specified for them. The others such as 64b/66b, 128b/130b, 128b/132b have unlimited RD values, and thus, those cannot be used for this comparison. Table shows the parameters of these line codings. The S parameters are chosen as 2, 12, and 64 for 8b/10b, 16b/18b, and 64b/67b.

| Line Encoding | Max_RL | Max_RD | Bit-Overhead |
|:-------------:|:------:|:------:|:------------:|
|   8b/10b      |   5    |    3   |     25%      |
|   16b/18b     |   42   |   26   |    12.5%     |
|   64b/67b     |   64   |   96   |    4.687%    |
