import socket

PORT = 1235
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

    reversed_str = str[::-1]
    print("The string sent is:" + reversed_str)

    client_socket.send(reversed_str.encode())
    client_socket.close()
