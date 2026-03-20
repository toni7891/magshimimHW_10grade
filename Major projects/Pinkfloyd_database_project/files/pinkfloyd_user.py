import socket



IP = "127.0.0.1"
PORT = 4242


def main():
    connection = tcp_socket()
    menu(connection)
    connection.close()






def tcp_socket():
    connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    adress = (IP, PORT)
    message = ""
    while message != "Welcome!":
        connection.connect(adress)
        message = connection.recv(1024)
        message.decode()
    print(message)
    return connection
def menu(connection):
    print("Commands: 1-List of albums"
          "2 - list of songs in album"
          "3 - length of song"
          "4 - words of song"
          "5 - find song in albums"
          "6 - find song by using word"
          "7 - find song by using liricks"
          "8 - Exit ")
    choice = int(input("Enter your choise:"))
    if (choice == 1):
        msg = "1,"
        connection.sendall(msg.encode())
    elif (choice == 2):
        msg = "2,"
        connection.sendall(msg.encode())
    elif (choice == 3):
        msg = "3,"
        msg_temp = input("Enter name of song: ").lower()
        msg += msg_temp
        connection.sendall(msg.encode(),msg_temp.encode())
    elif (choice == 4):
        msg = "4,"
        msg_temp = input("Enter name of song: ").lower()
        msg += msg_temp
        connection.sendall(msg.encode(),msg_temp.encode())
    elif (choice == 5):
        msg = "5,"
        msg_temp = input("Enter name of song: ").lower()
        msg += msg_temp
        connection.sendall(msg.encode(),msg_temp.encode())
    elif (choice == 6):
        msg = "6,"
        msg_temp = input("Enter word in title: ").lower()
        msg += msg_temp
        connection.sendall(msg.encode(),msg_temp.encode())
    elif (choice == 7):
        msg = "7,"
        msg_temp = input("Enter word in lyrics: ").lower()
        msg += msg_temp
        connection.sendall(msg.encode(),msg_temp.encode())
    elif (choice == 8):
        msg = "8,"
        connection.sendall(msg.encode())

