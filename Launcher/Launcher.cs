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

namespace Launcher {
    public partial class SCam : Form {
        public SCam() {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e) {
            string path = clPathBox.Text;
            string ip = clIpBox.Text;
            string port = clPortBox.Text;

            Process process = new Process();
            try {
                process.StartInfo.FileName = path;
                process.StartInfo.Arguments = ip + " " + port;
                process.Start();
            } catch (Exception ex) {
                MessageBox.Show(ex.Message);
            }
        }

        private void button1_Click_1(object sender, EventArgs e) {
            string path = svPathBox.Text;
            string port = svPortBox.Text;

            Process process = new Process();
            try {
                process.StartInfo.FileName = path;
                process.StartInfo.Arguments = port;
                process.Start();
            } catch (Exception ex) {
                MessageBox.Show(ex.Message);
            }
        }
    }
}
