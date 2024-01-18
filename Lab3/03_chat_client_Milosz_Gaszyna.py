import socket
from threading import Thread

SERVER_HOST = "127.0.0.1" # adres localhosta
SERVER_PORT = 3000 # numer portu

s = socket.socket() # tworzymy gniazdo
s.connect((SERVER_HOST, SERVER_PORT)) # laczy gniazdo z serwerem

def listen_for_messages_recived():
    while True:
        message_recived = s.recv(1024).decode() # odbiera od serwera do 1024 bajtow i dekoduje je
        print("\n" + message_recived) # wypisuje otrzymana wiadomosc

thread = Thread(target=listen_for_messages_recived) # nowy watek nasluchujacy serwera
thread.start() 

while True:
    message =  input()
    if message.lower() == 'exit':
        break
    s.send(message.encode())

s.close()
