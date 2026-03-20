import socket

'''
This function is creating tcp server to get the user msg
input: Ip address and port of the server
output: conversation socket and user message that was received
'''


def receive_msg_and_create_conversation(host, port):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.bind((host, port))
    sock.listen()
    conn, address = sock.accept()
    user_msg = conn.recv(1024)
    return conn, user_msg


'''
This function send the user message to the film4me server and return the message from them database
input: host and port of film4me server and user msg(named data)
output: reply from film4me server on user message
'''


def return_message_from_database_server(host, port, data):
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((host, port))
    sock.send(data)
    return sock.recv(1024)


'''
This function is fixing the message that was received from fil4me server if it should be fixed
input: message form fil4me
output: fixed message that will appear in user's application
'''


def fix_message(message):
    if 'France' in message.decode():
        return 'ERROR#"France is banned!"'.encode()

    return ('ERROR#' + message.decode().split('#')[1]).encode() if 'SERVERERROR' in message.decode() else\
        message.decode().replace('jpg', '.jpg').encode()


def main():
    while True:
        conn, user_msg = receive_msg_and_create_conversation('127.0.0.1', 9090)
        new_message = fix_message(return_message_from_database_server('54.71.128.194', 92, user_msg))
        conn.send(new_message)
    conn.close()


if __name__ == '__main__':
    main()
