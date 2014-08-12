import clr
clr.AddReference('System.Drawing')
clr.AddReference('System.Windows.Forms')

from System.Drawing import *
from System.Windows.Forms import *

#--------------------------------------------
#
#  Introduction to Windows Forms with IronPython
#
#--------------------------------------------

# tutorial index url:
#  http://www.voidspace.org.uk/ironpython/winforms/index.shtml
# current tutorial url:
#  http://www.voidspace.org.uk/ironpython/winforms/part1.shtml

class MyForm(Form):
    def __init__(self):
        # Create child controls and initialize form
        pass

Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
