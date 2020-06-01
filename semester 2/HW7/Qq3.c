import socket
import data_pinkFloyd

database = data_pinkFloyd.extract_data("Pink_Floyd_DB.txt")
PORT = 1337


def main(): 
    print("Listening on port 1337")
    call_function = {"AlbumList": AlbumList, "SongsInAlbum": SongsInAlbum, "SongLength": SongLength, "GetLyrics": GetLyrics, "WhichAlbum": WhichAlbum, "SongByName": SongByName, "SongByLyrics": SongByLyrics, "MostCommonWords": MostCommonWords, "AlbumLength": AlbumLength}
    listen_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ('', PORT)
    listen_socket.bind(server_address)
    
	while True: 
			listen_socket.listen(1)
			client_socket, client_address = listen_socket.accept()
			command = ""
			client_socket.sendall("Welcome to Pink Floyd database!".encode())
			print(client_address[0] + " has connected on port " + str(client_address[1]))
			while not command == "Exit":
				try: 
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

    command = client_response[8:client_response.index('&')]
    parameter = client_response[client_response.index('&') + 11:]
    return command, parameter


def AlbumList(parameter):

    album_list = []
    for song in database:
        if song[4] not in album_list:
            album_list.append(song[4])
    return "Album list: " + ", ".join(album_list)


def SongsInAlbum(parameter):
    song_list = []
    for song in database:
        if (song[4] == parameter) and (song[0] not in song_list):
            song_list.append(song[0])
    return "Songs in \'" + str(parameter) + '\': ' + ", ".join(song_list)


def SongLength(parameter):
    for song in database:
        if song[0] == parameter:
            return parameter + "\'s length: " + str(song[2])


def GetLyrics(parameter):
    for song in database:
        if song[0] == parameter:
            return "----Lyrics for \'" + song[0] + "\' are:----\n" + song[3]
    return "The entered song wasn't found"


def WhichAlbum(parameter):
#song[0] - song name, song[4] - album name
    for song in database:
        if song[0] == parameter:
            return "The song of \'" + song[0] + "\' is in the " + song[4] + "album"
    return "The entered song wasn't found"


def SongByName(parameter):
    song_list = []
    for song in database:
        if parameter.lower() in song[0].lower():
            song_list.append(song[0])
    return "Songs with the word you entered are in their name are: " + str(song_list) + "\n"


def SongByLyrics(parameter):
    song_list = []
    for song in database:
        if parameter.lower() in song[3].lower():
            song_list.append(song[0])
    return "Songs with the lyrics you entered are: " + str(song_list) + "\n"


def MostCommonWords(parameter):
    lyrics = ""
    words = []
    i = 0
    word = ""
    send = []
    occurrences = {}
    for song in database:
        lyrics += song[3]

    for char in lyrics:
        if not char == "\n" and not char == " " and not char == "." and not char == "," and not char == "!" and not char == "?":
            word += char
        else:
            if not word == '':
                words.append(word.lower())
            word = ""

    for word in words:
        if not word == occurrences:
            occurrences[word] = words.count(word)
    sorted_words = sorted(occurrences.items())  # this make a list of tuples
    sorted_words.sort(key=return_second, reverse=True)
    for word in sorted_words:
        if i < 50:  
            send.append(word[0])
            i += 1
    return "The 50 most common words are: " + str(send)


def AlbumLength(parameter):
    len_dict = {}
    send = []
    for song in database:
        a = song[2]
        if len(a) == 5:
            s = int(a[0:2]) + int(a[3:5]) / 60  
        else:
            s = int(a[0]) + int(a[3:4]) / 60  
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
    return t[1]


if __name__ == '__main__':
    main()
