
namespace LAB1
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            ShippingID = new TextBox();
            CustomerOrdersView = new DataGridView();
            ShippingDetailsView = new DataGridView();
            ShippingDate = new TextBox();
            ShippingStreet = new TextBox();
            label1 = new Label();
            label2 = new Label();
            label3 = new Label();
            button1 = new Button();
            ID = new TextBox();
            deleteModel = new Button();
            Model = new Label();
            label4 = new Label();
            ShippingCity = new TextBox();
            OrderID = new TextBox();
            label5 = new Label();
            shippingDateTextBox = new TextBox();
            shippingCityTextBox = new TextBox();
            shippingStreetTextBox = new TextBox();
            label6 = new Label();
            button2 = new Button();
            label7 = new Label();
            label8 = new Label();
            orderIDTextBox = new TextBox();
            shippingIDTextBox = new TextBox();
            label10 = new Label();
            label11 = new Label();
            ((System.ComponentModel.ISupportInitialize)CustomerOrdersView).BeginInit();
            ((System.ComponentModel.ISupportInitialize)ShippingDetailsView).BeginInit();
            SuspendLayout();
            // 
            // ShippingID
            // 
            ShippingID.Location = new Point(818, 103);
            ShippingID.Margin = new Padding(3, 2, 3, 2);
            ShippingID.Name = "ShippingID";
            ShippingID.Size = new Size(140, 25);
            ShippingID.TabIndex = 1;
            // 
            // CustomerOrdersView
            // 
            CustomerOrdersView.AllowUserToAddRows = false;
            CustomerOrdersView.AllowUserToDeleteRows = false;
            CustomerOrdersView.BackgroundColor = SystemColors.ActiveCaption;
            CustomerOrdersView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            CustomerOrdersView.Location = new Point(43, 44);
            CustomerOrdersView.Margin = new Padding(3, 2, 3, 2);
            CustomerOrdersView.Name = "CustomerOrdersView";
            CustomerOrdersView.RowHeadersWidth = 51;
            CustomerOrdersView.Size = new Size(554, 303);
            CustomerOrdersView.TabIndex = 2;
            CustomerOrdersView.CellContentClick += dataGridView1_CellContentClick_1;
            // 
            // ShippingDetailsView
            // 
            ShippingDetailsView.AllowUserToAddRows = false;
            ShippingDetailsView.BackgroundColor = SystemColors.ActiveCaption;
            ShippingDetailsView.ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            ShippingDetailsView.Location = new Point(12, 401);
            ShippingDetailsView.Margin = new Padding(3, 2, 3, 2);
            ShippingDetailsView.Name = "ShippingDetailsView";
            ShippingDetailsView.RowHeadersWidth = 51;
            ShippingDetailsView.Size = new Size(686, 330);
            ShippingDetailsView.TabIndex = 3;
            ShippingDetailsView.CellContentClick += dataGridView1_CellContentClick_2;
            // 
            // ShippingDate
            // 
            ShippingDate.Location = new Point(818, 151);
            ShippingDate.Margin = new Padding(3, 2, 3, 2);
            ShippingDate.Name = "ShippingDate";
            ShippingDate.Size = new Size(140, 25);
            ShippingDate.TabIndex = 4;
            // 
            // ShippingStreet
            // 
            ShippingStreet.Location = new Point(818, 197);
            ShippingStreet.Margin = new Padding(3, 2, 3, 2);
            ShippingStreet.Name = "ShippingStreet";
            ShippingStreet.Size = new Size(140, 25);
            ShippingStreet.TabIndex = 5;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(693, 110);
            label1.Name = "label1";
            label1.Size = new Size(90, 19);
            label1.TabIndex = 8;
            label1.Text = "ShippingID";
            label1.Click += label1_Click;
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(690, 154);
            label2.Name = "label2";
            label2.Size = new Size(109, 19);
            label2.TabIndex = 9;
            label2.Text = "ShippingDate";
            label2.Click += label2_Click;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(685, 200);
            label3.Name = "label3";
            label3.Size = new Size(120, 19);
            label3.TabIndex = 10;
            label3.Text = "ShippingStreet";
            // 
            // button1
            // 
            button1.Location = new Point(783, 293);
            button1.Margin = new Padding(3, 2, 3, 2);
            button1.Name = "button1";
            button1.Size = new Size(106, 27);
            button1.TabIndex = 12;
            button1.Text = "Add record";
            button1.UseVisualStyleBackColor = true;
            button1.Click += addButton_Click;
            // 
            // ID
            // 
            ID.Location = new Point(818, 363);
            ID.Margin = new Padding(3, 2, 3, 2);
            ID.Name = "ID";
            ID.Size = new Size(140, 25);
            ID.TabIndex = 15;
            // 
            // deleteModel
            // 
            deleteModel.Location = new Point(783, 420);
            deleteModel.Margin = new Padding(3, 2, 3, 2);
            deleteModel.Name = "deleteModel";
            deleteModel.Size = new Size(106, 59);
            deleteModel.TabIndex = 16;
            deleteModel.Text = "Delete record";
            deleteModel.UseVisualStyleBackColor = true;
            deleteModel.Click += deleteModel_Click;
            // 
            // Model
            // 
            Model.AutoSize = true;
            Model.Location = new Point(693, 369);
            Model.Name = "Model";
            Model.Size = new Size(90, 19);
            Model.TabIndex = 18;
            Model.Text = "ShippingID";
            Model.Click += label6_Click;
            // 
            // label4
            // 
            label4.AutoSize = true;
            label4.Location = new Point(693, 247);
            label4.Name = "label4";
            label4.Size = new Size(103, 19);
            label4.TabIndex = 19;
            label4.Text = "ShippingCity";
            label4.Click += label4_Click;
            // 
            // ShippingCity
            // 
            ShippingCity.Location = new Point(818, 240);
            ShippingCity.Margin = new Padding(3, 2, 3, 2);
            ShippingCity.Name = "ShippingCity";
            ShippingCity.Size = new Size(140, 25);
            ShippingCity.TabIndex = 20;
            // 
            // OrderID
            // 
            OrderID.ForeColor = SystemColors.MenuHighlight;
            OrderID.Location = new Point(818, 55);
            OrderID.Margin = new Padding(3, 2, 3, 2);
            OrderID.Name = "OrderID";
            OrderID.Size = new Size(140, 25);
            OrderID.TabIndex = 21;
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(693, 58);
            label5.Name = "label5";
            label5.Size = new Size(70, 19);
            label5.TabIndex = 22;
            label5.Text = "OrderID";
            // 
            // shippingDateTextBox
            // 
            shippingDateTextBox.Location = new Point(839, 611);
            shippingDateTextBox.Margin = new Padding(3, 2, 3, 2);
            shippingDateTextBox.Name = "shippingDateTextBox";
            shippingDateTextBox.Size = new Size(140, 25);
            shippingDateTextBox.TabIndex = 23;
            // 
            // shippingCityTextBox
            // 
            shippingCityTextBox.Location = new Point(839, 672);
            shippingCityTextBox.Margin = new Padding(3, 2, 3, 2);
            shippingCityTextBox.Name = "shippingCityTextBox";
            shippingCityTextBox.Size = new Size(140, 25);
            shippingCityTextBox.TabIndex = 25;
            // 
            // shippingStreetTextBox
            // 
            shippingStreetTextBox.Location = new Point(839, 640);
            shippingStreetTextBox.Margin = new Padding(3, 2, 3, 2);
            shippingStreetTextBox.Name = "shippingStreetTextBox";
            shippingStreetTextBox.Size = new Size(140, 25);
            shippingStreetTextBox.TabIndex = 26;
            // 
            // label6
            // 
            label6.AutoSize = true;
            label6.Location = new Point(713, 611);
            label6.Name = "label6";
            label6.Size = new Size(109, 19);
            label6.TabIndex = 27;
            label6.Text = "ShippingDate";
            // 
            // button2
            // 
            button2.Location = new Point(783, 707);
            button2.Margin = new Padding(3, 2, 3, 2);
            button2.Name = "button2";
            button2.Size = new Size(106, 59);
            button2.TabIndex = 28;
            button2.Text = "Update record";
            button2.UseVisualStyleBackColor = true;
            button2.Click += updateModel_Click;
            // 
            // label7
            // 
            label7.AutoSize = true;
            label7.Location = new Point(721, 678);
            label7.Name = "label7";
            label7.Size = new Size(103, 19);
            label7.TabIndex = 29;
            label7.Text = "ShippingCity";
            // 
            // label8
            // 
            label8.AutoSize = true;
            label8.Location = new Point(704, 640);
            label8.Name = "label8";
            label8.Size = new Size(120, 19);
            label8.TabIndex = 30;
            label8.Text = "ShippingStreet";
            // 
            // orderIDTextBox
            // 
            orderIDTextBox.Location = new Point(839, 570);
            orderIDTextBox.Margin = new Padding(3, 2, 3, 2);
            orderIDTextBox.Name = "orderIDTextBox";
            orderIDTextBox.Size = new Size(140, 25);
            orderIDTextBox.TabIndex = 32;
            // 
            // shippingIDTextBox
            // 
            shippingIDTextBox.Location = new Point(839, 520);
            shippingIDTextBox.Margin = new Padding(3, 2, 3, 2);
            shippingIDTextBox.Name = "shippingIDTextBox";
            shippingIDTextBox.Size = new Size(140, 25);
            shippingIDTextBox.TabIndex = 33;
            // 
            // label10
            // 
            label10.AutoSize = true;
            label10.Location = new Point(724, 520);
            label10.Name = "label10";
            label10.Size = new Size(70, 19);
            label10.TabIndex = 34;
            label10.Text = "OrderID";
            // 
            // label11
            // 
            label11.AutoSize = true;
            label11.Location = new Point(704, 570);
            label11.Name = "label11";
            label11.Size = new Size(90, 19);
            label11.TabIndex = 35;
            label11.Text = "ShippingID";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(9F, 19F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(1261, 779);
            Controls.Add(label11);
            Controls.Add(label10);
            Controls.Add(shippingIDTextBox);
            Controls.Add(orderIDTextBox);
            Controls.Add(label8);
            Controls.Add(label7);
            Controls.Add(button2);
            Controls.Add(label6);
            Controls.Add(shippingStreetTextBox);
            Controls.Add(shippingCityTextBox);
            Controls.Add(shippingDateTextBox);
            Controls.Add(label5);
            Controls.Add(OrderID);
            Controls.Add(ShippingCity);
            Controls.Add(label4);
            Controls.Add(Model);
            Controls.Add(deleteModel);
            Controls.Add(ID);
            Controls.Add(button1);
            Controls.Add(label3);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(ShippingStreet);
            Controls.Add(ShippingDate);
            Controls.Add(ShippingDetailsView);
            Controls.Add(CustomerOrdersView);
            Controls.Add(ShippingID);
            Font = new Font("Bookman Old Style", 9F, FontStyle.Regular, GraphicsUnit.Point, 0);
            Margin = new Padding(3, 2, 3, 2);
            Name = "Form1";
            Text = "Form1";
            Load += Form1_Load_1;
            Paint += Form1_Paint;
            ((System.ComponentModel.ISupportInitialize)CustomerOrdersView).EndInit();
            ((System.ComponentModel.ISupportInitialize)ShippingDetailsView).EndInit();
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion
        private TextBox ShippingID;
        private DataGridView CustomerOrdersView;
        private DataGridView ShippingDetailsView;
        private TextBox ShippingDate;
        private TextBox ShippingStreet;
        private Label label1;
        private Label label2;
        private Label label3;
        private Button button1;
        private TextBox ID;
        private Button deleteModel;
        private Label Model;
        private Label label4;
        private TextBox ShippingCity;
        private TextBox OrderID;
        private Label label5;
        private TextBox shippingDateTextBox;
        private TextBox shippingCityTextBox;
        private TextBox shippingStreetTextBox;
        private Label label6;
        private Button button2;
        private Label label7;
        private Label label8;
        private TextBox orderIDTextBox;
        private TextBox shippingIDTextBox;
        private Label label10;
        private Label label11;
    }
}
