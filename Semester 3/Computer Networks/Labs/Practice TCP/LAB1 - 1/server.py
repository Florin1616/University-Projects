import socket
import struct
SIZE = 16
FORMAT = 'utf-8'
EXIT_MESSAGE = '!EXIT'
PORT = 1233
SERVER = "0.0.0.0"
ADDR = (SERVER, PORT)


# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)

sock.listen(5)
while True:
    client_socket, client_address = sock.accept()
    print("Accepted connection from {}:{}".format(*client_address))

    l = struct.unpack('!H', client_socket.recv(2))[0]
    print("The length l =", l)

    sum = 0
    for i in range(l):
        number = struct.unpack('!H', client_socket.recv(2))[0]
        print("Received number =", number)
        sum += number

    client_socket.send(struct.pack('!H', sum))
    client_socket.close()


