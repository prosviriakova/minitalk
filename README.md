# minitalk
```
FINAL GRADE: 125/100
```
- C Programming
- Linux Process Management
- UNIX signals
- Bitwise operations
  
**Project goal:** To create a simple messaging system between a client and server using UNIX signals.

### Mandatory

We will create a communication program in the form of a client and a server.

- The server must be started first. After its launch, it has to print its PID.
- The client takes two parameters:
    1. The server PID.
    2. The string to send.
- The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
- The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
- Your server should be able to receive strings from several clients in a row without needing to restart.
- The communication between your client and your server has to be done only using UNIX signals.
- You can only use these two signals: SIGUSR1 and SIGUSR2.

### Bonus

- The server acknowledges every message received by sending back a signal to the
client.
- Unicode characters support.

## Usage
Start the server:
```
./server
```
The server displays its PID. Use this PID to send messages from the client:
```
./client <server_PID> "your message"
```
## Test
My program can transmit over 1 million characters in under 30 seconds and support Unicode characters. It uses a global variable to receive acknowledgments from the server.

To evaluate the execution time, run test.sh with:
```
./test.sh <server_PID>
```
Subject version: 3.
