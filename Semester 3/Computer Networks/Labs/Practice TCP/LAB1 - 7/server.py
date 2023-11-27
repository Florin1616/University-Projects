import socket
import struct

FORMAT = 'utf-8'
PORT = 12345
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)
sock.listen(5)

def compute_substring(string, a, b):
    new_string = ""
    for i in range(a,len(string)):
        print(new_string)
        print(string[i])
        if len(new_string) == b:
            break
        new_string += string[i]
    return new_string

while True:
    print("Waiting for a connection...")
    client_socket, client_address = sock.accept()
    print("Accepted connection from {}:{}".format(*client_address))

    str = client_socket.recv(1024).decode(FORMAT)
    print("Received string: ", str)

    a = client_socket.recv(2)
    a = struct.unpack('!H', a)[0]
    print("Received a: ", a)

    b = client_socket.recv(2)
    b = struct.unpack("!H",b)[0]
    print("Received b: ", b)

    computed_substring = compute_substring(str,a,b)
    print(computed_substring)

    client_socket.send(computed_substring.encode(FORMAT))

    client_socket.close()


