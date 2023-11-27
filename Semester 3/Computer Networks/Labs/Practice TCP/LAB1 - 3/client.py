import struct
import socket

SERVER = '127.0.0.1'
PORT = 1235
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

str = input("Enter a string: ")
sock.send(str.encode())

c = sock.recv(1024)
c = c.decode()

print("The reversed string is: ", c)
sock.close()

