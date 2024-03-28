# OS HW1
## 2.24
step 1:
```bash=
strace ./FileCopy
```
![alt text](image-2.png)

step 2:
#### enter input & copy
![alt text](image-6.png)

step 3:
#### done
![alt text](image-5.png)

## 3.19
### Pipe
step 1:
```bash=
./time mkdir test_dir
```
![alt text](image-8.png)

step 2:
#### done
![alt text](image-7.png)

### Shared Memory

step 1:
```bash=
./time mkdir test_dir
```
![alt text](image-9.png)

step 2:
#### done
![alt text](image-10.png)

## 3.21
step 1:
```bash=
./main
35
```
![alt text](image-12.png)

step 2:
#### done
![alt text](image-13.png)

## 3.27
step 1:
#### enter something into input.txt &
```bash=
./filecopy input.txt copy.txt
```
![alt text](image-14.png)

step 2:
#### done & check copy.txt

## project
#### entire code all made by Hung-Yuan, Hsiao 110590063

### simple
step 1:
```bash=
sudo dmesg -C #TO CLEAR DMESSG
```

step 2:
```bash=
sudo insmod simple.ko
```

step 3:
```bash=
sudo dmesg
```
![alt text](image-17.png)

step 4:
```bash=
sudo rmmod simple
```
step 5:
```bash=
sudo dmesg
```
![alt text](image-18.png)

### hello
step 1:
```bash=
sudo insmod hello.ko
```

step 2:
```bash=
cat /proc/hello
```
![alt text](image-20.png)

step 4:
```bash=
sudo rmmod hello
```

### jiffies
step 1:
```bash=
sudo insmod jiffies.ko
```

step 2:
```bash=
cat /proc/jiffies
```
![alt text](image-21.png)

step 3:
```bash=
sudo rmmod hello
```

### seconds
```bash=
sudo insmod seconds.ko
```

step 2:
```bash=
cat /proc/seconds
```
![alt text](image-22.png)

step 3:
```bash=
sudo rmmod seconds
```
