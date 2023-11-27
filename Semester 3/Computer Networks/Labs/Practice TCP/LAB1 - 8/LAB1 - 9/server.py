import socket
import struct

FORMAT = 'utf-8'
PORT = 12345
SERVER = '127.0.0.1'
ADDR = (SERVER, PORT)


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(ADDR)
sock.listen(5)

def uncommon_numbers(first_array, second_array):
    common_numbers = []
    for i in range(len(first_array)):
        check = True
        for j in range(len(second_array)):
            if first_array[i] == second_array[j]:
                check = False
        if check:
            common_numbers.append(first_array[i])
    return common_numbers
while True:
    print("Waiting for a connection...")
    client_socket, client_address = sock.accept()
    print("Accepted connection from {}:{}".format(*client_address))

    a = client_socket.recv(2)
    a = struct.unpack('!H', a)[0]
    print("Received a: ", a)
    first_array = []
    for i in range(a):
        number = client_socket.recv(2)
        number = struct.unpack('!H', number)[0]
        first_array.append(number)
        print("Received : ", number)


    b = client_socket.recv(2)
    b = struct.unpack('!H', b)[0]
    second_array = []
    for i in range(b):
        number = client_socket.recv(2)
        number = struct.unpack('!H', number)[0]
        second_array.append(number)
        print("Received b: ", b)



    uncommon_numbers = uncommon_numbers(first_array, second_array)
    client_socket.send(struct.pack('!H', len(uncommon_numbers)))
    for i in range(len(uncommon_numbers)):
        client_socket.send(struct.pack('!H', uncommon_numbers[i]))

    client_socket.close()


