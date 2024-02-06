import socket
HOST="127.0.0.1" #loopback address
PORT=1238 #port number, make sure it is greater than 1024
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    messagi = input("Enter your messagi in lower case: ")
    s.sendto(messagi.encode(), (HOST, PORT))
    data,addr = s.recvfrom(1024)
    print("Received ", data.decode())
s.close()
