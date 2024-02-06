import socket
HOST="127.0.0.1" #loopback address
PORT=1238 #port number, make sure it is greater than 1024
with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as s:
    s.bind((HOST, PORT))
    print("UDP server is now listening")
    while True:
        data,addr = s.recvfrom(1024)
        print("Received ", data.decode(), " from ", addr)
        upper = data.decode().upper()
        s.sendto(upper.encode(), addr)
        print("Sent upper stuff to client")
s.close() 
