
## Data Communications (CO250): Mini-Project

**Title:**

Improvement of Line Coding Overhead Targeting Both Run-Length and DC-Balance

**Members:**

Kaushik I. (16CO120) - <kaushik5699@gmail.com>

Pavan Vachhani (16CO151) - <vachhanihpavan@gmail.com>

**Abstract:**

High-speed serial data communication is now very
popular for connecting various resources in high-performance
computing systems. In such high-speed serial links, a line coding
is important to control the run length (RL) and the running
disparity (RD), because a large run length causes insufficient
transitions on data-links that make it difficult to perform reliable
clock and data recovery (CDR), and a bounded running disparity
is needed for maintaining the DC-balance of data links. These
requirements for a line coding, however, cause additional bits
to be transmitted, which decreases the throughput of data
transmission. We are implementing a new approach which guarantees the bounded run length and running disparity. We will also compare the overhead values with other line encoding schemes like 8b/10b.

**Objectives:**

* Implementing algorithm to encode the bit stream with the new approach.

* Comparing the bit overhead with other encoding schemes
* Implementing algorithm to decode the bit stream with new approach 

**References:**

1. Tomohiro Yoneda, Sarat Yoowattana, "Improvement of Line Coding Overhead Targeting Both
Run-Length and DC-Balance", 2016 IEEE 10th International Symposium on Embedded Multicore/Many-core Systems-on-Chip (http://ieeexplore.ieee.org/document/7774415)
    * For combined RL-RD handling technique.

2. BOSCH. CAN specification.
    * For RL handling bit-stuffing technique.

3. J. Saade, A. Goulahsen, A. Picco, J. Huloux, and F. Petrot. Low overhead, DC-balanced and run length limited line coding. In Signal and Power Integrity (SPI), 2015 IEEE 19th Workshop on, pages 1–4, May 2015.
    * For RD handling using S-block inversion technique.

## File Structure

* Introduction.md - Explain theoretical aspects of the mini project.

* Design.md - Explain design aspects of the mini project.

* Implementation - Code under development

* Cleaned Code - Code working with all functions

```
CO250-MP-120-151
│   README.md
│   Introduction.md
|   Design.md
│
└───Implementation
│      b2s.cpp
│      s2b.cpp
|      decode.cpp
|      encode.cpp
|      graphs.m
|      encode_string.cpp
|      decode_input.txt
|      decoded_data.txt
|	   controller.c
|      automation.cpp
│   
└───Cleaned Code
       b2s.cpp
       s2b.cpp
       decode.cpp
       encode.cpp
       automation.cpp
       graphs.m
       Overlap.m
       |__MATLAB
            Initial implementation idea
          
          
          
```

## Dependencies

Following are the basic dependencies required to run the code
1. C++ compiler on Windows OS for system calls
2. MATLAB