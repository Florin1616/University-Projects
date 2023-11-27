import socket
import struct
import time
import select

list_of_questions = "10+2;4/2;3+1"
list_of_answers = [12, 2, 4]
number_of_questions = 3

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp.bind(('0.0.0.0', 1238))
tcp.listen(5)

connected_clients = [tcp]

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
udp.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)


total_time = 12
while total_time > 0:
    udp.sendto(list_of_questions.encode(), ("<broadcast>", 7777))
    time.sleep(2)
    total_time -= 2
print("FINISHED")
udp.close()

clients_score = {}


while True:

    current_fds_list, _, _ = select.select(connected_clients, [], [])
    for fd in current_fds_list:
        if fd == tcp:
            new_sock, addr = tcp.accept()
            print("A new client has connected ", addr)
            msg = new_sock.recv(1024)
            print(msg.decode())
            connected_clients.append(new_sock)
        else:
            nr = 3
            clients_score[fd] = []
            while nr > 0:
                data = fd.recv(8)

                if data:
                    index, answer = struct.unpack("!ii", data)
                    print(index, answer)
                    clients_score[fd].append((index, answer))

                    score = 0
                    if len(clients_score[fd]) == 3:
                        pass
                nr-=1
            score = 0
            if len(clients_score[fd]) == 3:
                #TIME TO COMPUTE THE SCORE
                for index, answer in clients_score[fd]:
                    if list_of_answers[index] == answer:
                        score += 10
                time.sleep(5)
                fd.send(struct.pack('!i', score))

            print("The client with addr:" + str(fd.getpeername()) + " has disconnected")
            fd.close()
            connected_clients.remove(fd)