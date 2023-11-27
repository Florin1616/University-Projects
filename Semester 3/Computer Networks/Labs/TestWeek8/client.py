import select
import socket
import struct
import sys

SERVER_ADDR = ('127.0.0.1', 1234)

tcp_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_sock.connect(SERVER_ADDR)

udp_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)
udp_sock.bind(('0.0.0.0', 1233))

list_of_sockets = [sys.stdin, tcp_sock, udp_sock]

while True:
    curr_fds_list, _, _  = select.select(list_of_sockets, [], [])
    for fd in curr_fds_list:
        if fd == tcp_sock:
            #THIS MEANS WE GET A MESSAGE FROM THE SERV
            mes = tcp_sock.recv(1024)
            print(mes.decode())
        elif fd == udp_sock:
            #THIS MEANS WE RECEIVE THE MAP FROM THE SERVER
            data, addr = udp_sock.recvfrom(256)
            print(data.decode())
        else:
            #THIS MEANS THE USER WANTS TO SEND A MESSAGE TO THE SERVER
            index = int(input())
            character = input()
            tcp_sock.send(struct.pack('!H', index))
            tcp_sock.send(character.encode())