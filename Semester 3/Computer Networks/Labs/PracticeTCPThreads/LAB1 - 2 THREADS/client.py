import socket
import struct

FORMAT = 'utf-8'
PORT = 1234
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

read_string = input("Enter a string: ")
sock.send(read_string.encode(FORMAT))

c = sock.recv(2)
c = struct.unpack('!H', c)
print(c[0])