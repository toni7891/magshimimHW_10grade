import socket
import datetime

caps = '''
1,China,Beijing,20693000
2,India,New Delhi,16787949
3,Japan,Tokyo,13189000
4,Philippines,Manila,12877253
5,Russia,Moscow,11541000
6,Egypt,Cairo,10230350
7,Indonesia,Jakarta,10187595
8,Democratic Republic of the Congo,Kinshasa,10125000
9,South Korea,Seoul,9989795
10,Mexico,Mexico City,8851080
11,Iran,Tehran,8846782
12,United Kingdom,London,8630100
13,Peru,Lima,8481415
14,Thailand,Bangkok,8249117
15,Germany,Berlin,3769495
16,Vietnam,Hanoi,7587800
17,Hong Kong,Hong Kong,7298600
18,Iraq,Baghdad,7216040
19,Singapore,Singapore,5535000
20,Turkey,Ankara,5150072
'''

def temp(city, date):
    SERVER_IP = '34.218.16.79'
    SERVER_PORT = 77

    #CREATE A TCP/IP SOCKET
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = (SERVER_IP, SERVER_PORT)
    sock.connect(server_address)


    sum1 = 0
    for i in city.lower():
        sum1 += ord(i)-96

    sum2 = 0
    for i in date:
        if i != "/":
            sum2 += int(i)

    # recieve
    server_msg = sock.recv(1024)
    server_msg = server_msg.decode()

    # send
    msg = "100:REQUEST:city=%s&date=%s&checksum=%d.%d" % (city, date, sum1, sum2)
    sock.sendall(msg.encode())



    # recieve
    server_msg = sock.recv(1024)
    server_msg = server_msg.decode()

    if "ERROR" in server_msg:
        return "999:" + server_msg.split("ERROR:")[1]
    t = server_msg.split("temp=")[1].split("&text=")[0]
    text = server_msg.split("text=")[1]

    return t, text


def main():
    today = datetime.date.today().strftime("%d/%m/%Y")
    print("Hello! and welcome to the auto temperature awesome maghsimeter\n")
    city = input("Please enter the name of your city (full name)")
    choice = input("Please choose an option:\n"
          "1: Get today's date!\n"
          "2: Get the date for the next 3 days!")
    ###


    if choice == '1':
        print(today + ": %s, %s." % temp(city=city, date=today))
    if choice == '2':
        for i in range(3):
            #get each iteration the date in 'i' days from today
            date = (datetime.date.today() + datetime.timedelta(days=i)).strftime("%d/%m/%Y")
            print(date + ": %s, %s." % temp(city=city, date=date))


if __name__ == '__main__':
    main()