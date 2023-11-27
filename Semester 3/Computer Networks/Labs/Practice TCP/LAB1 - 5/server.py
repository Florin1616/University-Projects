import struct
import socket

FORMAT = 'utf-8'
PORT = 1234
SERVER = '127.0.0.1'
ADDR = (SERVER,PORT)


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)
sock.listen(5)

def divisors_of_number(nb):
    divisors = []
    #do an algorithm to determine the divisors of nb
    i = 0
    for i in range(1, nb + 1):
        if nb % i == 0:
            divisors.append(i)
    if i*i == nb:
        divisors.append(i)
    return divisors

while True:
    print("Waiting for a connection...")
    client_socket, client_address = sock.accept()
    print("Accepted connection from {}:{}".format(*client_address))

    nb = struct.unpack('!H', client_socket.recv(2))[0]
    print("The numver received is =", nb)

    divisors = divisors_of_number(nb)
    print("The divisors are:", divisors)

    client_socket.send(struct.pack('!H', len(divisors))) # WE SEND THE LEN OF THE ARRAY
    for i in range(len(divisors)):
        client_socket.send(struct.pack('!H', divisors[i]))

    client_socket.close()


