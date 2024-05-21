using System;
using System.Data;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Configuration;
using System.Collections.Generic;

namespace LAB2BUUUN
{
    public partial class Form1 : Form
    {

        SqlConnection cs = new SqlConnection("Data Source=DESKTOP-99TL53K\\SQLEXPRESS;Initial Catalog=CarPartsShop;Integrated Security=True");
        string parentTableName = ConfigurationManager.AppSettings.Get("parentTableName");
        string childTableName = ConfigurationManager.AppSettings.Get("childTableName");
        string parentPrimaryKey = ConfigurationManager.AppSettings.Get("parentPrimaryKey");
        string childPrimaryKey = ConfigurationManager.AppSettings.Get("childPrimaryKey");
        string childColumns = ConfigurationManager.AppSettings.Get("childColumns");
        string columnNamesInsertParameters = ConfigurationManager.AppSettings.Get("columnNamesInsertParameters");
        List<string> childColumnsList = new List<string>(ConfigurationManager.AppSettings.Get("childColumns").Split(','));
        List<string> columnNamesInsertParametersList = new List<string>(ConfigurationManager.AppSettings.Get("columnNamesInsertParameters").Split(','));

        public Form1()
        {
            InitializeComponent();
            displayParentTable.Text = "Display " + parentTableName;
            displayChildTable.Text = "Display " + childTableName;
            int x = 10;
            int y = 10;
            foreach (string column in childColumnsList)
            {
                Label label = new Label();
                label.Text = column;
                label.Location = new System.Drawing.Point(x, y);
                panel1.Controls.Add(label);
                TextBox textBox = new TextBox();
                textBox.Name = column;
                textBox.Location = new System.Drawing.Point(x + 100, y);
                panel1.Controls.Add(textBox);
                y += 30;
            }

        }

        private void addButton_Click(object sender, EventArgs e)
        {
            try
            {
                int id = 0;
                string query = "SELECT MAX(" + childPrimaryKey + ") FROM " + childTableName;
                SqlCommand cmd = new SqlCommand(query, cs);
                cs.Open();
                SqlDataReader reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    id = reader.GetInt32(0);
                }
                cs.Close();
                id++;
                SqlCommand cmd2 = new SqlCommand("INSERT INTO " + childTableName + " (" + childColumns + ") VALUES (" + columnNamesInsertParameters + ")", cs);

                foreach (string column in childColumnsList)
                {
                    TextBox textBox = (TextBox)panel1.Controls[column];
                    if (string.IsNullOrWhiteSpace(textBox.Text))
                    {
                        MessageBox.Show(column + " should not be empty");
                        return;
                    }
                    cmd2.Parameters.AddWithValue("@" + column, textBox.Text);
                }
                cs.Open();
                cmd2.ExecuteNonQuery();
                cs.Close();
                MessageBox.Show(childTableName + " added successfully");
                DataSet ds = new DataSet();
                SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM " + childTableName, cs);
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];

                foreach (Control control in panel1.Controls)
                {
                    if (control is TextBox)
                    {
                        control.Text = "";
                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("An error occurred: " + ex.Message);
                if (cs.State == ConnectionState.Open)
                {
                    cs.Close();
                }
            }

        }



        private void displayChildTableButton_Click(object sender, EventArgs e)
        {
            DataSet ds = new DataSet();
            try
            {
                int id = (int)dataGridView2.SelectedRows[0].Cells[0].Value;
                SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM " + childTableName + " WHERE " + parentPrimaryKey + " = " + id, cs);
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show("Please select a " + parentTableName);
                return;
            }
        }

        private void displayParentTable_Click(object sender, EventArgs e)
        {
            DataSet ds = new DataSet();
            SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM " + parentTableName, cs);
            da.Fill(ds);
            dataGridView2.DataSource = ds.Tables[0];
            displayChildTable.Show();
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            try
            {
                int id = (int)dataGridView1.SelectedRows[0].Cells[0].Value;
                SqlCommand cmd = new SqlCommand("DELETE FROM " + childTableName + " WHERE " + childPrimaryKey + " = " + id, cs);
                cs.Open();
                cmd.ExecuteNonQuery();
                cs.Close();
                MessageBox.Show(childTableName + " deleted successfully");
                DataSet ds = new DataSet();
                SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM " + childTableName, cs);
                da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
            }
            catch (Exception ex)
            {
                MessageBox.Show("Please select a " + childTableName + " to delete");
                return;
            }

        }

        private void updateButton_Click(object sender, EventArgs e)
         {

             string updateQuery = ConfigurationManager.AppSettings.Get("updateQuery");
             try
             {
                 if (dataGridView1.SelectedRows.Count == 0)
                 {
                     throw new Exception("Please select a " + childTableName + " to update");
                 }
                 int id = (int)dataGridView1.SelectedRows[0].Cells[0].Value;
                 SqlCommand cmd = new SqlCommand(updateQuery, cs);
                 foreach (string column in childColumnsList)
                 {
                     if (column != childPrimaryKey) {
                         TextBox textBox = (TextBox)panel1.Controls[column];
                         if(textBox.Text == "")
                         {
                             throw new Exception("Please fill in all fields");
                         }
                         cmd.Parameters.AddWithValue("@" + column, textBox.Text);
                     }
                 }
                 cmd.Parameters.AddWithValue("@" + childPrimaryKey, id);
                 cs.Open();
                 cmd.ExecuteNonQuery();
                 cs.Close();
                 MessageBox.Show(childTableName + " updated successfully");
                 DataSet ds = new DataSet();
                 SqlDataAdapter da = new SqlDataAdapter("SELECT * FROM " + childTableName, cs);
                 da.Fill(ds);
                dataGridView1.DataSource = ds.Tables[0];
             }
             catch (Exception ex)
             {
                //MessageBox.Show("Please select a " + childTableName + " to update");
                 MessageBox.Show(ex.Message);
                 return;
             }

         }

    }
}
