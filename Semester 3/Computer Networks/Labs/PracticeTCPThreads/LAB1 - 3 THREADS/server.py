import struct
import socket
import threading

FORMAT = 'utf-8'
PORT = 1234
SERVER = '0.0.0.0'
ADDR = (SERVER, PORT)

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)

def client_handler(client_socket, client_addr):
    print("Accepted connection from: {} : {}\n".format(*client_addr))

    received_string = client_socket.recv(1024)
    received_string = received_string.decode(FORMAT)

    reversed_string = received_string[::-1]

    print(reversed_string)

    client_socket.send(reversed_string.encode(FORMAT))
    client_socket.close()

def main():
    print("Waiting for connections...")
    sock.listen(5)
    while True:
        client_socket, client_address = sock.accept()
        thread = threading.Thread(target=client_handler, args=(client_socket, client_address))
        thread.start()

if __name__ == '__main__':
    main()