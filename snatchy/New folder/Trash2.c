import socket

# server and client info
SERVER_IP_ADDR = '54.71.128.194'
SERVER_PORT = 92
CLIENTSIDE_IP_ADDR = '127.0.0.1'
CLIENTSIDE_PORT = 9090


# the proxy server

# in this function i took insperation from
# https://stackoverflow.com/questions/51331426/python-socket-how-do-i-choose-between-s-send-and-conn-send

def proxy_server():
    socket_status = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_status = socket_status.bind((CLIENTSIDE_IP_ADDR, CLIENTSIDE_PORT))
    socket_status = socket_status.listen()
    conn, addr = socket_status.accept()
    client_message = conn.recv(1024).decode()
    return conn, client_message


# fixing error because of dumb protocol
def error_help(client_message):
    socket_get_message = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_get_message = socket_get_message.connect(
        (SERVER_IP_ADDR, SERVER_PORT))
    socket_get_message = socket_get_message.send(client_message)
    if 'France' in client_message.decode():
        return 'ERROR#"France is banned!"'.encode()
    if 'SERVERERROR' in client_message.decode():
        return ('ERROR#' + client_message.decode().split('#')[1]).encode()
    if 'SERVERERROR' not in client_message.decode() and 'France' not in client_message.decode():
        return client_message.decode().replace('jpg', '.jpg').encode()


def main():
    while True:
        message_from_usr = proxy_server()
        print(message_from_usr)
        error_help(message_from_usr)
    conn.close()


if __name__ == "main":
    main()
