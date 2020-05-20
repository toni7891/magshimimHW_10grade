import socket
import time

IP = "127.0.0.1"
PORT = 1337


def main():
    command_list = ["ListOfAlbums", "SongsInAlbum", "SongLength", "GetLyrics","WhichAlbum", "SongByName", "SongByLyrics", "MostCommonWords", "AlbumLength", "Exit"]
    choice = "ListOfAlbums"
    connect = connection_to_server(IP, PORT)
    while not choice == command_list[9]:
        print(command_list)
        choice = input("Enter command: ")
        if choice == command_list[0]:
            connect = assemble_request(command_list[0], connect)
        elif choice == command_list[1]:
            album_name = input("Enter album name: ")
            connect = assemble_request(command_list[1], connect, album_name)
        elif choice == command_list[2]:
            song_name = input("Enter song name: ")
            connect = assemble_request(command_list[2], connect, song_name)
        elif choice == command_list[3]:
            song_name = input("Enter song name: ")
            connect = assemble_request(command_list[3], connect, song_name)
        elif choice == command_list[4]:
            song_name = input("Enter song name: ")
            connect = assemble_request(command_list[4], connect, song_name)
        elif choice == command_list[5]:
            word = input("Enter a word: ")
            connect = assemble_request(command_list[5], connect, word)
        elif choice == command_list[6]:
            word = input("Enter a word: ")
            connect = assemble_request(command_list[6], connect, word)
        elif choice == command_list[7]:
            connect = assemble_request(command_list[7], connect)
        elif choice == command_list[8]:
            connect = assemble_request(command_list[8], connect)
        elif choice == command_list[9]:
            assemble_request(command_list[9], connect)
        else:
            print("Invalid command!\n")


def assemble_request(command, connect, parameter=""):
    request = ("command=" + command + "&parameter=" + parameter).encode()
    try:
        connect.sendall(request)
        print(connect.recv(4096).decode())
    except Exception:
        print("Re-connecting to server\n")
        return connection_to_server(IP, PORT)
    return connect


def connection_to_server(IP, PORT):
    connection_status = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    address = (IP, PORT)
    message = ""
    while not message == "Welcome to Pink Floyd database!":
        try:
            connection_status.connect(address)
            message = connection_status.recv(1024).decode()
        except Exception:
            print("Can't reach server, trying again")
            time.sleep(2)
    print(message)
    return connection_status


if __name__ == '__main__':
    main()
