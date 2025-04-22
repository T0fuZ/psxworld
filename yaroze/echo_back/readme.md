F: drive in Dosbox is my mount to  this project

```siocons auto``` loads all and executes and we can see that the echo back to STDOUT works fine
```
F:\ECHO_B~1>make
gcc -c -O3 main.c
gcc -Xlinker -Map -Xlinker mapfile -Xlinker -Ttext -Xlinker 80100000 main.o -o m
ain

F:\ECHO_B~1>siocons auto
siocons -- PlayStation debug system console program
   for DTLH3000 1996/05/10 00:00:03
   type  F1   ----> display help
   when hung up try type  ESC
 I/O addr = 0x03F8, IRQ=4(vect=0x000C,8259=20)
 BAUDRATE = 115200
main [ .text] address:80100000-8010022f size:000230  000230:    0sec.
main [.rdata] address:80100230-8010024f size:000020  000020:    1sec.
main [ .data] address:80100250-8010039f size:000150  000150:    1sec.
main [.sdata] address:801003a0-8010042f size:000090  000090:    2sec.
  PC=80100070, GP=801083a0, SP=801ffff0

>>go
hi
Reply to STDOUT: hi
this seems to be working
Reply to STDOUT: this seems to be working
nice
Reply to STDOUT: nice
quit
Reply to STDOUT: quit
ResetGraph:jtb=8004829c,env=800482e4
ResetGraph:jtb=8004829c,env=800482e4
PS-X Control PAD Driver  Ver 3.0
addr=8004d724

Connected CIP ver2.0
Communication baud rate 115200 bps
OK
>>Terminate by user!
F:\ECHO_B~1>
```