def get_text(file_path):
    """
    The file returns the context of a given the file
    :param file_path: the file path
    :type file_path: str
    :return: the file context
    :rtype: str
    """
    with open(file_path, "r") as file:
        text_string = file.read()
    return text_string


def extract_data(input_file):
    """
    The function extracts the information from the text file and formats it accordingly
    :param input_file: the database file
    :type input_file: str
    :return: the database in a list of tuples
    :rtype: list
    """
    input_file = get_text(input_file)  # get the text from the file
    song_index = 1
    database = []
    for song in range(0, input_file.count("*")):  # run through the number of songs, each time assemble the required information

        # find song name
        song_index = input_file.find('*', song_index + 1)  # update the song index to the last appearance of *
        song_name = input_file[song_index + 1:input_file.find(':', song_index)]  # assign the song and go on!
        #  find song length
        singer_index = input_file.find(':', song_index) + 2
        singer = input_file[singer_index:input_file.find(":", singer_index)]
        # find song length
        length_index = input_file.find(':', singer_index) + 2
        song_length = input_file[length_index:input_file.find(":", length_index) + 3]
        # find song lyrics
        lyc_index = input_file.find(':', length_index) + 5
        lyc = input_file[lyc_index:input_file.find("*", length_index) or input_file.find("#", length_index)]
        # finding album:
        max_index = 0  # this will be the index of the highest # until the song index
        for i in range(0, song_index):
            if input_file[i] == "#":
                max_index = i
        album_name = input_file[max_index + 1:input_file.find(":", max_index + 1)]
        # get album year
        year_index = input_file.find(album_name) + len(album_name) + 2
        album_year = input_file[year_index:year_index + 4]
        database.append((song_name, singer, song_length, lyc, album_name, album_year))
    return database