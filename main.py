from oauth2client import client
from oauth2client.service_account import ServiceAccountCredentials
import gspread
from pprint import pprint 
import json

scope =  ["https://www.googleapis.com/auth/spreadsheets","https://www.googleapis.com/auth/drive.file","https://www.googleapis.com/auth/drive"]

creds = ServiceAccountCredentials.from_json_keyfile_name('sheet.json')
client = gspread.authorize(creds)

stocks = client.open('Stocks').sheet1
data=stocks.get_all_records()
with open("data.txt","w") as f:
    for items in data:
        f.write("%s\n"% items)

#pprint(data)


f.close()
