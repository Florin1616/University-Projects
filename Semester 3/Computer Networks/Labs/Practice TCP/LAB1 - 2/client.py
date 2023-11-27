import struct
import socket

SIZE = 16
FORMAT = 'utf-8'
PORT = 1234
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

str = input("Enter a string: ")

sock.send(str.encode())

c = sock.recv(2)
c = struct.unpack('!H', c)
print('Number of empty spaces is: ' + c[0].__format__('d'))

sock.close()