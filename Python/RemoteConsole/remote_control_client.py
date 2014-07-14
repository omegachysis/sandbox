#!/usr/bin/env python3

import socket
import traceback

ADDRESS = '10.0.0.13'
TERM = "$$..<>".encode()

def main():
    print("\n===============================================================\n")
    print(" - Connecting to remote server at {} ...".format(ADDRESS))

    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect((ADDRESS, 25566))

    print(" - Connected to remote server.")
    print("\n===============================================================\n")

    choice = ""
    while True:
        choice = input("\n :: ").encode() + TERM
        client.sendall(choice)

        response = bytes()
        while TERM not in response:
            response += client.recv(1024)
        response = response.decode()
        response = response.replace(bytes.decode(TERM), "")

        if "$$$STOP COMMAND" in response:
            client.sendall("$$$STOP COMMAND CONFIRMED".encode() + TERM)
            input("\n - Server closed.")
            break
        else:
            print("\n" + response)

if __name__ == "__main__":
    try:
        main()
    except:
        print(traceback.format_exc())
        input("\nPress enter to continue...")
