import socket
import struct

PORT = 1239
SERVER = '127.0.0.1'
ADDR = (SERVER,PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.connect(ADDR)

str = input("Enter the string: ")
character = input("Enter the character: ")

sock.send(str.encode())
sock.send(character.encode())

c = sock.recv(2)
c = struct.unpack('!H', c)
length_of_positions_list = c[0]


positions = []
for i in range(length_of_positions_list):
    c = sock.recv(2)
    c = struct.unpack('!H', c)
    positions.append(c[0])

print(f"The positions of the character {character} in the string {str} are:")
print(positions)

sock.close()