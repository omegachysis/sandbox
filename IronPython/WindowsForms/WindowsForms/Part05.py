import clr
clr.AddReference('System.Drawing')
clr.AddReference('System.Windows.Forms')

from System.Drawing import *
from System.Windows.Forms import *

#--------------------------------------------
#
#  TextBox
#
#--------------------------------------------

# tutorial index url:
#  http://www.voidspace.org.uk/ironpython/winforms/index.shtml
# current tutorial url:
#  http://www.voidspace.org.uk/ironpython/winforms/part5.shtml

class MyForm(Form):
    def __init__(self):
        self.Text = "Simple TextBox Example"
        
        self.Width = 300
        self.Height = 200

        self.label = Label()
        self.label.Text = "Nothing So Far"
        self.label.Location = Point(25, 25)
        self.label.Height = 25
        self.label.Width = 250

        self.textbox = TextBox()
        self.textbox.Text = "The Default Text"
        self.textbox.Location = Point(25, 75)
        self.textbox.Width = 150

        self.button1 = Button()
        self.button1.Text = "Presse Me"
        self.button1.Location = Point(25, 125)
        self.button1.Click += self.update

        self.button2 = Button()
        self.button2.Text = "Reset"
        self.button2.Location = Point(125, 125)
        self.button2.Click += self.reset

        self.acceptButton = self.button1
        self.cancelButton = self.button2

        self.Controls.Add(self.label)
        self.Controls.Add(self.textbox)
        self.Controls.Add(self.button1)
        self.Controls.Add(self.button2)

    def update(self, sender, event):
        self.label.Text = self.textbox.Text

    def reset(self, sender, event):
        self.label.Text = "Nothing So Far"
        self.textbox.Text = "The Default Text"

Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
