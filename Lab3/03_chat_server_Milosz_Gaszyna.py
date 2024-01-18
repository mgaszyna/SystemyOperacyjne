import socket
from threading import Thread

SERVER_HOST = "0.0.0.0" # nasluchujemy wszystkich adresow
SERVER_PORT = 3000

client_sockets = set() # pusty zbior przechowujacy gniazda klientow
s = socket.socket() # towrzy nowe gniazdo sieciowe
s.bind((SERVER_HOST, SERVER_PORT)) # przypisuje stworzone gniazdo do adresu i portu
s.listen(10) # gniazdo w trybie nasluchiwania (max 10 polaczen)
print(f"Nasłuchuje na porcie {SERVER_PORT}")

def listen_for_client(client_socket):
    while True:
        try:
            message_from_client = client_socket.recv(1024).decode() # odczytaj do 1024 bajtow od klienta i zdekoduj
        except Exception:
            client_sockets.remove(client_socket)
        else:
            for c_socket in client_sockets:
                if c_socket != client_socket:
                    c_socket.send(message_from_client.encode())

while True:
    client_socket, _ = s.accept()
    client_sockets.add(client_socket)
    thread = Thread(target=listen_for_client, args=(client_socket,))
    thread.start()
