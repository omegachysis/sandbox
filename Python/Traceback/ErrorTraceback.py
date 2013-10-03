#!/usr/bin/env python3

import traceback

def main():
    raise ValueError

if __name__ == "__main__":
    try:
        main()
    except:
        print (traceback.format_exc())
        input ("Press enter to continue...")
