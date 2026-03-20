def who_is_missing(file_name):
    with open(file_name, 'r') as data:
        num_list = []
        read = data.read()
        for i in read.split(','):
            num_list.append(int(i))
        num_list.sort()
    print(num_list)
    for item in range(1, len(num_list)):
        if item not in num_list:
            with open('found.txt', 'w+') as data:
                data.write(str(item))
            return item
