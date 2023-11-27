#CREATE THE TCP SOCKET AND CONNECT
import select
import socket
import struct
import sys
import time

serv_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serv_socket.connect(('localhost', 7001))

list_of_sockets = [sys.stdin, serv_socket]
while True:
    curr_fds_list, _, _ = select.select(list_of_sockets, [], [])
    for fd in curr_fds_list:
        if fd == sys.stdin:
        #THIS MEANS THAT WE NEED TO READ FROM THE KEYBOARD AND SEND THE GUESS
            read_number = int(input())
            serv_socket.sendall(struct.pack('!h', read_number))
        else:
            #THIS MEANS WE WILLR RECEIVE A NUMBER FROM THE SERVER AND WE NEED TO PRINT IT
            message_answer = fd.recv(256)
            message_answer = message_answer.decode('ascii')
            print(message_answer)


            answer_number = serv_socket.recv(2)
            answer_number = struct.unpack('!h', answer_number)[0]
            print(answer_number)
            if(answer_number == 0):
                print("GAME IS OVER!")
                time.sleep(5)
                fd.close()
                exit(0)