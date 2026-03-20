import socket
import data_pink

database = data_pink.extract_data("Pink_Floyd_DB.txt")
PORT = 9011


def main():
    print("Listening on port 9011")
    call_function = {"Alist": Alist, "SongsInAlb": SongsInAlb, "SongLen": SongLen, "GetLyc": GetLyc, "WhichAlb": WhichAlb, "SByName": SByName, "SByLyc": SByLyc, "cmnWords": cmnWords, "albumLen": albumLen}
    listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('', PORT)
    listen_socket.bind(server_address)

    while True:  # the server runs forever, never closes. the second while is for the client socket, which closes
        listen_socket.listen(1)
        client_socket, client_address = listen_socket.accept()
        command = ""
        client_socket.sendall("Welcome to Pink Floyd database!".encode())
        print(client_address[0] + " has connected on port " + str(client_address[1]))
        while not command == "Exit":
            try:  # try to send response, throw exception if you can't
                response = client_socket.recv(1024).decode()
                command, parameter = disassemble_response(response)
                if not command == "Exit":
                    a = call_function[command](parameter)
                    client_socket.sendall(a.encode())
            except Exception:
                print("Client disconnected unexpectedly")
                break
        client_socket.close()
        print("Connection closed. Listening on port 9011")
    listen_socket.close()


def disassemble_response(client_response):
    """
    The function disassembles the request to command and parameter
    :param client_response:the response of the clients
    :type client_response: str
    :return:command the parameter
    :rtype: tuple
    """
    command = client_response[8:client_response.index('&')]
    parameter = client_response[client_response.index('&') + 11:]
    return command, parameter


def Alist(parameter):
    """
    the function returns a list with all the albums
    :param parameter: default empty parameter
    :type parameter: str
    :return: a list with album names
    :rtype: list
    """
    album_list = []
    print("Alist function is being activated")
    for song in database:
        if song[4] not in album_list:
            album_list.append(song[4])
    return "Album list: " + str(album_list)


def SongsInAlb(parameter):
    print("SongsInAlb function activated")
    # song[0] - song name, song[4] - album name
    song_list = []
    for song in database:
        if (song[4] == parameter) and (song[0] not in song_list):
            song_list.append(song[0])
    return "Songs in \'" + str(parameter) + '\': ' + str(song_list)


def SongLen(parameter):
    print("SongLen function activated")
    # song[0] - song name, song[2] - length
    for song in database:
        if song[0] == parameter:
            return parameter + "\'s length: " + str(song[2])


def GetLyc(parameter):
    """
    The function returns the lyrics for specific song
    :param parameter: song name
    :type parameter: str
    :return: the lyrics for the song
    :rtype: str
    """
    print("GetLyc function activated")
    # song[3] = lyrics, song[0] - song name
    for song in database:
        if song[0] == parameter:
            return "----Lyrics for \'" + song[0] + "\' are:----\n" + song[3]
    return "The entered song wasn't found"


def WhichAlb(parameter):
    """
    The function receives a song name and returns its album
    :param parameter: the song name
    :type parameter: str
    :return: the album of the song
    :rtype: str
    """
    print("WhichAlb function activated")
    # song[0] - song name, song[4] - album name
    for song in database:
        if song[0] == parameter:
            return "The song of \'" + song[0] + "\' is in the " + song[4] + "album"
    return "The entered song wasn't found"


def SByName(parameter):
    print("SByName function activated")
    song_list = []
    for song in database:
        if parameter.lower() in song[0].lower():
            song_list.append(song[0])
    return "Songs with the word you entered are in their name are: " + str(song_list) + "\n"


def SByLyc(parameter):
    print("SByLyc function activated")
    song_list = []
    for song in database:
        if parameter.lower() in song[3].lower():
            song_list.append(song[0])
    return "Songs with the lyrics you entered are: " + str(song_list) + "\n"


def cmnWords(parameter):
    """
    This function returns the 50 most common words in pink floyd lyrics
    :param parameter: empty parameter
    :type parameter: str
    :return: the list of the most common words
    :rtype: str
    """
    lyrics = ""
    words = []
    i = 0
    word = ""
    send = []
    occurrences = {}
    for song in database:
        lyrics += song[3]
    # separate words
    for char in lyrics:
        if not char == "\n" and not char == " " and not char == "." and not char == "," and not char == "!" and not char == "?":
            word += char
        else:
            if not word == '':
                words.append(word.lower())
            word = ""
    # not that we have the word list, we can count for occurrences
    for word in words:
        if not word == occurrences:
            occurrences[word] = words.count(word)
    sorted_words = sorted(occurrences.items())  # this make a list of tuples
    sorted_words.sort(key=return_second, reverse=True)
    for word in sorted_words:
        if i < 50:  # with range it doesnt work have no idea why
            send.append(word[0])
            i += 1
    return "The 50 most common words are: " + str(send)


def albumLen(parameter):
    """
    The function returns the list of albums from the longest to the shortest
    :param parameter: nothing
    :type parameter: str
    :return: the list of albums sorted from longest to shortest
    :rtype: str
    """
    len_dict = {}
    send = []
    for song in database:
        a = song[2]
        if len(a) == 5:
            s = int(a[0:2]) + int(a[3:5]) / 60  # get the time in minutes
        else:
            s = int(a[0]) + int(a[3:4]) / 60  # get the time in minutes
        if song[4] not in len_dict.keys():
            len_dict[song[4]] = s
        else:
            len_dict[song[4]] += s

    for key, value in len_dict.items():
        len_dict[key] = round(value, 2)
    sorted_words = sorted(len_dict.items())  # this make a list of tuples
    sorted_words.sort(key=return_second, reverse=True)

    for album in sorted_words:
        send.append(album[0])
    return "This is a list of albums from the longest to the shortest: " + str(send)


def return_second(t):
    """
    This function returns the second element of a tuple
    :param t: tuple
    :type t: tuple
    :return: second element of tuple
    :rtype: str
    """
    return t[1]


if __name__ == '__main__':
    main()