# ----------------
# IronPython 2.7
# ----------------
# Matthew Robinson
# ----------------

import clr
import sys
import os

# Find the current project folder that we are running our environment from.
path = os.path.split(sys.argv[0])

# Import our compiled C# library
sys.path.Add(path)
clr.AddReference("ClassLibrary1.dll")
import ClassLibrary1

# Create an instance of the main class of our library
Math = ClassLibrary1.Class1()

x = Math.squareNumber(4)
print(x)

raw_input()
