import socket
import struct
import time

udp = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
udp.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
udp.bind(("0.0.0.0", 7777))
d,a = udp.recvfrom(1024)
list_of_questions = d.decode()
print(list_of_questions)
time.sleep(10)

SERVER = '127.0.0.1'
PORT = 1238
ADDR = (SERVER, PORT)

tcp = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
tcp.connect(ADDR)
tcp.send("Hello".encode())

number_of_questions = list_of_questions.count(";") + 1
print(number_of_questions)
while number_of_questions > 0:
    try:
        index = int(input("Enter the index of the problem you want to answer to: "))
        answer = int(input("Enter the answer: "))

        tcp.send(struct.pack("!ii", index, answer))
    except ValueError:
        print("Invalid input")
    number_of_questions -= 1


score = tcp.recv(4)
print("The obtained score is ", struct.unpack("!i", score)[0])
tcp.close()