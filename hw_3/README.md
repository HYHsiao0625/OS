
# HW2

7.15:
```bash=
g++ main.c -o main
./main
```

7.17:
```bash=
g++ main.c -o main
./main
```


9.28:
```bash=
g++ main.c -o main
./main 19986
```


ch7:
```bash=
make
./main
```

ch8:
```bash=
make
./banker 10 6 7 8
```


Operations:

    Request resources: RQ <customer> <resources>
    Release resources: RL <customer> <resources>
    Display resources: *

ch9:
```bash=
make
./memory_allocator 100
```


Operations:

    RQ <process name> <memory size (in bytes)> <strategy>
    Request for a contigous block of memory (available strategies are F, W and B)

    RL <process name>
    Release the process's contigous block of memory

    C
    Compact unused holes of memory into one single block

    STAT
    Report the regions of free and allocated memory

    X
    Exit