import socket


PORT = 4242
IP = ''
def main():
    listen_sock = listen_function()
    while True:
        listen_sock.listen()
        conn, message = listen_sock.accept()
        conn.sendall("Welcome!".encode())
        command = ""
        while command != "8":
            responce = conn.recv(1024)
            responce.decode()
            command, param = protocol(responce)
            conn.sendall("you want to get:".encode() + command.encode())

    listen_sock.close
    conn.close()



def listen_function():
    listen_sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_adress = (IP, PORT)
    listen_sock.bind(server_adress)
    return listen_sock



def protocol(responce):
    responce = responce.split(',')
    command = responce[0]
    param = responce[1]
    return command, param
