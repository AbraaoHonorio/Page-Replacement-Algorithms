# Page-Replacement-Algorithms
Implementation of algorithms for replacing pages in memory

## Algorithms

- FIFO (First-in-First-out)
- OTM (Optimal Algorithm)
- LRU (Last Recent Used)


### Page replacement 

The input is a list of integer numbers, one per line, whose first number indicates
the number of available frames in RAM, and the rest indicates the sequences
of references to memory. E.g.:

    4
    1
    2
    3
    4
    1
    2
    5
    1
    2
    3
    4
    5



## Output


The program emits, for every page replacement algorithm, the number of page faults.
For example, for the example given above, we have as result:

    FIFO 10
    OTM 6
    LRU 8
    
### Building for source 
  ```sh
  make all
   ```
   
   ## Reference

[Nobr15]  
Alexandre Nóbrega. 2015.  
Site of Operating Systems course.  
Available at http://alexandre.ci.ufpb.br/ensino/so/.
 
