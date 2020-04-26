import requests
import collections


def extract_password_from_site():
    new_list = []
    dict_of_req = {
        1: requests.get('http://webisfun.cyber.org.il/nahman/files/file11.nfo'),
        2: requests.get('http://webisfun.cyber.org.il/nahman/files/file12.nfo'),
        3: requests.get('http://webisfun.cyber.org.il/nahman/files/file13.nfo'),
        4: requests.get('http://webisfun.cyber.org.il/nahman/files/file14.nfo'),
        5: requests.get('http://webisfun.cyber.org.il/nahman/files/file15.nfo'),
        6: requests.get('http://webisfun.cyber.org.il/nahman/files/file16.nfo'),
        7: requests.get('http://webisfun.cyber.org.il/nahman/files/file17.nfo'),
        8: requests.get('http://webisfun.cyber.org.il/nahman/files/file18.nfo'),
        9: requests.get('http://webisfun.cyber.org.il/nahman/files/file19.nfo'),
        10: requests.get('http://webisfun.cyber.org.il/nahman/files/file20.nfo'),
        11: requests.get('http://webisfun.cyber.org.il/nahman/files/file21.nfo'),
        12: requests.get('http://webisfun.cyber.org.il/nahman/files/file22.nfo'),
        13: requests.get('http://webisfun.cyber.org.il/nahman/files/file23.nfo'),
        14: requests.get('http://webisfun.cyber.org.il/nahman/files/file24.nfo'),
        15: requests.get('http://webisfun.cyber.org.il/nahman/files/file25.nfo'),
        16: requests.get('http://webisfun.cyber.org.il/nahman/files/file26.nfo'),
        17: requests.get('http://webisfun.cyber.org.il/nahman/files/file27.nfo'),
        18: requests.get('http://webisfun.cyber.org.il/nahman/files/file28.nfo'),
        19: requests.get('http://webisfun.cyber.org.il/nahman/files/file29.nfo'),
        20: requests.get('http://webisfun.cyber.org.il/nahman/files/file30.nfo'),
        21: requests.get('http://webisfun.cyber.org.il/nahman/files/file31.nfo'),
        22: requests.get('http://webisfun.cyber.org.il/nahman/files/file32.nfo'),
        23: requests.get('http://webisfun.cyber.org.il/nahman/files/file33.nfo'),
        24: requests.get('http://webisfun.cyber.org.il/nahman/files/file34.nfo')}

    for key in dict_of_req:
        temp = dict_of_req[key]
        flag = 0
        for char in temp.text:
            flag += 1
            if flag == 100:
                new_list.append(char)
    return "".join(new_list)

def find_most_common_words():
    file = requests.get(
        'http://webisfun.cyber.org.il/nahman/final_phase/words.txt').text.split(" ")
    list_sorted = collections.Counter(file).most_common(6)
    first_tuple_elements = [a_tuple[0] for a_tuple in list_sorted]
    return " ".join(first_tuple_elements)

def main():
    choice = int(input("1: Find the password (part 1).\n2: Find sentence (part 2)\nYour choice?: "))
    print(extract_password_from_site()) if choice is 1 else print(find_most_common_words())

if __name__ == '__main__':
    main()
