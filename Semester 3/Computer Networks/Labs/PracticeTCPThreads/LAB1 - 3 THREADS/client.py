import struct
import socket

FORMAT = 'utf-8'
PORT = 1234
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
sock.connect(ADDR)

read_string = input("Please enter the string: ")
sock.send(read_string.encode(FORMAT))

receiced_string = sock.recv(1024)
receiced_string = receiced_string.decode(FORMAT)

print("The received string is: " + receiced_string)
sock.close()