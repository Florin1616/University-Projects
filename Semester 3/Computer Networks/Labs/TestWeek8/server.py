import select
import struct
import socket

tcp_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
tcp_sock.bind(('0.0.0.0', 1234))
tcp_sock.listen(5)

list_of_sockets = [tcp_sock]
connected_clients = {}
nr_of_connected_clients = 0

map_to_guess = ['u','u','u','u','u']

udp_sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR,1)
udp_sock.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST,1)

while True:
    curr_fds_list, _, _ = select.select(list_of_sockets, [], [])
    for fd in curr_fds_list:
        if fd == tcp_sock:
            #THIS MEANS A NEW CLIENT WANTS TO CONNECT
            new_sock, new_addr = tcp_sock.accept()
            connected_clients[new_sock] = new_addr
            list_of_sockets.append(new_sock)
            nr_of_connected_clients += 1
            print("SAY WELCOME TO THE NEW USER: " +  str(new_addr))

        else:
            #THIS MEANS THAT IS A CLIENT THAT IS ALREADY CONNECTED

            index = fd.recv(2)
            index = struct.unpack('!H', index)[0]
            character = fd.recv(1)
            character = character.decode()
            if map_to_guess[index] == 'u':
                map_to_guess[index] = character
            print(map_to_guess)

            str_map_to_guess = ""
            str_map_to_guess += str(map_to_guess)
            udp_sock.sendto(str_map_to_guess.encode(), ('<broadcast>', 1233))