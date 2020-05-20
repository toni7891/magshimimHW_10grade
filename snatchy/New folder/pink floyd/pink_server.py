import socket

PORT = 1337


def main():
    print("Listening on port 1337") # make sure server listening
    call_function = {"ListOfAlbums": ListOfAlbums, "SongsInAlbum": SongsInAlbum, "SongLength": SongLength, "GetLyrics": GetLyrics, "WhichAlbum": WhichAlbum, "SongByName": SongByName, "SongByLyrics": SongByLyrics, "MostCommonWords": MostCommonWords, "albumLength": albumLength}
    listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('', PORT)
    listen_socket.bind(server_address)

    while True:
        listen_socket.listen(1)
        client_socket, client_address = listen_socket.accept()
        command = ""
        client_socket.sendall("Welcome!".encode())
        print(client_address[0] + " has connected on port " + str(client_address[1]))
        while not command == "Exit":
            try:    # if cant connect throw Exception
                response = client_socket.recv(1024).decode()
                command, parameter = disassemble_response(response)
                if not command == "Exit":
                    a = call_function[command](parameter)
                    client_socket.sendall(a.encode())
            except Exception:
                print("Client disconnected unexpectedly")
                client_socket.close()
                break
        client_socket.close()
    listen_socket.close()


def disassemble_response(client_response):
    command = client_response[8:client_response.index('&')]
    parameter = client_response[client_response.index('&') + 11:]
    return command, parameter


def ListOfAlbums(parameter):
    print("ListOfAlbums function is being activated")
    return "Album list: "


def SongsInAlbum(parameter):
    print("SongsInAlbum function activated")
    return "Songs in " + str(parameter)


def SongLength(parameter):
    print("SongLength function activated")
    return parameter + "\'s length: "


def GetLyrics(parameter):
    print("GetLyrics function activated")
    return "Lyrics for"


def WhichAlbum(parameter):
    print("WhichAlbum function activated")
    return "The song of album"


def SongByName(parameter):
    print("SongByName function activated")
    return "Songs with the word you entered are in their name are: "


def SongByLyrics(parameter):
    print("SongByLyrics function activated")
    return "Songs with the lyrics you entered are: "


def MostCommonWords(parameter):
    return "The 50 most common words are: "


def albumLength(parameter):
    return "This is a list of albums from the longest to the shortest: "


if __name__ == '__main__':
    main()