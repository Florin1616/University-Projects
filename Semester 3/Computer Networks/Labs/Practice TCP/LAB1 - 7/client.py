import struct
import socket

FORMAT = 'utf-8'
PORT = 12345
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

str = input("Enter the string: ")
a = int(input("Enter the starting index: "))
b = int(input("Enter the length of the substring: "))

sock.send(str.encode())
sock.send(struct.pack('!H',a))
sock.send(struct.pack('!H',b))

c = sock.recv(1024)
substring = c.decode()

print(f"The substring from position {a} to position {b} from the word {str} is: \n{substring}")

sock.close()