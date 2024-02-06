import socket
HOST="127.0.0.1" #loopback address
PORT=1235 #port number, make sure it is greater than 1024
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    messagi = input("Enter your messagi in lower case: ")
    s.sendall(messagi.encode())
    data = s.recv(1024)
    print("Received ", data.decode())
s.close()
