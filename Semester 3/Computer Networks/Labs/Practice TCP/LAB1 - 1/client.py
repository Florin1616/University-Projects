import struct
import socket
SIZE = 16
FORMAT = 'utf-8'
EXIT_MESSAGE = '!EXIT'
PORT = 1233
SERVER = "127.0.0.1"
ADDR = (SERVER, PORT)


# Create a TCP/IP socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

length = int(input("How many numbers do you want to read? "))
sock.send(struct.pack('!H', length))

for i in range(length):
    number = int(input("Number: "))
    sock.send(struct.pack('!H', number))

c = sock.recv(2)
c = struct.unpack('!H', c)
print('Sum of numbers: ' + c[0].__format__('d'))

sock.close()