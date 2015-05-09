namespace Launcher {
    partial class SCam {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing) {
            if (disposing && (components != null)) {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent() {
            this.clIpBox = new System.Windows.Forms.TextBox();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.connect = new System.Windows.Forms.Button();
            this.label2 = new System.Windows.Forms.Label();
            this.clPortBox = new System.Windows.Forms.TextBox();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.label4 = new System.Windows.Forms.Label();
            this.clPathBox = new System.Windows.Forms.TextBox();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.label3 = new System.Windows.Forms.Label();
            this.svPathBox = new System.Windows.Forms.TextBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.runserver = new System.Windows.Forms.Button();
            this.label6 = new System.Windows.Forms.Label();
            this.svPortBox = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.groupBox1.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.SuspendLayout();
            // 
            // clIpBox
            // 
            this.clIpBox.Location = new System.Drawing.Point(83, 19);
            this.clIpBox.Name = "clIpBox";
            this.clIpBox.Size = new System.Drawing.Size(109, 20);
            this.clIpBox.TabIndex = 0;
            this.clIpBox.Text = "127.0.0.1";
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = global::Launcher.Properties.Resources.logo;
            this.pictureBox1.Location = new System.Drawing.Point(22, 35);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(132, 102);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(6, 22);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(61, 13);
            this.label1.TabIndex = 2;
            this.label1.Text = "IP Address:";
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.connect);
            this.groupBox1.Controls.Add(this.label2);
            this.groupBox1.Controls.Add(this.clPortBox);
            this.groupBox1.Controls.Add(this.label1);
            this.groupBox1.Controls.Add(this.clIpBox);
            this.groupBox1.Location = new System.Drawing.Point(180, 72);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(198, 101);
            this.groupBox1.TabIndex = 3;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Connection";
            // 
            // connect
            // 
            this.connect.Location = new System.Drawing.Point(117, 71);
            this.connect.Name = "connect";
            this.connect.Size = new System.Drawing.Size(75, 23);
            this.connect.TabIndex = 5;
            this.connect.Text = "Connect";
            this.connect.UseVisualStyleBackColor = true;
            this.connect.Click += new System.EventHandler(this.button1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(9, 48);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(29, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Port:";
            // 
            // clPortBox
            // 
            this.clPortBox.Location = new System.Drawing.Point(83, 45);
            this.clPortBox.Name = "clPortBox";
            this.clPortBox.Size = new System.Drawing.Size(109, 20);
            this.clPortBox.TabIndex = 3;
            this.clPortBox.Text = "6030";
            // 
            // groupBox2
            // 
            this.groupBox2.Controls.Add(this.label4);
            this.groupBox2.Controls.Add(this.clPathBox);
            this.groupBox2.Location = new System.Drawing.Point(180, 12);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(198, 48);
            this.groupBox2.TabIndex = 4;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "Client";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(6, 22);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(32, 13);
            this.label4.TabIndex = 2;
            this.label4.Text = "Path:";
            // 
            // clPathBox
            // 
            this.clPathBox.Location = new System.Drawing.Point(83, 19);
            this.clPathBox.Name = "clPathBox";
            this.clPathBox.Size = new System.Drawing.Size(109, 20);
            this.clPathBox.TabIndex = 0;
            this.clPathBox.Text = "Client.exe";
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.label3);
            this.groupBox3.Controls.Add(this.svPathBox);
            this.groupBox3.Location = new System.Drawing.Point(384, 12);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(198, 48);
            this.groupBox3.TabIndex = 6;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "Server";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(3, 22);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(32, 13);
            this.label3.TabIndex = 2;
            this.label3.Text = "Path:";
            // 
            // svPathBox
            // 
            this.svPathBox.Location = new System.Drawing.Point(83, 19);
            this.svPathBox.Name = "svPathBox";
            this.svPathBox.Size = new System.Drawing.Size(109, 20);
            this.svPathBox.TabIndex = 0;
            this.svPathBox.Text = "Server.exe";
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.runserver);
            this.groupBox4.Controls.Add(this.label6);
            this.groupBox4.Controls.Add(this.svPortBox);
            this.groupBox4.Location = new System.Drawing.Point(384, 72);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(198, 101);
            this.groupBox4.TabIndex = 7;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "Connection";
            // 
            // runserver
            // 
            this.runserver.Location = new System.Drawing.Point(117, 71);
            this.runserver.Name = "runserver";
            this.runserver.Size = new System.Drawing.Size(75, 23);
            this.runserver.TabIndex = 5;
            this.runserver.Text = "Run";
            this.runserver.UseVisualStyleBackColor = true;
            this.runserver.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(6, 22);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(29, 13);
            this.label6.TabIndex = 2;
            this.label6.Text = "Port:";
            // 
            // svPortBox
            // 
            this.svPortBox.Location = new System.Drawing.Point(83, 19);
            this.svPortBox.Name = "svPortBox";
            this.svPortBox.Size = new System.Drawing.Size(109, 20);
            this.svPortBox.TabIndex = 0;
            this.svPortBox.Text = "6030";
            // 
            // SCam
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(594, 185);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox3);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.pictureBox1);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedDialog;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "SCam";
            this.ShowIcon = false;
            this.Text = "Launcher";
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox4.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TextBox clIpBox;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Button connect;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox clPortBox;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox clPathBox;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox svPathBox;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button runserver;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.TextBox svPortBox;
    }
}

