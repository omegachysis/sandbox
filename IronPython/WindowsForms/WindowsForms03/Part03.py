import clr
clr.AddReference('System.Drawing')
clr.AddReference('System.Windows.Forms')

from System.Drawing import *
from System.Windows.Forms import *

#--------------------------------------------
#
#  Widgets & Event Handlers
#
#--------------------------------------------

# tutorial index url:
#  http://www.voidspace.org.uk/ironpython/winforms/index.shtml
# current tutorial url:
#  http://www.voidspace.org.uk/ironpython/winforms/part3.shtml

class MyForm(Form):
    def __init__(self):
        pass


Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
