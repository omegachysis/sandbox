#!/usr/bin/env python3

import socket
import traceback
import errno
import os
import glob

from imp import reload

import remote_control_module as rcm

ADDRESS = '10.0.0.13'
TERM = "$$..<>".encode()

_print = print
def print(value):
    global connection
    _print(value)
    connection.sendall((str(value) + "\n").encode())

global_reset = False
env = None

def run_server():
    global connection
    global global_reset

    global ADDRESS
    global env
    global rcm

    _print("\n===============================================================\n")

    _print(" - Starting server at {} ...".format(ADDRESS))

    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind((ADDRESS, 25566))
    server.listen(1)

    connection, connaddress = server.accept()

    env = rcm.Environment(print)

    _print(" - Accepted connection from {}.".format(connaddress))

    _print("\n===============================================================\n")

    while True:
        message = bytes()
        while TERM not in message:
            message += connection.recv(1024)

        message = message.decode()
        message = message.replace(bytes.decode(TERM), "")
        if len(message) > 0:
            if message == "stop":
                print(" > {}".format(message))
                _print("\n - Stopping the remote server...")
                connection.sendall("$$$STOP COMMAND".encode() + TERM)
            elif "$$$STOP COMMAND CONFIRMED" in message:
                _print(" - Server closed.")
                global_reset = True
                break
            elif message.lower() in ["reload_module", "reload_env",
                             "reload_environment", "reload env",
                             "reload module", "reload environment",
                             "reload"]:
                reload(rcm)
                env = rcm.Environment(print)
                print(" - Server module reloaded.")
            else:
                print(" > {}".format(message) + "\n")
                env._process(message)

            connection.sendall(TERM)
            
    connection.close()

def main():
    while not global_reset:
        try:
            run_server()
        except socket.error as error:
            if error.errno == errno.WSAECONNRESET:
                _print("\n - Remote client disconnected...")
            else:
                raise

if __name__ == "__main__":
    try:
        main()
    except:
        _print(traceback.format_exc())
        input ("\nPress enter to continue...")
