# minitalk
```
FINAL GRADE: 125/100
```
- C Programming
- Linux Process Management
- UNIX signals
- Bitwise operations
  
**Project goal:** To create a simple messaging system between a client and server using UNIX signals.

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
My program can transmit over 1 million characters in under 30 seconds, supporting Unicode characters. It uses a global variable to receive acknowledgments from the server.

To evaluate the execution time, run test.sh with:
```
./test.sh <server_PID>
```
