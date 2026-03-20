import xlsxwriter

workbook = xlsxwriter.Workbook("1.xlsx")
mySheet = workbook.add_worksheet()

mySheet.write("A1", "t_value")
mySheet.write("B1", "y1_value")
mySheet.write("C1", "y2_value")

t = 0
t1 = 0
y2 = 0

t1_value = []
y1_value = []
y2_value = []

while int(t) != 2:
    t += 0.1
    y1 = (5 * t) + ((2 * t) ** 2)
    t = ("{:.2f}".format(t))
    t1_value.append(t)
    y1_value.append(y1)
    t = float(t)
    print(y1)

j = 0
for i in range(2, len(t1_value)+2):
    mySheet.write(("A"+str(i)), t1_value[j])
    j += 1

j = 0
for i in range(2, len(y1_value)+2):
    mySheet.write("B"+str(i), y1_value[j])
    j += 1

while int(t1) != 2:
    t1 += 0.1
    y2 = 30 + (10 * t1) - ((5 * t1) ** 2)
    t1 = ("{:.2f}".format(t1))
    y2_value.append(y2)
    t1 = float(t1)

j = 0
for i in range(2, len(y2_value)+2):
    mySheet.write(("C"+str(i)), y2_value[j])
    j += 1

workbook.close()
