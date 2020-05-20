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
    socket_status.bind((CLIENTSIDE_IP_ADDR, CLIENTSIDE_PORT))
    socket_status.listen()
    conn, addr = socket_status.accept()
    client_message = conn.recv(1024).decode()
    return conn, client_message


# fixing error because of dumb protocol
def error_help(client_message):
    socket_get_message = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    socket_get_message.connect(
        (SERVER_IP_ADDR, SERVER_PORT))
    socket_get_message.send(client_message.encode())
    reply = socket_get_message.recv(1024)
    for_black = reply.decode()

    if 'France' in reply.decode():
        return 'ERROR#"France is banned!"'.encode()
    if 'SERVERERROR' in reply.decode():
        return ('ERROR#' + reply.decode().split('#')[1]).encode()
    if 'SERVERERROR' not in reply.decode() and 'France' not in reply.decode():
        return reply.decode().replace('jpg', '.jpg').encode()
    if(for_black.count("actors:") > 0):
        black_file = open("blackList.txt", 'r')
        blacklist_ban = black_file.read()
        blacklist_ban = blacklist_ban.split(',')
        banned_actors = for_black[for_black.find("actors:\"") + 8 :for_black.find("\"", for_black.find("actors:\"") + 10):].split(',')
        
        for item in blacklist_ban:
            if item in blacklist_ban:
                return ("ERROR#\" the movie was blocked because an actor that appear in the film is banned in the black list! ( " + item + " )").encode()
    


def main():
    while True:
        conn, message_from_usr = proxy_server()
        print(message_from_usr)
        message_from_usr = error_help(message_from_usr)
        conn.send(message_from_usr)
    conn.close()


if __name__ == "__main__":
    main()
