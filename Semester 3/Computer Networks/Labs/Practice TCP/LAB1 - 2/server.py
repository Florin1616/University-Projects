import socket
import struct

PORT = 1234
SERVER = '127.0.0.1'
ADDR = (SERVER,PORT)
FORMAT = 'utf-8'


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)

sock.listen(5)

while True:
    print("Waiting for a connection...")
    client_socket, client_address = sock.accept()
    print("Accepted connection from {}:{}".format(*client_address))

    str = client_socket.recv(1024)
    str = str.decode()
    print("Received string: ", str)

    number_of_empty_spaces = 0

    for i in range(len(str)):
        if str[i] == ' ':
            number_of_empty_spaces += 1

    client_socket.send(struct.pack('!H', number_of_empty_spaces))
    #client_socket.send(str.encode())
    client_socket.close()