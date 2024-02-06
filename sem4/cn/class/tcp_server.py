import socket
HOST="127.0.0.1" #loopback address
PORT=12345 #port number, make sure it is greater than 1024
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.bind((HOST, PORT))
    s.listen() #listen for incoming connections, if no argument is passed, its listening to 1 client, specify the number of clients 
    conn,addr = s.accept() #accept the connection
    #accept method return a new socket object representing the connection and a tuple holding the address of the client
    with conn:
        print("Connected by", addr)
        while True:
            data = conn.recv(1024)
            if not data:
                break
            upper_data=data.decode().upper(data)
            conn.sendall(upper_data.encode())
s.close()

