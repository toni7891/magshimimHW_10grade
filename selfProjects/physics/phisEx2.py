import xlsxwriter

workbook = xlsxwriter.Workbook("2.xlsx")
mySheet = workbook.add_worksheet()

x = -5.5
p = 2/x

x1_value = ["x1"]
p1_value = ["p1_value"]
p2_value = []

while x != 5:
    x += 0.5
    if x == 0:
        x += 0.5
    p = 2 / x
    print("when X is: " + str(("{:.2f}".format(x))) + ";  P is: " + str(("{:.2f}".format(p))))
    x1_value.append(x)
    p1_value.append(p)

for i in range(1, len(x1_value)):
    mySheet.write(("A"+str(i)), x1_value[i])

for i in range(1, len(p1_value)):
    mySheet.write("B"+str(i), p1_value[i])

x1 = -5.5
p1 = 0
while x1 != 5:
    x1 += 0.5
    if x1 == 0:
        x1 += 0.5
    p1 = (2+x1) / x1**2
    print("when X is: " + str(("{:.2f}".format(x1))) + ";  P is: " + str(("{:.2f}".format(p1))))
    p2_value.append(p1)

for i in range(1, len(p2_value)):
    mySheet.write(("C"+str(i)), p2_value[i])
workbook.close()
