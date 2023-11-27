import socket
import struct
import threading

FORMAT = 'utf-8'
PORT = 1234
SERVER = '0.0.0.0'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)

def handle_client(client_socket, client_address):
    print("Accepted connection from {}:{}".format(*client_address))

    l = client_socket.recv(1024)
    l = l.decode(FORMAT)

    print("The string is:= ", l)
    count = 0
    for i in range(len(l)):
        if l[i] == ' ':
            count += 1

    client_socket.send(struct.pack('!H', count))

    client_socket.close()

def main():
    sock.listen(5)
    while True:
        client_socket, client_address = sock.accept()
        client_handler = threading.Thread(target = handle_client, args = (client_socket,client_address))
        client_handler.start()

if __name__ == '__main__':
    main()
