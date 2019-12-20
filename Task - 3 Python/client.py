#Base Python client for MEng in IoT Assignment
#consumes data from IoT Gateway
import urllib3
# import html2text
import json
import matplotlib.pyplot as plt

http = urllib3.PoolManager()
resp = http.request('GET', 'http://localhost:8080/')

res_data = resp.data
decoded_data = res_data.decode('utf-8')
evaluated_data = eval(decoded_data)
list_readings = json.loads(evaluated_data)

time_list = []
temperature_list = []

for i in range(len(list_readings)):
    time_list.append(list_readings[i]['reading']['time'])
    temperature_list.append(list_readings[i]['reading']['temperature'])

print(time_list)
print(temperature_list)

plt.plot(time_list, temperature_list)
plt.show()







#'http://localhost:8080/'