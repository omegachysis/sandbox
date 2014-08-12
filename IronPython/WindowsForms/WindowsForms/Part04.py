import clr
clr.AddReference('System.Drawing')
clr.AddReference('System.Windows.Forms')

from System.Drawing import *
from System.Windows.Forms import *

#--------------------------------------------
#
#  Panels and Styles
#
#--------------------------------------------

# tutorial index url:
#  http://www.voidspace.org.uk/ironpython/winforms/index.shtml
# current tutorial url:
#  http://www.voidspace.org.uk/ironpython/winforms/part4.shtml

class MyForm(Form):
    def __init__(self):
        self.Text = "Hello World 3"
        self.FormBorderStyle = FormBorderStyle.FixedDialog

        screenSize = Screen.GetWorkingArea(self)
        self.Height = screenSize.Height / 3
        self.Width = screenSize.Width / 3

        self.panelHeight = self.ClientRectangle.Height / 2

        self.setupPanel1()
        self.setupPanel2()
        self.setupCounters()

        self.Controls.Add(self.panel1)
        self.Controls.Add(self.panel2)

    def setupPanel1(self):
        self.panel1 = Panel()
        self.panel1.BackColor = Color.LightSlateGray
        self.panel1.ForeColor = Color.Blue
        self.panel1.Width = self.Width
        self.panel1.Height = self.panelHeight
        self.panel1.Location = Point(0, 0)
        self.panel1.BorderStyle = BorderStyle.FixedSingle

        self.label1 = Label()
        self.label1.Text = "Go On - Press Me"
        self.label1.Location = Point(20, 20)
        self.label1.Height = 25
        self.label1.Width = 175

        self.button1 = Button()
        self.button1.Name = '1'
        self.button1.Text = 'Press Me 1'
        self.button1.Location = Point(20, 50)
        self.button1.Click += self.update

        self.panel1.Controls.Add(self.label1)
        self.panel1.Controls.Add(self.button1)

    def setupPanel2(self):
        self.panel2 = Panel()
        self.panel2.BackColor = Color.LightSalmon
        self.panel2.Width = self.Width
        self.panel2.Height = self.panelHeight
        self.panel2.Location = Point(0, self.panelHeight)
        self.panel2.BorderStyle = BorderStyle.FixedSingle

        self.subpanel1 = Panel()
        self.subpanel1.BackColor = Color.Wheat
        self.subpanel1.Width = 175
        self.subpanel1.Height = 100
        self.subpanel1.Location = Point(25, 25)
        self.subpanel1.BorderStyle = BorderStyle.Fixed3D

        self.label2 = Label()
        self.label2.Text = "Go On - Press Me"
        self.label2.Location = Point(20, 20)
        self.label2.Height = 25
        self.label2.Width = 175

        self.button2 = Button()
        self.button2.Name = '2'
        self.button2.Text = 'Press Me 2'
        self.button2.Location = Point(20, 50)
        self.button2.Click += self.update

        self.subpanel1.Controls.Add(self.label2)
        self.subpanel1.Controls.Add(self.button2)

        self.subpanel2 = Panel()
        self.subpanel2.BackColor = Color.Transparent
        self.subpanel2.Width = 175
        self.subpanel2.Height = 100
        self.subpanel2.Location = Point(220, 25)
        self.subpanel2.BorderStyle = BorderStyle.Fixed3D

        self.label3 = Label()
        self.label3.Text = "Go On - Press Me"
        self.label3.Location = Point(20, 20)
        self.label3.Height = 25
        self.label3.Width = 175

        self.button3 = Button()
        self.button3.Name = '3'
        self.button3.Text = 'Press Me 3'
        self.button3.Location = Point(20, 50)
        self.button3.Click += self.update

        self.subpanel2.Controls.Add(self.label3)
        self.subpanel2.Controls.Add(self.button3)

        self.panel2.Controls.Add(self.subpanel1)
        self.panel2.Controls.Add(self.subpanel2)

    def setupCounters(self):
        self.counterDict = {
            '1': 0,
            '2': 0,
            '3': 0,
        }

    def update(self, sender, event):
        name = sender.Name
        self.counterDict[name] += 1
        label = getattr(self, 'label' + name)
        label.Text = "You have pressed me %s times." % self.counterDict[name]


Application.EnableVisualStyles()
Application.SetCompatibleTextRenderingDefault(False)

form = MyForm()
Application.Run(form)
