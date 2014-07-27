import clr
clr.AddReference('System.Drawing')
clr.AddReference('System.Windows.Forms')

from System.Drawing import *
from System.Windows.Forms import *

#--------------------------------------------
#
#  Hello World with IronPython
#
#--------------------------------------------

# tutorial index url:
#  http://www.voidspace.org.uk/ironpython/winforms/index.shtml
# current tutorial url:
#  http://www.voidspace.org.uk/ironpython/winforms/part2.shtml

class MyForm(Form):
    def __init__(self):
        self.Text = "Hello World"
        self.Name = "Hello World"

Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
