import socket

SERVER_IP = "54.71.128.194"
SERVER_PORT = 92
IP = "127.0.0.1"
PORT = 9090

def main():

    while True:
        conn, message = connect()
        message = send_connection(message)

        if (message[:5] != "ERROR") and (message.find("France") == -1):
            message = message[:len(message) -11] + "." + message[len(message) -11:]
            message = message[:16] + "Proxy" + message[16:]

        elif (message[:6] == "SERVER") and (message.find("France") == -1):
            message = message[6:]

        elif message.find("France") != -1:
            message ='ERROR#"France is banned!"'#french films is bullshit
        message = message.encode()
        print(message)
        conn.send(message)
    conn.close()


def connect():
    sock_listen = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = (IP, PORT)
    sock_listen.bind(address)
    sock_listen.listen()
    conn, addr = sock_listen.accept()
    message = conn.recv(1024)
    message = message.decode()
    print("Message:" + message)
    return conn, message

def send_connection(message):
    sock_send = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = (SERVER_IP, SERVER_PORT)
    sock_send.connect(address)
    sock_send.sendall(message.encode())
    response = sock_send.recv(1024)
    response = response.decode()
    return response

if __name__ == "__main__":
    main()
