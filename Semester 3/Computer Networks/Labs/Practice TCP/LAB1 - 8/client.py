import struct
import socket

FORMAT = 'utf-8'
PORT = 12345
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

a = int(input("Enter the length of the first array: "))
sock.send(struct.pack('!H',a))
for i in range(a):
    number = int(input("Number: "))
    sock.send(struct.pack('!H', number))

b = int(input("Enter the length of the second array: "))
sock.send(struct.pack('!H',b))
for i in range(b):
    number = int(input("Number: "))
    sock.send(struct.pack('!H', number))

c = sock.recv(2)
c = struct.unpack('!H', c)[0]
common_numbers = []
for i in range(c):
    c = sock.recv(2)
    c = struct.unpack('!H', c)[0]
    common_numbers.append(c)

print(f"The common numbers are: {common_numbers}")

sock.close()