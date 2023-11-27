import socket
import struct

FORMAT = 'utf-8'
PORT = 1234
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)


a = int(input("Enter the number a:"))
sock.send(struct.pack('!H', a))

divisors = []
c = sock.recv(2)
c = struct.unpack('!H', c)
length = c[0]
for i in range(length):
    c = sock.recv(2)
    c = struct.unpack('!H', c)
    divisors.append(c[0])

print(f"The divisors of {a} are:")
for i in range(len(divisors)):
    print(divisors[i])

sock.close()
