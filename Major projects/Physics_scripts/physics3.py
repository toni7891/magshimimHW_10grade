import xlsxwriter

workbook = xlsxwriter.Workbook("3.xlsx")
mySheet = workbook.add_worksheet()

f = 0.5
u = 0

u1 = []
v1 = []

while u != 3:
    u += 0.2
    u = ("{:.2f}".format(u))
    v = (1/f) - (1/float(u))
    v_value = 1/v
    v1.append(v_value)
    u1.append(u)
    u = float(u)
    
mySheet.write("A1", "u_value")
mySheet.write("B1", "v1_value")
mySheet.write("C1", "v2_value")

for i in range(2, len(u1)):
    mySheet.write(("A"+str(i)), u1[i])

for i in range(2, len(v1)):
    mySheet.write(("B"+str(i)), v1[i])

f = -0.5
u = 0

v2 = []
while u != 3:
    u += 0.2
    u = ("{:.2f}".format(u))
    v = (1/f) - (1/float(u))
    v_value = 1/v
    v2.append(v_value)
    u = float(u)

for i in range(2, len(v1)):
    mySheet.write(("C"+str(i)), v2[i])
workbook.close()
