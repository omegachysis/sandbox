using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApplication2
{
    public partial class Form1 : Form
    {

        Timer timer = new Timer();

        public Form1()
        {
            InitializeComponent();

            timer.Tick += new EventHandler(timer_Tick); // Everytime timer ticks, timer_Tick will be called
            timer.Interval = (1000) * (3);             // Timer will tick evert 10 seconds
            timer.Enabled = true;                       // Enable the timer
            timer.Start();                              // Start the timer
        }

        void timer_Tick(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
