import struct
import socket

PORT = 1239
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)
FORMAT = 'utf-8'

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)
sock.listen(5)

def compute_positions(string,character):
    positions = []
    for i in range(len(string)):
        if string[i] == character:
            positions.append(i)
    return positions


while True:
    print("Waiting for a connection...")
    client_socket, client_address = sock.accept()
    print("Accepted connection from {}:{}".format(*client_address))


    str = client_socket.recv(1024).decode(FORMAT)
    c = client_socket.recv(1).decode(FORMAT)

    print("Received string: ", str)
    print("Received character: ", c)

    positions_of_character_in_string = compute_positions(str,c)
    print(positions_of_character_in_string)
    length = len(positions_of_character_in_string)

    client_socket.send(struct.pack('!H', length))
    for i in range(length):
        client_socket.send(struct.pack('!H', positions_of_character_in_string[i]))

    client_socket.close()
