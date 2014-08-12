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
        self.Text = "Hello World"
        self.Name = "Hello World"

        label = Label()
        label.Text = "Please Click Me"
        label.Location = Point(50, 50)
        label.Width = 200
        label.Height = 30
        self.Controls.Add(label)
        self.label = label

        button = Button()
        button.Text = "Click Me"
        button.Location = Point(50, 100)
        button.Click += self.buttonPressed
        self.Controls.Add(button)
        self.button = button

        self.count = 0

    def buttonPressed(self, sender, args):
        self.count += 1
        self.label.Text = "You have clicked me %s times." % self.count

Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
