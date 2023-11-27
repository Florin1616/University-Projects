import select
import socket
import struct
import sys
import random
import time
from time import sleep

serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)
serv_socket.bind(('localhost',7001))
serv_socket.listen(10)

list_of_sockets = [serv_socket]
number_to_be_guessed = random.randint(1,100)
print(number_to_be_guessed)
connected_clients = {}


while True:
    curr_fd_list, _, _  = select.select(list_of_sockets, [], [])
    for fd in curr_fd_list:
        if fd == serv_socket:
            new_fd, new_addr = serv_socket.accept()
            connected_clients[new_fd] = new_addr
            list_of_sockets.append(new_fd)
            print("The user: " + str(connected_clients[new_fd][0]) + ":" + str(connected_clients[new_fd][1]) + ", socket: " + str(fd.fileno())+ " has connected!")
        else:
            received_guess = fd.recv(2)
            received_guess = struct.unpack('!h', received_guess)[0]

            message = "Another player entered: "
            message += str(received_guess)
            print(message)

            response_to_guess_hint = -3
            if received_guess == number_to_be_guessed:
                response_to_guess_hint = 0

            elif received_guess < number_to_be_guessed:
                response_to_guess_hint = -1
            else: response_to_guess_hint = 1
            for client in list_of_sockets:
                if client != serv_socket :
                    client.sendall(message.encode('ascii'))
                    time.sleep(2)
                    client.sendall(struct.pack('!h', response_to_guess_hint))
                    time.sleep(2)
                    if response_to_guess_hint == 0:
                        print("Game over!")
                        exit(0)